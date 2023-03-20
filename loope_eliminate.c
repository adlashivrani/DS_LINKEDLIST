#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node *head;

struct node *insert(int);
void remove_loop(struct node *);
struct node *meet_node(struct node *);
struct node *start_node(struct node *);
void display(struct node *);

// Driver Code
int main()
{
        struct node* head = insert(10);
        head->next = insert(20);
        head->next->next = insert(30);
        head->next->next->next = insert(40);
        head->next->next->next->next = insert(50);
        /* Create a loop for testing */
        head->next->next->next->next->next = head->next->next;
        remove_loop(head);
        printf("Linked List after removing loop \n");
        display(head);
        return 0;
}

struct node *meet_node(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;
	while ( fast != NULL && fast->next != NULL) { //find if loop exists or not
		slow = slow->next;
		fast = fast->next->next;
		/* If slow and fast meet at some point then there
		is a loop */
		if (slow == fast) {
			return slow;
		}
	}
	return NULL; // no loop detected
}
struct node *start_node( struct node *head)
{ 	
	struct node *meet = meet_node(head);
	struct node *start = head;
	while ( start != meet) {
		start = start->next;
		meet = meet->next;
	}
	return start;
}		
void remove_loop(struct node *head)
{
	struct node *ptr1 = start_node(head);
	struct node *ptr2 = meet_node(head);
	while (ptr2->next != ptr1)
		ptr2 = ptr2->next;
	ptr2->next = NULL;
}

/* Function to display the linked list */
void display(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

struct node* insert(int data)
{
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

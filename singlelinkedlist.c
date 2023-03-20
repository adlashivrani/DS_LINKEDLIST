#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head;
struct node *newnode;
struct node *temp;
struct node *nextnode;

int pos;
int i;
int count;
int choice;

void create();
void insert();
void delete();
void display();
void search();
int length();
void reverse();
int main()
{ 
	int ch;
	while (1) {
		printf("\nSELECT OPTION:\n");
		printf("\nMenu:\n1.create\n2.insert\n3.delete\n4.display\n5.search\n6.reverse\n7.exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				create();
				break;
			case 2:
				insert();
				break;
			case 3:
				delete();
				break;
			case 4:
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				reverse();
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("\nEnter Correct Option!\n");
			}
	}
	return 0;
}

void create() 
{ 
	int choice;
	head = NULL;
	while (choice) {
		newnode = ( struct node *) malloc( sizeof(struct node));
		printf("Enter data\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		if ( head == NULL) {
			temp = head = newnode;
		} else {
				temp->next = newnode;
				temp = newnode;
		}
		printf("Select choice either 0 0r 1 ");
		scanf("%d", &choice);
	}
}
	
int length()
{ 	
	int count;
	count = 0;
	temp = head;
	while ( temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
	
void insert()
{
 	count = length();
	printf("Enter a positon\n");
	scanf("%d", &pos);
	if ( count < pos) {
		printf("\nInvalid position\n");
	} else {
			temp = head;
			int i = 1;
			while ( i < pos) {
				temp = temp->next;
				i++;
			}
		newnode = (struct node*) malloc ( sizeof(struct node));
		printf("\nEnter data:\n");
		scanf("%d", &newnode->data);
		newnode->next = temp->next;
		temp->next = newnode;
	}
	
}
void delete()
{
	count = length();
	int pos;
	printf("Enter a position\n");
	scanf("%d", &pos);
	if ( count < pos) {
		printf("Invalid position");
	} else {
				temp = head;
				int i = 1;
				while ( i < pos - 1) {
					temp = temp->next;
					i++;
				}
				nextnode = temp ->next;
				temp->next = nextnode->next;
				free(nextnode);
	}
}

void search()
{
 	int val;
	int flag = 0;
	temp = head;
	printf("\nEnter value:\n");
	scanf("%d", &val);
	while ( temp != NULL) {
		if ( temp->data == val) {
			flag = 1;
			break;
		}
		temp = temp ->next;
	}
	if ( flag == 1) {
		printf("\nElement found\n");
	} else {
		printf("\n Element not found\n");
	}
}
void display()
{
	temp = head;
	printf("\nLinked list:\n");
	while ( temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void reverse()
{
	struct node *prev = NULL;
	struct node *current;
	current = nextnode = head;
	while ( nextnode != NULL) {
		nextnode = nextnode->next;
		current->next = prev;
		prev = current;
		current = nextnode;
	}
	head = prev;
}

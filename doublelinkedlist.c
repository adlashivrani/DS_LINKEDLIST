#include<stdio.h>
#include<stdlib.h>
de->next = NULL;

struct node {
	struct node *next;
	int data;
	struct node *prev;
};
struct node *head;
struct node *newnode;
struct node *temp;

void create();
void display();
void search();
int length();
void insert_pos();
void insert_end();
void insert_begin();
void delete_begin();
void delete_end();
void delete_pos();

int main()
{
	int ch;
	while(1) {
		printf("\nSelect option:\n");
		printf("\n1.Create\n2.Display\n3.Search\n4.Insert\n5.delete\n6.Exit\n");
		scanf("%d", &ch);
		switch ( ch) {
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				insert_pos();
				break;
			case 5:
				delete_pos();
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("\nEnter Correct Option\n");
		}
	}
	return 0;
}

void create()
{
	head = NULL;
	int choice = 1;
	while(choice) {
		newnode = (struct node *) malloc (sizeof(struct node));
		printf("\nEnter data\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		newnode->prev = NULL;
		if ( head == NULL) {
			head = newnode; 
			temp = newnode;
		} else {
				
				temp->next = newnode;
				newnode->prev = temp;
				temp = newnode;
			}
		printf("\nEnter 1 to continue or 0 to exit\n");
		scanf("%d", &choice);
	}
}

void display()
{ 	
	temp = head;
	printf("\nDouble Linked list:\n ");
	while ( temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int length()
{ 	
	int count = 0;
	temp = head;
	while ( temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void search()
{ 
	int val;
	temp = head;
	int loc = 0;
	int flag = 0;
	printf("\nEnter value:\n ");
	scanf("%d", &val);
	while ( temp != NULL) {
		if ( temp->data == val) {
			flag = 1;
			break;
		}
		temp = temp->next;
		loc++;
	}
	if ( flag == 1) {
		printf("\nElement found at %d location:\n", loc + 1);
	} else {
		printf("\nElement not found\n");
	}
}

void insert_begin()
{
	newnode  = (struct node *) malloc (sizeof(struct node));
	printf("Enter data");
	scanf("%d", &newnode->data);
	newnode->next = head;
	newnode->prev = NULL;
	if ( head != NULL) {
		head->prev = newnode;
		head = newnode;
	}
}

void insert_end()
{
	if (head = NULL) {
		head = newnode;
		newnode->prev = NULL;
	} else {
		newnode = (struct node*) malloc (sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}

void insert_pos()
{ 	
	int count = length();
	int pos;
	printf("Enter the position:\n");
	scanf("%d", &pos);
	if (pos < 1 || pos > count) {
		printf("Invalid position\n");
	} else if ( pos == 1) {
		insert_begin();
	} else if (pos == count) {
		insert_end();
	}	else {
		temp = head;
		newnode = (struct node*) malloc (sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		int i = 1;
		while (i < pos) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void delete_begin()
{
	temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}

void delete_end()
{
	if ( head == NULL) {
		printf("underflow");
	}	else if (head->next == NULL) {
		head = NULL;
		free(head);
	} else { 
		temp = head;
		while (temp->next != NULL) {
				temp = temp->next;
		}
	temp->prev->next = NULL;
	free(temp);
	}
}

void delete_pos()
{
	int pos;
	int count = length();
	printf("%d", count);
	printf("Enter position:\n");
	scanf("%d", &pos);
	if ( pos < 1 || pos > count) {
		printf("ERROR\n");
	} else if ( pos == 1) {
		delete_begin();
	} else if ( pos == count) {
		delete_end();
	} else {
		temp = head;
		int i = 1;
		while ( i != pos - 1) {
			temp = temp->next;
			i++;
		}
	struct node *nextnode = temp->next;
	temp->next = nextnode->next;
	nextnode->next->prev = temp;
	free(nextnode);
	}
}

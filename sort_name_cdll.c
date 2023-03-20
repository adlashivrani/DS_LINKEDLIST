#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int id;
    char name[50];
    char gender[10];
    char occupation[20];
    int age;
    struct node* prev;
    struct node* next;
};
struct node *head;
struct node *temp;

struct node *create();
void display(struct node *);
void reverselist(struct node *);
void sort(struct node *);

int main()
{
    head = NULL;
    head = create();
    sort(head);
	reverselist(head);
	printf("\nLinkedlist in reverse order starting from M:\n");
    display(head);
    return 0;
}

struct node *create()
{
        head = NULL;
        struct node *new;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
         while(ch != EOF) {
                        new = (struct node* ) malloc (sizeof(struct node));
                        ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
                new->prev = NULL;
                new->next = NULL;
                if (head == NULL) {
                head = new;
                temp = new;
                new->prev = new;
                } else {
                temp->next = new;
                new->prev = temp;
                temp = temp->next;
                }
                new->next = head;
        }
}

void sort(struct node* head)
{
        struct node *i;
        struct node *j;
        struct node* temp;
        for ( i = head; i->next != head; i = i->next) {
                for (j = i->next; j != head; j = j->next) {
                        if (strcmp(i->name, j->name) > 0) {
                                temp->id = i->id;
                                strcpy(temp->name, i->name);
                                strcpy(temp->gender, i->gender);
                                strcpy(temp->occupation, i->occupation);
                                temp->age = i->age;

                                i->id = j->id;
                                strcpy(i->name, j->name);
                                strcpy(i->gender, j->gender);
                                strcpy(i->occupation, j->occupation);
                                i->age = j->age;

                                j->id = temp->id;
                                strcpy(j->name, temp->name);
                                strcpy(j->gender, temp->gender);
                                strcpy(j->occupation, temp->occupation);
                                j->age = temp->age;
                    }
                }
        }
}
void reverselist(struct node *head) 
{
	if (head != NULL) {
		//1. If head is not null create three nodes
  		//prevNode - pointing to head,
  		//tempNode - pointing to head,
  		//curNode - pointing to next of head
		struct node* last = head;
    	struct node* prevNode = last;
    	struct node* tempNode = last;
    	struct node* curNode = last->next;
		//2. assign next and previous of prevNode 
    	//as itself to make the first node as last 
    	//node of the reversed list
    	prevNode->next = prevNode;
    	prevNode->prev = prevNode;
    
        while (curNode != head) {
		 	//. While the curNode is not head adjust links 
      		//(unlink curNode and link it to the reversed list 
      		//from front and modify curNode and prevNode)  
      		tempNode = curNode->next;
      		curNode->next = prevNode;
     	 	prevNode->prev = curNode;
      		last->next = curNode;
      		curNode->prev = last;

      		prevNode = curNode;
      		curNode = tempNode;
    	}
		//4. Make prevNode (last node) as head
    	last = prevNode;
  } 
}
 			 
void display(struct node *head)
{
        int c = 0;
		temp = head->next;
        while ( temp != head) {
			if ( temp->name[0] == 'M') {
                printf("%d\t", temp->id);
                printf("%-20s", temp->name);
                printf("%-20s", temp->gender);
                printf("%-20s", temp->occupation);
                printf("%d\n", temp->age);
				c = 1;
			} else if ( c == 1) {
			 	printf("%d\t", temp->id);
             	printf("%-20s", temp->name);
             	printf("%-20s", temp->gender);
             	printf("%-20s", temp->occupation);
             	printf("%d\n", temp->age);	
			}
            temp = temp->next;
        }
        printf("\n");
}

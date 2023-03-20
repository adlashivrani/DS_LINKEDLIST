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

struct node* create();
void display(struct node *);
void deletealt(struct node *);

int main()
{
    	struct node *head = NULL;
	    head = create();
		deletealt(head);
        display(head);
        return 0;
}

struct node* create()
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
	return head;
}

void deletealt(struct node *head)
{
        struct node *current;
        struct node *nextnode;
        if ( head == NULL) {
                return;
        }
        struct node *previous = head->next;
        current = previous->next;
        while (previous != head && current != head) {
             previous->next = current->next;
             nextnode = current->next;
             free(current);
             if (nextnode != head) {
                    nextnode->prev = previous;
                    current = nextnode->next;
                } else {
                    current = head;
             }
             previous = nextnode;
        }
}

void display(struct node *head)
{
        temp = head->next;
        while ( temp->next != head) {
                printf("%d\t", temp->id);
                printf("%-20s", temp->name);
                printf("%-20s", temp->gender);
                printf("%-20s", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
        printf("\n");
}

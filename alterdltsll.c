#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
        int id;
        char name[32];
        char gender[8];
        char occupation[16];
        int age;
        struct node* next;
};

struct node* create();
void display(struct node*);
void deletealt(struct node *);

int main ()
{
    struct node * head = NULL;
    head = create();
	deletealt(head);
    display(head);
}

struct node* create()
{
        struct node * head = NULL;
        struct node* new;
        struct node* temp;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
        while (ch != EOF) {
                new = (struct node* ) malloc (sizeof(struct node));
                ch = fscanf(fp, "%d%s%s%s%d", &new -> id, new -> name, new -> gender, new -> occupation, &new -> age);
                new -> next = NULL;
                if (head == NULL) {
                        head = new;
                        temp = new;
                } else {
                        temp -> next = new;
                        temp = temp -> next;
                }
        }
        return head;
}

void deletealt(struct node *head)
{
	struct node *temp;
	if ( head == NULL) {
		return;
	}
	struct node *prev = head;
	temp = head->next;
	while (prev != NULL && temp != NULL) {
		prev->next = temp->next;
		free(temp);
		prev = prev->next;
		if (prev != NULL) {
			temp = prev->next;
		}
	}	
}

void display(struct node *head)
{
	struct node* temp = head;
    while (temp -> next != NULL) {
          printf("%d\t", temp -> id);
          printf("%-20s\t", temp -> name);
          printf("%-20s\t", temp -> gender);
          printf("%-20s\t", temp -> occupation);
          printf("%d\n", temp -> age);
          temp = temp -> next;
        }
}

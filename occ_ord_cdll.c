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
void sort(struct node *);

int main()
{
	head = NULL;
    head = create();
	sort(head);
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
                        if (strcmp(i->occupation, j->occupation) > 0) {
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

void display(struct node *head)
{
        temp = head->next;
        while ( temp != head) {
                printf("%d\t", temp->id);
                printf("%-20s", temp->name);
                printf("%-20s", temp->gender);
                printf("%-20s", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
        printf("\n");
}

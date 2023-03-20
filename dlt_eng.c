#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;
    char name[50];
    char gender[10];
    char occupation[20];
    int age;
    struct node* next;
};
struct node *head;
struct node *temp;

struct node* create();
void delete();
void display(struct node *);

int main ()
{
    head = NULL;
    head = create();
	delete();
	display(head);
}

struct node* create()
{
    struct node* new;
    struct node* temp;
    FILE *fp;
    fp = fopen("club_membership_2020.txt", "r");
    int ch;
    while(ch != EOF) {
        new = (struct node* ) malloc (sizeof(struct node));
        ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
        if (head == NULL) {
            head = new;
            temp = new;
        } else {
            temp->next = new;
            temp = temp->next;
        }
                new->next = head;
    }
	return head;
}
void delete()
{
	temp = head;
	while (temp->next != head) {
			if ( temp == head) {
				if (temp->occupation[0] == 'E') {
					head = temp->next;
				} 
			}
			if(temp->next->occupation[0] == 'E') {
				temp->next = temp->next->next;
				if (temp->next == head) {
					return;	
				}
			}
		temp = temp->next;
	}
}
void display(struct node *head)
{
    struct node* temp;
	temp = head;
    while(temp->next != head) {
        printf("%d\t", temp->id);
        printf("%-20s", temp->name);
        printf("%-20s", temp->gender);
        printf("%-20s", temp->occupation);
        printf("%d\n", temp->age);
        temp = temp->next;
    }
    printf("\n");
}

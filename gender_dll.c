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
struct node *mhead;
struct node *fhead;
struct node *temp;
void create();
struct node* reverselist(struct node *);
void display(struct node *);

int main()
{
	mhead = NULL;
	fhead = NULL;
    create();
	mhead = reverselist(mhead);
	printf("\nMale list:\n");
    display(mhead);
	fhead = reverselist(fhead);
	printf("\nFemale list:\n");
	display(fhead);
    return 0;
}

void create()
{
        mhead = NULL;
		fhead = NULL;
		struct node *mtemp;
		struct node *ftemp;
        struct node *new;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
        while(ch != EOF) {
        		new = (struct node* ) malloc (sizeof(struct node));
        		ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
                new->prev = NULL;
                new->next = NULL;
			if (new->gender[0] == 'M') {
        		if (mhead == NULL) {
            		mhead = new;
            		mtemp = new;
        		} else {
            		mtemp->next = new;
            		new->prev = mtemp;
            		mtemp = mtemp->next;
				}
			} else {
				if ( fhead == NULL) {
					fhead = new;
					ftemp = new;
				} else {
					ftemp->next = new;
					new->prev = ftemp;
					ftemp = ftemp->next;
				}
        	}
    }
}

struct node* reverselist(struct node *head) 
{
	temp = head;
	struct node *nextnode = NULL;
	while ( temp->next != NULL) {
		nextnode = temp->prev;
		temp->prev = temp->next;
		temp->next = nextnode;
		temp = temp->prev;
	}
	if ( temp != NULL) {
		head = temp->prev;
	}
	return head;
}
void display(struct node *head)
{
        temp = head;
        while ( temp->next != NULL) {
                printf("%d\t", temp->id);
                printf("%-20s", temp->name);
                printf("%-20s", temp->gender);
                printf("%-20s", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
        printf("\n");
}

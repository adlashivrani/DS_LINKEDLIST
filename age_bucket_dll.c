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
struct node *ahead;
struct node *bhead;
struct node *chead;
struct node *dhead;
struct node *temp;

void create();
void sort(struct node*);
struct node* reverselist(struct node *);
void display(struct node *);

int main()
{
    ahead = NULL;
    bhead = NULL;
	chead = NULL;
	dhead = NULL;
    create();
	sort(ahead);
	sort(bhead);
	sort(chead);
	sort(dhead);
	printf("\nBefore reversing list:\n");
	display(ahead);
	display(bhead);
	display(chead);
	display(dhead);
	printf("\nAfter reversing list:\n");
    ahead = reverselist(ahead);
	bhead = reverselist(bhead);
	chead = reverselist(chead);
	dhead = reverselist(dhead);
    display(dhead);
	display(chead);
	display(bhead);
	display(ahead);
    return 0;
}

void create()
{
    ahead = NULL;
    bhead = NULL;
	chead = NULL;
	dhead = NULL;

    struct node *atemp;
    struct node *btemp;
	struct node *ctemp;
	struct node *dtemp;
    struct node *new;
	
    FILE *fp = NULL;
    fp = fopen("club_membership_2020.txt", "r");
    int ch;
    while(ch != EOF) {
    	new = (struct node* ) malloc (sizeof(struct node));
        ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender, new->occupation, &new->age);
        new->prev = NULL;
        new->next = NULL;
        if ((new->age >= 21) && (new->age <= 30)) {
        	if (ahead == NULL) {
            	ahead = new;
                atemp = new;
             } else {
             	atemp->next = new;
                new->prev = atemp;
                atemp = atemp->next;
             }
        } else if ( (new->age >= 31) && (new->age <= 40)) {
            if ( bhead == NULL) {
                bhead = new;
                btemp = new;
           	 } else {
                btemp->next = new;
              	new->prev = btemp;
                btemp = btemp->next;
             }
        } else if ( (new->age >= 41) && (new->age <= 50)) {
            if ( chead == NULL) {
                chead = new;
                ctemp = new;
                 } else {
                ctemp->next = new;
                new->prev = ctemp;
                ctemp = ctemp->next;
             }
        } else if ( (new->age >= 51) && (new->age <= 60)) {
            if ( dhead == NULL) {
                dhead = new;
                dtemp = new;
                 } else {
                dtemp->next = new;
                new->prev = dtemp;
                dtemp = dtemp->next;
             }
        }
    }
}
struct node* reverselist(struct node *head)
{
    temp = head;
	if (temp->next == NULL) {
		return head;
	}
    struct node *nextnode = NULL;
    while ( temp->next != NULL) {
    	nextnode = temp->prev;
        temp->prev = temp->next;
        temp->next = nextnode;
        temp = temp->prev;
    }
	if (temp != NULL) {
		head = temp->prev;
	}
	return head;
}
		
void display(struct node *head)
{
        temp = head;
        while ( temp != NULL) {
                printf("%d\t", temp->id);
                printf("%-20s", temp->name);
                printf("%-20s", temp->gender);
                printf("%-20s", temp->occupation);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
        printf("\n");
}
void sort(struct node* head)
{
        struct node *i;
        struct node *j;
        struct node* temp;
        for ( i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                        if (i->age >  j->age) {
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

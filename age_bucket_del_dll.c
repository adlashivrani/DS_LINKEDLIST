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
void display(struct node *);

int main()
{
    ahead = NULL;
    bhead = NULL;
    chead = NULL;
    dhead = NULL;
    create();
    printf("\nBefore deleting list:\n");
    display(ahead);
    display(bhead);
    display(chead);
    display(dhead);
	chead = NULL;
    printf("\nAfter deleting 41-50 list:\n");
    display(ahead);
    display(bhead);
    display(chead);
    display(dhead);
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

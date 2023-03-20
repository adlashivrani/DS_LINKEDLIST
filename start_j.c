#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
        int id;
        char name[32];
        char gender[8];
        char occp[10];
        int age;
        struct node* next;
};

void freelist(struct node*);
struct node* sort(struct node*);
struct node* create();
void display(struct node*);

int main()
{
        struct node* head = NULL;
        head = create();
                printf("\nBefore Sorting\n");
        display(head);
        struct node* n1 = NULL;
        n1 = sort(head);
        printf("\n");
                printf("\nAfter sorting\n");
        display(head);
        freelist(head);
        return 0;
}

struct node* create()
{
        struct node* head1 = NULL;
        struct node* new;
        struct node* temp;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
        while(ch != EOF){
                new = (struct node*)malloc(sizeof(struct node));
                ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender,new->occp, &new->age);
                new->next = NULL;
                if ( head1 == NULL){
                        head1 = new;
                        temp = new;
                } else {
                        temp->next = new;
                        temp = temp->next;
                }
        }
        fclose(fp);
        return head1;
}

void display(struct node* head)
{
        struct node* temp = head;
        while (temp->next != NULL) {
			if ( temp->name[0] == 'J') {
                printf("%d\t", temp->id);
                printf("%-20s\t", temp->name);
                printf("%-20s\t", temp->gender);
                printf("%-20s\t", temp->occp);
                printf("%d\n", temp->age);
			}
                temp = temp->next;
        }
}

void freelist(struct node* head)
{
        struct node* temp;
        while (head != NULL) {
                temp = head;
                head = head->next;
                free(temp);
                temp = NULL;
        }
}

struct node* sort(struct node* head)
{
        struct node *i;
        struct node *j;
        struct node* temp;
        for ( i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                        if (strcmp(i->name, j->name) > 0) {
                                temp->id = i->id;
                                strcpy(temp->name, i->name);
                                strcpy(temp->gender, i->gender);
                                strcpy(temp->occp, i->occp);
                                temp->age = i->age;

                                i->id = j->id;
                                strcpy(i->name, j->name);
                                strcpy(i->gender, j->gender);
                                strcpy(i->occp, j->occp);
                                i->age = j->age;

                                j->id = temp->id;
                                strcpy(j->name, temp->name);
                                strcpy(j->gender, temp->gender);
                                strcpy(j->occp, temp->occp);
                                j->age = temp->age;
                    }
                }
        }
        return head;
}

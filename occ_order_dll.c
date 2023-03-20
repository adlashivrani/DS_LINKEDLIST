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
void onlyone(struct node *);
struct node* sort(struct node*);
void display(struct node*);

int main()
{
	struct node * head = NULL;
    head = create();
	head = sort(head);
	onlyone(head);
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
        } else {
            temp->next = new;
            new->prev = temp;
            temp = temp->next;
        }
    }
	return head;
}
struct node* sort(struct node* head)
{
        struct node *i;
        struct node *j;
        struct node* temp;
        for ( i = head; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
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
        return head;
}
void onlyone(struct node* head)
{
	temp = head;
	int c = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0;
	int c6 = 0;
	for ( temp = head; temp->next != NULL; temp = temp->next) {
		if ((temp->occupation[0] == 'A') && (temp->occupation[1] == 'c')) { 
				if ( c == 0 ) {
				   /*	printf("%d\t", temp->id);
    				printf("%-20s", temp->name);
    				printf("%-20s", temp->gender);
    				printf("%-20s", temp->occupation);
    				printf("%d\n", temp->age);
    				printf("\n");*/
			 		display(temp);
					c = 1;
					}
		} else if ((temp->occupation[0] == 'A') && (temp->occupation[1] == 'u')) {
				if ( c1 == 0) {
					/*printf("%d\t", temp->id);
  					printf("%-20s", temp->name);
   					printf("%-20s", temp->gender);
   					printf("%-20s", temp->occupation);
   					printf("%d\n", temp->age);
   					printf("\n");*/
					display(temp);
					c1 = 1;
					}
		} else if ((temp->occupation[0] == 'D') && (temp->occupation[1] == 'o')) {
				if (c2 == 0) {
					/*printf("%d\t", temp->id);
    				printf("%-20s", temp->name);
    				printf("%-20s", temp->gender);
    				printf("%-20s", temp->occupation);
    				printf("%d\n", temp->age);
    				printf("\n");*/
					display(temp);
					c2 = 1;
					} 
		} else if (temp->occupation[0] == 'E' ) {
				if ( c3 == 0) {
				    /*printf("%d\t", temp->id);
    				printf("%-20s", temp->name);
    				printf("%-20s", temp->gender);
    				printf("%-20s", temp->occupation);
    				printf("%d\n", temp->age);
    				printf("\n");*/
					display(temp);
					c3 = 1;
					}
		}  else if ((temp->occupation[0] == 'D') && (temp->occupation[1] == 'r')) {
                 if ( c4 == 0) {
                    /*printf("%d\t", temp->id);
                    printf("%-20s", temp->name);
                    printf("%-20s", temp->gender);
                    printf("%-20s", temp->occupation);
                    printf("%d\n", temp->age);
                    printf("\n");*/
                    display(temp);
                    c4 = 1;
                    }
		}  else if (temp->occupation[0] == 'M') {
                 if ( c5 == 0) {
                    /*printf("%d\t", temp->id);
                    printf("%-20s", temp->name);
                    printf("%-20s", temp->gender);
                    printf("%-20s", temp->occupation);
                    printf("%d\n", temp->age);
                    printf("\n");*/
                    display(temp);
                    c5 = 1;
                    } 
		}  else if (temp->occupation[0] == 'P') {
                 if ( c6 == 0) {
                    /*printf("%d\t", temp->id);
                    printf("%-20s", temp->name);
                    printf("%-20s", temp->gender);
                    printf("%-20s", temp->occupation);
                    printf("%d\n", temp->age);
                    printf("\n");*/
                    display(temp);
                    c6 = 1;
                    }
		} 
	}
}

void display(struct node *temp)
{
    printf("%d\t", temp->id);
    printf("%-20s", temp->name);
    printf("%-20s", temp->gender);
    printf("%-20s", temp->occupation);
    printf("%d\n", temp->age);
    printf("\n");
}

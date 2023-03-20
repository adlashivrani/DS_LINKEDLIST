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

void create();
void display();

int main()
{
        create();
        display();
        return 0;
}

void create()
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
}

void display()
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

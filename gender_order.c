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
struct node* Hmale;
struct node* Hfemale;
void create();
void display(struct node*);

int main()
{
        create();
		printf("\nMale list\n");
        display(Hmale);
        printf("\n");
		printf("\nFemale list\n");
        display(Hfemale);
        return 0;
}
void create()
{
        Hmale = NULL;
        Hfemale = NULL;
        struct node* new;
        struct node* Mtemp;
        struct node* Ftemp;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
        while(ch != EOF){
                new = (struct node*)malloc(sizeof(struct node));
                ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender,new->occp, &new->age);
                new->next = NULL;
                if(new->gender[0] == 'M'){
                        if(Hmale == NULL){
                                Hmale = new;
                                Mtemp = new;
                        } else{
                                Mtemp->next = new;
                                Mtemp = Mtemp->next;
                        }
                }else {
                        if(Hfemale == NULL){
                                Hfemale = new;
                                Ftemp = new;
                        }else {
                                Ftemp->next = new;
                                Ftemp = Ftemp->next;
                        }
                }
        }
        fclose(fp);
}
void display(struct node* head)
{
        struct node* temp = head;
        while(temp->next != NULL){
                printf("%d\t", temp->id);
                printf("%-20s\t", temp->name);
                printf("%-20s\t", temp->gender);
                printf("%-20s\t", temp->occp);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
}

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
struct node* ha_age;
struct node* hb_age;
struct node* hc_age;
struct node* hd_age;
void create();
void display(struct node*);

int main()
{
        create();
        printf("\nAge:21-30\n");
        display(ha_age);
        printf("\n");
        printf("\nAge:31-40\n");
        display(hb_age);
		printf("\n");
		printf("\nAge:41-50\n");
		display(hc_age);
		printf("\n");
		printf("\nAge:51-60\n");
		display(hd_age);
        return 0;
}
void create()
{
        ha_age = NULL;
        hb_age = NULL;
		hc_age = NULL;
		hd_age = NULL;
        struct node* new;
        struct node* atemp;
        struct node* btemp;
		struct node* ctemp;
		struct node* dtemp;
        FILE *fp = NULL;
        fp = fopen("club_membership_2020.txt", "r");
        int ch;
        while(ch != EOF){
                new = (struct node*)malloc(sizeof(struct node));
                ch = fscanf(fp, "%d%s%s%s%d", &new->id, new->name, new->gender,new->occp, &new->age);
                new->next = NULL;
                if((new->age >= 20) && (new->age <= 30)){
                        if(ha_age == NULL){
                                ha_age = new;
                                atemp = new;
                        } else{
                                atemp->next = new;
                                atemp = atemp->next;
                        }
                }else if((new->age >= 31) && (new->age <= 40)) {
                        if(hb_age == NULL){
                                hb_age = new;
                                btemp = new;
                        }else {
                                btemp->next = new;
                                btemp = btemp->next;
                        }
                } else if ((new->age >= 41) && (new->age <= 50)) {
						if ( hc_age == NULL) {
								hc_age = new;
								ctemp = new;
						} else {
								ctemp ->next = new;
								ctemp = ctemp->next;
						}
				} else if ((new->age >= 51) && (new->age <= 60)) {
						if (hd_age == NULL) {
							hd_age = new;
							dtemp = new;
						} else {
							dtemp->next = new;
							dtemp = dtemp->next;
						}
				}
        }
        fclose(fp);
}
void display(struct node* head)
{
        struct node* temp = head;
        while(temp!= NULL){
                printf("%d\t", temp->id);
                printf("%-20s\t", temp->name);
                printf("%-20s\t", temp->gender);
                printf("%-20s\t", temp->occp);
                printf("%d\n", temp->age);
                temp = temp->next;
        }
}

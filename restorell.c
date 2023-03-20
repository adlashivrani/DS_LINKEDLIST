#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *string;
    struct node *next;
};
struct node *current;
struct node *head;

int main() {
    FILE *fp;
    char line[200];
    head = NULL;
	current = NULL;
    if ((fp = fopen("club_membership_2020.txt", "r")) == NULL) {
			printf("ERROR\n");
	}
    while (fgets(line, sizeof(line), fp)) {
        struct node *newnode = (struct node *) malloc ( sizeof(struct node));
        newnode->string = strdup(line);
        newnode->next = NULL;
        if (head == NULL) {
            current = head = newnode;
        } else {
            current = current->next = newnode;
        }
    }
    fclose(fp);
    for (current = head; current ; current = current->next) {
        printf("%s", current->string);
    }
    return 0;
}

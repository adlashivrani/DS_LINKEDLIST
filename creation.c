#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice;    
    while (choice)
    {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
   	printf("if you want to enter elements enter any number otherwise enter '0': \n");
    scanf("%d", &choice);
    }
    temp = head;
    while (temp	!= NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
  	}
}

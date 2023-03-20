#include<stdio.h>  
#include<stdlib.h>  

struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head; 
struct node *ptr;
struct node *temp;

void insert_begin();  
void insert_last();
void insert_pos();  
void delete_begin();  
void delete_last();
void delete_pos();  
void display();  
void search(); 
 
void main ()  
{  
	int choice = 1;  
    while (choice)  
    {  
        printf("\nSELECT OPTION\n");      
        printf("\n1.Insert Begin\n2.Insert last\n3.Insert pos\n4.Delete Begin\n5.Delete last\n6.Delete pos\n7.Search\n8.Show\n9.Exit\n");    
        scanf("%d", &choice);  
        switch (choice)  
        {  
            case 1:  
            	insert_begin();
            	break;  
            case 2:  
                insert_last();  
            	break;
			case 3:
				insert_pos();
				break;  
            case 4:  
            	delete_begin();  
            	break;  
            case 5:  
            	delete_last();  
            	break;  
			case 6:
				delete_pos();
				break;
            case 7:  
            	search();  
            	break;  
            case 8:  
            	display();  
            	break;  
            case 9:  
            	exit(1);  
            	break;  
            default:  
            	printf("enter valid option\n");  
        }  
    }  
}  
void insert_begin()  
{  
   	int item;  
   	ptr = (struct node *) malloc (sizeof(struct node));  
   	if (ptr == NULL)  
   	{  
       printf("\nOVERFLOW");  
   	} else {  
    	printf("\nEnter Item value");  
    	scanf("%d", &item);  
    	ptr->data = item;  
   		if (head == NULL)  
   		{  
      		head = ptr;  
      		ptr -> next = head;   
      		ptr -> prev = head;   
   		} else {  
       		temp = head;   
    		while (temp -> next != head) {  
        		temp = temp -> next;   
    		}  
    		temp -> next = ptr;  
    		ptr -> prev = temp;  
    		head -> prev = ptr;  
    		ptr -> next = head;  
    		head = ptr;  
   		} printf("\nNode inserted\n");  
	}      
}  

void insert_last()  
{  
   	int item;  
   	ptr = (struct node *) malloc(sizeof(struct node));  
   	if (ptr == NULL)  
    {  
       printf("\nOVERFLOW");  
    } else {  
       printf("\nEnter value");  
       scanf("%d", &item);  
       ptr->data = item;  
       if (head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       } else {  
          temp = head;  
          while (temp->next != head) {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev = temp;  
          head -> prev = ptr;  
      	  ptr -> next = head;  
        }  
   }  
   printf("\nnode inserted\n");  
}  
  
void insert_pos()
{
    if (head == NULL) {
            printf("ERROR\n");
        } else {
				int pos;
				printf("Enter position:\n");
				scanf("%d", &pos);
                temp = head;
                ptr = (struct node*) malloc (sizeof(struct node));
                printf("Enter data:\n");
                scanf("%d", &ptr->data);
                ptr->next = NULL;
                int i = 1;
                while (i < pos) {
                        temp = temp->next;
                        i++;
                }
                ptr->next = temp->next;
                ptr->prev = temp;
                temp->next = ptr;
                temp->next->prev = ptr;
        }
}
void delete_begin()  
{  
    if (head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    } else if(head->next == head) {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    } else {  
        temp = head;   
        while (temp -> next != head) {  
            temp = temp -> next;  
        }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;  
    }  
}  

void delete_last()  
{    
    if (head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    } else if (head->next == head) {  
        head = NULL;   
        free(head);  
    } else {  
        ptr = head;   
        if (ptr->next != head)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = head;  
        head -> prev = ptr -> prev;    
        free(ptr);   
    }  
}  

void delete_pos()
{
	if ( head == NULL) {
		printf("ERROR\n");
        } else {
                temp = head;
                int i = 1;
				int pos;
				printf("Enter position\n");
				scanf("%d", &pos);
                while ( i != pos - 1) {
                        temp = temp->next;
                        i++;
                }
        struct node *nxtptr = temp->next;
        temp->next = nxtptr->next;
        nxtptr->next->prev = temp;
        free(nxtptr);
        }	
}
  
void display()  
{  
    ptr = head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {     
        while(ptr -> next != head) {  
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    } 
}  
  
void search()  
{  
    int item;
	int i = 0;
	int flag = 1;  
    ptr = head;   
    if (ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    } else {   
        printf("\nEnter item to search\n");   
        scanf("%d", &item);  
        if (head ->data == item)  
        {  
        	printf("item found at location %d", i+1);  
        	flag = 0;  
        } else {  
        	while (ptr->next != head) {  
            if (ptr ->data == item)  
            {  
                printf("item found at location %d ", i + 1);  
                flag = 0;  
                break;  
            } else {  
                flag = 1;  
            }  
            i++;  
            ptr = ptr -> next;  
        	}  
        }  
        if (flag != 0)  
        {  
            printf("Item not found\n");  
        }  
    }           
}  

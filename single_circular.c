#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
struct node *ptr;
struct node *temp;
  
void begin_insert ();   
void last_insert ();  
void insert_pos();  
void begin_delete();  
void last_delete();  
void pos_delete();  
void display();  
void search();  

void main ()  
{  
    int choice = 1;  
    while(choice)   
    {  
        printf("\nSELECT OPTION:\n"); 
        printf("\n1.Insert begin\n2.Insertlast\n3.Delete Begin\n4.Insert pos\n5.Delete from last\n6.Delect pos\n7.Search element\n8.Show\n9.Exit\n");        
        scanf("\n%d", &choice);  
        switch (choice)  
        {  
            case 1:  
            	begin_insert();      
            	break;  
            case 2:  
            	last_insert();         
            	break;  
            case 3:  
            	begin_delete();       
            	break;  
			case 4:
				insert_pos();
				break;
            case 5:  
            	last_delete();        
            	break;
			case 6:
				pos_delete();
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

void begin_insert()  
{    
    int item;   
    ptr = (struct node *) malloc (sizeof(struct node));  
    if (ptr == NULL)  
    {  
        printf("\nERROR\n");  
    } else {  
        printf("\nEnter data\n");  
        scanf("%d", &item);  
        ptr -> data = item;  
        if (head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        } else {     
            temp = head;  
            while (temp->next != head) {
                temp = temp->next;  
			}
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nnode inserted\n");  
    }   
}  

void last_insert()  
{  
    int item;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if (ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    } else {  
        printf("\nEnter Data?");  
        scanf("%d", &item);  
        ptr->data = item;  
        if (head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        } else {  
            temp = head;  
            while (temp -> next != head) {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }    
        printf("\nnode inserted\n");  
    }  
}  

void insert_pos()
{
    int i;
	int pos;
	printf("Enter position\n");
	scanf("%d", &pos);
    if(head == NULL)
    {
        printf("List is empty");
    } else {
        ptr = (struct node *) malloc (sizeof(struct node));
       	printf("Enter data:\n");
		scanf("%d", &ptr->data);
		temp = head;
        for ( i = 1; i <= pos; i++ ) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}   

void begin_delete()  
{     
    if (head == NULL)  
    {  
        printf("\nERROR\n");    
    } else if (head->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
    } else {   ptr = head;   
        while (ptr -> next != head) {
            ptr = ptr -> next;   
		}
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nnode deleted\n");  
    }  
}  

void last_delete()  
{  
    struct node *preptr;  
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head ->next == head) {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
  
    } else {  
        ptr = head;  
        while (ptr ->next != head) {  
            preptr = ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
  
void pos_delete()
{  
    if (head == NULL)  {
        printf("\n List is empty");  
    } else {  
        int i = 1;
		int  pos;  
        printf("\n Enter the position to be deleted:");  
        scanf("%d", &pos);  
        temp = head;  
        while (i < pos)  
        {  
            ptr = temp;  
            temp = temp->next;  
            i++;  
        }  
        ptr->next = temp->next;  
        free(temp);  
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
        printf("\nEnter item which you want to search?\n");   
        scanf("%d", &item);  
        if (head ->data == item)  
        {  
        printf("item found at location %d", i + 1);  
        flag = 0;  
        } else {  
        while (ptr->next != head) {  
            if (ptr->data == item)  
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
  
void display()  
{  
    ptr = head;  
    if (head == NULL)  
    {  
        printf("\nnothing to print\n");  
    } else {  
        printf("\n LINKED LIST: \n");  
        while (ptr -> next != head)  
        {  
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }     
}  

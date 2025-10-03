#include <stdio.h>
#include <stdlib.h> 
typedef struct node
	{
    	int info;
    	struct node *link; 
	}Node;
Node *head=NULL,*tail=NULL;
Node* newnode() 
	{
    	Node* p=(Node*)malloc(sizeof(Node));
    	if (p==NULL)
		{
        	printf("Memory Allocation Failed.\n");
        	exit(1);
    		}
    	return p;
	}
void insert_begin(int a)
	{
        Node *p=newnode();
        p->info=a;
	if(head==NULL)
		{
		head=tail=p;
		p->link=NULL;
		}
	else	
		{
		p->link=head;
		head=p;
		}
	}
void insert_end(int a) 
	{
        Node *p=newnode();
        p->info=a;
	p->link=NULL;
	if(head==NULL)
		{
		head=tail=p;
		}
	else	
		{
		tail->link=p;
		tail=p;
		}
	}
int is_empty()
	{
	if(head==NULL)
		return 1;
	else
		return 0;
	}
int insert_bef(int val1, int val2)
	{
	Node *p,*q,*r;
	p=newnode();
	q=head;
	r=NULL;
	p->info=val1;
	while(q!=NULL && q->info!=val2)
		{
		r=q;
		q=q->link;
		}
	if(q==NULL)
		{
		printf("%d is not found in the list",val2);
		free(p);
		return 0;
		}
	else if(q==head)
		{
		p->link=q;
		head=p;
		}
	else
		{
		p->link=q;
		r->link=p;
		}
	}
int insert_aft(int val1, int val2)
	{
	Node *p,*q;
	p=newnode();
	q=head;
	p->info=val1;
	while(q!=NULL && q->info!=val2)
		{
		q=q->link;
		}
	if(q==NULL)
		{
		printf("LIST IS EMPTY");
		free(p);
		return 0;
		}
	else if(q==tail)
		{
		p->link=NULL;
		tail=p;
		q->link=p;
		}
	else
		{
		p->link=q->link;
		q->link=p;
		}
	}	 
int dlt_first()
	{
	Node *p;
	if(is_empty()==1)
		{
		printf("LIST IS EMPTY");
		return 0;
		}
	p=head;
	head=head->link;
	free(p);
	}
int dlt_node(int val)
	{
	Node *p;
	if(is_empty()==1)
		{
		printf("LIST IS EMPTY");
		return 0;
		}
	p=head;
	Node *q=NULL;
	while(p!=NULL && p->info!=val)
		{
		q=p;
		p=p->link;
		}	
	if(p==NULL)
		{
		printf("Element is not found in the list");
		return 0;
		}
	if(p==head)
		{
		head=p->link;
		}
	else if(p==tail)
		{
		tail=q;
		tail->link=NULL;
		}
	else
		{
		q->link=p->link;
		}
	free(p);
	}
void disply()
	{
	Node *p;
	if(is_empty()==1)
		{
		printf("LIST IS EMPTY");
		return;
		}
	p=head;
	while(p!=NULL)
		{
		printf("%d ->",p->info);
		p=p->link;
		}
	}
int main()
	{
    	int choice, val, val1, val2;
    	do
		{
		printf("\n--- Menu ---\n");
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert before a value\n");
		printf("4. Insert after a value\n");
		printf("5. Delete first node\n");
		printf("6. Delete a node by value\n");
		printf("7. Display list\n");
		printf("8. Exit\n");
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		switch(choice)
			{
		    	case 1:
		        printf("Enter Value to insert at beginning: ");
		        scanf("%d", &val);
		        insert_begin(val);
		        break;
		    	case 2:
		        printf("Enter Value to insert at end: ");
		        scanf("%d", &val);
		        insert_end(val);
		        break;
		    	case 3:
		        printf("Enter Value to insert: ");
		        scanf("%d", &val1);
		        printf("Enter Value before which to insert: ");
		        scanf("%d", &val2);
		        insert_bef(val1, val2);
		        break;
		    	case 4:
		        printf("Enter Value to insert: ");
		        scanf("%d", &val1);
		        printf("Enter Value after which to insert: ");
		        scanf("%d", &val2);
		        insert_aft(val1, val2);
		        break;
		    	case 5:
		        if (dlt_first())
		            printf("First Node Deleted.\n");
		        break;
		    	case 6:
		        printf("Enter Value of Node to delete: ");
		        scanf("%d", &val);
		        if (dlt_node(val))
		            printf("Node with Value %d deleted.\n", val);
		        break;
		    	case 7:
		        printf("Current List:\n");
		        disply();
		        break;
		    	case 8:
		        printf("Exiting Program.\n");
		        break;
		    	default:
		        printf("Invalid Choice! Try again.\n");
        		}
    		}
	while (choice != 8);
	return 0;
	}

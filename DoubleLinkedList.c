#include <stdio.h>
#include <stdlib.h>
typedef struct node
	{
    	int info;
    	struct node *prev;
    	struct node *next;
	}Node;
Node *head=NULL,*tail=NULL;
Node* newnode(int val)
	{
    	Node *p = (Node*)malloc(sizeof(Node));
    	if (p == NULL)
		{
        	printf("Memory Allocation failed.\n");
        	exit(1);
    		}
    	p->info = val;
    	p->prev = p->next = NULL;
    	return p;
	}
void insert_begin(int val)
	{
    	Node *p = newnode(val);
    	if (head == NULL) 
		{
        	head = tail = p;
    		} 
	else
		{
        	p->next = head;
        	head->prev = p;
        	head = p;
    		}
	}
void insert_end(int val) 
	{
    	Node *p = newnode(val);
    	if (head == NULL)
		{
        	head = tail = p;
    		} 
	else 
		{
        	tail->next = p;
        	p->prev = tail;
        	tail = p;
    		}
	}	
void insert_before(int val1, int val2) 
	{
    	if (head == NULL) 
		{
        	printf("List is Empty.\n");
        	return;
    		}
    	Node *q = head;
    	while (q != NULL && q->info != val2) 
		{
        	q = q->next;
    		}
    	if (q == NULL) 
		{
        	printf("Value %d not found in the list.\n", val2);
        	return;
    		}
    	Node *p = newnode(val1);
	if (q == head) 
		{
        	p->next = head;
        	head->prev = p;
        	head = p;
    		}
	else 	
		{
        	p->prev = q->prev;
        	p->next = q;
        	q->prev->next = p;
        	q->prev = p;
    		}
	}
void insert_after(int val1, int val2) 
	{
    	if (head == NULL) 
		{
        	printf("List is Empty.\n");
        	return;
    	}
    	Node *q = head;
    	while (q != NULL && q->info != val2) 
		{
        	q = q->next;
    		}
    	if (q == NULL) 
		{
        	printf("Value %d not found in the list.\n", val2);
        	return;
    		}
    	Node *p = newnode(val1);
	p->prev = q;
    	p->next = q->next;
	if (q == tail) 	
		{
        	tail = p;
    		} 
	else 
		{
        	q->next->prev = p;
    		}
    	q->next = p;
	}

int delete_first() 
	{
    	if (head == NULL)
		{
        	printf("List is Empty.\n");
        	return 0;
    		}
    	Node *p = head;
    	if (head == tail) 
		{ // Only one node
        	head = tail = NULL;
    		} 
	else 
		{
        	head = head->next;
        	head->prev = NULL;
    		}
    	free(p);
    	return 1;
	}
int delete_last() 
	{
    	if (tail == NULL)
		{
        	printf("List is Empty.\n");
        	return 0;
    		}
    	Node *p = tail;
    	if (head == tail) 
		{
        	head = tail = NULL;
    		} 
	else
		{
        	tail = tail->prev;
        	tail->next = NULL;
    		}
    	free(p);
    	return 1;
	}
int delete_node(int val) 
	{
    	if (head == NULL) 
		{
        	printf("List is Empty.\n");
        	return 0;
    		}
    	Node *q = head;
    	while (q != NULL && q->info != val) 
		{
        	q = q->next;
    		}
    	if (q == NULL) 
		{
        	printf("Value %d not found in the list.\n", val);
        	return 0;
    		}
    	if (q == head) 
		{
        	return delete_first();
    		} 
	else if (q == tail) 
		{
        	return delete_last();
    		}
	else
		{
        	q->prev->next = q->next;
        	q->next->prev = q->prev;
        	free(q);
        	return 1;
    		}
	}
void display_forward() 
	{
    	if (head == NULL) 
		{
        	printf("List is Empty.\n");
        	return;
    		}
    	Node *p = head;
    	printf("Forward: ");
    	while (p != NULL) 
		{
        	printf("%d <-> ", p->info);
        	p = p->next;
    		}
    	printf("NULL\n");
	}
void display_backward() 
	{
    	if (tail == NULL) 
		{
        	printf("List is Empty.\n");
        	return;
    		}
    	Node *p = tail;
    	printf("Backward: ");
    	while (p != NULL) 
		{
        	printf("%d <-> ", p->info);
        	p = p->prev;
    		}
    	printf("NULL\n");
	}
int main() 
	{
    	int choice, val, val1, val2;
    	do 
		{
        	printf("\n--- Doubly Linked List Menu ---\n");
        	printf("1. Insert at beginning\n");
        	printf("2. Insert at end\n");
        	printf("3. Insert before a value\n");
        	printf("4. Insert after a value\n");
        	printf("5. Delete first node\n");
        	printf("6. Delete last node\n");
        	printf("7. Delete a node by value\n");
        	printf("8. Display forward\n");
        	printf("9. Display backward\n");
        	printf("10. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch (choice) 
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
		        insert_before(val1, val2);
		        break;
		    	case 4:
		        printf("Enter Value to insert: ");
		        scanf("%d", &val1);
		        printf("Enter Value after which to insert: ");
		        scanf("%d", &val2);
		        insert_after(val1, val2);
		        break;
		    	case 5:
		        if (delete_first()) printf("Deleted first node.\n");
		        break;
		    	case 6:
		        if (delete_last()) printf("Deleted last node.\n");
		        break;
		    	case 7:
		        printf("Enter Value to delete: ");
		        scanf("%d", &val);
		        if (delete_node(val)) printf("Deleted node with value %d.\n", val);
		        break;
		   	case 8:
		        display_forward();
		        break;
		    	case 9:
		        display_backward();
		        break;
		    	case 10:
		        printf("Exiting program.\n");
		        break;
		    	default:
		        printf("Invalid Choice! Please try again.\n");
        		}
    		} 
	while (choice != 10);
	return 0;
	}

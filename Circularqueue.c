#include <stdio.h>
#include<stdio.h>
#define size 5
int queue[size],f=-1,r=-1;
int is_empty()
	{
    	if(f==-1)
        	return 1;
    	return 0;
	}
int is_full()
	{
   	if ((r+1)%size==f)
        	return 1;
    	return 0;
	}
void insert_queue(int item)
	{
    	if(f==-1)
        	r=f=0;
    	else
        	r=(r+1)%size;
    	queue[r]=item;
	}
int delete_queue()
	{
    	int item=queue[f];
    	if(f==r)
        	f=r=-1;
    	else
        	f=(f+1)%size;
    	return item;
	}
void peek()
	{
    	printf("Element is :%d\n",queue[f]);
	}

void main()
	{
    	int choice, n;
    	do
    		{
		printf("Menu:\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Peek\n");
		printf("4. Status\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
			{
		    	case 1:
		        	if(is_full())
		        		{
		            		printf("Queue is Full!");
		       			}
		        	else
		           		{
		                	printf("Enter the element to insert: ");
		                	scanf("%d",&n);
		                	insert_queue(n);
		            		}
		        	break;
		    	case 2:
		        	if(is_empty())
		        		{
		            		printf("Queue is Empty!");
		        		}
		        	else
		        		{
		            		n=delete_queue();
		            		printf("Deleted element: %d\n", n);
		        		}
		        	break;
		    	case 3:
		        	if(is_empty())
		            		printf("Queue is Empty!\n");
		        	else
		            		peek();
		        	break;
		    	case 4:
		       		if(is_empty())
		            		printf("Queue Empty!\n");
		        	else if(is_full())
		            		printf("Queue Full!\n");
		        	else
		            		printf("Space Available\n");
		        	break;
		    	case 5:
		        	printf("Exiting...\n");
		        	break;
		    	default:
		        	printf("Invalid choice!\n");
        		}
    		}
	while(choice !=5);
	}

#include<stdio.h>
#define size 5
int queue[size];
int f=-1,r=-1;
int is_empty()
	{
	if(f==-1)
		return 1;
	else
		return 0;
	}
int is_full()
	{
	if((r+1)%size==f)
		return 1;
	else 
		return 0;
	}
void insert_front(int e)
	{
	if(f==-1)
		r=f=0;
	else
		f=(f-1+size)%size;
	queue[f]=e;
	}
void insert_rear(int e)
	{
	if(f==-1)
		r=f=0;
	else
		r=(r+1)%size;
	queue[r]=e;
	}
int dlt_front()
	{
	int e=queue[f];
	if(f==r)
		f=r=-1;
	else
		f=(f+1)%size;
	return e;
	}
int dlt_rear()
	{
	int e=queue[r];
	if(f==r)
		f=r=-1;
	else
		r=(r-1+size)%size;
	return e;
	}
void peek_front()
	{
	printf("Element is %d",queue[r]);
	}
void main()
	{
    	int choice, n;
    	do
    		{
		printf("Menu:\n");
		printf("1. Insertfront\n");
		printf("2. Insertrear\n");
		printf("3. Deletefront\n");
		printf("4. Deleterear\n");
		printf("5. Peek\n");
		printf("6. Status\n");
		printf("7. Exit\n");
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		switch(choice)
			{
		    	case 1:if(is_full())
		        		{
		            		printf("Queue is Full!\n");
		        		}
		        	else
		            		{
		                	printf("Enter the Element to insert: ");
		                	scanf("%d", &n);
					insert_front(n);
		            		}
		        	break;
	 	    	case 2:if(is_full())
		        		{
		            		printf("Queue is Full!\n");
		        		}
		        	else
		            		{
		                	printf("Enter the Element to insert: ");
		                	scanf("%d", &n);
					insert_rear(n);
		            		}
		        	break;
		    	case 3:if(is_empty())
		        		{
		            		printf("Queue is Empty!\n");
		        		}
		        	else
		        		{
		            		n = dlt_front();
		            		printf("Deleted Element: %d\n", n);
		        		}
		        	break;
		    	case 4:if(is_empty())
		        		{
		            		printf("Queue is Empty!\n");
		        		}
		        	else
		        		{
		            		n = dlt_rear();
		            		printf("Deleted Element: %d\n", n);
		        		}
		        	break;
		    	case 5:if(is_empty())
		            		printf("Queue is Empty!\n");
		        	else
		            		peek_front();
					printf("\n");
		        	break;
		    	case 6:if(is_empty())
		            		printf("Queue Empty!\n");
		        	else if(is_full())
		            		printf("Queue Full!\n");
		        	else
		            		printf("Space Available\n");
		        	break;
		    	case 7: printf("Exiting...\n");
		        	break;
		    	default:
		        	printf("Invalid Choice!\n");
        		}
    		}
	while(choice != 7);
	}

# include <stdio.h>
# define size 10
int choice,item;
int top=0;
int s[size];
int isfull()
	{
	if (top>=size)
		return (1);
	else
		return (0);
	}
int isempty()
	{
	if (top==0)
		return (1);
	else
		return (0);
	}
void push(int item)
	{
	if (isfull())
		printf("Stack Full");
	else
		s[top++]=item;
	}
int pop()
	{
	if (isempty())
		printf("Stack Empty");
	else
		return (s[--top]);
	}

void main()
{
do
	{
	printf("\n\n1.Push\n2.Pop\n3.isempty\n4.isfull\n5.Exit\n");
	printf("Enter the Choice=");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1: if (!isfull())
		       		{
				printf("Enter the element to be pushed=");
				scanf("%d",&item);
				push(item);
				}
			break;
		case 2: if (isempty())
				printf("Stack Empty");
			else
				printf("\nItem Popped=%d",pop());
			break;
		case 3: if (isempty())
				printf("Yes");
			else
				printf("No");
			break;
		case 4: if (isfull())
				printf("Yes");
			else
				printf("No");
			break;
		case 5: printf("Exiting");
			break;
		default:printf("Invalid Choice");
		}
	}
while(choice!=5);
printf("\n");
}

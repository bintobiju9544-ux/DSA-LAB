# include <stdio.h>
int ls(int a[],int lim,int e);
void main()
	{
	int lim,e,p;
	printf("Enter the Number of Elements=");
	scanf("%d",&lim);
	int a[lim];
	printf("Enter the Numbers:\n");
	for (int i=0;i<lim;i++)
		scanf("%d",&a[i]);
	printf("Enter the Element to be Searched=");
	scanf("%d",&e);
	p=ls(a,lim,e);
	if (p==0)
		printf("Element Not Found");
	else
		printf("Position:%d",p);
	printf("\n");
	}
int ls(int a[],int lim,int e)
	{
	for (int i=0;i<lim;i++)
		if (e==a[i])
			{
			return i+1;
			}
	return 0;
	}

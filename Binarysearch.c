# include <stdio.h>
int bs(int a[],int lim,int e);
void main()
	{
	int lim,e,p;
	printf("Enter the Number of Elements=");
	scanf("%d",&lim);
	int a[lim];
	printf("Enter the Numbers in Sorted Order:\n");
	for (int i=0;i<lim;i++)
		scanf("%d",&a[i]);
	printf("Enter the Element to be Searched=");
	scanf("%d",&e);
	p=bs(a,lim,e);
	if (p==0)
		printf("Element Not Found");
	else
		printf("Position:%d",p);
	printf("\n");
	}
int bs(int a[],int lim,int e)
	{
	int t=0,b=lim-1,m;
	while (t<=b)
		{
		m=(t+b)/2;
		if (e==a[m])
			return m+1;
		else if (e>a[m])
			t=m+1;
		else
			b=m-1;
		}
	return 0;
	}

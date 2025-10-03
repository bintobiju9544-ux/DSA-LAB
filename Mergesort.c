# include <stdio.h>
void readarray(int a[],int lim)
	{
	int i;
	for (i=0;i<lim;i++)
		scanf("%d",&a[i]);
	}
void simplemerge(int a[],int f,int s,int l)
	{
	int temp[50],i=f,j=s,k=0;
	while (i<s && j<=l)
		{
		if (a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
		}
	while (i<s)
		temp[k++]=a[i++];
	while (j<=l)
		temp[k++]=a[j++];
	for (i=f,k=0;i<=l;i++,k++)
		a[i]=temp[k];
	}
void mergesort(int a[],int t,int b)
	{
	if (t<b)
		{
		int m=(t+b)/2;
		mergesort(a,t,m);
		mergesort(a,m+1,b);
		simplemerge(a,t,m+1,b);
		}
	}
void display(int a[],int lim)
	{
	int i;
	printf("Sorted Array:");
	for (i=0;i<lim;i++)
		printf("%d  ",a[i]);
	}
void main()
	{
	int lim,t=0;
	printf("Enter How Many Numbers?=");
	scanf("%d",&lim);
	int a[lim];
	int b=lim-1;
	readarray(a,lim);
	mergesort(a,t,b);
	display(a,lim);
	printf("\n");
	}

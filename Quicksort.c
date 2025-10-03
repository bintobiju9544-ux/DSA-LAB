# include <stdio.h>
void quicksort(int a[],int left,int right);
int partition(int a[],int left,int right);
void swap(int *a,int *b)
	{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}
void main()
	{
	int lim;
	printf("Enter the Number of Elements=");
	scanf("%d",&lim);
	int a[lim];
	printf("Enter the Numbers:\n");
	for (int i=0;i<lim;i++)
		scanf("%d",&a[i]);
	int left=0,right=lim-1;
	quicksort(a,0,lim-1);
	printf("Sorted Array:\n");
	for (int i=0;i<lim;i++)
		printf("%d  ",a[i]);
	printf("\n");
	}
int partition(int a[],int left,int right)
	{
	int key=a[left];
	int i=left+1,j=right;
	do
		{
		while(i<right && a[i]<key)
			i++;
		while(j>left && a[j]>key)
			j--;
		if (i<j)
			swap(&a[i],&a[j]);
		}
	while(i<j);
	swap(&a[left],&a[j]);
	return (j);
	}
void quicksort(int a[],int left,int right)
	{
	if (left<right)
		{
		int pos=partition(a,left,right);
		quicksort(a,left,pos-1);
		quicksort(a,pos+1,right);
		}
	}

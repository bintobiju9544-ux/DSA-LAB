#include <stdio.h>
void selectionsort(int a[],int n);
void main()
	{
	int n;
	printf("Enter the Number of Elements=");
	scanf("%d",&n);
	int a[n];
	printf("Enter the Numbers:\n");
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	selectionsort(a,n);
	printf("Sorted Array:\n");
	for (int i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
	}
void selectionsort(int a[],int n)
	{
	int p,small,index,c,temp;
	for (p=0;p<n-1;p++)
		{
		small=a[p];
		index=p;
		for (c=p+1;c<n;c++)
			if (a[c]<small)
				{
				small=a[c];
				index=c;
				}
		temp=a[index];
		a[index]=a[p];
		a[p]=temp;
		}
	}

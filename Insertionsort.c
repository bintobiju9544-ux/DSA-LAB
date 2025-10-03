# include <stdio.h>
void insertionsort(int a[],int lim);
void main()
	{
	int lim;
	printf("Enter the Number of Elements=");
	scanf("%d",&lim);
	int a[lim];
	printf("Enter the Numbers:\n");
	for (int i=0;i<lim;i++)
		scanf("%d",&a[i]);
	insertionsort(a,lim);
	printf("Sorted Array:\n");
	for (int i=0;i<lim;i++)
		printf("%d  ",a[i]);
	printf("\n");
	}
void insertionsort(int a[],int lim)
	{
	int p,key,i;
	for (p=1;p<lim;p++)
		{
		key=a[p];
		i=p-1;
		while (i>=0 && a[i]>key)
			{
			a[i+1]=a[i];
			i--;
			}
		a[i+1]=key;
		}
	}

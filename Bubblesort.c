# include <stdio.h>
void bubblesort(int a[],int lim);
void main()
	{
	int lim;
	printf("Enter the Number of Elements=");
	scanf("%d",&lim);
	int a[lim];
	printf("Enter the Numbers:\n");
	for (int i=0;i<lim;i++)
		scanf("%d",&a[i]);
	bubblesort(a,lim);
	printf("Sorted Array:\n");
	for (int i=0;i<lim;i++)
		printf("%d  ",a[i]);
	printf("\n");
	}
void swap(int *a,int *b)
	{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}
void bubblesort(int a[],int lim)
	{
	int p,c;
	for (p=1;p<lim;p++)
		for (c=0;c<lim-p;c++)
			if (a[c]>a[c+1])
				swap(&a[c],&a[c+1]);
	}

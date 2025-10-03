# include <stdio.h>
typedef struct
	{
	int row;
	int col;
	int val;
	}sparse;
int readmat(int matrix[][10],int m,int n)
	{
	int count=0;
	printf("Enter the Elements of the Matrix:\n");
	int i,j;
	for (i=0;i<m;i++)
		{
		printf("Enter %d elements of Row %d:\n",n,i+1);
		for (j=0;j<n;j++)
			{
			scanf("%d",&matrix[i][j]);
			if (matrix[i][j]!=0)
				count=count+1;
			}
		}
	return count;
	}
void main()
	{
	int m,n,nz,k;
	printf("Enter the order of the Matrix=");
	scanf("%d %d",&m,&n);
	int matrix[10][10];
	nz=readmat(matrix,m,n);
	sparse sa[nz+1];
	sa[0].row=m;
	sa[0].col=n;
	sa[0].val=nz;
	k=1;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			{
			if (matrix[i][j]!=0)
				{
				sa[k].row=i;
				sa[k].col=j;
				sa[k].val=matrix[i][j];
				k++;
				}
			}
	printf("Sparse Matrix:\n");
	for (int i=0;i<=nz;i++)
		printf("%d %d %d\n",sa[i].row,sa[i].col,sa[i].val);
	printf("\n");
	}

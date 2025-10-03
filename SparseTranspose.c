#include <stdio.h>
typedef struct
	{
    	int row,col,val;
	}sparse;
void main()
	{
    	int m,n,nz,k=1;
    	printf("Enter the dimensions of the sparse matrix: ");
    	scanf("%d%d",&m,&n);
    	printf("Enter the Number of non-zero elements: ");
    	scanf("%d",&nz);
    	sparse sa[nz+1];
    	sparse transpose[nz+1];
    	sa[0].row=m;
    	sa[0].col=n;
    	sa[0].val=nz;
    	for(int i=1;i<=nz;i++)
    		{
        	printf("Enter the position of the non zero element %d: ",i);
        	scanf("%d%d%d",&sa[i].row,&sa[i].col,&sa[i].val);
    		}
	printf("Sparse Matrix:\n");
	for (int i=0;i<=nz;i++)
		printf("%d %d %d\n",sa[i].row,sa[i].col,sa[i].val);
    	transpose[0].row=n;
    	transpose[0].col=m;
    	transpose[0].val=nz;
    	for (int i=1;i<=nz;i++)
    		{
        	transpose[i].row=sa[i].col;
        	transpose[i].col=sa[i].row;
        	transpose[i].val=sa[i].val;
    		}
    	for (int i=1;i<nz;i++)
    		{
        	for (int j=i+1;j<=nz;j++)
        		{
            		if (transpose[i].row>transpose[j].row || (transpose[i].row==transpose[j].row && transpose[i].col>transpose[j].col))
            			{
                		sparse temp=transpose[i];
                		transpose[i]=transpose[j];
                		transpose[j]=temp;
            			}
        		}
    		}
    	printf("Transpose :\n");
    	for(int i=0;i<=nz;i++)
        	printf("%d  %d  %d\n",transpose[i].row,transpose[i].col,transpose[i].val);
	}

#include <stdio.h>
typedef struct
	{
    	int row;
    	int col;
    	int value;
	}sparse;
void read(sparse sa[], int *nz)
	{
    	int m,n;
    	printf("Enter the dimensions of the sparse matrix: ");
    	scanf("%d%d",&m,&n);
    	sa[0].row=m;
    	sa[0].col=n;
    	sa[0].value=*nz;
    	for (int i = 1; i <= *nz; i++)
    		{
        	printf("Enter row, column and value for element %d: ", i);
        	scanf("%d%d%d", &sa[i].row, &sa[i].col, &sa[i].value);
    		}
	}
void main()
	{
    	int nz1, nz2, i=1, j=1, k=1;
	printf("Enter the non-zero elements of the sparse matrix 1: ");
	scanf("%d", &nz1);
	sparse sa1[nz1+1];
	read(sa1, &nz1);
	printf("Enter the non-zero elements of the sparse matrix 2: ");
	scanf("%d", &nz2);
	sparse sa2[nz2+1];
	read(sa2, &nz2);
	int total_nz=nz1+nz2;
	sparse sa3[total_nz + 1];
    	if (sa1[0].row!=sa2[0].row || sa1[0].col!=sa2[0].col)
        	printf("Matrix addition not possible\n");
    	else
    		{
        	sa3[0].row=sa1[0].row;
        	sa3[0].col=sa1[0].col;
        	sa3[0].value=total_nz;
        	while(i<=nz1 && j<=nz2)
        		{
           	 	if(sa1[i].row == sa2[j].row && sa1[i].col == sa2[j].col)
            			{
                		sa3[k].row=sa1[i].row;
                		sa3[k].col=sa1[i].col;
                		sa3[k].value=sa1[i].value+sa2[j].value;
                		i++,j++,k++;
            			}
            		else
            			{
                		if(sa1[i].row<sa2[j].row || (sa1[i].row==sa2[j].row && sa1[i].col<sa2[j].col))
                			{
                    			sa3[k++]=sa1[i++];
                			}
                		else
                			{
                    			sa3[k++]=sa2[j++];
                			}
            			}
        		}
        	while (i <= nz1)
            		sa3[k++]=sa1[i++];
        	while (j<=nz2)
            		sa3[k++]=sa2[j++];
        	printf("Resultant sparse matrix in 3-tuple form:\n");
        	for (int i=0;i<k;i++)
        		{
            		printf("%d %d %d\n",sa3[i].row,sa3[i].col,sa3[i].value);
        		}
    	}
}

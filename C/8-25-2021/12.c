//2D array using DMA

#include <stdio.h>
#include <stdlib.h>

void read(int **p,int r, int c);
void display(int **p,int r, int c);
int sum(int **p,int r, int c);

int main()
{
	int r,c;
	printf("Enter number of rows: ");fflush(stdin);scanf("%d",&r);
	printf("Enter number of columns: ");fflush(stdin);scanf("%d",&c);
	int** p = (int**)malloc(r*sizeof(int*));
	for(int i=0 ; i<r ; i++)
	{
		*(p+i) = (int *)malloc(c*sizeof(int));
	}
	read(p,r,c);
	display(p,r,c);
	printf("Sum = %d",sum(p,r,c));
}

void read(int **p,int r, int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("Row = %d\t Column = %d\n",i,j);
			scanf("%d",(*(p+i)+j));
		}
	}
}

void display(int **p,int r, int c)
{
	printf("The Matrix is: \n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d\t",*(*(p+i)+j));
		}
		printf("\n");
	}
}

int sum(int **p,int r, int c)
{
	int sum=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			sum+= *(*(p+i)+j);
		}
	}
	return sum;
}
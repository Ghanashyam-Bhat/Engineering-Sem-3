#include <stdio.h>
#include <stdlib.h>
struct T
{
	int row;
	int* col;
};
struct rc
{
	int** r;
};
int main()
{
	struct T* table = (struct T*)malloc(sizeof(table));
	printf("Enter number of rows: ");scanf("%d",&(table->row));
	table->col = (int*)malloc((table->row)*sizeof(int));
	struct rc* rows = (struct rc*)malloc(sizeof(rows));
	rows->r = (int**)malloc((table->row)*sizeof(int*));
	for(int i=0;i<(table->row) ; i++)
	{
		printf("Number of columns in Row %d: ",i+1);scanf("%d",&(table->col)[i]);
		(rows->r)[i] = (int*)malloc((table->col)[i]*sizeof(int));
	}
	for(int i=0;i<(table->row) ; i++)
	{
		printf("Row %d:\n",i+1);
		for(int j=0;j<(table->col)[i]; j++)
			printf("Column %d: ",j+1);scanf("%d",&(rows->r)[i][j]);	
	}
	for(int i=0;i<(table->row) ; i++)
	{
		printf("\n");
		for(int j=0;j<(table->col)[i]; j++)
			printf("%d\t",(rows->r)[i][j]);	
	}
}
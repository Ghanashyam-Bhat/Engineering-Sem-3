#include <stdio.h>
#include <stdlib.h>

void read(int *p, int n)
{
	if(p)
	{
		printf("Enter %d elements\n",n);
		for(int i=0;i<n;i++)
		{
			fflush(stdin);scanf("%d",(p+i));		
		}
	}
	else
	{
		printf("\nError");
	}
}

void display(int *p, int n)
{
	if(p)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d\t",*(p+i));		
		}
	}
	else
	{
		printf("\nError");
	}
}

int sum(int *p, int n)
{
	int x=0;
	if(p)
	{
		printf("Enter %d elements\n",n);
		for(int i=0;i<n;i++)
		{
			x += (*(p+i));		
		}
		return x;
	}
	else
	{
		printf("\nError");
	}
}

int main()
{
	int *p ;p = (int*)malloc(sizeof(int));
	int n;
	printf("Enter the size of array: ");fflush(stdin);scanf("%d",&n);
	read(p,n);
	display(p,n);
	printf("\n%d",sum(p,n));
}
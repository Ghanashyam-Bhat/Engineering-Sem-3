#include <stdio.h>
int fun(int *arr, int n, int i,int x);
int main()
{
	int n,x;
	printf("Enter the number of elements: ");fflush(stdin);scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the element number-%d: ",i+1);fflush(stdin);scanf("%d",&arr[i]);
	}
	printf("Enter the element to be checked: ");fflush(stdin);scanf("%d",&x);
	if(fun(arr,n,0,x))
		printf("Number is present");
	else 
		printf("Number is not there");
}

int fun(int *arr, int n, int i,int x)
{
	if(i==n)
		return 0;
	else if(arr[i]==x)
		return 1;
	else 
	{
		fun(arr,n,i+1,x);
	}	
}
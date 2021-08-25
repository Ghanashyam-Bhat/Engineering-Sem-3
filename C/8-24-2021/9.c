//Maximum element in using recursive function
#include <stdio.h>
int fun(int arr[],int n);
int main()
{
	int arr[20]={0,1,2,3,4,10,5,6,7,8,9};
	//printf("%d",arr[10]);
	printf("%d",fun(arr,11-1));
}

int fun(int arr[],int n)
{
	if(n==0)
	{
		return arr[n];
	}
	else
	{
		return (arr[n]>fun(arr,n-1))?arr[n]:fun(arr,n-1);
	}
}
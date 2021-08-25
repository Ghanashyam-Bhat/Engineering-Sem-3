#include <stdio.h>
void print(int *a,int n);
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(int);
	print(arr,n);
}

void print(int *a,int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d\n",*(a+i));
	}
}
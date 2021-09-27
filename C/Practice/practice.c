//Recurssion

/*//Finding Maximum
#include <stdio.h>
int fun(int arr[],int n)
{
	if(n==0)
		return arr[0];
	else 
	{
		int c = fun(arr,n-1);
		return arr[n]>c?arr[n]:c ;
	}
}

int main()
{
	int arr[] = {5,4,7,6,8,3,13,7,4,9,10};
	int n = sizeof(arr)/sizeof(int);
	printf("%d",fun(arr,n-1));	
}*/


/*//Palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pal(char* arr,int x, int n)
{
	if (x>n)
		return 1;
	else if(arr[x]!=arr[n])
		return 0;
	else
		return pal(arr,x+1,n-1);
	
}
int main()
{
	char* arr=(char*)calloc(10,sizeof(char));
	printf("String: ");scanf("%[^\n]s",arr);
	if(pal(arr,0,strlen(arr)-1))
		printf("palindrome");
	else
		printf("Not palindrome");
}*/


/*//String reversal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fun(char *arr,char *a,int n,int x)
{
	if(n==0)
		a[x-n]='\0';
	else
	{
		a[x-n] = arr[n-1];
		fun(arr,a,n-1,x);
	}
}
int main()
{
	char arr[15];printf("String: ");scanf("%[^\n]s",arr);
	char *a = (char*)malloc(15*sizeof(char));
	fun(arr,a,strlen(arr),strlen(arr));
	printf("%s",a);
}*/


/*//Fibonacci Using Recurssion
#include <stdio.h>
int fib(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

int main()
{
	int n;printf("n: ");scanf("%d",&n);
	for(int i=1;i<=n;i++)
		printf("%d\t",fib(i));
}*/
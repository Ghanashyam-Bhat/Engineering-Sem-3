//Fibonacci numbers
#include <stdio.h>
//This takes lot of time for n=50, so iterative solution works in a better way for Fibonacci
/*int fun(int n);
int main()
{
	int n=5;
	for(int i=0;i<n;i++)
	{
		printf("%d\t",fun(i));
	}
}

int fun(int n)
{
	if(n==0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		return fun(n-1)+fun(n-2);
	}
*/

int main()
{
	int n=50;
	int c=0,d=1,a;
	printf("%d\t%d\t",c,d);
	for(int i=2;i<n;i++)
	{
		printf("%d\t",c+d);
		a=d;d=c+d;c=a;
	}
}
//print 50 N numbers
#include <stdio.h>
void fun(int n);
int main()
{
	int n=50;
	fun(n);
}

void fun(int n)
{
	if(n==0);
	else{
	fun(n-1);
	printf("%d\t",n);}
}
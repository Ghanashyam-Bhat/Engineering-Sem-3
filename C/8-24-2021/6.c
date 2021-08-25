//sum of 50 N numbers
#include <stdio.h>
int fun(int n);
int main()
{
	int n=50;
	printf("%d\n",fun(n));
	printf("%d",50*51/2);
}

int fun(int n)
{
	if(n==0){
		return 0;
	}
	else{
	return n+fun(n-1);
	}
}
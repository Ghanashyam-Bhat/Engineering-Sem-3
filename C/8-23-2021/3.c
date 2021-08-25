#include <stdio.h>
int main()
{
	int a = 1;
	int *p=&a;
	*(p+1)=0;
	int *q=(int*)((char*)p+3);
	printf("lower addr= %d\n",q);
	printf("upper addr= %d\n",p);
	*q=0;
	printf("lower = %d\n",(*p));
	printf("upper = %d",(*q));
}
//Josephy's Problem
#include <stdio.h>
#include <math.h>
int main()
{
	int x,n=0;printf("Total number of soldiers: ");scanf("%d",&x);
	for(int i=x;i;i=i/2,n++);
	printf("Position of Joshepie %d",2*(x-(int)pow(2,n-1))+1);
}
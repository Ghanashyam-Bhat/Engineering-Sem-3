//Josephy's Problem ~ Not working
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long long int convert(long long int n)
{
	int rem,bin=0,i=1,j;
	for(j=n;j!=0;j)
    {
        rem = j % 2;
        j /= 2;
        bin += rem * i;
        i *= 10;
    }
	return bin;
}

int main()
{
	long long int x;printf("Total number of soldiers: ");scanf("%lld",&x);
	printf("%lld",convert(x));
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

int main()
{
	H h;
	h.head = NULL;
	int x,ans;
	char o;
	do
	{
		printf("\nSelect\n1.To initialize a polynimial\n2.To perform operations\n");fflush(stdin);scanf("%c",&o);
		switch(o)
		{
			case '1':x = initialize(&h);
						break;
			case '2':ans = operation(&h,x);
					printf("The answer is: %d",ans);
						break;
			case '3':printf("\nClosed");
						break;
			default:printf("\nEnter proper option");
		}
	}while(o!='3');
}

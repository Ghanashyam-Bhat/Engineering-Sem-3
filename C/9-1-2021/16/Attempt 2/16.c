#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

int main()
{
	H h,he,final;
	h.head = NULL;he.head=NULL;final.head=NULL;
	int x,y,ans;
	char o;
	do
	{
		printf("\nSelect\n1.To initialize two polynimials\n2.To perform operations on polynomials\n");fflush(stdin);scanf("%c",&o);
		switch(o)
		{
			case '1':x = initialize(&h,1);
					 y = initialize(&he,2);
					 /*printf("\nReached the Calling of merge function");
						merge(&h,&he,x+y);*/
						printf("reached combination\n");
						//comb(&h,&he,&final,x+y);
						break;
						
			case '2':operation(&h,x);
					operation(&he,y);
					//ans = operation(&final,x+y);
					printf("The answer is: %d",ans);
						break;
			case '3':printf("\nClosed");
						break;
			default:printf("\nEnter proper option");
		}
	}while(o!='3');
}

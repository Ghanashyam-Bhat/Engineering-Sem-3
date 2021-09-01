#include <stdio.h>
#include <string.h>
#include "head.h"

void main()
{
	char string[500];
	printf("Enter String: ");fflush(stdin);scanf("%[^\n]s",string);
	char sub[50];
	printf("Enter String: ");fflush(stdin);scanf("%[^\n]s",sub);
	char test[500]="";
	if(fun(string,sub,test,strlen(string),strlen(sub),strlen(sub)))
		printf("True");
	else
		printf("False");
}

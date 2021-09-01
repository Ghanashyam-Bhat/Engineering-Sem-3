#include <stdio.h>
#include <string.h>
#include "head.h"

int fun(char* string,char* sub,char* test,int x,int y,int z)
{
	if(strcmp(test,sub)==0)
		return 1;
	else if(x<z)
		return 0;
	else
	{
		strcpy(test,string+x-z);
		test[y]='\0';
		z+=1;
		fun(string,sub,test,x,y,z);
	}
}
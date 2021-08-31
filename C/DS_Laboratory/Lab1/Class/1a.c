#include <stdio.h>
#include <string.h>
int fun(char* string,char* sub,char* test,int x,int y,int z);
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
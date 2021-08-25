//Reverse print string
#include <stdio.h>
#include <string.h>
void fun(char* n,int x);
int main()
{
	char n[]="Ghanashyam";
	fun(n,strlen(n)-1);
}

void fun(char* n,int x)
{
	if(n[x]=='\0');
	else{
	printf("%c",n[x]);
	fun(n,x-1);
	}
}
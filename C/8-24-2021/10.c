//Check if it is palindrome
#include <stdio.h>
#include <string.h>
void fun(char* n,int x,char* a);
int main()
{
	char n[]="aabbaac";char a[50];
	fun(n,strlen(n)-1,a);
	a[strlen(n)]='\0';
	if(!strcmp(a,n))
	{
		printf("Palin");
	}
	else
	{
		printf("Not Palin");
	}
}

void fun(char* n,int x,char* a)
{
	if(n[x]=='\0');
	else{
	a[strlen(n)-1-x]=n[x];
	fun(n,x-1,a);
	}
}
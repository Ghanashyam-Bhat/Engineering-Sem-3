//C language
#include <stdio.h>
#include <string.h>
int qo(char *arr);
int q1(char *arr);
int q2(char *arr);
int q3(char *arr);
int q4(char *arr);
int D(char *arr);

void main()
{
	printf("Regular Expression is: (a+b)*baba\n");
	char arr[50];scanf("%s",arr);
	if(qo(arr))
		printf("String Accepted");
	else
		printf("String Rejected");
	
}

int qo(char *arr)
{
	if (strlen(arr)==0)
		return 0;
	else if(arr[0] == 'a')
		return qo(arr+1);
	else if(arr[0] == 'b')
		return q1(arr+1);
	else
		return D(arr+1);
}

int q1(char *arr)
{
	if (strlen(arr)==0)
		return 0;
	else if(arr[0] == 'b')
		return q1(arr+1);
	else if(arr[0] == 'a')
		return q2(arr+1);
	else
		return D(arr+1);
}

int q2(char *arr)
{
	if (strlen(arr)==0)
		return 0;
	else if(arr[0] == 'b')
		return q3(arr+1);
	else if(arr[0] == 'a')
		return qo(arr+1);
	else
		return D(arr+1);
}

int q3(char *arr)
{
	if (strlen(arr)==0)
		return 0;
	else if(arr[0] == 'b')
		return q1(arr+1);
	else if(arr[0] == 'a')
		return q4(arr+1);
	else
		return D(arr+1);
}

int q4(char *arr)
{
	if (strlen(arr)==0)
		return 1;
	else if(arr[0] == 'b')
		return q1(arr+1);
	else if(arr[0] == 'a')
		return qo(arr+1);
	else
		return D(arr+1);
}

int D(char* arr)
{
	return 0;
}


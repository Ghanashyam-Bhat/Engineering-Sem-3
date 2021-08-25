#include <stdio.h>
#include <string.h>
//Method 1
int main()
{
	int x=0,y=0;long long int k=1,l=1;
	char a[]="ad",b[]="cb";
	if(strlen(a)==strlen(b))
	{
		for(int i=0;a[i]!='\0';i++)
		{
			x+=a[i];
			y+=b[i];
			k*=a[i];
			l*=b[i];
		}
		if(x==y&&k==l)
		{
			printf("It is an anagram");
		}
		else
		{
			printf("Not anagram");
		}
	}
	else
	{
		printf("Not anagram");
	}
}
/*
//Method 2: Sorting and the strcmp

//Method 3
int main()
{
	
	int x=0;
	char a[]="god",b[]="doc";
	if(strlen(a)==strlen(b))
	{
		for(int i=0;i<strlen(a);i++)
		{
			for(int j=0;j<strlen(a);j++)
			{
				if(a[i]==b[j])
				{
					x++;
					b[j]='*';
				}
			}
		}
		if(x==strlen(a))
		{
			printf("It is anagram");
		}
		else
		{
			printf("Not anagram");
		}
	}
	else
	{
		printf("Not anagram");
	}
}*/
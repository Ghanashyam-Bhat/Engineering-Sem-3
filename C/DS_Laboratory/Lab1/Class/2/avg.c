#include <stdio.h>
#include <string.h>
#include "head.h"

float avg(HEAD* h ,int n)
{
	char code[50];
	INFO* pres = h->head;
	int x=0,total=0;
	
	printf("Enter the subject code of which average is to be calculated: ");fflush(stdin);scanf("%s",code);
	for(int i=0;i<n&&(pres!=NULL);i++)
	{
		for(int j=0;j<5;j++)
		{
			if(strcmp(code,pres->subjects[j].sub_code)==0)
			{
				total+=pres->subjects[j].marks;
				x++;
			}
		}
		pres = pres->link;
	}
	return (float)total/x;
}

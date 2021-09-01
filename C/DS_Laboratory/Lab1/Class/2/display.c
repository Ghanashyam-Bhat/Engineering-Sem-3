#include <stdio.h>
#include "head.h"

void display(HEAD* h,int n)
{
	INFO* pres = h->head;
	for(int i=0;i< n;i++)
	{
		printf("\n\nName: %s\n",pres->name);
		printf("\nSRN: %s\n",pres->SRN);
		printf("\nSemester: %d\n",pres->sem);
		for(int j=0;j<5;j++)
		{
			printf("\nSub Name:%s\n", pres->subjects[j].sub_name);
			printf("Sub ID:%s\n", pres->subjects[j].sub_code);
			printf("Marks: %d\n", pres->subjects[j].marks);
		}
		pres = pres->link;
	}
}
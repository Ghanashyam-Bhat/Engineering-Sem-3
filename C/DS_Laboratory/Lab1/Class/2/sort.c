#include <stdio.h>
#include <string.h>
#include "head.h"

void sort(HEAD* h,int n)
{
	INFO temp;
	INFO* pres,*t,*t1;
	for(int i=0;i<n-1;i++)
	{
		pres=h->head;
		for(int j=0;j<n-i-1;j++)
		{
			if(strcmp(pres->SRN,pres->link->SRN)>0)
			{
				t = pres->link;
				t1 = pres->link->link;
				temp = *(pres);
				*(pres) = *(pres->link);
				pres->link = t;
				*(pres->link) = temp;
				pres->link->link = t1;
			}
			pres=pres->link;
		}
	}
	
	display(h,n);
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

int initialize(H* h)
{
	int n,x=0,c,p;NODE* temp= h->head,*pres;
	printf("Enter the degree of the polynominal: ");fflush(stdin);scanf("%d",&n);
	for(int i=n;i>=0;i--)
	{
		printf("Enter the coefficient: ");fflush(stdin);scanf("%d",&c);
		printf("Enter the degree: ");fflush(stdin);scanf("%d",&p);
		if(p>i)
		{
			printf("The power is greater than the degree of polyomial\n");
			break;
		}
		else
		{
			while(p!=i)
				i--;
			temp = (NODE*)malloc(sizeof(NODE));
			temp->poly.coeff = c;
			temp->poly.power = p;
			temp->link = NULL;
			x++;
		}
		if(h->head==NULL)
			h->head = temp;
		else
		{
			pres = h->head;
			while(pres->link)
			{
				pres=pres->link;
			}
			pres->link=temp;
		}
	}
	return x;
}

int operation(H* h,int n)
{
	int res=0;
	NODE* pres=h->head;
	for(int i=0;i<n&&pres;i++)
	{
		printf("+(%d*x^%d)",pres->poly.coeff,pres->poly.power);
		pres=pres->link;
	}
	pres=h->head;
	printf("\nEnter the value of variable x: ");fflush(stdin);int x;scanf("%d",&x);
	for(int i=0;i<n&&pres;i++)
	{
		res+=pres->poly.coeff*pow(x,pres->poly.power);
		pres=pres->link;
	}
	return res;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

int initialize(H* h,int num)
{
	int n,x=0,y=0,c,p;NODE* temp,*pres;
	printf("Enter the degree of the polynominal %d: ",num);fflush(stdin);scanf("%d",&n);
	for(int i=n;i>=0;i--)
	{
		printf("Enter the coefficient: ");fflush(stdin);scanf("%d",&c);
		printf("Enter the power: ");fflush(stdin);scanf("%d",&p);
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

int merge(H* h, H* he,int n)
{
	NODE* prev;
	NODE* pres = h->head;
	NODE* pres2 = he->head;
	for(int i=0;i<n;i++)
	{
		while(pres->poly.power<=pres2->poly.power)
		{
			if(pres2==NULL)
			{
				return 0;
			}
			if(pres==NULL)
			{
				pres = he->head;
				return 0;
			}
			if((pres->poly.power==pres2->poly.power)&&pres2==he->head)
			{
				pres->poly.coeff=pres->poly.coeff+pres2->poly.coeff;
				he->head = he->head->link;
				free(pres2);
				pres2 = h->head;
			}
			else if(pres->poly.power==pres2->poly.power)
			{
				prev = pres2;
				pres->poly.coeff=pres->poly.coeff+pres2->poly.coeff;
				prev->link = pres2->link;
				free(pres2);
				pres2= prev->link;
			}
		}
		pres = pres->link;
	}
	printf("\nReached the Calling of sort function");
	sort(h,n);
	
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

void sort(H* h,int n)
{
	NODE temp;
	NODE* pres,*t,*t1;
	for(int i=0;i<n-1;i++)
	{
		pres=h->head;
		for(int j=0;j<n-i-1;j++)
		{
			if(pres->poly.power,pres->link->poly.power)
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
}
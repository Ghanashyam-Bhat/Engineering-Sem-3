#include <stdio.h>
#include <stdlib.H>
#include "head.h"

void initialize(H* h)
{
	h->head = NULL;
}

void insert_front(H* h,int x)
{
	D* temp = (D*)malloc(sizeof(D));
	temp->info = x;
	temp ->link = h->head;
	h->head = temp ;
}

void insert_rear(H* h,int x)
{
	D* temp = (D*)malloc(sizeof(D));
	temp->info = x;
	temp ->link = NULL;
	D* pres=h->head;
	while(pres->link)
	{
		pres = pres->link;
	}
	pres->link = temp;
}

void display(const H* h)
{
	D* pres=h->head;
	while(pres)
	{
		printf("%d\t",pres->info);
		pres = pres->link;
	}
}

void delete_front(H* h)
{
	if(h->head)
	{
		D* temp = h->head;
		h->head = h->head->link;
		printf("Deleted element: %d",temp->info);
		free(temp);temp=NULL;
	}
	else
	{
		printf("\nNo element to delete\n");
	}
}

void delete_rear(H* h)
{	
	if(h->head)
	{
		D* prev;
		D* pres=h->head;
		while(pres->link)
		{	
			prev = pres;
			pres = pres->link;
		}
		prev->link = NULL;
		printf("Deleted element is: %d",pres->info);
		free(pres);pres=NULL;
	}
	else
	{
		printf("\nNo element to delete\n");
	}
}
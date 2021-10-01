#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int pos;
	struct node* link;
}NODE;

typedef struct head_to_node{
	NODE* head;
}HEAD;


void list(HEAD* h,int n)
{
	NODE* pres;
	for(int i=0;i<n;i++)
	{	
		if(h->head==NULL)
		{
			h->head = (NODE*)malloc(sizeof(NODE));
			h->head->pos = i+1;
			h->head->link = h->head;
			pres=h->head;
		}
		else
		{
			pres->link = (NODE*)malloc(sizeof(NODE));
			pres = pres->link;
			pres->pos = i+1;
			pres->link = h->head;
			
		}
	}
}

void display(HEAD *h)
{
	if(h->head !=NULL)
	{
		printf("%d\t",h->head->pos);
	}
	NODE* pres = h->head->link;
	while(pres!=h->head)
	{
		printf("%d\t",pres->pos);
		pres = pres->link;
	}
}

void kill(HEAD* h)
{
	NODE* pres = h->head;
	while(h->head->link != h->head)
	{
		if(pres->link == h->head)
		{
			h->head = pres->link->link;
		}
		pres->link = pres->link->link;
		pres = pres->link;
	}
}

int main()
{
	HEAD h;h.head=NULL;
	NODE* temp;
	int n;printf("Enter number of elements: ");scanf("%d",&n);
	list(&h,n);
	display(&h);
	kill(&h);
	printf("\nThe surviving node: ");
	display(&h);
}
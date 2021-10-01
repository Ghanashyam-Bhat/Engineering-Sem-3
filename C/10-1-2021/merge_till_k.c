#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}NODE;

typedef struct head_to_node
{
	NODE* head;
}HEAD;

int input(HEAD* h1,HEAD* h2)
{
	int k = 4;
	h1->head = (NODE*)malloc(sizeof(NODE));
	h1->head->data = 2;
	h1->head->link = (NODE*)malloc(sizeof(NODE));
	h1->head->link->data = 2;
	h1->head->link->link = (NODE*)malloc(sizeof(NODE));
	h1->head->link->link->data = 2;
	h1->head->link->link->link = (NODE*)malloc(sizeof(NODE));
	h1->head->link->link->link->data = 2;
	h1->head->link->link->link->link = (NODE*)malloc(sizeof(NODE));
	h1->head->link->link->link->link->data = 6;
	h1->head->link->link->link->link->link=NULL;
	
	h2->head = (NODE*)malloc(sizeof(NODE));
	h2->head->data = 1;
	h2->head->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->data = 1;
	h2->head->link->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->link->data = 2;
	h2->head->link->link->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->link->link->data = 3;
	h2->head->link->link->link->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->link->link->link->data = 3;
	h2->head->link->link->link->link->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->link->link->link->link->data = 5;
	h2->head->link->link->link->link->link->link = (NODE*)malloc(sizeof(NODE));
	h2->head->link->link->link->link->link->link->data = 6;
	h2->head->link->link->link->link->link->link->link = NULL;
	return k;
}

void display(HEAD* h)
{
	NODE* pres = h->head;
	while(pres!=NULL)
	{
		printf("%d\t",pres->data);
		pres = pres->link;
	}
}

void merge(HEAD* h1,HEAD* h2,HEAD* h3)
{
	NODE* pres=NULL,pres1=h1->head,pres2=h2->head;
	for(int i=k;k!=0;)
	{
		if(h3->head == NULL)
		{
			if(h1->head != NULL)
			{
				h3->head = (NODE*)malloc(sizeof(NODE));
				h3->head->link = NULL;
				pres = h3->head;
				h3->head->data = h1->head->data;
				pres1 = h1->head->link;
				k--;
			}
			else if(h2->head != NULL)
			{
				h3->head = (NODE*)malloc(sizeof(NODE));
				h3->head->link = NULL;
				pres = h3->head;
				h3->head->data = h2->head->data;
				pres2 = h2->head->link;
				k--;
			}
			else
				break;
		}
		else
		{
			if(pres1 != NULL)
			{
				pres->link = (NODE*)malloc(sizeof(NODE));
				pres->link->link = NULL;
				pres = pres->link;
				pres->data = pres1->data;
				k--;
			}
			else if(pres2 != NULL)
			{
				pres->link = (NODE*)malloc(sizeof(NODE));
				pres->link->link = NULL;
				pres = pres->link;
				pres->data = pres2->data;
				k--;
			}
			else
				break;
		}
		
	}	
}

int main()
{
	HEAD h1,h2,h3;h1.head = NULL;h2.head=NULL;h3.head=NULL
	int k = input(&h1,&h2);
	display(&h1);
	printf("\n");
	display(&h2);
	merge(&h1,&h2,&h3,k);
	display(&h3);
}

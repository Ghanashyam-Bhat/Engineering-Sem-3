//Reverse the linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node* link;
}N;

typedef struct head_pointer
{
	N* head;
}H;

void reverse(H* h);
void main()
{
	H* h=(H*)malloc(sizeof(H));
	h->head =( N*)malloc(sizeof(struct node));
	h->head->info = 10;
	h->head->link = ( N*)malloc(sizeof(struct node));
	h->head->link->info = 50;
	h->head->link->link = ( N*)malloc(sizeof(struct node));
	h->head->link->link ->info = 60;
	h->head->link->link ->link = NULL;
	reverse(h);
	N* pres = h->head;
	while(pres)
	{
		printf("%d\n",pres->info);
		pres = pres->link;
	}
}

void reverse(H* h)
{
	N *prev = NULL ,*pres = h->head;N *next;
	if(h->head)
		next = h->head->link;
	while(pres)
	{
		pres->link = prev;
		prev=pres;
		pres = next;
		if(next)
			next = next->link;
	}
	h->head = prev;
}





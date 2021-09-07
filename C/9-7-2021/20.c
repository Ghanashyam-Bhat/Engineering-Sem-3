#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node* rlink;
	struct node* llink;
}NODE;

typedef struct head_node
{
	NODE* head;
}HEAD;

void add_front(HEAD* h,int inf);
void display(HEAD* h);
void add(HEAD* h1,HEAD* h2,HEAD* h3);

int main()
{
	HEAD h1,h2,h3;
	h1.head = NULL;
	h2.head = NULL;
	h3.head =NULL;
	printf("Enter number 1: ");int n1;scanf("%d",&n1);
	printf("Enter number 2: ");int n2;scanf("%d",&n2);
	while(n1)
	{
		add_front(&h1,n1%10);
		n1 /= 10;
	}
	while(n2)
	{
		add_front(&h2,n2%10);
		n2 /= 10;
	}
	add(&h1,&h2,&h3);
	display(&h3);
}


void add_front(HEAD* h,int inf)
{
	NODE *temp;
	if(h->head ==NULL)
	{
		h->head = (NODE*)malloc(sizeof(NODE));
		h->head->llink = NULL;
		h->head->rlink = NULL;
		h->head->info = inf;
	}		
	else 
	{
		temp = (NODE*)malloc(sizeof(NODE));
		temp->info = inf;
		temp->rlink = h->head;
		temp->llink =NULL;
		h->head->llink = temp;
		h->head = temp;
	}
}

void add(HEAD* h1,HEAD* h2,HEAD* h3)
{
	int carry=0,sum;
	NODE* pres1=h1->head, *pres2=h2->head;
	while(pres1->rlink!=NULL)
		pres1=pres1->rlink;
	while(pres2->rlink!=NULL)
		pres2=pres2->rlink;
	
	while(pres1!=NULL || pres2!=NULL)
	{
		if(pres1!=NULL && pres2!=NULL)
		{
			sum = pres1->info + pres2->info+carry;
			add_front(h3,sum%10);
			carry = sum/10;
			pres1 = pres1->llink;
			pres2 = pres2 ->llink;
		}
		else if(pres1!=NULL)
		{
			sum = pres1->info+carry ;
			add_front(h3,sum%10);
			carry = sum /10 ;
			pres1 = pres1->llink;
		}
		else if(pres2!=NULL)
		{
			sum = pres2->info+carry;
			add_front(h3,sum %10);
			carry = sum/10;
			pres2 = pres2 ->llink;
		}
		
	}
	if(carry!=0)
	{
		add_front(h3,carry);
	}
}


void display(HEAD* h)
{
	NODE* pres = h->head;
	while(pres)
	{
		printf("%d",pres->info);
		pres=pres->rlink;
	}
	printf("\n");
}
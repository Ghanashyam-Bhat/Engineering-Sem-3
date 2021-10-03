#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* llink;
	struct node* rlink;
}NODE;

typedef struct head_to_node
{
	NODE* head;
}HEAD;


void input_rear(HEAD* h,int ele)
{
	if(h->head ==NULL)
	{
		h->head = (NODE*)malloc(sizeof(NODE));
		h->head->llink = NULL;
		h->head->rlink = NULL;
		h->head->data = ele;
	}
	else
	{
		NODE* pres=h->head,*prev=NULL;
		while(pres->rlink)
		{
			pres = pres->rlink;
		}
		pres->rlink = (NODE*)malloc(sizeof(NODE));
		prev = pres;
		pres = pres->rlink;
		pres->rlink = NULL;
		pres->llink = prev;
		pres->data = ele;
	}
}

void input_front(HEAD* h,int ele)
{
	if(h->head==NULL)
	{
		input_rear(h,ele);
	}
	else
	{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->rlink = h->head;
		h->head = temp;
		temp->rlink->llink = temp;
		temp->llink = NULL;
		temp->data = ele;
	}
}

void display(HEAD* h)
{
	NODE* pres=h->head;
	while(pres!=NULL)
	{
		printf("%d\t",pres->data);
		pres = pres->rlink;
	}
}

void display_rev(HEAD* h)
{
	NODE* pres=h->head;
	while(pres->rlink)
		pres =pres->rlink;
	while(pres!=NULL)
	{
		printf("%d\t",pres->data);
		pres = pres->llink;
	}
}


int main()
{
	HEAD h;
	h.head = NULL;
	printf("Give value: ");int ele;scanf("%d",&ele);
	input_rear(&h,ele);
	printf("Give value: ");scanf("%d",&ele);
	input_rear(&h,ele);
	
	display(&h);
	printf("\n");
	display_rev(&h);
	printf("Give value: ");scanf("%d",&ele);
	input_front(&h,ele);
	display(&h);
}
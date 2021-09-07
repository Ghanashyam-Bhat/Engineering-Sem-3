//Doubley Linked List
/*This will have double pointers, one pointing to  next element and another pointing to previous element*/


//Q. Write a code for doubly linked list, that supports initialize, insert front and display 
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

void add_front(HEAD* h);
void display(HEAD* h);
void add_rear(HEAD* h);
void display_rev(HEAD* h);
void delete_front(HEAD* h);
void delete_rear(HEAD* h);

int main()
{
	HEAD h;h.head = NULL;
	char c;
	do
	{
		printf("Enter:\n1.To Insert front\n2.Display\n3.To close\n4.To insert rear\n5.Display reverse\n6.Delete Front\n");fflush(stdin);scanf("%c",&c);
		switch(c)
		{
			case '1' :add_front(&h);
						break;
			case '2' : display(&h);
						break;
			case '3' : printf("Closed\n");
						break;
			case '4' : add_rear(&h);
					break;
			case '5' : display_rev(&h);
						break;
			case '6' : delete_front(&h);
					break;
			case '7' : delete_rear(&h)
						break;
			default: printf("Select a valid option\n");
		}
	}while(c!='3');
}


void add_rear(HEAD* h)
{
	NODE* pres=h->head,*prev,*temp;
	if (h->head==NULL)
		add_front(h);
	else
	{
		int inf;
		while(pres->rlink!=NULL)
		{
			prev = pres;
			pres=pres->rlink;
		}
		printf("Enter the info: ");scanf("%d" ,&inf);
		temp = (NODE*)malloc(sizeof(NODE));
		temp->info = inf;
		pres->rlink = temp;
		temp->rlink =NULL;
		temp->llink = prev->rlink;
	}
}


void add_front(HEAD* h)
{
	int inf;
	NODE *temp;
	printf("Enter the info: ");scanf("%d" ,&inf);
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

void display(HEAD* h)
{
	printf("\nllink\t\tinfo\t  rrlink\n");
	NODE* pres = h->head;
	while(pres)
	{
		printf("%p\t%d\t%p\n",pres->llink,pres->info,pres->rlink);
		pres=pres->rlink;
	}
}

void display_rev(HEAD* h)
{
	printf("\nllink\t\tinfo\t  rrlink\n");
	NODE* pres = h->head;
	while(pres->rlink!=NULL)
		pres=pres->rlink;
	while(pres)
	{
		printf("%p\t%d\t%p\n",pres->llink,pres->info,pres->rlink);
		pres=pres->llink;
	}
}

void delete_front(HEAD* h)
{
	NODE* pres = h->head;
	h->head->rlink = pres->rlink;
	pres->rlink->llink = NULL;
	h->head = pres->rlink;
	free(pres);
	pres= NULL;
}

void delete_rear(HEAD* h)
{
	
	
}
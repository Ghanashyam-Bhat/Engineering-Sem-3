//Write a Program to impliment priority queue using Linked list and make it enqueue heavy(We can also use array reprasentation)
#include <stdio.h>
#include <stdlib.h>

//Higher the value ,lower the priority
typedef struct node
{
	int data;
	int priority;
	struct node* link;
}NODE;

typedef struct head_to_node
{
	NODE* head;
}HEAD;

void enqueue(HEAD* h, int ele,int pri);
void display(HEAD* h);
void dequeue(HEAD* h);

int main()
{
	HEAD h;
	h.head= NULL;
	char ch='0';int ele, pri;
	do
	{
		printf("Enter:\n1.To enqueue\n2.To dequeue\n3.To display\n>");fflush(stdin);scanf("%c",&ch);
		switch(ch)
		{
			case '1':
				printf("Enter the element to be enqueue: ");scanf("%d",&ele);
				printf("Enter the priority of element: ");scanf("%d",&pri);
				enqueue(&h,ele,pri);
				break;
			case '2':
				dequeue(&h);
				break;
			case '3':
				display(&h);
				break;
			case '4':
				printf("Closed\n");
				break;
			default:
				printf("Invalid Input\n");
				break;
		}		
	}while(ch!='4');
}

void enqueue(HEAD* h, int ele,int pri)
{
	if(h->head == NULL)
	{
		h->head = (NODE*)malloc(sizeof(NODE));
		h->head->priority = pri;
		h->head->data = ele;
		h->head->link = NULL;
	}
	else
	{
		NODE *pres = h->head,*prev=NULL;
		while(pres!=NULL && (pres->priority) < pri)
		{
			prev = pres;
			pres = pres ->link;	
		}
		if (prev!=NULL)
		{
			prev->link = (NODE*)malloc(sizeof(NODE));
			prev->link->priority = pri;
			prev->link->data= ele;
			prev->link->link= pres;
		}
		else
		{
			h->head = (NODE*)malloc(sizeof(NODE));
			h->head->priority = pri;
			h->head->data = ele;
			h->head->link = pres;
		}
	}
}

void display(HEAD* h)
{
	NODE* pres = h->head;
	printf("Value\tPriority\n");
	while(pres!=NULL)
	{
		printf("%d\t%d\n",pres->data,pres->priority);
		pres=pres->link;
	}	
}

void dequeue(HEAD* h)
{
	NODE* temp=h->head;
	h->head = h->head->link;
	free(temp);temp=NULL;	
}
//telephone Directory 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <stdio_ext.h>

typedef struct information
{
        char name[30];
        char phone_number[15];
        char address[500];
        char area[100];
}INFO;

typedef struct node
{
	INFO info;
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

int main()
{
	HEAD h;h.head = NULL;
	char c;
	do
	{
		printf("Enter:\n1.To Insert front\n2.Display\n3.To close\n4.To insert rear\n5.Display reverse\n6.Delete Front\n");__fpurge(stdin);scanf("%c",&c);
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
			default: printf("Select a valid option\n");
		}
	}while(c!='3');
}


void add_rear(HEAD* h)
{
        char na[30];
        char ph[15];
        char ad[500];
        char ar[100];

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
		__fpurge(stdin);
		printf("Enter the name: ");scanf("%[^\n]s" ,na);__fpurge(stdin);
		printf("Enter the phone Number: ");scanf("%[^\n]s" ,ph);__fpurge(stdin);
		printf("Enter the address: ");scanf("%[^\n]s" ,ad);__fpurge(stdin);
		printf("Enter the area: ");scanf("%[^\n]s" ,ar);__fpurge(stdin);
		temp = (NODE*)malloc(sizeof(NODE));
		strcpy(temp->info.name,na); 
		strcpy(temp->info.phone_number,ph); 
		strcpy(temp->info.address,ad); 
		strcpy(temp->info.area,ar);                   
		pres->rlink = temp;
		temp->rlink =NULL;
		temp->llink = prev->rlink;
	}
}


void add_front(HEAD* h)
{
	char na[30];
        char ph[15];
        char ad[500];
        char ar[100];
	NODE *temp;
	__fpurge(stdin);
	printf("Enter the name: ");scanf("%[^\n]s" ,na);__fpurge(stdin);
	printf("Enter the phone Number: ");scanf("%[^\n]s" ,ph);__fpurge(stdin);
	printf("Enter the address: ");scanf("%[^\n]s" ,ad);__fpurge(stdin);
	printf("Enter the area: ");scanf("%[^\n]s" ,ar);__fpurge(stdin);
	if(h->head ==NULL)
	{
		h->head = (NODE*)malloc(sizeof(NODE));
		h->head->llink = NULL;
		h->head->rlink = NULL;
		strcpy(h->head->info.name,na); 
		strcpy(h->head->info.phone_number,ph); 
		strcpy(h->head->info.address,ad); 
		strcpy(h->head->info.area,ar); 
	}		
	else 
	{
		temp = (NODE*)malloc(sizeof(NODE));
		strcpy(temp->info.name,na); 
		strcpy(temp->info.phone_number,ph); 
		strcpy(temp->info.address,ad); 
		strcpy(temp->info.area,ar); 
		temp->rlink = h->head;
		temp->llink =NULL;
		h->head->llink = temp;
		h->head = temp;
	}
}

void display(HEAD* h)
{
	printf("\nName\tPhone Number\tAddress\tArea\n");
	NODE* pres = h->head;
	while(pres)
	{
		printf("%s\t%s\t%s\t%s\n",pres->info.name,pres->info.phone_number,pres->info.address,pres->info.area);
		pres=pres->rlink;
	}
}

void display_rev(HEAD* h)
{
	printf("\nName\tPhone Number\nAddress\nArea\n");
	NODE* pres = h->head;
	while(pres->rlink!=NULL)
		pres=pres->rlink;
	while(pres)
	{
		printf("%s\t%s\t%s\t%s\n",pres->info.name,pres->info.phone_number,pres->info.address,pres->info.area);
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


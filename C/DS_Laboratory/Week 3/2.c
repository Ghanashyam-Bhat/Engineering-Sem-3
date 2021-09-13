//Employee details

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>

typedef struct information
{
        char ssn[15];
        char name[30];
        char department[15];
        char designations[15];
        char salary[10];
        char phone_number[15];
        char age[5];
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
void delete(HEAD* h);

int main()
{
	HEAD h;h.head = NULL;
	char c;
	do
	{
		printf("Enter:\n1.To Insert front\n2.Display particular department\n3.To close\n6.Delete 58+\n");fflush(stdin);scanf("%c",&c);
		switch(c)
		{
			case '1' :add_front(&h);
						break;
			case '2' : display(&h);
						break;
			case '3' : printf("Closed\n");
						break;
			case '6' : delete(&h);
					break;
			default: printf("Select a valid option\n");
		}
	}while(c!='3');
}

void add_front(HEAD* h)
{
	char s[15];
        char na[30];
        char dep[15];
        char sa[10];
        char ph[15];
        char ag[5];
	NODE *temp;
	fflush(stdin);
	printf("Enter the ssn: ");scanf("%[^\n]s" ,s);fflush(stdin);
	printf("Enter the name: ");scanf("%[^\n]s" ,na);fflush(stdin);
	printf("Enter the department: ");scanf("%[^\n]s" ,dep);fflush(stdin);
	printf("Enter the salary: ");scanf("%[^\n]s" ,sa);fflush(stdin);
	printf("Enter the phone number: ");scanf("%[^\n]s" ,ph);fflush(stdin);
	printf("Enter the age: ");scanf("%[^\n]s" ,ag);fflush(stdin);
		
	if(h->head ==NULL)
	{
		h->head = (NODE*)malloc(sizeof(NODE));
		h->head->llink = NULL;
		h->head->rlink = NULL;
		strcpy(h->head->info.ssn,s); 
		strcpy(h->head->info.name,na); 
		strcpy(h->head->info.department,dep); 
		strcpy(h->head->info.salary,sa);
		strcpy(h->head->info.phone_number,ph);
		strcpy(h->head->info.age,ag);
	}		
	else 
	{
		temp = (NODE*)malloc(sizeof(NODE));
		strcpy(temp->info.ssn,s); 
		strcpy(temp->info.name,na); 
		strcpy(temp->info.department,dep); 
		strcpy(temp->info.salary,sa);
		strcpy(temp->info.phone_number,ph);
		strcpy(temp->info.age,ag);
		temp->rlink = h->head;
		temp->llink =NULL;
		h->head->llink = temp;
		h->head = temp;
	}
}

void display(HEAD* h)
{
	printf("\nSSN\tName\tDepartment\tSalary\tPhone Number\tAge\n");
	char dep[16];
	printf("\nEnter the department: ");fflush(stdin);scanf("%[^\n]s",dep);
	NODE* pres = h->head;
	while(pres)
	{
	if(strcmp(pres->info.department,dep)==0){
		printf("%s\t%s\t%s\t%s\t%s\t%s\n",pres->info.ssn,pres->info.name,pres->info.department,pres->info.salary,pres->info.phone_number,pres->info.age);}
		pres=pres->rlink;
	}
}

void delete(HEAD* h)
{
	if(h->head != NULL)
	{
		NODE* pres = NULL;
		NODE* prev=h->head;
		if (h->head->rlink!=NULL)
			pres = prev->rlink;
		if(atoi(h->head->info.age)>58)
		{
			h->head->rlink = prev->rlink;
			prev->rlink->llink = h->head;
			h->head = prev->rlink;
			free(prev);
			prev= NULL;
			prev = h->head;
			pres = NULL;
			if(prev->rlink!=NULL)
				pres = prev->rlink;
		}
		while(pres!=NULL)
		{	
			if(atoi(pres->info.age)>58)
			{
				prev->rlink = pres->rlink;
				pres->rlink->llink = prev;
				prev = pres->rlink;
				free(pres);
				pres= NULL;
				pres = prev->rlink;
			}
			prev = pres;
			pres = pres->rlink;
		}
	}
	else{
		
		printf("No elements\n");
	}
}
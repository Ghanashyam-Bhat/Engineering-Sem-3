#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct subject
{
	char sub_name[50];
	char sub_code[50];
	int marks;
}SUB;
typedef struct info
{
	char SRN[50];
	char name[50];
	int sem;
	SUB subjects[5];
	struct info* link;
}INFO;
typedef struct head
{
	INFO *head;
}HEAD;
int input(HEAD* h);
float avg(HEAD* h ,int n);
void display(HEAD* h,int n);
void sort(HEAD* h,int n);

int main()
{
	HEAD h;
	h.head = NULL;
	int n= input(&h);
	float average = avg(&h,n);
	printf("Average marks of the class for the subject is: %.2f",average);
	sort(&h,n);
}

int input(HEAD* h)
{
	int n;
	INFO *temp,*pres;
	printf("Enter number of students: ");fflush(stdin);scanf("%d",&n);
	for(int i=0; i<n;i++)
	{
		printf("Student %d:",i+1);
		pres=h->head;
		temp =(INFO*) malloc(sizeof(INFO));
		printf("\n\nEnter student SRN: ");fflush(stdin);scanf("%[^\n]s",temp->SRN);
		printf("Enter student name: ");fflush(stdin);scanf("%[^\n]s",temp->name);
		printf("Enter Semester: ");fflush(stdin);scanf("%d",&temp->sem);
		for(int j=0;j<5;j++)
		{
			printf("Subject: %d\n",j+1);
			printf("Enter subject name: ");fflush(stdin);scanf("%[^\n]",temp->subjects[j].sub_name);
			printf("Enter subject code: ");fflush(stdin);scanf("%[^\n]",temp->subjects[j].sub_code);
			printf("Enter marks: ");fflush(stdin);scanf("%d",&temp->subjects[j].marks);
		}
		h->head = temp;
		temp->link = pres;
	}
	return n;
}

float avg(HEAD* h ,int n)
{
	char code[50];
	INFO* pres = h->head;
	int x=0,total=0;
	
	printf("Enter the subject code of which average is to be calculated: ");fflush(stdin);scanf("%s",code);
	for(int i=0;i<n&&(pres!=NULL);i++)
	{
		for(int j=0;j<5;j++)
		{
			if(strcmp(code,pres->subjects[j].sub_code)==0)
			{
				total+=pres->subjects[j].marks;
				x++;
			}
		}
		pres = pres->link;
	}
	return (float)total/x;
}

void sort(HEAD* h,int n)
{
	INFO temp;
	INFO* pres,*t,*t1;
	for(int i=0;i<n-1;i++)
	{
		pres=h->head;
		for(int j=0;j<n-i-1;j++)
		{
			if(strcmp(pres->SRN,pres->link->SRN)>0)
			{
				t = pres->link;
				t1 = pres->link->link;
				temp = *(pres);
				*(pres) = *(pres->link);
				pres->link = t;
				*(pres->link) = temp;
				pres->link->link = t1;
			}
			pres=pres->link;
		}
	}
	
	display(h,n);
}

void display(HEAD* h,int n)
{
	INFO* pres = h->head;
	for(int i=0;i< n;i++)
	{
		printf("\n\nName: %s\n",pres->name);
		printf("\nSRN: %s\n",pres->SRN);
		printf("\nSemester: %d\n",pres->sem);
		for(int j=0;j<5;j++)
		{
			printf("\nSub Name:%s\n", pres->subjects[j].sub_name);
			printf("Sub ID:%s\n", pres->subjects[j].sub_code);
			printf("Marks: %d\n", pres->subjects[j].marks);
		}
		pres = pres->link;
	}
}
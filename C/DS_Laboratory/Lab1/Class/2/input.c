#include <stdio.h>
#include <stdlib.h>
#include "head.h"


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
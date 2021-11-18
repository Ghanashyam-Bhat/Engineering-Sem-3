#include<stdio.h>
#include<stdlib.h>
#include <errno.h>
#include "PES1UG20CS153_H.h"

void read_file()
{
	int rows,cols,i,j,val;
	head = NULL;
    FILE *fp = fopen("input.txt","r");
    if (fp == NULL)
    {
        printf(" File cannot be opened\n");
		perror("MESSAGE: ");
    }
    else
    {
		fscanf(fp,"%d",&i);
		fscanf(fp,"%d",&j);
		fscanf(fp,"%d",&rows);
		fscanf(fp,"%d",&cols);
        while (!feof(fp))
        {
            for (i = 0;i<=rows;i++)
            {
                for (j = 0;j<=cols;j++)
                {
                    fscanf(fp,"%d",&val);
					if (val == 0)
						insert(i,j);
                }
            }
        }
		fclose(fp);
		rearrange();
    }    
}

void insert(int x,int y)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->link = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        node *present,*prev;
        present = head;
        prev = NULL;
        while (present != NULL)
        {
            prev = present;
            present = present->link;
        }
        temp->link = present;
        prev->link = temp;
    }
}



void swap(node* cur1, node* cur2)
{
	int temp;
	temp = cur1->x;
	cur1->x = cur2->x;
	cur2->x = temp;
	temp = cur1->y;
	cur1->y = cur2->y;
	cur2->y = temp;
}

void rearrange()
{
    node *cur1 = head;
    node *cur2 = head->link;
    while (cur1 != NULL)
    {
        while (cur2 != NULL)
        {
            if (cur1->y > cur2->y)
				swap(cur1,cur2);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
        if (cur1 != NULL)
        {
            cur2 = cur1->link;
        }
    }	
	cur1 = head;
    cur2 = head->link;
    while (cur1 != NULL)
    {
        while (cur2 != NULL && cur1->y == cur2->y)
        {
            if (cur1->x > cur2->x)
                swap(cur1,cur2);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
        if (cur1 != NULL)
        {
            cur2 = cur1->link;
        }
    }
}

void traverse()
{
    node *cur1 = head;
    node *cur2 = head->link;
    while (cur1 != NULL)
    {
        while (cur2 != NULL)
        {
			if (cur2->x == 5 && cur2->y == 8)
				break; 
			else if ((cur1->x == cur2->x && cur2->y == cur1->y + 1)||(cur2->x == cur1->x + 1 && cur1->y == cur2->y))
				cur1->link = cur2;
		cur2 = cur2->link;
        }
        cur1 = cur1->link;
        if (cur1 != NULL)
        {
            cur2 = cur1->link;
        }
    }
}

void display()
{
    node *pres = head;
    while (pres != NULL)
    {
        printf("%d  %d\n",pres->x,pres->y);
        pres = pres->link;
    }
}

void save()
{
	FILE *fp = fopen("output.txt","w");
	while (head != NULL)
    {
        fprintf(fp,"%d  %d\n",head->x,head->y);
        head = head->link;
    }
	fclose(fp);
}
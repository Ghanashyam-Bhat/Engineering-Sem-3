//Doubly eneded Queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
	char name[50];
	char date[20];
	char time[10];
}INFO;

typedef struct queue
{
	int front;
	int rear;
	int max;
	INFO* info;
}Queue;

void a_rear(Queue* Q,char* name,char* date,char* time)
{
	if(Q->rear+1 == Q->front)
		printf("No slots\n");
	else if(Q->rear != Q->max-1)
	{
		if(Q->front ==-1)
			Q->front ++;
		Q->rear ++;
		strcpy(Q->info[Q->rear].name ,name);
		strcpy(Q->info[Q->rear].date ,date);
		strcpy(Q->info[Q->rear].time ,time);
		printf("Added %s\n",name);
	}
	else if(Q->front == 0)
		printf("No slots left\n");
	else
	{
		Q->rear =0;
		strcpy(Q->info[Q->rear].name ,name);
		strcpy(Q->info[Q->rear].date ,date);
		strcpy(Q->info[Q->rear].time ,time);
		printf("Added %s\n",name);
	}
}

void d_front(Queue* Q)
{
	char name[50];
	if(Q->front != -1)
	{
		strcpy(name,Q->info[Q->front].name);
		if(Q->front ==Q->rear)
		{
			Q->front = -1;
			Q->front = -1;
		}
		else if(Q->front ==Q->max-1)
			Q->front = 0;
		else
			Q->front ++;
		printf("Removed %s's Appointment\n",name);
	}
	else
		printf("No Appointements\n");
	
}

void display(Queue* Q)
{
	printf("\n%s\t\t\t%s\t\t\t%s\n","Name","Date","Time");
	if(Q->rear >= Q->front)
	{
		for(int i=Q->front;i<=Q->rear;i++)
		{
			printf("%s\t\t%s\t\t%s\n",Q->info[i].name,Q->info[i].date,Q->info[i].time);
		}
	}
	else
	{
		for(int i=Q->front;i<Q->max;i++)
		{
			printf("%s\t\t%s\t\t%s\n",Q->info[i].name,Q->info[i].date,Q->info[i].time);
		}
		for(int i=0;i<=Q->rear;i++)
		{
			printf("%s\t\t%s\t\t%s\n",Q->info[i].name,Q->info[i].date,Q->info[i].time);
		}
	}
}

void a_front(Queue* Q,char* name,char* date,char* time)
{
	if(Q->front ==0)
	{
		if(Q->rear != Q->max-1)
		{
			Q->front = Q->max-1;
			strcpy(Q->info[Q->front].name ,name);
			strcpy(Q->info[Q->front].date ,date);
			strcpy(Q->info[Q->front].time ,time);
			printf("Added %s\n",name);
		}
		else
			printf("No slots\n");
	}
	else if(Q->front ==-1)
		a_rear(Q,name,date,time);
	else
	{
		if(Q->rear != Q->front-1)
		{
			Q->front --;
			strcpy(Q->info[Q->front].name ,name);
			strcpy(Q->info[Q->front].date ,date);
			strcpy(Q->info[Q->front].time ,time);
			printf("Added %s\n",name);
		}
		else
			printf("No slots\n");
		
	}
}

int main()
{
	int n;printf("Enter size of Queue: ");scanf("%d",&n);
	Queue Q;Q.front = -1;Q.rear = -1;Q.max = n;Q.info = (INFO*)malloc(n*sizeof(INFO));
	a_rear(&Q,"John Smith","11/12/2003","15:32");
	a_front(&Q,"Angelina Juli","09/04/2003","15:32");
	d_front(&Q);
	a_rear(&Q,"Mr. Robot","04/04/2004","15:32");
	a_rear(&Q,"Jadoo alien","22/05/2005","15:32");
	a_rear(&Q,"Rohit Mehra","03/08/2006","15:32");
	a_front(&Q,"Hruthik Roshan","07/08/2001","15:32");
	a_rear(&Q,"Selmon Boi","03/08/2008","15:32");
	display(&Q);
}
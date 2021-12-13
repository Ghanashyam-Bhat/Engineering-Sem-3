#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PES1UG20CS153_H.h"

void reverse(Node* base[],int max_r)
{
	
	Node *prev,*pres,*next;
	for(int i=0;i<=max_r;i++)
	{
		
		prev = NULL;pres=base[i];next=base[i]->left;
		while(next!=NULL)
		{
			pres->left = prev;
			prev = pres;
			pres=next;
			next=next->left;
		}
		pres->left = prev;
		base[i] = pres;
	}

}

void search_path(Node* base[],int i,int j,Stack* S,int max_r,int max_f)
{
	
	Node* pres = base[i];
	while(pres!=NULL && pres->y<j)
		pres=pres->left;
	if (pres==NULL)
	{
		pop(S);
		pop(S);
		pop(S);
		return;
	}
	push(S,pres->id);
	if (pres->y == j)
	{
		if(pres->x==max_r && pres->y==max_f)
		{
			printf("\nPath Found\n");
			end_of_dfs(S);
			return;
		}
		else if(pres->x>max_r ||pres->y>max_f)
			return;
		else 
		{
			
			if (pres->x<max_r)
			{
				push(S,pres->x+1);
				push(S,pres->y);
				search_path(base,pres->x+1,pres->y,S,max_r,max_f);
				//printf("%d %d\n",pres->x+1,pres->y);
			}
			
			if (pres->y<max_f)
			{	push(S,pres->x);
				push(S,pres->y+1);
				search_path(base,pres->x,pres->y+1,S,max_r,max_f);
				//printf("%d %d\n",pres->x,pres->y+1);
			}			
		}
	}
	pop(S);
	pop(S);
	pop(S);
	return;
}

void initialize(Stack* S,int size)
{
	S->top = -1;
	S->maxsize = size;
	S->arr = (int*)malloc(size*sizeof(int));
}

void push(Stack* S, int ele)
{
	if(!isFull(S))
	{
		S->top ++;
		S->arr[S->top] = ele;
	}
	else
		printf("Stack Overflow\nCould not push the element\n");
}

int isFull(Stack* S)
{
	if(S->top ==S->maxsize-1)
		return 1;
	else
		return 0;
}

int pop(Stack* S)
{
	int ele;
	if(!isEmpty(S))
	{
		ele = S->arr[S->top] ;
		S->top --;
		return ele;
	}
	else
	{
		printf("Stack Underflow....No element to be removed. Returning -1");
		return -1;
	}
}

int isEmpty(Stack* S)
{
	if(S->top==-1)
		return 1;
	else 
		return 0;
}

void end_of_dfs(Stack* S)
{
	printf("The path from the starting point to ending point: \n");
	FILE* op = fopen("outdfs.txt","w");
	FILE* op2 = fopen("outbfs.txt","w");
	for (int i=0;i<S->top;i++)
	{
		fprintf(op,"(%d,",S->arr[i]);
		fprintf(op2,"(%d,",S->arr[i]);
		printf("(%d,",S->arr[i]);
		i++;
		fprintf(op,"%d) --> ",S->arr[i]);
		fprintf(op2,"%d) --> ",S->arr[i]);
		printf("%d) --> ",S->arr[i]);
		i++;
		fprintf(op,"%d\n",S->arr[i]);
		fprintf(op2,"%d\n",S->arr[i]);
		printf("%d\n",S->arr[i]);
	}
	fclose(op);
	fclose(op2);
	exit(0);
}



void init(Queue* Q, int n)
{
	Q->front = -1;
	Q->rear = -1;
	Q->qsize = n;
	Q->data = (int*)malloc(n*sizeof(int));
}

int isFullQ(Queue* Q)
{
	if(Q->rear+1 == Q->front)
		return 1;
	else if(Q->rear==Q->qsize-1 && Q->front ==0)
		return 1;
	return 0;
}

int isEmptyQ(Queue* Q)
{
	if(Q->front == -1)
		return 1;
	return 0;
}


void enqueue(Queue* Q , int ele)
{
	if(isFullQ(Q))
	{
		printf("Queue is Full..cannot enqueue\n");
		return ;
	}
	else
	{
		if(Q->rear != Q->qsize-1)
			Q->rear ++;
		else
			Q->rear = 0;
		Q->data[Q->rear] = ele;
		
		if(isEmptyQ(Q))
			Q->front ++;
	}
}

void display(Queue* Q)
{
	if(isEmptyQ(Q))
	{
		printf("\nQueue is Empty\n");
		return ; //Returning NULL
	}
	else if(Q->front <= Q->rear)
	{
		for(int i=Q->front;i<=Q->rear;i++)
		{
			printf("%d\t",Q->data[i]);
		}
	}
	else
	{
		for(int i=Q->front;i<=Q->qsize-1;i++)
		{
			printf("%d\t",Q->data[i]);
		}
		for(int i=0;i<=Q->rear;i++)
		{
			printf("%d\t",Q->data[i]);
		}
	}
	printf("\n");
}

int dequeue(Queue* Q)
{
	int ele;
	if(isEmptyQ(Q))
	{
		printf("\nQueue is Empty. Cannot Dequeue\n");
		return -1;
	}
	ele = Q->data[Q->front];
	if(Q->front == Q->rear)
	{
		Q->front = -1;
		Q-> rear = -1;
		return ele;
	}
	if(Q->front != Q->qsize-1)
		Q->front++ ;
	else 
		Q->front = 0;
	return ele;
}
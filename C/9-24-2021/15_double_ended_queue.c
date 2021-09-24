//Double Ended Queue

/*

Insert front
Insert rear
Delete front
Delete rear
					+ It should be circular queue
*/


#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int front;
	int rear;
	int qsize;
	int* data;
};
typedef struct queue Queue;

void init(Queue* Q, int n);
int isFull(Queue* Q);
int isEmpty(Queue* Q);
void display(Queue* Q);
void insert_rear(Queue* Q , int ele);
int delete_front(Queue* Q);

int main()
{
	int size,ele;printf("\nEnter size of Queue: ");scanf("%d",&size);
	Queue Q;
	init(&Q,size);
	
}

void init(Queue* Q, int n)
{
	Q->front = -1;
	Q->rear = -1;
	Q->qsize = n;
	Q->data = (int*)malloc(n*sizeof(int));
}

int isFull(Queue* Q)
{
	if(Q->rear+1 == Q->front)
		return 1;
	else if(Q->rear==Q->qsize-1 && Q->front ==0)
		return 1;
	return 0;
}

int isEmpty(Queue* Q)
{
	if(Q->front == -1)
		return 1;
	return 0;
}

void display(Queue* Q)
{
	if(isEmpty(Q))
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

void insert_rear(Queue* Q , int ele)  //Enqueue of Normal Circular Queue
{
	if(isFull(Q))
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
		
		if(isEmpty(Q))
			Q->front ++;
	}
}


int delete_front(Queue* Q) //Dequeue of normal circular Queue
{
	int ele;
	if(isEmpty(Q))
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
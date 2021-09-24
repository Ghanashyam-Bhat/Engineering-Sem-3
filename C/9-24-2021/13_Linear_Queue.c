//Linear Queue 

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
void enqueue(Queue* Q , int ele);
void display(Queue* Q);
int dequeue(Queue* Q);

int main()
{
	int size,ele;printf("\nEnter size of Queue: ");scanf("%d",&size);
	Queue Q;
	init(&Q,size);
	enqueue(&Q , 10);
	display(&Q);
	enqueue(&Q , 20);
	display(&Q);
	enqueue(&Q , 30);
	display(&Q);
	ele = dequeue(&Q);
	printf("Dequeued element is %d\n",ele);
	display(&Q);
	ele = dequeue(&Q);
	printf("Dequeued element is %d\n",ele);
	display(&Q);
	enqueue(&Q , 40);
	display(&Q);
	enqueue(&Q , 50);
	display(&Q);
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
	if(Q->rear == Q->qsize-1)
		return 1;
	return 0;
}

int isEmpty(Queue* Q)
{
	if(Q->front == -1)
		return 1;
	return 0;
}


void enqueue(Queue* Q , int ele)
{
	if(isFull(Q))
	{
		printf("Queue is Full..cannot enqueue\n");
		return ;
	}
	else
	{
		Q->rear ++;
		Q->data[Q->rear] = ele;
		
		if(isEmpty(Q))
			Q->front ++;
	}
}

void display(Queue* Q)
{
	if(isEmpty(Q))
	{
		printf("\nQueue is Empty\n");
		return ; //Returning NULL
	}
	for(int i=Q->front;i<=Q->rear;i++)
	{
		printf("%d\t",Q->data[i]);
	}
	printf("\n");
}

int dequeue(Queue* Q)
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
	Q->front++ ;
	return ele;
}
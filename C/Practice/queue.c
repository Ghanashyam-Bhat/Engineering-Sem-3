#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int front;
	int rear;
	int max;
	int* data;
}Queue;

void enqueue(Queue* Q,int ele)
{
	if(Q->rear != Q->max-1)
	{
		if(Q->front ==-1)
			Q->front ++;
		Q->rear ++;
		Q->data[Q->rear] = ele;
		printf("Enqueued %d\n",ele);
	}
	else
		printf("No space in Queue\n");
}

void dequeue(Queue* Q)
{
	int va;
	if(Q->front != -1)
	{
		va = Q->data[Q->front];
		if(Q->front ==Q->rear)
		{
			Q->front = -1;
			Q->front = -1;
		}
		else
			Q->front ++;
		printf("Dequeued %d\n",va);
	}
	else
		printf("No element to Dequeue\n");
	
}

int main()
{
	int n;printf("Enter size of Queue: ");scanf("%d",&n);
	Queue Q;Q.front = -1;Q.rear = -1;Q.max = n;Q.data = (int*)malloc(n*sizeof(int));
	enqueue(&Q,10);
	enqueue(&Q,11);
	enqueue(&Q,12);
	dequeue(&Q);
	enqueue(&Q,13);
	enqueue(&Q,14);
	enqueue(&Q,15);
}
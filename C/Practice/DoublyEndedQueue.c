//Doubly eneded Queue
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int front;
	int rear;
	int max;
	int* data;
}Queue;

void a_rear(Queue* Q,int ele)
{
	if(Q->rear+1 == Q->front)
		printf("No space in Queue\n");
	else if(Q->rear != Q->max-1)
	{
		if(Q->front ==-1)
			Q->front ++;
		Q->rear ++;
		Q->data[Q->rear] = ele;
		printf("Enqueued %d\n",ele);
	}
	else if(Q->front == 0)
		printf("No space in Queue\n");
	else
	{
		Q->rear =0;
		Q->data[Q->rear] = ele;
		printf("Enqueued %d\n",ele);
	}
}

void a_front(Queue* Q,int ele)
{
	if(Q->front ==0)
	{
		
		if(Q->rear != Q->max-1)
		{
			Q->front = Q->max-1;
			Q->data[Q->max-1] = ele;
			printf("Enqueued %d\n",ele);
		}
		else
			printf("No space in Queue\n");
	}
	else if(Q->front ==-1)
		a_rear(Q,ele);
	else
	{
		if(Q->rear != Q->front-1)
		{
			Q->front --;
			Q->data[Q->front] = ele;
			printf("Enqueued %d\n",ele);
		}
		else
			printf("No space in Queue\n");
		
	}
}

void d_front(Queue* Q)
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
		else if(Q->front ==Q->max-1)
			Q->front = 0;
		else
			Q->front ++;
		printf("Dequeued %d\n",va);
	}
	else
		printf("No element to Dequeue\n");
	
}

void d_rear(Queue* Q)
{
	int va;
	if(Q->front != -1)
	{
		va = Q->data[Q->rear];
		if(Q->front ==Q->rear)
		{
			Q->front = -1;
			Q->front = -1;
		}
		else if(Q->rear ==0)
			Q->rear = Q->max-1;
		else
			Q->rear --;
		printf("Dequeued %d\n",va);
	}
	else
		printf("No element to Dequeue\n");
}

void display(Queue* Q)
{
	if(Q->rear >= Q->front)
	{
		for(int i=Q->front;i<=Q->rear;i++)
		{
			printf("%d\t",Q->data[i]);
		}
	}
	else
	{
		for(int i=Q->front;i<Q->max;i++)
		{
			printf("%d\t",Q->data[i]);
		}
		for(int i=0;i<=Q->rear;i++)
		{
			printf("%d\t",Q->data[i]);
		}
	}
}

int main()
{
	int n;printf("Enter size of Queue: ");scanf("%d",&n);
	Queue Q;Q.front = -1;Q.rear = -1;Q.max = n;Q.data = (int*)malloc(n*sizeof(int));
	a_rear(&Q,11);
	a_rear(&Q,12);
	a_rear(&Q,13);
	a_rear(&Q,14);
	d_front(&Q);
	a_rear(&Q,15);
	a_rear(&Q,16);
	a_rear(&Q,17);
	d_front(&Q);
	d_front(&Q);
	d_front(&Q);
	a_front(&Q,55);
	a_front(&Q,56);
	a_front(&Q,57);
	d_rear(&Q);
	display(&Q);
}
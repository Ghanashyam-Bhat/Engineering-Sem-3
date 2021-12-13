#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct queue
{
	int front;
	int rear;
	int qdata[MAX];
}Queue;
void initq(Queue *Q)
{
	Q->front=-1;
	Q->rear=-1;

}
void enqueue(Queue *Q,int src)
{
	if(Q->rear==MAX-1)
	{
		printf("\nQueue is full\n");
		exit(0);
	}
	Q->rear++;
	if(Q->front==-1)
		Q->front++;
	Q->qdata[Q->rear]=src;
}
int isEmpty(Queue *Q)
{
	if(Q->front == -1)
		return 1;
	return 0;
}
int dequeue(Queue *Q)
{
	int ele;
	if(!isEmpty(Q))
	{
		ele=Q->qdata[Q->front];
		if(Q->front == Q->rear)
		{
			Q->front=-1;
			Q->rear=-1;
			return ele;
		}
		Q->front++;
		return ele;
	}
	printf("Queue is empty");
	exit(0);
}
void bfs(int adjmat[][MAX],int src,int n,int visited[])
{
	Queue Q;
	initq(&Q);
	int ele;
	enqueue(&Q,src);
	visited[src]=1;
	while(!isEmpty(&Q))
	{
		ele=dequeue(&Q);
		for(int i=0;i<n;i++)
		{
			if(adjmat[ele][i] && visited[i]==0)
			{
				printf("\n %d--%d",ele,i);
				visited[i]=1;
				enqueue(&Q,i);//vertex i
			}
		}		
	}
}
int main()
{
	int n;
	int adjmat[MAX][MAX];
	int visited[MAX];
	printf("Enter value of n:");
	scanf("%d",&n);
	printf("Enter matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&adjmat[i][j]);
			visited[i]=0;
		}
	}
	bfs(adjmat,0,n,visited);
}

/*

0 1 1 0 0 0 0 
1 0 1 0 0 0 0 
1 1 0 1 0 0 0 
0 0 1 0 1 0 0 
0 0 0 0 0 0 0 
0 0 0 0 1 0 1 
0 0 0 0 1 1 0

*/
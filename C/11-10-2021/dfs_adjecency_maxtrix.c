//Dept First Search
#include <stdio.h>
#define MAX 10


void dfs(int adjmat[][MAX],int visited[],int src,int n)
{
	int i;
	visited[src] = 1;
	for(int i=0;i<n;i++)
	{
		if((adjmat[src][i]==1)&&(visited[i]==0))
			dfs(adjmat,visited,i,n);
	}
}

int main()
{
	int n;
	int adjmat[MAX][MAX],visited[MAX];
	printf("\nEnter the number of Vertices in the graph: ");
	scanf("%d",&n);
	printf("\n Enter the ajecency matrix: ");
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&adjmat[i][j]);
		visited[i] = 0;
	}
	dfs(adjmat,visited,0,n);
	int i=0;
	for(;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n Disconnected Graph");
			break;
		}
	}
	if(i==n)
		printf("Connected Graph");
}
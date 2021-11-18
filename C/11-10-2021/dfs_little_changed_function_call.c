//Dept First Search : Counting number of connections
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
	int n=7;
	int adjmat[MAX][MAX] = {{0,1,1,0,0,0,0},
					 {1,0,1,0,0,0,0},
					 {1,1,0,1,0,0,0},
					 {0,0,1,0,1,0,0},
					 {0,0,0,0,0,0,0},
					 {0,0,0,0,1,0,1},
					 {0,0,0,0,1,1,0}};
	int visited[MAX] = {0,0,0,0,0,0,0};
	
	
	/*printf("\nEnter the number of Vertices in the graph: ");
	scanf("%d",&n);
	printf("\n Enter the ajecency matrix: ");
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&adjmat[i][j]);
		visited[i] = 0;
	}*/
	
	int i=0,cc=0;
	for(;i<n;i++)
	{
		if(visited[i]==0)
		{
			cc++;
			dfs(adjmat,visited,i,n);
		}
	}
	if(cc==1)
		printf("Connected Graph");
	else
		printf("Number of connected components are %d",cc);
}
//Dept First Search : Counting number of connections
#include <stdio.h>
#define Max 10

void dfs(int adjmat[][Max],int visited[],int src,int n)
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
	int n,i;
	int adjmat[Max][Max];
    int visited[Max];
	printf("\nEnter the number of vertices in the graph:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:");
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjmat[i][j]);
            visited[i]=0;
        }
    }
	
	i=0;
	int cc=0;
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


//WAP to represent undirected graph using adjacency list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int v;
	struct node *link;
};

typedef struct node Node;

struct graph
{
	int numv;
	Node **Adjlist;
};

typedef struct graph Graph;


void creategraph(Graph *G,int n)
{
	G->numv=n;
	G->Adjlist=(Node **)malloc(n*sizeof(Node *));
	for(int i=0;i<n;i++)
	{
		G->Adjlist[i]=NULL;
	}
}

void Addedge(Graph* G,int fromv,int tov)
{
	Node *newnode;
	newnode=(Node*)malloc(sizeof(Node));
	newnode->v=tov;
	newnode->link=G->Adjlist[fromv];
	G->Adjlist[fromv]=newnode;
	newnode=(Node*)malloc(sizeof(Node));
	newnode->v=fromv;
	newnode->link=G->Adjlist[tov];
	G->Adjlist[tov]=newnode;// as it an undirected graph

}

void printgraph(Graph G)
{
	Node *temp=NULL;	

	for(int i=0;i<G.numv;i++)
	{
		printf("\nAdjacency list of vertex %d: ",i);
		temp=G.Adjlist[i];
		while(temp!=NULL)
		{
			printf("%d  ",temp->v);
			temp=temp->link;
		}
	}
}

void dfs(Graph G,int src,int *visited)
{
	Node *cur;
	cur=G.Adjlist[src];
	visited[src]=1;
	printf("\nVisited %d",src);
	while(cur!=NULL)
	{
		src=cur->v;
		if(visited[src]==0)
		{
			dfs(G,src,visited);
		}
		
		cur=cur->link;
	}

}

int main()
{
	Graph G;
	int n,e;
	int fromv,tov;
	printf("\nEnter the number of vertices in the graph: ");
	scanf("%d",&n);
	creategraph(&G,n);
	printf("\nEnter the number of edges in the graph: \n");
	scanf("%d",&e);
	for(int i=0;i<e;i++)
	{
		printf("Enter the from vertice: ");
		scanf("%d",&fromv);
		printf("\nEnter the to vertice: ");
		scanf("%d",&tov);
		Addedge(&G,fromv,tov);
	}
	printgraph(G);
	int src=0;
	int visited[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	printf("\nDFS TRAVERSAL");
	dfs(G,src,visited);
	
	return 0;
}
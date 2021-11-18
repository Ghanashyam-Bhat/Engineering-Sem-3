//Write a program to reprasent undrirected graph using adjecency list
//Here, for an array of pointers linked lists will be attached

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int v;
	struct node* link;
}Node;

typedef struct graph{
	int numv;
	Node **Adjlist;
}Graph;

void creategraph(Graph* G,int n);
void Addedge(Graph *G,int fromv,int tov);
void printgraph(Graph G);

int main()
{
	Graph G;
	int n,e,fromv,tov;
	printf("\n Enter the number of Vertices in the graph: ");scanf("%d",&n);
	
	creategraph(&G,n);
	
	printf("\nNumber of edges in the graph: ");scanf("%d",&e);
	for(int i=0;i<e;i++)
	{
		printf("Enter the from and to vertices: ");scanf("%d %d",&fromv,&tov);
		Addedge(&G,fromv,tov);
	}	
	
	printgraph(G);
}

void Addedge(Graph *G,int fromv,int tov)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->v = tov;
	newnode->link = G->Adjlist[fromv];
	G->Adjlist[fromv] = newnode;
	
	newnode = (Node*)malloc(sizeof(Node));
	newnode->v = fromv;
	newnode->link = G->Adjlist[tov];
	G->Adjlist[tov] = newnode;
	
}

void creategraph(Graph* G,int n)
{
	G->numv = n;
	G->Adjlist = (Node**)malloc(n*sizeof(Node*));
	for(int i=0;i<n;i++)
	{
		G->Adjlist[i] = NULL;	
	}
}

void printgraph(Graph G)
{
	Node* pres;
	for(int i=0;i<G.numv;i++)
	{
		pres = G.Adjlist[i];
		while(pres)
		{
			printf("%d\t",pres->v);
			pres = pres->link;
		}
		printf("\n");
	}
	
}
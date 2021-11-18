.#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int v;
    struct node* link;
}node;
typedef struct graph
{
    int numv;
    node **adjlist;
	int visited;
}graph;
void creategraph(graph* gp,int n)// gp refers to the Graph Pointer
{
    gp->numv=n;
    gp->adjlist=(node**)malloc(n*sizeof(node*));
    for(int i=0;i<n;i++)
    {
        gp->adjlist[i]=NULL;
    }
}
void Addedge(graph* gp,int fromv,int tov)
{
    //It is an undirected graph and hence adding of edges needs to be symmetric;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->v=tov;
    newnode->link=gp->adjlist[fromv];
    gp->adjlist[fromv]=newnode;
    node* newnode1 = (node*)malloc(sizeof(node));
    newnode1->v=fromv;
    newnode1->link=gp->adjlist[tov];
    gp->adjlist[tov]=newnode1;
}
void displaygraph(graph* gp,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d--->",i);
        node* pres = gp->adjlist[i];
        while(pres)
        {
            printf("%d-->",pres->v);
            pres=pres->link;
        }
        printf("NULL\n");
    }
}
int main()
{
    graph g;
    int n,e,fromv,tov;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    creategraph(&g,n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        printf("Enter the from and to vertices: ");
        scanf("%d %d",&fromv,&tov);
        Addedge(&g,fromv,tov);
    }
    printf("Graph Elements\n");
    displaygraph(&g,n);
	
	printf("DFS Traversal: \n");
	int src = 0
	dfs(G,src);
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 100  //preprocessing directive

struct tnode
{
	int data;
	struct tnode* lchild;
	struct tnode* rchild;
};
typedef struct tnode Node;

typedef struct tree 
{
	Node *root;
}Tree;

typedef struct q
{
	int front;
	int rear;
	Node* qdata[100];
}Queue;

void initialize(Tree* T)
{
	T->root = NULL;
}

void initq(Queue* Q)
{
	Q->front = -1;	
	Q->rear = -1;
}

int QFull(Queue *Q)
{
	if(Q->rear==MAX-1)
		return 1;
	return 0;
	
}

int QEmpty(Queue *Q)
{
	if(Q->front==-1)
		return 1;
	return 0;
}


Node* createnode(Tree* T,int data)
{
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->lchild = NULL;
	newnode->rchild =NULL;
	newnode->data = data;
	
	if(T->root==NULL)
	{
		T->root = newnode;
	}
	return newnode;
	
}


void enqueue(Queue* Q,Node* cur)
{
	if(!QFull(Q))
	{
		if(QEmpty(Q))
			Q->front++;
		Q->rear ++;
		Q->qdata[Q->rear] = cur;
		return;
	}
}

Node* dequeue(Queue *Q)
{
	if(!QEmpty(Q))
	{
		Node* cur;
		cur = Q->qdata[Q->front];
		if(Q->front==Q->rear)
		{
			Q->rear =-1;
			Q->front =-1;
			return cur;
		}
		Q->front ++;
		return cur;
	}
	printf("Done with Tree\n");
}

void createtree(Tree* T)
{
	Node*  cur;
	Queue Q;
	initq(&Q);
	int data;
	printf("\nEnter the data for root: ");
	scanf("%d",&data);
	createnode(T,data);
	enqueue(&Q,T->root);
	while(!QEmpty(&Q))
	{
		cur = dequeue(&Q);
		printf("\nEnter the left child of %d -1 for no child: ",cur->data);
		scanf("%d",&data);
		if(data!=-1)
		{
			cur->lchild = createnode(T,data);
			enqueue(&Q,cur->lchild);
		}
		
		printf("\nEnter the right child of %d -1 for no child: ",cur->data);
		scanf("%d",&data);
		if(data!=-1)
		{
			cur->rchild = createnode(T,data);
			enqueue(&Q,cur->rchild);
		}
	}
}

void preordertraversal(Node* cur,int *min)
{
	if(cur!=NULL)
	{
		printf("%d",cur->data);
		if(*min>cur->data)
			*min = cur->data;
		preordertraversal(cur->lchild,min);
		preordertraversal(cur->rchild,min);
	}
}

void Preorder(Tree *T)
{
	int min=T->root->data;
	printf("Preorder Traversal: \n");
	preordertraversal(T->root,&min);
	printf("Minimum is : %d",min);
}

int main()
{
	Tree T;
	initialize(&T);
	createtree(&T);

}
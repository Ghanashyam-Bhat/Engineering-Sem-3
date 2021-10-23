#include <stdio.h>
#include <stdlib.h>
//Traversal

void preorder(int btree[],int n,int i)
{
	if(i>=n)
		return;
	if(btree[i]!=-1)
	{
		printf("%d ",btree[i]);
		preorder(btree,n,2*i+1);
		preorder(btree,n,2*i+2);
	}
}

void inorder(int btree[],int n,int i)
{
	if(i>=n)
		return;
	if(btree[i]!=-1)
	{
		inorder(btree,n,2*i+1);
		printf("%d ",btree[i]);
		inorder(btree,n,2*i+2);
	}
}

void postorder(int btree[],int n,int i)
{
	if(i>=n)
		return;
	if(btree[i]!=-1)
	{
		postorder(btree,n,2*i+1);
		postorder(btree,n,2*i+2);
		printf("%d ",btree[i]);
	}
}

int main()
{
	int *btree;
	int n;
	printf("How many nodes: ");scanf("%d",&n);
	btree = (int*)malloc(n*sizeof(int));
	printf("Enter the root node: ");scanf("%d",&btree[0]);
	printf("Enter the node in level order and -1 for null\n");
	for(int i=0;i<n/2;i++)
	{
		if(btree[i]==-1)
		{
			continue;
		}
		else
		{
			printf("Enter the lchild of %d: ", btree[i]);
			scanf("%d",&btree[2*i+1]);
			
			if(2*i+2>= n)
			{
				continue;
			}
			else
			{
				printf("Enter the rchlid of %d: ",btree[i]);
				scanf("%d",&btree[2*i+2]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",btree[i]);
	}
	
	printf("\nPreorder\n");
	preorder(btree,n,0);
	printf("\nInorder\n");
	inorder(btree,n,0);
	printf("\nPostorder\n");
	postorder(btree,n,0);
}
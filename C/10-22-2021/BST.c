//Binary Search Tree : Time constraint =  (log n)
//BST overcomes the limitations of both trees and linked list
//All the values lesser than root lie to left and greater to root lie on right(No duplicates)
//If we do inorder Traversal in BST,it gives in ascending order

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bst
{
	int data;
	struct bst* lchild;
	struct bst* rchild;
}BST;

BST* createnode(int data)
{
	BST* newnode;
	newnode = (BST*)(malloc(sizeof(BST)));
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	newnode->data = data;
	return newnode;
}

BST* insert(BST *tree,int data)
{
	if(tree==NULL)
	{
		tree = createnode(data);
		return tree;
	}
	else if(data<tree->data)
		tree->lchild=insert(tree->lchild,data);
	else if(data>tree->data)
		tree->rchild=insert(tree->rchild,data);
	else 
		printf("\nDuplicate Value!!!\n");
	
	return tree;
}

void inorder(BST *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->data);
		inorder(root->rchild);
		
	}
	
}
BST* findmin(BST *tree)
{
	BST *min=tree;
	while(min->lchild!=NULL)
	{
		min = min->lchild;
	}
	return min;
}

BST* findmax(BST *tree)
{
	BST *max=tree;
	while(max->rchild!=NULL)
	{
		max = max->rchild;
	}
	return max;
}

BST* search(BST* root,int key)
{
	if(root ==NULL)
		return root;
	else if(root->data ==key)
		return root;
	else if(root->data >key)
		return search(root->rchild,key);
	else if(root->data <key)
		return search(root->lchild,key);
}

int main()
{
	BST *tree;tree = NULL;
	int flag =1;
	
	int data;
	while(flag)
	{
		printf("\n Enter Tree node values ....-1 to stop: ");
		scanf("%d",&data);
		if(data ==-1)
			flag = 0;
		else 
		{
			if(tree==NULL)
				tree = insert(tree,data);
			else 
				insert(tree,data);
		}
	}
	printf("Inorder Traversal: ");
	inorder(tree);
	
	BST *min=findmin(tree),*max = findmax(tree);
	printf("Minimum Element: %d \n Maximum Element: %d",min->data,max->data);
	
	/*
	printf("\nPostorder Traversal: ");
	postorder(tree);
	printf("\nPreorder Traversal: ");
	preorder(tree);
	*/
	
	//For Searching We can use Binary search
	int key;printf("Enter number: ");scanf("%d",&key);
	BST* x = search(tree,key);
	if(x!=NULL)
	{
		printf("%d",x->data);
	}
	else
	{
		printf("%d",-1);
	}
	
}
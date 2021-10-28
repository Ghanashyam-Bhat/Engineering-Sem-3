//Threaded Binary Tree : Coding
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
	int lthread;
	int rthread;
};

typedef struct node Node;

Node* insert(Node *root,int ele)
{
	Node *newnode,*cur,*parent;
	if(root==NULL)
	{
		newnode = (Node*)malloc(sizeof(Node));
		newnode->data = ele ;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		newnode->rthread = true;
		newnode->lthread = true;
		return newnode;
	}
	cur = root;
	while(cur!=NULL){
		parent = cur;
		if(ele==cur->data)
		{
			printf("Dulicate Element, Hence cannot insert");
			return NULL;
		}
		else if(ele<cur->data)
		{
			if(cur->lthread==false) //It has a child
			{
				cur = cur->lchild;
			}
			else 
			{
				break;
				//Because thats the position
			}
		}
		else 
		{
			if(cur->rthread==false) //It has a child
			{
				cur = cur->rchild;
			}
			else 
			{
				break;
				//Because thats the position
			}
			
		}
	}
	//Creating newnode
	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = ele ;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->rthread = true;
	newnode->lthread = true;
	if(ele<parent->data)
	{
		newnode->rchild = parent;
		newnode->lchild = parent->lchild;
		parent->lthread = false;
		parent->lchild = newnode;
	}
	else 
	{
		newnode->lchild = parent;
		newnode->rchild = parent->rchild;
		parent->rthread = false;
		parent->rchild = newnode;
	}
}

Node *inordersuccessor(Node* cur)
{
	if(cur->rthread ==true)
		return cur->rchild;
	cur = cur->rchild;
	while(cur->lthread!=true)
	{
		cur=cur->lchild;	
	}
	return cur;
}

void inorder(Node* root)
{
	Node* cur;
	if(root==NULL)
	{
		printf("\nEmpty Tree");
		return;
	}
	cur = root;
	//To get first node to be displayed
	while(cur->lthread!=true)
		cur = cur->lchild ;
	while(cur!=NULL)
	{
		printf("%d ",cur->data);
		cur = inordersuccessor(cur);
		
	}
}

int main(){
	Node* root =NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,80);
	inorder(root);
}
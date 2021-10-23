/*
Expression Tree

Operators with highest precedence will be at the lowest part of the tree (Just like evaluating Postfix expression, but here we create Tree)
example: abc*+
Every Operator will have two children and operend will be leaf node.

When we encounter the the operator, we pop two operands from the stack and attach it as children of the operator 
then we push that subtree into Stack

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

struct exptree
{
	char data;
	struct exptree* rchild;
	struct exptree* lchild;
};
typedef struct exptree ET;

struct stack{
	int top;
	ET* sdata[MAX];
};
typedef struct stack Stack;

ET* createnode(char c)
{
	ET* newnode = (ET*)malloc(sizeof(ET));
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	newnode->data = c;
	return newnode;
}

int isOperator(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
	}
	return 0;
	
}

void initstack(Stack *S)
{
	
	S->top =-1;
}

void push(Stack* S,ET *newnode)
{
	S->top++;
	S->sdata[S->top] = newnode;
}

ET* pop(Stack* S)
{
	ET* temp;
	temp = S->sdata[S->top];
	S->top --;
	return temp;
	
}

ET* createETree(char *postfix)
{
	Stack S;initstack(&S);
	int length = strlen(postfix);
	ET *root, *newnode;
	for(int i=0;i<length;i++)
	{
		newnode = createnode(postfix[i]);
		if(!isOperator(postfix[i]))
		{
			//Operand
			push(&S,newnode);
		}
		else
		{
			newnode->rchild = pop(&S);
			newnode->rchild = pop(&S);
			push(&S,newnode);
		}
	}
	root = pop(&S);
	return root;
}

void inorder(ET* E)
{
	if(E!=NULL)
	{
		inorder(E->lchild);
		printf("%c ",E->data);
		inorder(E->rchild);
	}
	
}

float evaluate(ET* node)
{
	float lresult,rresult;
	if(node==NULL)
		return 0;
	if(node->lchild==NULL && node->rchild==NULL)
		return node->data-'0' ;//To get int value from char
	lresult = evaluate(node->lchild);
	rresult = evaluate(node->rchild);	
	if(node->data=='+')
		return lresult+rresult;
	if(node->data=='-')
		return lresult-rresult;
	if(node->data=='*')
		return lresult*rresult;
	if(node->data=='/')
		return lresult/rresult;
}

int main()
{
	ET* E;
	char postfix[]="abc*+";
	E = createETree(postfix);
	printf("\nInorder Traversal: ");
	inorder(E);
}

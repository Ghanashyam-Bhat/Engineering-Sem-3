#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int max;
	int top;
	int *data;
};
typedef struct stack Stack;

int notFUll(Stack* S)
{
	if(S->max -1 != S->top)
		return 1;
	return 0;
}

int notEmpty(Stack* S)
{
	if(S->top != -1)
		return 1;
	return 0;
}

void push(Stack* S,int ele)
{
	if(notFUll(S))
	{
		S->top ++;
		S->data[S->top] = ele;
		printf("Pushed %d\n",S->data[S->top]);
	}
	else
		printf("Stack is Full\n");
}

void pop(Stack* S)
{
	if(notEmpty(S))
	{
		printf("Popped %d\n",S->data[S->top]);
		S->top --;
	}
	else
		printf("Stack is Empty\n");
}



int main()
{
	int n,ele;printf("Enter the size of stack: ");scanf("%d",&n);
	Stack S;S.data = (int*)malloc(n*sizeof(Stack));S.max = n;S.top = -1;
	push(&S,5);
	push(&S,6);
	push(&S,7);
	push(&S,8);
	push(&S,9);
	pop(&S);
	push(&S,10);
	push(&S,11);
	pop(&S);
	pop(&S);
	
}
//When there is Stack Full condition, increase the size of stack using Realloc
//Double the size whenever there is overflow
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int *arr;
	int top ;
	int maxsize;
};
typedef struct stack Stack;

void initialize(Stack* S,int size);
void push(Stack* S, int ele);
int isFull(Stack* S);
int pop(Stack* S);
int isEmpty(Stack* S);

int main()
{
	Stack S;
	int size,ele;
	printf("\n What should be the stack size: ");
	scanf("%d",&size);
	initialize(&S,size);
	
	push(&S,10);
	push(&S,15);
	push(&S,18);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d\n",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d\n",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d\n",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d\n",ele);
}

void initialize(Stack* S,int size)
{
	S->top = -1;
	S->maxsize = size;
	S->arr = (int*)malloc(size*sizeof(int));
}

void push(Stack* S, int ele)
{
	if(!isFull(S))
	{
		printf("Element pushed :%d\n",ele);
		S->top ++;
		S->arr[S->top] = ele;
	}
	else
	{
		printf("Stack Overflow\nCould not push the element\n");
		printf("Extending size\n");
		S->arr = (int*)realloc(S->arr,sizeof(int)*(S->maxsize)*2);
		S->maxsize *= 2;
		push(S,ele);
	}
}

int isFull(Stack* S)
{
	if(S->top ==S->maxsize-1)
		return 1;
	else
		return 0;
}

int pop(Stack* S)
{
	int ele;
	if(!isEmpty(S))
	{
		ele = S->arr[S->top] ;
		S->top --;
		return ele;
	}
	else
	{
		printf("Stack Underflow....No element to be removed. Returning -1");
		return -1;
	}
}

int isEmpty(Stack* S)
{
	if(S->top==-1)
		return 1;
	else 
		return 0;
}
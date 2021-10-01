//Implement Queue using Stack
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
void enque(Stack* S,Stack* aux,int ele);

int main()
{
	Stack S,aux;
	int size,ele;
	printf("\n What should be the stack size: ");
	scanf("%d",&size);
	initialize(&S,size);
	initialize(&aux,size);
	
	enque(&S,&aux,15);
	enque(&S,&aux,16);
	enque(&S,&aux,17);
	enque(&S,&aux,18);
	enque(&S,&aux,19);
	enque(&S,&aux,20);
	ele = pop(&S);
	printf("%d\n",ele);
	ele = pop(&S);
	printf("%d\n",ele);
	ele = pop(&S);
	printf("%d\n",ele);
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
		S->top ++;
		S->arr[S->top] = ele;
	}
	else
		printf("Stack Overflow\nCould not push the element\n");
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

void enque(Stack* S,Stack* aux,int ele)
{
	int temp;
	while(isEmpty(S)==0)
	{
		temp = pop(S);
		push(aux,temp);
	}
	push(S,ele);
	if(isFull(S)==0)
		printf("Enqueued %d\n",ele);
	while(isEmpty(aux)==0)
	{
		temp = pop(aux);
		push(S,temp);
	}	
}
//Stack data structure :Stack always supports first in first out

/*Various opertations can be performed on stack : like pop(removing element), push(adding element),peak(just looking for element) etc
top always points to the last element */

//top = -1 when the stack is empty
/*
struct stack
{
	int arr[20];
	int top;
};
*/
//Stack Overflow: porforming push on completely filled list 
//Stack Underflow: performing pop on empty list




//Impliment stack Data structure using Arrays
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
		printf("\nThe element removed: %d",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d",ele);
	
	ele = pop(&S);
	if (ele!=-1)
		printf("\nThe element removed: %d",ele);
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
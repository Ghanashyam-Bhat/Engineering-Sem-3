#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //Is digit function
#include <math.h>

//When we get operator, pop 2 elements from top of operand stack and perform operation and push the ans to same stack

struct stack
{
	int* operand;
	int top;
	int maxsize;
};

typedef struct stack Stack;

int isOperand(char c);
void initStack(Stack* S,int length);
void push(Stack* S, int ch);
int pop(Stack* S);
int isEmpty(Stack* S);
double evaluate(char* postfix);
int isFull(Stack* S);

int main()
{
	int i;double result;
	char postfix[50];printf("Enter the postfix expression: ");scanf("%s",postfix);
	result = evaluate(postfix);
	printf("Answer: %lf",result);
}

double evaluate(char* postfix)
{
	Stack S;
	int op1,op2;
	initStack(&S,strlen(postfix));
	for(int i=0;i<strlen(postfix);i++)
	{
		if(isOperand(postfix[i]))
		{
			push(&S,postfix[i]-'0'); //Passing number instead of ascii value
		}		
		else
		{
			op2 = pop(&S);
			op1 = pop(&S);
			switch(postfix[i])
			{
				case '+' : push(&S,op1+op2);
							break;
				case '-' : push(&S,op1-op2);
							break;
				case '*' : push(&S,op1*op2);
							break;
				case '/' : push(&S,op1/op2);
							break;
				case '^' : push(&S,pow(op1,op2));
							break;
			}
		}
	}
	return pop(&S); //The final answer
}

void initStack(Stack* S,int length)
{
	S->top = -1;
	S->operand = (int*)malloc(length*sizeof(char));
	S->maxsize = length;
}

int isOperand(char c)
{
	if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')'))  //We can also check Ascii values
		return 1;
	return 0;
}

void push(Stack* S, int ch)
{
	if(!isFull(S))
	{
		S->top ++;
		S->operand[S->top] = ch;
	}
	else
		printf("Stack Overflow\nCould not push the element\n");
}

int pop(Stack* S)
{
	int c;
	if(!isEmpty(S))
	{
		c = S->operand[S->top] ;
		S->top --;
		return c;
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

int isFull(Stack* S)
{
	if(S->top ==S->maxsize-1)
		return 1;
	else
		return 0;
}



/*
//	USING LINKED LIST
typedef struct postfix_expression
{
	char ch;
	struct postfix_expression* link;
}POST;

int main()
{
	char postfix[50];printf("Enter the postfix expression: ");scanf("%s",postfix);
	int n = strlen(postfix);
	for(int i=0;
	
}

*/
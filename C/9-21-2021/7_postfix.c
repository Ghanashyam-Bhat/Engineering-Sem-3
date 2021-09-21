//Infix-Postfix Implimentation

#include <stdio.h>
#include <stdlib.h>          //pexels.com  //shutterstock.com //pinterest.com
#include <string.h>

typedef struct stack
{
	int top;
	char* operator;
	int maxsize;
}Stack;

void infix_to_postfix(char* exp, char* postfix);
void initStack(Stack* S,int length);
int isOperand(char c);
void push(Stack* S, char ch);
int isFull(Stack* S); //TO check if Operator stack is full or not // This is optional in this case
char pop(Stack* S); //To pop last element from operator stack
char peek(Stack* S);
int isEmpty(Stack* S); //To check if operator-stack is empty or not
int isLeftAssociative(char ch);

int prec(char ch); //Precedence of operator

void main()
{
	char exp[50]; //To store infix expression
	char postfix[50]; //To store postfix expression 
	
	printf("\nEnter the infix Expression: ");
	scanf("%s",exp);
	
	infix_to_postfix(exp,postfix);
	
}

void infix_to_postfix(char* exp, char* postfix)
{
	Stack S;
	int k=0;
	initStack(&S,strlen(exp));
	for(int i=0;i<strlen(exp);i++)
	{
		if(isOperand(exp[i]))
		{
			postfix[k] = exp[i];
			k++;
		}
		else if(exp[i]=='(')
		{
			push(&S,exp[i]);
		}
		else if(exp[i]==')')
		{
			while(!isEmpty(&S) && peek(&S)!='(')
			{
				postfix[k] = pop(&S);
				k++;
			}
			if(isEmpty(&S))
			{
				printf("\nInfix Expression is not Valid\n");
			}
			pop(&S); //popping '('
		}
		else
		{
			if( !isEmpty(&S) && prec(exp[i])==prec(peek(&S)) ) //Then we have to check associativity
			{
				if(isLeftAssociative(exp[i]))
				{
					while(prec(exp[i])<prec(peek(&S)))
					{
						postfix[k] = pop(&S); //Top is decremented in pop function
						k++;
					}
				}
			}
			else 
			{
				while(!isEmpty(&S) && prec(exp[i]) < prec(peek(&S)))
				{
					postfix[k] = pop(&S);
					k++;
				}				
			}
			push(&S,exp[i]);
		}
	}

	while(!isEmpty(&S))
	{
		postfix[k] = pop(&S);
		k++;
	}
	postfix[k] = '\0';
	printf("\n Postfix Expression: %s",postfix);
}

void initStack(Stack* S,int length)
{
	S->top = -1;
	S->operator = (char*)malloc(length*sizeof(char));
	S->maxsize = length;
}

int isOperand(char c)
{
	if(!(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')'))  //We can also check Ascii values
		return 1;
	return 0;
}

void push(Stack* S, char ch)
{
	if(!isFull(S))
	{
		S->top ++;
		S->operator[S->top] = ch;
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

char pop(Stack* S)
{
	char c;
	if(!isEmpty(S))
	{
		c = S->operator[S->top] ;
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

char peek(Stack* S)
{
	char ch;
	ch = S->operator[S->top];
	return ch;
}

int prec(char ch)
{
	switch(ch)
	{
			case '+' :
			case '-' :	return 1;
			case '*' :
			case '/' : return 2;
			case '^' : return 3;
	}
	return -1;
}

int isLeftAssociative(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return 1;
	else if(ch=='^')
		return 0;
	return -1;
}
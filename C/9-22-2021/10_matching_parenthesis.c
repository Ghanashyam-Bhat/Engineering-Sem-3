//Application of stack Data Structure

//Matching of Parenthesis

//By creating the stack of opening brackets //Ignore all other charecters
//When we encounter the closing bracket we pop the top most element in stack and check if it is matching bracket or not
//On reaching  end of expression, if stack is empty, it is valid expression


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
struct stack{
	char* brackets;
	int top;
};

typedef struct stack Stack;

int isClosing(char ch);
int isOpening(char ch);
char pop(Stack* S);
int value(char ch);

int main()
{
	Stack S;int check=0;
	S.brackets = (char*)malloc(50*sizeof(char));
	S.top = -1;
	char str[50];printf("Enter the expression: ");scanf("%s",str);
	for(int i=0 ; i<strlen(str) ; i++)
	{
		if(isOpening(str[i]))
		{
			S.top ++;
			S.brackets[S.top] = str[i];
		}
		else if(  isClosing(str[i]) )
		{
			if(S.top==-1 )
			{
				printf("Invalid Expression\nNo opening Bracket to match\n");
				check ++;
				break;
			}
			else if(value(str[i]) == value(S.brackets[S.top]))
				pop(&S);
			else
			{
				printf("\nInvalid Expression\nBracket Not Matching\n");
				check ++;
				break;
			}
		}
	}
	if(S.top != -1 && check==0 )
		printf("Invalid Expression\nMore opening Bracket to match");
	else if(S.top == -1)
		printf("Expression is Valid\n");
}

char pop(Stack* S)
{
	char ch=S->brackets[S->top];
	S->top --;
	return ch;
	
}

int isOpening(char ch)
{
	switch(ch)
	{
		case '(' :
		case '[' :
		case '{' : return 1;
	}
	return 0;
}

int isClosing(char ch)
{
	switch(ch)
	{
		case ')' :
		case ']' :
		case '}' : return 1;
	}
	return 0;
}

int value(char ch)
{
	if(ch=='(' || ch==')')
		return 1;
	else if(ch=='[' || ch==']')
		return 2;
	else if(ch=='{' || ch=='}')
		return 3;	
}
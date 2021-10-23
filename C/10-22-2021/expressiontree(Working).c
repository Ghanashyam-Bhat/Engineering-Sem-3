#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct exptree{
    char data;
    struct exptree *lchild;
    struct exptree *rchild;
};
typedef struct exptree ET;
struct stack{
    int top;
    ET *sdata[MAX];
};
typedef struct stack Stack;


void initstack(Stack *S)
{
    
    S->top=-1;
}

void push(Stack *S,ET *newnode)
{
    //add stck full if needed
    S->top++;
    S->sdata[S->top]=newnode;
}

ET * pop(Stack *S)
{
    ET *temp;
    temp=S->sdata[S->top];
    S->top--;
    return temp;

}
ET * createNode(char c)
{
    ET *newnode;
    newnode=(ET *)malloc(sizeof(ET));
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    newnode->data=c;
    return newnode;
}

int isOperator(char ch)
{
    switch(ch)
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
 
ET * createETree(char *postfix)
{
    int length=strlen(postfix);
    ET *root, *newnode;
    Stack S;
    initstack(&S);
    for(int i=0;i<length;i++)
    {
        newnode=createNode(postfix[i]);
        if(!isOperator(postfix[i]))
        {
            push(&S,newnode);
        }
        else
        {
            newnode->rchild=pop(&S);
            newnode->lchild=pop(&S);
            push(&S,newnode);

        }

    }
    root=pop(&S);
    return root;


}

void inorder(ET *E)
{
    if(E!=NULL)
    {
        inorder(E->lchild);
        printf("%c ",E->data);
        inorder(E->rchild);
    }
}

float evaluate(ET *node)
{
    float lresult,rresult;

    if(node==NULL)
        return 0;
    if((node->lchild==NULL) && (node->rchild==NULL))
        return node->data-'0';
    lresult=evaluate(node->lchild);
    rresult=evaluate(node->rchild);
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
    ET *E;    
    char postfix[]="999*+";
    E=createETree(postfix);

    printf("Infix traversal\n");
    inorder(E);
    float result=evaluate(E);
    printf("\n answer %f\n",result);

}
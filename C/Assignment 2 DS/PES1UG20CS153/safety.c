#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	int x;
	int y;
	int id;
	struct node* left;
}Node;

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

void reverse(Node** base,int max_r);
void search_path(Node* base[],int i,int j,Stack* S,int max_r,int max_f);
void end_of_dfs(Stack* S);

int main()
{
	int min_r ,max_r,max_f,min_f ;
	Node* prev,*pres;
	int t,temp;
	int i,j;
	char buffer[100];
	FILE* fp;
	
	fp = fopen("input.txt","r");
	
	Stack S;
	int size,ele;
	initialize(&S,(max_r*max_r)*3+50);
	
	fgets(buffer,100,fp);
	min_r = atoi(strtok(buffer," "));
	min_f = atoi(strtok(NULL," "));
	
	fgets(buffer,100,fp);
	max_r = atoi(strtok(buffer," "));
	max_f = atoi(strtok(NULL," "));
	
	Node* base[max_r+1];
	for( int k= 0 ; k<=max_r;k++)
		base[k]=NULL;
	
	for(int m = 0;m<=max_r;m++)
	{
		fgets(buffer,100,fp);
		t = atoi(strtok(buffer," "));
		for (int n=0;n<=max_r;n++)
		{
			
			if (t==0)
			{
				prev = base[m];
				base[m] = (Node*)malloc(sizeof(Node));
				base[m]->left = prev;
				base[m]->x = m;
				base[m]->y = n;
				printf("%d %d\t",base[m]->x,base[m]->y);
			}
			else
				printf("x x\t");
			t = atoi(strtok(NULL," "));
		}		
		printf("\n");
	}
	
	reverse(base,max_r);
	
	//Id numbering
	temp = 1;
	for(int m = 0;m<=max_r;m++)
	{
		pres = base[m];
		while(pres!=NULL)
		{
			pres->id=temp;
			temp ++;
			pres=pres->left;
		}
	}
	
	push(&S,0);
	push(&S,0);
	search_path(base,min_r,min_f,&S,max_r,max_f);	
	printf("Path Not Found");
	
}

void reverse(Node* base[],int max_r)
{
	
	Node *prev,*pres,*next;
	for(int i=0;i<=max_r;i++)
	{
		
		prev = NULL;pres=base[i];next=base[i]->left;
		while(next!=NULL)
		{
			pres->left = prev;
			prev = pres;
			pres=next;
			next=next->left;
		}
		pres->left = prev;
		base[i] = pres;
	}

}

void search_path(Node* base[],int i,int j,Stack* S,int max_r,int max_f)
{
	
	Node* pres = base[i];
	while(pres!=NULL && pres->y<j)
		pres=pres->left;
	if (pres==NULL)
	{
		pop(S);
		pop(S);
		pop(S);
		return;
	}
	push(S,pres->id);
	if (pres->y == j)
	{
		if(pres->x==max_r && pres->y==max_f)
		{
			printf("\nPath Found\n");
			end_of_dfs(S);
			return;
		}
		else if(pres->x>max_r ||pres->y>max_f)
			return;
		else 
		{
			
			if (pres->x<max_r)
			{
				push(S,pres->x+1);
				push(S,pres->y);
				search_path(base,pres->x+1,pres->y,S,max_r,max_f);
				//printf("%d %d\n",pres->x+1,pres->y);
			}
			
			if (pres->y<max_f)
			{	push(S,pres->x);
				push(S,pres->y+1);
				search_path(base,pres->x,pres->y+1,S,max_r,max_f);
				//printf("%d %d\n",pres->x,pres->y+1);
			}			
		}
	}
	pop(S);
	pop(S);
	pop(S);
	return;
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

void end_of_dfs(Stack* S)
{
	FILE* op = fopen("outdfs.txt","w");
	for (int i=0;i<S->top;i++)
	{
		fprintf(op,"(%d,",S->arr[i]);
		i++;
		fprintf(op,"%d) --> ",S->arr[i]);
		i++;
		fprintf(op,"%d\n",S->arr[i]);
	}
	exit(0);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	int y;
	int value;
	struct node* link;
}NODE;

typedef struct head_node
{
	NODE* head;
}H;

void display(H* h,int m,int n);
void storage(H* h);
void new_matrix(H* h,int *x, int* y);

int main()
{
	int m,n;
	H h;h.head=NULL;
	new_matrix(&h,&m,&n);
	storage(&h);
	display(&h,m,n);
}

void display(H* h,int m,int n)
{
	NODE* pres;
	printf("\nDisplaying The matrix\n");
	pres = h->head;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(pres!=NULL && i==pres->x && j==pres->y)
			{
				printf("%d\t",pres->value);
				pres = pres->link;
			}
			else 
				printf("%d\t",0);
		}	
		printf("\n");	
	}
}

void storage(H* h)
{
	NODE* pres;
	pres = h->head;
	printf("Stored valyes:\n");
	printf("Value\tx\ty\n");
	while(pres!=NULL)
	{
		printf("%d\t%d\t%d\n",pres->value,pres->x,pres->y);
		pres = pres->link;
	}
}

void new_matrix(H* h,int* x,int* y)
{
	NODE* pres;int m,n,v;
	printf("Enter number of rows & column: ");scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Enter value for row %d and column %d: ",i+1,j+1);scanf("%d",&v);
			if(h->head ==NULL && v!=0)
			{
				h->head = (NODE*)malloc(sizeof(NODE));
				h->head->value = v;
				h->head->x = i;
				h->head->y = j;
				h->head->link = NULL;
				pres = h->head;
			}			
			else if(v!=0)
			{
				pres->link = (NODE*)malloc(sizeof(NODE));
				pres = pres->link;
				pres->value=v;
				pres->x = i;
				pres->y = j;
				pres->link = NULL;
			}
		}		
	}
	*x = m;*y = n;
}

extern edit(H* h,int m,int n)
{
	int x,y;NODE *pres=h->head,*prev=NULL,*temp;int t=0,v;
	printf("Enter the row and column number: ");scanf("%d%d",&x,&y);
	printf("Enter value for row %d and column %d: ",x,y);scanf("%d",&v);
	if(x<=m && y<= n)
	{
		while(pres!=NULL && t==0 )
		{
			if( (pres->x == x-1) && (pres->y == y-1) )
			{
				pres->value = v;
				t = 1;
			}
			else if( (pres->x) > (x-1) )
			{
				if( (pres->y) > (y-1) )
				{
					temp = (NODE*)malloc(sizeof(NODE));
					temp->value = v;
					temp->x = x-1;
					temp->y = y-1;
					if(prev ==NULL)
					{
						h->head = temp;
						temp ->link = pres;
						t = 1;
					}
					else 
					{
						prev->link = temp;
						temp ->link = pres;
						t = 1;
					}				
				}
			}
			prev = pres;
			pres = pres->link;
		}
	}
	else
	{
		printf("\nMatrix Out of range\n");
	}	
}

//In transposed matrix , row number and colum number gets swapped
//Also we have to sort using row major order //For displaying can display using column major fashion

extern transpose(H* h)
{
	int temp;
	NODE* pres = h->head;
	while(pres!=NULL)
	{
		temp = pres->x;
		pres->x = pres-> y;
		pres->y = temp;
	}
	//Keep a array to keep count of number of columns corresponding to each row in transpose matrix
	//Create a new list by giving last element of each group as first element of new list
	//Group should be selected in normal order itself because the row is already sorted
}
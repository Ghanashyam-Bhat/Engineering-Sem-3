#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial_expansion
{
	int coeff;
	int power1;
	int power2;
}POLY;

typedef struct node_of_polynimial
{
	POLY poly;
	struct node_of_polynimial* link;
}NODE;

typedef struct head_of_expansion
{
	NODE* head;
}H;

int initialize(H* h,int num);
int operation(H* h,int n);
int comb(H* h,int x,H* he,int y);
void display(H* h,int n);

int powe(int x, int n)
{
	if(n==0)
		return 1;
	else
		return x*powe(x,n-1);
}

int main()
{
	H h,he,final;
	h.head = NULL;he.head=NULL;final.head=NULL;
	int x,y,ans;int c ;
	char o;
	do
	{
		printf("\nSelect\n1.To initialize two polynimials\n2.To perform operations on polynomials\n3.To exit\n");fflush(stdin);scanf("%c",&o);
		switch(o)
		{
			case '1':x = initialize(&h,1);
					display(&h, x);
					y = initialize(&he,2);
					display(&he, y);
					c = comb(&h,x,&he,y);
					break;
						
			case '2':
			        ans =  operation(&h, x+y-c);
					printf("The answer is: %d",ans);
					break;
			case '3':printf("\nClosed");
					break;
			default:printf("\nEnter proper option");
		}
	}while(o!='3');
}

int initialize(H* h,int num)
{
	NODE *pres=NULL,*prev=NULL;
	int c,p1,p2,n = 0;
	printf("For polynomial %d\n",num);
	while(1)
	{
		printf("Enter the coefficient: ");scanf("%d",&c);
		printf("Enter power of x: ");scanf("%d",&p1);
		printf("Enter power of y: ");scanf("%d",&p2);
		if(h->head == NULL)
		{
			h->head = (NODE*)malloc(sizeof(NODE));
			h->head->poly.coeff = c;
			h->head->poly.power1 = p1;
			h->head->poly.power2 = p2;
			pres=h->head;
		}
		else 
		{
			pres->link = (NODE*)malloc(sizeof(NODE));
			pres->link->poly.coeff = c;
			pres->link->poly.power1 = p1;
			pres->link->poly.power2 = p2;
			pres = pres->link;
		}
		n++;
		if(p1==0 && p2==0)
			break;
	}
	pres->link = NULL;
	return n;
}

int operation(H* h,int n)
{
	
	int res=0;
	NODE* pres=h->head;
	for(int i=0;i<n&&pres;i++)
	{
		printf("+(%d*x^%d*y^%d)",pres->poly.coeff,pres->poly.power1,pres->poly.power2);
		pres=pres->link;
	}
	pres=h->head;
	printf("\nEnter the value of variable x: ");int x;scanf("%d",&x);
	printf("\nEnter the value of variable y: ");int y;scanf("%d",&y);
	for(int i=0;i<n&&pres;i++)
	{
		res+=pres->poly.coeff*powe(x,pres->poly.power1)*powe(y,pres->poly.power2);
		pres=pres->link;
	}
	return res;
}

int comb(H* h,int x,H* he,int y)
{
	int c = 0;
	NODE* pres=h->head, *pres2=he->head, *prev=NULL,*last;
	while(pres!=NULL)
	{
		pres2 = he->head; prev = NULL;
		while(pres2!=NULL)
		{
			if((pres->poly.power1==he->head->poly.power1 )&& (pres->poly.power2==he->head->poly.power2))
			{
				c++;
				pres->poly.coeff = pres->poly.coeff+pres2->poly.coeff;
				he ->head = he->head->link; 
				pres2 = he->head;
			}
			else if(pres2!=NULL)
			{
				if((pres->poly.power1==pres2->poly.power1 )&&( pres->poly.power2==pres2->poly.power2))
				{
					c++;
					pres->poly.coeff = pres->poly.coeff+pres2->poly.coeff;
					prev->link = pres2->link;
					pres2 = prev->link;
				}
				else
				{
					prev = pres2;
					pres2 = pres2->link;
				}
			}
		}
		last =pres;
		pres = pres->link;
	}
	last->link = he->head;
	return c;
}

void display(H* h,int n)
{
	NODE* pres=h->head;
	for(int i=0;i<n&&pres;i++)
	{
		printf("+(%d*x^%d*y^%d)",pres->poly.coeff,pres->poly.power1,pres->poly.power2);
		pres=pres->link;
	}
	printf("\n");
}
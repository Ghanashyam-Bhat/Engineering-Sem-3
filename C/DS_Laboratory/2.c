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
int comb(H* h,int x,h* he,int y);

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
		printf("\nSelect\n1.To initialize two polynimials\n2.To perform operations on polynomials\n");scanf("%c",&o);
		switch(o)
		{
			case '1':x = initialize(&h,1);
				 y = initialize(&he,2);]
				 c = comb(&h,x,&he,y);
				break;
						
			case '2':printf("Succefully taken data\n");
			        ans =  operation(&h , x+y-c);
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
	int n,x=0,y=0,c,p1,p2;NODE* temp,*pres;
	printf("Enter the degree of the polynominal w.rt. x %d: ",num);scanf("%d",&n);
	for(int i=n;i>=0;i--)
	{
		printf("Enter the coefficient: ");scanf("%d",&c);
		printf("Enter the power of x: ");scanf("%d",&p1);
		printf("Enter the power of x: ");scanf("%d",&p2);
		if(p1>i)
		{
			printf("The power is greater than the degree of polyomial\n");
			break;
		}
		else
		{
			while(p1!=i)
				i--;
			temp = (NODE*)malloc(sizeof(NODE));
			temp->poly.coeff = c;
			temp->poly.power1 = p1;
			temp->link = NULL;
			x++;
		}
		if(h->head==NULL)
			h->head = temp;
		else
		{
			pres = h->head;
			while(pres->link)
			{
				pres=pres->link;
			}
			pres->link=temp;
		}
	}
	return x;
}


int operation(H* h,int n)
{
	int res=0;
	NODE* pres=h->head;
        for(int i=0;i<n&&pres;i++)
	{
		printf("+(%d*x^%d)",pres->poly.coeff,pres->poly.power);
		pres=pres->link;
	}
	pres=h->head;
	printf("\nEnter the value of variable x: ");int x;scanf("%d",&x);
	for(int i=0;i<n&&pres;i++)
	{
		res+=pres->poly.coeff*powe(x,pres->poly.power);
		pres=pres->link;
	}
	return res;
}

int comb(H* h,int x,h* he,int y)
{




}


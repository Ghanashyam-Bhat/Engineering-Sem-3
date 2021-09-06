#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
 int info;
 struct node* link;
}NODE;

typedef struct head_node
{
        NODE* head;
}H;
void swap(H* h,int k,int l, int n);
void delete(H* h,int n);

int main()
{

        H h;int k,l;
        printf("Enter Number of elements: ");
        int n;
        scanf("%d",&n);
        if(n>0)
        {
                h.head = NULL;
                printf("Enter data %d: ",1);
                h.head = (NODE*)malloc(sizeof(NODE));
                scanf("%d",&(h.head->info));
                NODE* pres = h.head;
                for(int i=0 ;i<n-1;i++)
                {
                        pres->link = (NODE*)malloc(sizeof(NODE));
                        printf("Enter data %d: ",i+2);
                        scanf("%d",&(pres->link->info));
                        pres = pres->link;
                }
                pres->link= NULL;
                printf("Enter elements to be swapped: ");scanf("%d%d",&k,&l);
                if(k<=n && l<=n)
                {
                        swap(&h,k,l,n);
                        pres = h.head;
                        for(int i=0 ;i<n;i++)
                        {
                                printf("%d\n",(pres->info));
                                if(pres)
                                        pres = pres->link;
                        }
                }
                printf("***\n");
                delete(&h,n);
                 pres = h.head;
                while(pres!=NULL)
                {
                        printf("%d\n",(pres->info));
                        pres = pres->link;
                }
        }
}

void swap(H* h,int k,int l, int n)
{
	NODE* pres1=NULL , *prev1=NULL , *pres2=NULL , *prev2=NULL,*pres = h->head,*prev = NULL,*temp;
	for(int i=0;i<n && (pres1==NULL || pres2==NULL) && pres!=NULL; i++)
	{
	        if(i==k-1)
	        {
	                pres1 = pres;
	                prev1 = prev;
	        }
	        if(i==l-1)
	        {
	                pres2 = pres;
	                prev2 = prev;
	        }
                prev = pres;
	        pres = pres->link;
	       
	}
	if(prev1 && prev2)
	{
	
	        prev1->link = pres2;
	        prev2->link = pres1;
	        temp = pres2->link;
	        pres2->link = pres1->link;
	        pres1->link = temp;
	}
	else if(prev1)
	{
	        prev1->link = pres2;
	        h->head = pres1;
	        temp = pres2->link;
	        pres2->link = pres1->link;
	        pres1->link = temp;
	}
	else if(prev2)
	{
	        h->head->link = pres2;
	        prev2 = pres1;
	        temp = pres2->link;
	        pres2->link = pres1->link;
	        pres1->link = temp;
	}
}


void delete(H* h,int n)
{

     NODE* pres = h->head,*prev = NULL;
        for(int i=0;i<n && pres;i++)
        {
                if(i%2==0)
                {
                        if(prev==NULL)
                        {
                                h->head = h->head->link;
                                free(pres);
                                pres = h->head;
                        }
                        else
                        {
                        
                                prev->link = pres->link;
                                free(pres);
                                pres = prev->link;
                        }
                        
                }
                else
                {
                        prev = pres;
                        pres = pres->link;
                
                }
        }
}

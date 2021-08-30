#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void count_nodes(struct node*);

int main()
{
    
    int n;
    printf("Enter the number of values you want to enter:");
    scanf("%d", &n);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    
    printf("\nEnter the values:");
	struct node *pres = head;
    for (int i = 0; i < n; i++)
    {
        struct node *next = (struct node*)malloc(sizeof (struct node)); //allocating memory to each node.
        next->link=NULL;
        scanf("%d", &next->data);
        pres->link = next;
        pres = next;
    }
    count_nodes(head);
    
}
void count_nodes(struct node *head)
{
    int count=0;
    if (head->link == NULL)
    {
        printf("\nLinked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head->link;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("\n\n Number of NODES: %d",count);    
}
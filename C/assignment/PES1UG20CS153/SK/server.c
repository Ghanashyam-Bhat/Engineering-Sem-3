#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(START *s)
{
    s->row=0;
    s->col=0;
    s->r_link=NULL;
    s->c_link=NULL;
}

void read_map(FILE *fp,START *s)
{
    int r_no=0;
    char buffer[80];
    while(fgets(buffer,80,fp)!=NULL)
    {
        int c_no=0;
        r_no++;
        create_head_r(s,r_no-1);
        char *num=strtok(buffer," ");
        c_no++;
        if(r_no==1)
            create_head_c(s,c_no-1);
        if(atoi(num)==0)
        {
            create_node(s,r_no-1,c_no-1);
            printf("%d %d\n",r_no-1,c_no-1);
        }
        num=strtok(NULL," ");
        while(num!=NULL)
        {
            c_no++;
            if(r_no==1)
                create_head_c(s,c_no-1);
            if(atoi(num)==0)
            {
                create_node(s,r_no-1,c_no-1);
                printf("%d %d\n",r_no-1,c_no-1);
            }
            num=strtok(NULL," ");
        }
    }
}

void create_head_r(START *s,int no)
{
    s->row++;
    header *temp;
    header *new=(header*)malloc(sizeof(header));
    new->no=no;
    new->h_connect=NULL;
    new->n_connect=NULL;
    temp=s->r_link;
    if(temp==NULL)
    {
        s->r_link=new;
        return;
    }
    else
    {
        while(temp->h_connect!=NULL)
        {
            temp=temp->h_connect;
        }
        temp->h_connect=new;
        return;
    }
}

void create_head_c(START *s,int no)
{
    s->col++;
    header *temp;
    header *new=(header*)malloc(sizeof(header));
    new->no=no;
    new->h_connect=NULL;
    new->n_connect=NULL;
    temp=s->c_link;
    if(temp==NULL)
    {
        s->c_link=new;
        return;
    }
    else
    {
        while(temp->h_connect!=NULL)
        {
            temp=temp->h_connect;
        }
        temp->h_connect=new;
        return;
    }
}

void create_node(START *s,int r,int c)
{
    NODE *new=(NODE*)malloc(sizeof(NODE));
    NODE *temp;
    new->r_link=NULL;
    new->c_link=NULL;
    new->visited=0;
    new->row=r;
    new->col=c;
    header *temp1,*temp2;
    temp1=s->r_link;
    temp2=s->c_link;
    while(temp1->no!=r)
    {
        temp1=temp1->h_connect;
    }
    if(temp1->n_connect==NULL)
        temp1->n_connect=new;
    else
    {
        temp=temp1->n_connect;
        while(temp->r_link!=NULL)
        {
            temp=temp->r_link;
        }
        temp->r_link=new;
    }

    while(temp2->no!=c)
    {
        temp2=temp2->h_connect;
    }
    if(temp2->n_connect==NULL)
        temp2->n_connect=new;
    else
    {
        temp=temp2->n_connect;
        while(temp->c_link!=NULL)
        {
            temp=temp->c_link;
        }
        temp->c_link=new;
    }
}

void initialize(Q *q)
{
    q->head=NULL;
}

int traversal(START *s,Q *q,int s_r,int s_c,int d_r,int d_c)
{
    header *pos;
    NODE *cur;
    pos=s->r_link;
    if(pos->no!=s_r)
    {
        pos=pos->h_connect;
    }
    cur=pos->n_connect;
    while(cur->col!=s_c)
    {
        cur=cur->r_link;
    }
    while(cur->row!=d_r || cur->col!=d_c)
    {
        if(cur->visited==0)
        {
            if((cur->c_link!=NULL||cur->c_link==NULL) && cur->r_link!=NULL && cur->r_link->col==cur->col+1)
            {
                cur->visited=1;
                insert_node(q,cur);
                printf("(%d,%d)--->",cur->row,cur->col);
                cur=cur->r_link;
            }
            else if(cur->c_link!=NULL && (cur->r_link!=NULL||cur->r_link==NULL) && cur->c_link->row==cur->row+1)
            {
                cur->visited=1;
                insert_node(q,cur);
                printf("(%d,%d)--->",cur->row,cur->col);
                cur=cur->c_link;
            }
            else
            {
                cur->visited=1;
                insert_node(q,cur);
                printf("(%d,%d)--->",cur->row,cur->col);
                dqueue(q);
                cur=q->head->data;
            }
        }
        else
        {
            if(cur->col==s_c,cur->row==s_r)
                return 0;
            if(cur->c_link!=NULL && cur->c_link->row==cur->row+1)
            {
                cur=cur->c_link;
            }
            else
            {
                dqueue(q);
                cur=q->head->data;
            }
        }
    }
    if(cur->col==d_c && cur->row==d_r)
    {
        insert_node(q,cur);
        printf("(%d,%d)--->",cur->row,cur->col);
        return 1;
    }
}

void insert_node(Q *q,NODE *cur)
{
    queue *temp=(queue*)malloc(sizeof(queue));
    temp->data=cur;
    temp->link=NULL;
    if(q->head==NULL)
    {
        q->head=temp;
        return;
    }
    else
    {
        queue *iter=q->head;
        q->head=temp;
        temp->link=iter;
        return;
    }
}

void dqueue(Q *q)
{
    queue *temp=q->head;
    q->head=temp->link;
    free(temp);
    temp=NULL;
}

void store_path(Q *q,int res)
{
    FILE *fp;
    fp=fopen("output.txt","w");
    if(res==0)
    {
        fprintf(fp,"-1");
        return;
    }
    else
    {
        print(q->head,fp);
    }
    //fprintf(fp,"%d %d\n",->row,->col);
}

void print(queue *q,FILE *fp)
{
    if(q==NULL)
    {
        return;
    }
    print(q->link,fp);
    fprintf(fp,"%d %d",q->data->row,q->data->col);
    fprintf(fp,"\n");
}
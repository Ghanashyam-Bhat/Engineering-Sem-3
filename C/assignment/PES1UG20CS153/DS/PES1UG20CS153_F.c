#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void store_path(struct node** res,int top);
void read_path(struct node** head)
{
  FILE* fp=fopen("input.txt","r");
  if(!fp)
  {
    printf("Cannot open the file");
    return;
  }
  char buffer[1024];
  int row=0,column=0,rowx=-1;
  while(fgets(buffer,1024,fp))
  {
    column=0;
    row++;
    if(row==1 || row==2)
      continue;
    rowx++;
    struct node* rnode=(struct node*)malloc(sizeof(struct node));
    rnode->down=rnode->right=NULL;
    rnode->val=rowx;
    struct node* pres=*head;
    while(pres->down!=NULL)
    {
      pres=pres->down;
    }
    pres->down=rnode;
    pres=pres->down;
    char* value = strtok(buffer," ");
    while(value && column<10)
    {
      struct node* pres_col=*head;
      if(rowx==0)
      {
        struct node* cnode=(struct node*)malloc(sizeof(struct node));
        cnode->right=cnode->down=NULL;
        cnode->val=column;
        while(pres_col->right!=NULL)
        {
          pres_col=pres_col->right;
        }
        pres_col->right=cnode;
        pres_col=cnode;
      }
      else
      {
        pres_col=pres_col->right;
        while(pres_col->val!=column)
        {
          pres_col=pres_col->right;
        }
      }
      struct node* temp= (struct node*)malloc(sizeof(struct node));
      temp->x=10;
      if(atoi(value)==0)
      {
        temp->x=rowx;
        temp->y=column;
        temp->val=atoi(value);
        temp->down=temp->right=NULL;
        pres->right=temp;
        pres=pres->right;
      }
      if(temp->x==rowx)
      {
        while(pres_col->down!=NULL)
        {
          pres_col=pres_col->down;
        }
        pres_col->down=temp;
      }
      value=strtok(NULL," ");
      column++;
    }
  }
  fclose(fp);
}

void push(struct node* temp,struct node** stk,int* top)
{
  ++(*top);
  stk[*top]=temp;
}

struct node *pop(struct node **stk,int *top)
{
  struct node* temp;
  temp=stk[*top];
  --(*top);
  return temp;
}



void find_path(struct node* head)
{
  struct node* path=NULL;
  int st_x,st_y,end_x,end_y;

  
  FILE* fp=fopen("input.txt","r");
  if(!fp)
  {
    printf("Cannot open the file");
  }
  else
  {
    char buffer[1024];
    int row=0;
    while(fgets(buffer,1024,fp))
    {
      char* value = strtok(buffer," ");
      row++;
      if(row==1)
      {
        st_x=atoi(value);
        value=strtok(NULL," ");
        st_y=atoi(value);
      }
      else if(row==2)
      {
        end_x=atoi(value);
        value=strtok(NULL," ");
        end_y=atoi(value);
      }
      else
        break;
    }
  }
  fclose(fp);
 
  struct node* target=NULL,*temp=NULL;
  struct node* row=head->down;
  struct node* col=head->right;

  while(row->val!=end_x)
    row=row->down;

  temp=row->right;

  while(temp->y!=end_y)
    temp=temp->right;

  target=temp;

  row=head->down;
  col=head->right;

  while(row->val!=st_x)
    row=row->down;

  temp=row->right;
 

  while(temp->y!=st_y)
    temp=temp->right;

  path=temp;
  int top=-1;
  int top1=-1;
  struct node* res[100];
  struct node* stk[100];
  struct node* pres=path;
  push(pres,res,&top1);
  while(pres!=target)
  {
    if(pres->right!=NULL && (pres->right->y==((pres->y)+1)))
    {
      if(pres->down!=NULL && pres->down->x==((pres->x)+1))
      {
        push(pres,stk,&top);
      }
      pres=pres->right;
      push(pres,res,&top1);
    }
    else if(pres->right==NULL)
    {
      if(pres->down!=NULL && pres->down->x==((pres->x)+1))
      {
        pres=pres->down;
        push(pres,res,&top1);
      }
      else
      {
        if(top>=0)
        {
          pres=pop(stk,&top);
          while((temp = pop(res,&top1))!=pres);
          push(pres,res,&top1);
          pres=pres->down;
          push(pres,res,&top1);
          //printf("X->%d Y->%d\n",pres->x,pres->y);
        }
        else
        {
          return;
        }
      }
    }
    else
    {
      if(pres->down!=NULL && pres->down->x==((pres->x)+1))
      {
        pres=pres->down;
        push(pres,res,&top1);
      }
      else
      {
        if(top>=0)
        {
          pres=pop(stk,&top);
          while((temp = pop(res,&top1))!=pres);
          push(pres,res,&top1);
          pres=pres->down;
          push(pres,res,&top1);
        }
        else
        {
          return;
        }
      }
    }
  }
  store_path(res,top1);
}
void store_path(struct node** res,int top)
{
  FILE* fp=fopen("output.txt","w");
  if(!fp)
  {
    printf("ERROR in store path");
    return;
  }
  int i=0;
  if(top==-1)
  {
    fprintf(fp,"%d",-1);
  }
  else
  {
    while(i<=top)
    {
      fprintf(fp,"%d %d\n",res[i]->x,res[i]->y);
      i++;
    }
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void init(BST *tree)
{
    tree->root = NULL;
}
NODE *newnode(int ele)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->info = ele;
    new->lchild = NULL;
    new->rchild = NULL;
    return new;
}
void insert(BST *tree, int ele)
{
    NODE *new = newnode(ele);
    NODE *p, *befp;
    if (tree->root == NULL)
        tree->root = new;
    else
    {
        p = tree->root;
        befp = NULL;

        while (p != NULL)
        {
            if (p->info > new->info)
            {
                befp = p;
                p = p->lchild;
            }
            else
            {
                befp = p;
                p = p->rchild;
            }
        }
        if (befp->info > new->info)
            befp->lchild = new;
        else
            befp->rchild = new;
    }
}

void inorder(NODE *ph)
{
    NODE *p = ph;
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d\t", p->info);
        inorder(p->rchild);
    }
}
NODE *delete (NODE *r, int ele)
{
    NODE *curr, *prev, *p, *q, *new;
    curr = r;
    prev = NULL;
    while ((curr != NULL) && (curr->info != ele))
    {
        prev = curr;
        if (ele < curr->info)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    if (curr == NULL)
    {
        printf("number not found\n");
        return r;
    }
    if ((curr->lchild == NULL) || (curr->rchild == NULL))
    {
        if (curr->lchild == NULL)
            q = curr->rchild;
        else
            q = curr->lchild;
        if (prev == NULL)
        {
            free(curr);
            return q;
        }
        if (curr == prev->lchild)
            prev->lchild = q;
        else
            prev->rchild = q;
        free(curr);
    }
    else
    {
        p = NULL;
        new = curr->rchild;
        while (new->lchild != NULL)
        {
            p = new;
            new = new->lchild;
        }
        curr->info = new->info;
        if (p != NULL)
        {
            p->lchild = new->rchild;
        }
        else
        {
            curr->rchild = new->rchild;
        }
        free(new);
    }
    return r;
}
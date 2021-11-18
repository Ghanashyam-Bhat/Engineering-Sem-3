#include<stdio.h>
#include<stdlib.h>
#include "PES1UG20CS153_H.h"

int main()
{
  struct node* head=(struct node*)malloc(sizeof(struct node));
  head->val=0;
  head->down=head->right=NULL;
  read_path(&head);
  find_path(head);
  return 0;
}

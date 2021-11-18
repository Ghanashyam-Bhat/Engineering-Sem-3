struct node{
  struct node* right;
  struct node* down;
  int x,y,val;
};

void read_path(struct node**);
void find_path(struct node*);
void store_path(struct node**,int);

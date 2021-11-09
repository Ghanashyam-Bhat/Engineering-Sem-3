
typedef struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
} NODE;
typedef struct bst
{
    NODE *root;
} BST;

NODE *delete (NODE *r, int ele);
void inorder(NODE *ph);
void insert(BST *tree, int ele);
NODE *newnode(int ele);
void init(BST *tree);

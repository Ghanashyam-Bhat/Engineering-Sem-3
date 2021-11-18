typedef struct Node
{
    int x;
    int y;
    struct Node *link;
	struct Node *down;
}node;
node* head;

void read_file();
void insert(int x,int y);
void swap(node* cur1, node* cur2);
void rearrange();
void traverse();
void display();
void save();
typedef struct node
{
	int x;
	int y;
	int id;
	struct node* left;
}Node;

struct stack
{
	int *arr;
	int top ;
	int maxsize;
};
typedef struct stack Stack;


struct queue
{
	int front;
	int rear;
	int qsize;
	int* data;
};
typedef struct queue Queue;

void initialize(Stack* S,int size);
void push(Stack* S, int ele);
int isFull(Stack* S);
int pop(Stack* S);
int isEmpty(Stack* S);

void init(Queue* Q, int n);
int isFullQ(Queue* Q);
int isEmptyQ(Queue* Q);
void enqueue(Queue* Q , int ele);
void display(Queue* Q);
int dequeue(Queue* Q);

void reverse(Node** base,int max_r);
void search_path(Node* base[],int i,int j,Stack* S,int max_r,int max_f);
void end_of_dfs(Stack* S);
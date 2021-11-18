
typedef struct node
{
    int row;
    int col;
    int visited;
    struct node *r_link;
    struct node *c_link;
}NODE;

typedef struct header
{
    int no;
    NODE *n_connect;
    struct header *h_connect;
}header;

typedef struct head
{
    int row;
    int col;
    header *r_link;
    header *c_link;
}START;

typedef struct queue
{
    NODE *data;
    struct queue *link;
}queue;

typedef struct q_head
{
    queue *head;
}Q;

void initialize(Q *q);
void init(START *s);
void read_map(FILE *fp,START *s);
void create_head_r(START *s,int no);
void create_head_c(START *s,int no);
void create_node(START *s,int r,int c);
int traversal(START *s,Q *q,int s_r,int s_c,int d_r,int d_c);
void insert_node(Q *q,NODE *cur);
void store_path(Q *q,int res);
void dqueue(Q *q);
void print(queue *q,FILE *fp);
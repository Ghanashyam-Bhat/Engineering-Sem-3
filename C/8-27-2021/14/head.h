
typedef struct data
{
	int info;
	struct data* link;
}D;

typedef struct head
{
	D* head;
}H;

void initialize(H* h);
void insert_front(H* h,int x);
void insert_rear(H* h,int x);
void display(const H* h);
void delete_front(H* h);
void delete_rear(H* h);
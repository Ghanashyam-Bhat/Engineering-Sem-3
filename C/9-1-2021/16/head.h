
typedef struct polynomial_expansion
{
	int coeff;
	int power;
}POLY;

typedef struct node_of_polynimial
{
	POLY poly;
	struct node_of_polynimial* link;
}NODE;

typedef struct head_of_expansion
{
	NODE* head;
}H;

int initialize(H* h,int num);
int operation(H* h,int n);
int merge(H* h, H* he,int n);
void sort(H* h,int n);

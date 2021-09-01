typedef struct subject
{
	char sub_name[50];
	char sub_code[50];
	int marks;
}SUB;

typedef struct info
{
	char SRN[50];
	char name[50];
	int sem;
	SUB subjects[5];
	struct info* link;
}INFO;

typedef struct head
{
	INFO *head;
}HEAD;

int input(HEAD* h);
float avg(HEAD* h ,int n);
void display(HEAD* h,int n);
void sort(HEAD* h,int n);

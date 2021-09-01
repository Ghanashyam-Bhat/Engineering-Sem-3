
typedef struct info_of_player
{
	char name[50];
	char team[50];
	int no_matches;
	int run;
}INFO;

typedef struct node
{
	INFO info;
	struct node* link;	
}NODE;

typedef struct head_of_node
{
	NODE* head;
}HEAD;


int initialize(HEAD* h);
int max(HEAD* h, int n);
void display_max(HEAD* h, int n);
void display_match(HEAD* h, int n);
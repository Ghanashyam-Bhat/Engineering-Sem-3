#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main()
{
	HEAD h;
	h.head = NULL;
	
	int n = initialize(&h);
	printf("\nPlayers who scored maximum runs are: \n");
	display_max(&h,n);
	printf("\n\nDIsplay of Player name and the number of matches played by them: \n");
	display_match(&h,n);
}

int initialize(HEAD* h)
{
	NODE* pres;
	printf("Enter the number of players: ");fflush(stdin);int n;scanf("%d",&n);
	if(n)
	{
		h->head=(NODE*)malloc(sizeof(NODE));
		h->head->link=NULL;
		printf("Enter Player Details: \n");
		printf("\nPlayer 1\n");
		printf("Enter name of the player: ");fflush(stdin);scanf("%[^\n]s",h->head->info.name);	
		printf("Enter name of the team: ");fflush(stdin);scanf("%[^\n]s",h->head->info.team);	
		printf("Enter number of matches: ");fflush(stdin);scanf("%d",&(h->head->info.no_matches));
		printf("Enter runs scored: ");fflush(stdin);scanf("%d",&(h->head->info.run));	
		pres=h->head;
		for(int i=1;i<n;i++)
		{
			pres->link=(NODE*)malloc(sizeof(NODE));
			pres=pres->link;
			printf("\nPlayer %d\n",i+1);
			printf("Enter name of the player: ");fflush(stdin);scanf("%[^\n]s",pres->info.name);	
			printf("Enter name of the team: ");fflush(stdin);scanf("%[^\n]s",pres->info.team);	
			printf("Enter number of matches: ");fflush(stdin);scanf("%d",&(pres->info.no_matches));
			printf("Enter runs scored: ");fflush(stdin);scanf("%d",&(pres->info.run));	
		}
		pres->link=NULL;
	}
	return n;	
}

void display_max(HEAD* h, int n)
{
	int m = max(h,n);
	NODE* pres=h->head;
	for(int i=0;i<n;i++)
	{
		if(pres->info.run==m)
		{
			printf("\nName: %s\n",pres->info.name);
			printf("Team Name: %s\n",pres->info.team);
			printf("No. of matches: %d\n",pres->info.no_matches);
			printf("Score: %d\n",pres->info.run);
		}
		pres=pres->link;
	}
}

int max(HEAD* h, int n)
{
	NODE* pres= h->head;
	int m = h->head->info.run;
	for(int i=0;i<n;i++)
	{
		if(m<(pres->info.run))
		{
			m = (pres->info.run);
		}
		pres=pres->link;
	}		
	return m;
}

void display_match(HEAD* h, int n)
{
	NODE* pres= h->head;
	for(int i=0;i<n;i++)
	{
		printf("\nName: %s\n",pres->info.name);
		printf("Score: %d\n",pres->info.no_matches);
		pres=pres->link;
	}		
}
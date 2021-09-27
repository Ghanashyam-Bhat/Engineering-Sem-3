#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct car
{
	int d_c;
	char num_plate[20];
}Car;

typedef struct garage
{
	Car* C;
	int empt;
	int max;
}Garage;

void parking(Car* new , Garage* G , char* op);
void park(Car* new , Garage* G);
void dept(Car* new , Garage* G , int );

int main()
{
	Garage G;
	//Initializing with 8 car capacity
	G.C = (Car*)malloc(sizeof(Car)*8);
	G.empt = 8;
	G.max = 8;
	
	//Taking input from csv file
	Car new;
	char buffer[50];char* op;
	FILE* fp = fopen("input.csv","r");
	if(fp != NULL)
	{
		while(fgets(buffer,50,fp))
		{
			new.d_c = 0;
			op = strtok(buffer,",");
			strcpy(new.num_plate,strtok(NULL,","));
			if(new.num_plate[strlen(new.num_plate)-1]=='\n')
				new.num_plate[strlen(new.num_plate)-1] = '\0' ;
			parking(&new , &G , op);
		}
		fclose(fp);
	}
	else
		perror("Error Message: ");
}

void parking(Car* new , Garage* G , char* op)
{
	
	if((strcmp(op,"A"))==0)
	{
		if(G->empt == 0)
			printf("No space in Garage for this car\n");
		else
		{
			for(int i = (G->empt)-1;i<G->max;i++)
			{
				if(strcmp((G->C)[i].num_plate,new->num_plate)==0)
				{
					printf("Invalid Input\nThe Car %s is already in Garage\n",new->num_plate);
					return;
				}
				else
				{ 
					printf("Car %s can be parked at position %d\n",new->num_plate,G->empt - 1);
					park(new,G);
					return;
				}			
			}		
		}	
	}
	else if((strcmp(op,"D"))==0)
	{
		for(int i =(G->max)-1 ;i>=G->empt-1;i--)
		{
			if(strcmp((G->C)[i].num_plate,new->num_plate)==0)
			{
				dept(new,G,i);
				return;
			}				
		}	
		printf("Car %s Not in Garage\n",new->num_plate);
	}
}

void park(Car* new , Garage* G)
{
	strcpy((G->C)[G->empt-1].num_plate , new->num_plate);
	(G->C)[G->empt-1].d_c  = new->d_c ;
	G->empt --;
}

void dept(Car* new , Garage* G , int p)
{
	int last = G->empt-1;
	G->empt = G->max;
	for(int i=G->max-1;i>last;i--)
	{
		(G->C)[i].d_c ++; 
		if( i != p)
			park(&((G->C)[i]),G);
		else
			printf("Car %s departured and it was moved %d times from garage\n",(G->C)[i].num_plate,(G->C)[i].d_c-1);
	}	
}

/*
GHANASHYAM BHAT
PES1UG20CS153
*/
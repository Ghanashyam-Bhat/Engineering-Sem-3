#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PES1UG20CS153_H.h"
//GHANASHYAM BHAT
//PES1UG20CS153
int main()
{
	int min_r ,max_r,max_f,min_f ;
	Node* prev,*pres;
	int t,temp;
	int i,j;
	char buffer[100];
	FILE* fp;
	
	fp = fopen("input.txt","r");
	Queue Qx,Qy;
	//init(&Qx,max_r*max_r);
	//init(&Qy,max_r*max_r);
	Stack S;
	int size,ele;
	initialize(&S,(max_r*max_r)*3+50);
	
	fgets(buffer,100,fp);
	min_r = atoi(strtok(buffer," "));
	min_f = atoi(strtok(NULL," "));
	
	fgets(buffer,100,fp);
	max_r = atoi(strtok(buffer," "));
	max_f = atoi(strtok(NULL," "));
	
	Node* base[max_r+1];
	for( int k= 0 ; k<=max_r;k++)
		base[k]=NULL;
	
	for(int m = 0;m<=max_r;m++)
	{
		fgets(buffer,100,fp);
		t = atoi(strtok(buffer," "));
		for (int n=0;n<=max_r;n++)
		{
			
			if (t==0)
			{
				prev = base[m];
				base[m] = (Node*)malloc(sizeof(Node));
				base[m]->left = prev;
				base[m]->x = m;
				base[m]->y = n;
				printf("%d %d\t",base[m]->x,base[m]->y);
			}
			else
				printf("x x\t");
			t = atoi(strtok(NULL," "));
		}		
		printf("\n");
	}
	
	reverse(base,max_r);
	
	//Id numbering
	temp = 1;
	for(int m = 0;m<=max_r;m++)
	{
		pres = base[m];
		while(pres!=NULL)
		{
			pres->id=temp;
			temp ++;
			pres=pres->left;
		}
	}
	fclose(fp);
	push(&S,min_r);
	push(&S,min_f);
	search_path(base,min_r,min_f,&S,max_r,max_f);
	//bfs_path(base,min_r,min_f,&Q1,&Q2,max_r,max_f);
	
	printf("Path Not Found");
	FILE* op = fopen("outdfs.txt","w");
	FILE* op2 = fopen("outbfs.txt","w");
	fprintf(op,"-1");
	fprintf(op2,"-1");
	fclose(op);
	fclose(op2);	
}

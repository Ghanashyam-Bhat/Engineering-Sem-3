//Hash Table: Seperate Chaining
#include <stdio.h>
#include <stdlib.h>
#define Size 10

struct dataitem
{
	int key;
	float info;
	struct dataitem* link;
};
typedef struct dataitem Ditem;

int hash_fun(int key)
{
	return key%Size;
}

void insert(Ditem *htable[],int key,float info)
{
	int hashcode;
	Ditem *newnode;
	hashcode = hash_fun(key);
	newnode =(Ditem*)malloc(sizeof(Ditem));
	newnode->key = key;
	newnode->info = info;
	//insert front
	newnode->link = htable[hashcode];
	htable[hashcode]=newnode;	
}

void printtable(Ditem *htable[])
{
	Ditem *cur;
	for(int i=0;i<Size;i++)
	{
		cur = htable[i];
		printf("\n");
		if(cur==NULL)
		{
			printf("\nNULL\n");
		}
		while(cur!=NULL)
		{
			printf("Key %d\tInfo %f ||",cur->key,cur->info);
			cur = cur->link;
		}		
	}
	
}

int find(Ditem* htable[],int key)
{
	int hashcode= hash_fun(key);
	Ditem* cur;
	cur = htable[hashcode];
	while(cur!=NULL)
	{
		if(cur->key==key)
		{
			printf("Key %d found\nValue is %f\n",cur->key,cur->info);
			return 1;
		}
		cur = cur->link;
	}
	printf("Key %d not found\n",key);
	return 0;
}

int main()
{
	int key;
	Ditem *htable[Size];
	for (int i=0;i<Size;i++)
		htable[i]=NULL;
	insert(htable,53,14.5);
	insert(htable,23,287.5);
	insert(htable,28,156.5);
	insert(htable,106,23.5);
	printtable(htable);
	key = 53;
	find(htable,key);
}
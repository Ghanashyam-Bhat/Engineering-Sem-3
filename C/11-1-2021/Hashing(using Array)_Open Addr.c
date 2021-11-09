#include <stdio.h>
#include <stdlib.h>
#define Size 10

struct dataitem
{
	int key;
	float info;
};
typedef struct dataitem Ditem;

int hash_fun(int key)
{
	return key%Size;
}

void insert(Ditem htable[],int key,float info)
{
	int hashcode = hash_fun(key);
	if(htable[hashcode].key==-1)
	{
		htable[hashcode].key = key;
		htable[hashcode].info = info;
		return;
	}
	//Linear Probing
	do
	{
		hashcode = (hashcode+1)%Size;
		if(htable[hashcode].key==-1)
		{
			htable[hashcode].key = key;
			htable[hashcode].info = info;
			printf("Key is Inserted");
			return;
		}
	}while(htable[hashcode].key!=-1 && hashcode!=hash_fun(key));
	printf("Hash Table is FUll");
}

int main()
{
	Ditem htable[Size];
	for(int i=0;i<Size;i++)
	{
		htable[i].key = -1;
	}
	
}
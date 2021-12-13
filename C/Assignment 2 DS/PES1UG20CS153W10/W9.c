#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
	int key;
	char name[10];
	int contact;
	struct node *next;
}NODE;

typedef struct hash
{
	int count;
	NODE* head;
}HASH;

void initHash(HASH* hash, int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		hash[i].count = 0;
		hash[i].head = NULL;
	}
}

void initHash(HASH* hash, int size);
int insert(HASH* hasht, int size, int key, char* name, int num);
void display(HASH* hasht, int t_size);
void delete(HASH* hasht, int t_size, int key);
NODE* search(HASH* hasht, int t_size, int key);

int main()
{
	HASH* hashtable;
	int t_size, ch, key, cont;
	char name[10];
	printf("Enter table size: ");
	scanf("%d", &t_size);
	hashtable = (HASH*)malloc(t_size*sizeof(HASH));
	initHash(hashtable, t_size);
	do
	{
		printf("1.Insert\t2.Display\t3.Search\t4.Delete\t5.Exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				//printf("Enter key:");
				//scanf("%d", &key);
				printf("Enter name:");
				scanf("%s", name);
				printf("Enter contact:");
				scanf("%d", &cont);
				key = cont;
				if (insert(hashtable, t_size, key, name, cont))
					printf("Successfully inserted\n");
				else
					printf("Insertion failed\n");
				break;
			case 2:
				printf("Displaying the record:\n");
				display(hashtable, t_size);
				break;
			case 3:
				printf("Enter key to search:");
				scanf("%d", &key);
				NODE* res = search(hashtable, t_size, key);
				if (res!=NULL)
					printf("Key = %d\tName = %s\tContact = %d\n", res->key, res->name,res->contact);
				else
					printf("Key not found");
				break;
			case 4:
				printf("Enter key to delete:");
				scanf("%d", &key);
				delete(hashtable, t_size, key);
				break;
		}
	}while (ch != 5);
	
	return 0;
}

int insert(HASH* hasht, int size, int key, char* name, int num)
{
	//creating node
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->contact = num;
	temp->key = key;
	strcpy(temp->name, name);
	temp->next = NULL;
	if (temp == NULL)
		return 0;
	
	//inserting at first
	int index = key%size;
	temp->next = hasht[index].head;
	hasht[index].head = temp;
	hasht[index].count++;
	return 1;
}

void display(HASH* hasht, int t_size)
{
	NODE* temp;
	for(int i=0; i<t_size; i++)
	{
		printf("%d :\n", i);
		if (hasht[i].head != NULL)
		{
			temp = hasht[i].head;
			while (temp != NULL)
			{
				printf("Key : %d\t", temp->key);
				printf("Name : %s\t", temp->name);
				printf("Contact : %d\n", temp->contact);
				temp = temp->next;
			}
		}
	printf("\n");
	}
}


void delete(HASH* hasht, int t_size, int key)
{
	NODE *temp, *prev;
	prev = NULL;
	int index = key%t_size;
	temp = hasht[index].head;
	while (temp!=NULL && temp->key != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		if (prev == NULL)
			hasht[index].head = temp->next;
		else
			prev->next = temp->next;
		free(temp);
	}
	else
		printf("Element not found\n");
}
	
NODE* search(HASH* hasht, int t_size, int key)
{
	int index = key%t_size;
	NODE* temp = hasht[index].head;
	while (temp!=NULL && temp->key != key)
	{
		temp = temp->next;
	}
	if (temp == NULL)
		return NULL;
	else
	{
		return temp;
	}
}
#include <stdio.h>
#include <stdlib.h>
//Level order Traversal
int main()
{
	//Array Reprasentation
	int *btree;
	int n;
	printf("How many nodes: ");scanf("%d",&n);
	btree = (int*)malloc(n*sizeof(int));
	printf("Enter the root node: ");scanf("%d",&btree[0]);
	printf("Enter the node in level order and -1 for null\n");
	for(int i=0;i<n;i++)
	{
		if(btree[i]==-1)
		{
			continue;
		}
		else
		{
			printf("Enter the lchild of %d: ", btree[i]);
			scanf("%d",&btree[2*i+1]);
			
			if(2*i+2>= n)
			{
				continue;
			}
			else
			{
				printf("Enter the rchlid of %d: ",btree[i]);
				scanf("%d",&btree[2*i+2]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d",btree[i]);
	}
}
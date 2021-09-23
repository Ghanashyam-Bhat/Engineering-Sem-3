/*
There are number of of plants in a and each of these is treated with some amount pesticide
after each day if any plant has more pesticide than the plant on its left being weaker than the left one it dies!
You are given initial vlaues of pesticides in each plants
Code to print the live plant when there is no plant with higher concentration of pesticides than the one to its left plants
stop dying after that day
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedf struct plant
{
	int pesticide;
	int pos;
	struct plant* link;
}Plant;

typedef head_to_ll
{
	Plant* head;
}H;

int main()
{
	H h;h->head =NULL;
	int pest,n;
	int num;printf("Number of Plants: ");scanf("%d",&num);
	for(int i=0; i<num ; i++)
	{
		printf("Enter Pesticide: ");scanf("%d",&pest);
		printf("Enter Plant Number: ");scanf("%d",&n);
	}
}
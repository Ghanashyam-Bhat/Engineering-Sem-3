//25-8-2021
//Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h> //Malloc,Calloc,Realloc,Free

int main()
{
	int* ptr;//Stored in Stack 
	int n = 5;
	ptr = (int*)malloc(n*sizeof(int));
	
	//The memory allocated will be assigned garbage value
	//When we reserve memory, size of memory is also stored. Here it is 20 bytes
	//This entire set is considered as 1 block (1 block = 20 bytes here as n=5)
	
	//The typecasting is very importent beacuse, while moving to the next element, 
	//we get to know how many size we need to skip to move to next element only after typecasting
	
	//Here we have typecasted to int* so ptr+1 jumps by 4 bytes
	
	
	int* p = (int*)calloc(n,sizeof(int)); 
	
	//The memory allocated will be assigned 0
	//In calloc n is number block and sizeof(int) is 4
	//Here calloc considers n block of 4 bytes
	
	//Effieciency wise, Malloc is better than calloc
	
	
	int* pt = (int*)realloc(ptr,3*sizeof(int));
	
	//Arguments are: Pointer to be changed and new size
	//We can change the amount of space reserved using dynamic memory allocation
	
	//When we reduce the size, it returns same pointer
	//When increasing it depends on if size is avilable or not in old location
	//If location is changed, content of earlier memory will be copied to new location
	
	//Realloc automatically frees old pointer
	
	
	free(pt);free(p);
	
	ptr=NULL;p=NULL;pt=NULL;
}
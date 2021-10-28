//Heap Coding 
#include <stdio.h>

#define MAX 100

void max_heapify(int heap[],int i,int n)
{
	int lchild,rchild,temp;
	int maxindex = i;
	lchild = 2*i+1;
	rchild = 2*i+2;
	//Checking where the maximum element is
	if(lchild<n && heap[lchild]>heap[maxindex])
		maxindex = lchild;
	
	if(rchild<n && heap[rchild]>heap[maxindex])
		maxindex = rchild;
	
	//swaping
	if(maxindex!=i)
	{
		temp = heap[i];
		heap[i] = heap[maxindex];
		heap[maxindex] = temp;
		max_heapify(heap,maxindex,n);//Recurrsion will stop when maxindex will be i itself
	}
}

void build_max_heap(int heap[],int n)
{
	int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		max_heapify(heap,i,n);
		
	}
	
}

int main()
{
	int heap[MAX];
	int n;
	printf("\nEnter the heap size: ");
	scanf("%d",&n);
	printf("\n Enter the elements: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&heap[i]);
		
	build_max_heap(heap,n);
	printf("\n Heap Elements\n");
	for (int i=0;i<n;i++)
		printf("%d ",heap[i]);
}
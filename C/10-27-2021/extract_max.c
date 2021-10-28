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

int extract_max(int heap[],int *n)
{
	int max = heap[0];
	heap[0] = heap[*n-1];
	*n=*n-1;
	max_heapify(heap,0,*n);
	return max;
}

void insert(int heap[],int ele,int *n)
{
	int i,temp;
	if(*n>MAX)
	{
		printf("\nHeap is full, cannot insert new element");
		return;
	}
	heap[*n] = ele;
	//Heapifying Partially
	*n = *n+1;
	i  =*n-1;
	while(i>=0 && heap[i]>heap[(i-1)/2])
	{
		temp = heap[i];
		//Swaping
		heap[i] = heap[(i-1)/2];
		heap[(i-1)/2] = temp;
		i = (i-1)/2;
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
	printf("\n Heap Elements after Heapifying\n");
	for (int i=0;i<n;i++)
		printf("%d ",heap[i]);
	
	int max = extract_max(heap,&n);
	printf("\n\nMaximum : %d",max);
	
	printf("\n Heap Elements after max extraction\n");
	for (int i=0;i<n;i++)
		printf("%d ",heap[i]);
	
	insert(heap,35,&n);
	printf("\n Heap Elements after insertion\n");
	for (int i=0;i<n;i++)
		printf("%d ",heap[i]);
}
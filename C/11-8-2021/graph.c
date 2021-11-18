//Write a program to read a graph interms of an adjecency matrix find the degree of each and every vertex in graph
#include <stdio.h>
int main()
{
	int sum;
	int arr[7][7] = {{0,1,1,0,0,0,0},
					 {1,0,1,0,0,0,0},
					 {1,1,0,1,0,0,0},
					 {0,0,1,0,1,0,0},
					 {0,0,0,1,0,1,1},
					 {0,0,0,0,1,0,1},
					 {0,0,0,0,1,1,0}};
	for(int i=0;i<7;i++)
	{
		sum = 0;
		for(int j=0;j<7;j++)
			sum+=arr[i][j];
		printf("Degree of %d is %d\n",i,sum);
	}	
}
#include <stdio.h>
#include "head.h"

int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(n, 'A', 'C', 'B');
    return 0;
}

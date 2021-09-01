#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(n, 'A', 'C', 'B');
    return 0;
}
void towers(int n, char rod1, char rod2, char rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", rod1, rod2);
        return;
    }
    towers(n - 1, rod1, rod, rod2);
    printf("\n Move disk %d from rod %c to rod %c", n, rod1, rod2);
    towers(n - 1, rod, rod2, rod1);
}
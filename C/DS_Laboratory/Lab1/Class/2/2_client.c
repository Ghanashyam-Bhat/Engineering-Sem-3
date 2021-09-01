#include <stdio.h>
#include "head.h"

int main()
{
	HEAD h;
	h.head = NULL;
	int n= input(&h);
	float average = avg(&h,n);
	printf("Average marks of the class for the subject is: %.2f",average);
	sort(&h,n);
}

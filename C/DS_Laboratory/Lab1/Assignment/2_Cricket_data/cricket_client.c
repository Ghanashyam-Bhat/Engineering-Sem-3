#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	HEAD h;
	h.head = NULL;
	
	int n = initialize(&h);
	printf("\nPlayers who scored maximum runs are: \n");
	display_max(&h,n);
	printf("\n\nDIsplay of Player name and the number of matches played by them: \n");
	display_match(&h,n);
}
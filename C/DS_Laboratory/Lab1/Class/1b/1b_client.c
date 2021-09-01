#include <stdio.h>
#include <string.h>
#include "head.h"

void main()
{
	char string[10] = "ABC";
	int n = strlen(string);
	fun(string, 0, n-1);
}


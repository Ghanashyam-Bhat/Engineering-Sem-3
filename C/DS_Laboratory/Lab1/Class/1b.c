#include <stdio.h>
#include <string.h>
void swap(char *str1, char *str2)
{
	char temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
void permute(char *a, int l, int r)
{
int i;
if (l == r)
	printf("%s\n", a);
else
{
	for (i = l; i <= r; i++)
	{
		swap((a+l), (a+i));
		permute(a, l+1, r);
		swap((a+l), (a+i)); 
	}
}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);
	return 0;
}

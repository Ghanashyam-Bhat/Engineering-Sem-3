//Linked list
#include <stdio.h>
#include <stdlib.H>
#include "head.h"

int main()
{
	H h;
	initialize(&h);
	char o;int x;
	do
	{
		printf("\n\nSelect \n1.To insert in front\n2.Insert in rear\n3.Display\n4.delete front\n5.Delete rear\n");fflush(stdin);
		scanf("%c",&o);
		switch(o)
		{
			case '1':printf("Enter the element: ");fflush(stdin);
					scanf("%d",&x);
					insert_front(&h,x);
					break;
			case '2':printf("Enter the element: ");fflush(stdin);
					scanf("%d",&x);
					insert_rear(&h,x);
					break;
			case '3':display(&h);
					break;
			case '4':delete_front(&h);
					break;
			case '5':delete_rear(&h);
					break;
			case '6':printf("Closed");
					break;
			default: printf("Select proper option");
		}
	}while(o!='6');
}



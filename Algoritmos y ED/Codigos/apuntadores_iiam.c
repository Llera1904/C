#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int x=16, y=25;
	int *p= NULL;		// apuntador a enteros
	
	printf("x= %d\n", x);
	printf("y= %d\n", y);
	printf("p= %d\n", p);
	
	p= &x;
	y= *p;	
	
	printf("x= %d\n", x);
	printf("y= %d\n", y);
	printf("p= %X\n", p);
	
	return 0;
}

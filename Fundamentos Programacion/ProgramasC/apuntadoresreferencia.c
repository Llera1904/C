#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int x=23;
	int y=0;
	int *p= NULL;
	
	p= &x;	
	y= *p;	
	
	y= (*p)+50;
	y= 3*(*p);
	*p= 54;
	*p= (*p) + 10;
	(*p)+= 10;
	(*p)+10;
	(*p)*=10;
	p= &y;
	*p= y-(*p)+9;
	
	printf("p= %X, &p=%X, *p=%d \n", p, &p, *p);
	printf("x= %d, &x=%X\n", x, &x);
	printf("y= %d, &y=%X\n", y, &y);
	
	return 0;
}

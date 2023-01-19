#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int y= 0;
	int x= 23;
	int *p= NULL;
	
			printf("&x= %X, x= %d\n", &x, x);
			printf("&y= %X, y= %d\n", &y, y);
			printf("&p= %X, p= %X\n", &p, p);
			//printf("&p= %X, p= %X, *p= %d\n", &p, p, *p);
	
			printf("\n");
	
	p= &x;				// averigua la direccion de x
	y= *p;				// accede al contenido donde hace referencia p
	
			printf("&x= %X, x= %d\n", &x, x);
			printf("&y= %X, y= %d\n", &y, y);
			printf("&p= %X, p= %X, *p= %d\n", &p, p, *p);
	
			printf("\n");
	
	y= (*p) + 50;
	y= 3*(*p);
	
	*p= 54;
	*p= (*p) + 10;
	(*p)+= 10;
	
	(*p)*= 10;
	
	p= &y;
	(*p)-= 24;
	
			printf("&x= %X, x= %d\n", &x, x);
			printf("&y= %X, y= %d\n", &y, y);
			printf("&p= %X, p= %X, *p= %d\n", &p, p, *p);
	
	printf("\n");	
	
	return 0;
}

// especificadores de formato:
// %d: decimal
// %x, %X: hexadecimal minusculas, mayusculas

// Null Pointer Assignment int *p= NULL;
// intento de acceso al contenido a una referencia nula *p

/*
int x=0;

scanf("%d", &x);

if (x==17 && y==13)
 {
 	
 }*/

//x= a*b;

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int x= 1532, y= 112, z= 0;

	//alternativamente:	
	/*int x= 1804;
	int y= 2711;
	int z= 0;*/
	
	printf("x= ");		// impresion con formato
	scanf("%d", &x);	//lectura del flujo de entrada stdin
	
	printf("y= ");
	scanf("%d", &y);	//&y: &: averigua la direccion de memoria donde reside la variable
	
	z= x + y;
	printf("%d + %d = %d\n", x, y, z);
	//printf("%X + %X = %X\n", x, y, z);
	
	z= x - y;	
	printf("%d - %d = %d\n", x, y, z);
	
	z= x * y;	
	printf("%d * %d = %d\n", x, y, z);
	
	z= x / y;		// cociente	
	printf("%d / %d = %d\n", x, y, z);
	
	z= x % y;		// residuo, %= mod, modulo
	printf("%d mod %d = %d\n", x, y, z);
		
	return 0;
}

// %d= especificador de formato decimal
// %f= puntos flotantes
// %X= hexadecimal
// %c= caracteres
// %s= cadenas de caracteres

// '\n': salto de linea

// printf: escritura con formato
// scanf: lectura con formato


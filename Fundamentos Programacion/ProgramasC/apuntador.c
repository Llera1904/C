#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char *argv[]) 
{
	int x=23;
	int y=0;
	int *p= NULL;
	
	p= &x;	
	y= *p;	
	(*p)+= 6;
	
	return 0;
}
*/

// %X: formato hexadecimal en mayusculas
// %x: formato hexadecimal en minusculas


int main(int argc, char *argv[]) 
{
	int x=23;
	int y=0;
	int *p= NULL;
	
		printf("Inicio:\n");
		printf("x= %d\n", x);
		printf("p= %X\n", p);
		printf("y= %d\n\n", y);
	
	p= &x;		// &: consulta la direccion de memoria de x
				// la direccion se asigna a p
				// p hace referencia a x
			
		printf("Intermedio:\n");
		printf("x= %d\n", x);
		printf("p= %X\n", p);
		printf("y= %d\n\n", y);
		
	y= *p;		// *: p accede al contenido a donde hace referencia
				// el valor es copiado en y
			
		printf("Final:\n");
		printf("x= %d\n", x);
		printf("p= %X\n", p);
		printf("y= %d\n\n", y);
		
		// x= 29;
		// x= x+6;
		// x+=6;	
		// x= (*p)+6;	
		// (*p)= (*p)+6;
	
	(*p)+= 6;
	
		printf("Calculo:\n");
		printf("x= %d\n", x);
		printf("p= %X\n", p);
		printf("y= %d\n\n", y);
		
	printf("valor de x: %d\n", x);
	printf("la direccion de x (&x): %X\n", &x);
	
	printf("\nvalor de y: %d\n", y);
	printf("la direccion de y (&y): %X\n", &y);
	
	printf("\nvalor de p: %X\n", p);
	printf("la direccion de p (&p): %X\n", &p);
	printf("contenido de la referencia de p (*p): %d\n", *p);
	
	
	return 0;
}



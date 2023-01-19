#include <stdio.h>
#include <stdlib.h>

void saludar();		// firma de la funcion;
float sumar(float a, float b);

int main(int argc, char *argv[])
{
	float x=16.59, y=20.21, z=0.0;
	
	saludar();		// invocacion de funcion;
	
	z= sumar(x, y);		// a= x, b= y, z= c;
	
	printf("%0.4f + %0.4f = %0.4f\n", x, y, z);
	
	return 0;
}


// funcion sin parametros, sin valor de retorno
void saludar()
{
	printf("hola a todos!\n");
}

// funcion con parametros:

float sumar(float a, float b)
{
	float c=0;
	
	c= a+b;
	
	return(c);
}

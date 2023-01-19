#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	float lado= 0.0;
	float perimetro= 0.0, area= 0.0;
	float radio= 0.0;
	
	/*printf("cuadrado: \n")
	printf("lado= ");
	scanf("%f", &lado);
	
	perimetro= 4*lado;
	area= lado * lado;
	// area= pow(lado, 2.0);
	
	printf("area= %0.2f\n", area);
	printf("perimetro= %0.20f\n", perimetro);*/
	
	printf("circulo: \n");
	printf("radio= ");
	scanf("%f", &radio);
	
	perimetro= 2.0*M_PI*radio;
	area= M_PI * radio * radio;
	//area= M_PI * pow(radio, 2.0);
	
	printf("area= %0.20f\n", area);
	printf("perimetro= %0.20f\n", perimetro);
	
	return 0;
}

// programa para calcular el area y perimetro de un poligono regualar de N lados

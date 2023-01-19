#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int omnipotente= 1645;
			// variable global
// No usar variables globales, nunca!!!!
// el usar variables globales hace a sus funciones dependientes de la
// variable global

// Para que la funcion sea independiente, se acuerda una interfaz bien
// definida: lista de parametros y el tipo de dato de retorno
// de esta forma se comunica con la funcion que desee invocarla



float calcularHipotenusaPasoPorValor(float a, float b);
void funcionCasiOmnipresente(float e);

int main(int argc, char *argv[])
{
	float catetoA= 402.0, catetoB= 424.0, hipotenusa=0.0;
	// catetoA, catetoB, hipotenusa son variables locales al main
	float emisario= 13;
	
	printf("main: omnipotente= %d\n", omnipotente);
	
	printf("catetoA= ");
	scanf("%f", &catetoA);		// paso por referencia
								// &catetoA: consulta la direccion donde
								// habita la variable catetoA
	
	printf("catetoB= ");
	scanf("%f", &catetoB);		// paso por referencia
	
	
	hipotenusa= calcularHipotenusaPasoPorValor(catetoA, catetoB);
		// a= catetoA, b= catetoB;	// copia de los valores
	
	printf("hipotenusa= %0.2f\n", hipotenusa);
	printf("catetoA= %0.2f\n", catetoA);
	printf("catetoB= %0.2f\n", catetoB);
	
	// printf("a= %0.2f, b= %0.2f, c= %0.2f\n", a, b, c);
		// a, b, c no han sido declaradas en el main
		// por lo que no pueden ser accesadas en esta funcion
	
	printf("main: omnipotente= %d\n", omnipotente);
	
	funcionCasiOmnipresente(emisario);
	
	return 0;
}

float calcularHipotenusaPasoPorValor(float a, float b)
{
	int c=0;			// a, b,c son variables locales
	
	printf("hipo: omnipotente= %d\n", omnipotente);
	
	c= sqrt(a*a + b*b);
	
	a= 627;
	b= 28;
	
	omnipotente= -5432;
	
	// catetoA, catetoB, hipotenusa fueron declarados en la funcion main
	// por lo que no se pueden acceder dentro de esta funcion
	
	/*printf("hipotenusa= %0.2f\n", hipotenusa);
	printf("catetoA= %0.2f\n", catetoA);
	printf("catetoB= %0.2f\n", catetoB);	*/
	
	return(c);
}

void funcionCasiOmnipresente(float e)
{
	float k=0.0;
	
	k= 2*e+3;
	
	printf("k= %0.2f, e= %0.2f\n", k, e);
}


// Variables tienen un contexto delimitado por la funcion
	// solamente existen y son validas dentro de la funcion
	
	
// variables de tipo var en otros lenguajes:
	// C: tipo de datos comodin: wildcard
		// void *, apuntador a void
		
// variables globales: ?
	


#include <stdio.h>
#include <stdlib.h>

int global=0;					// variable global
								// no es recomendable!!!!

int main(int argc, char *argv[]) 
{
	int k=0, N=10, x=0, a=0;	// variable locales
	int cuadra= 0;
	
	// variables comunes de conteo:
	// int k=0, i=0, j=0, x=0, c=0, m=0, n=0, cont=0;
	
	// conteo ascendente:
	
	for (k=0; k<N; k=k+1)
	   {	   	
	   	 printf("k= %d\n", k);
	   }
	   
	printf("\n");
	
	// avance de calles:
	
	for (cuadra=0; cuadra<N; cuadra= cuadra+1)
	   {	   	
	   	 printf("caminando cuadra %d\n", cuadra);
	   	 printf("colocar marca en el mapa\n");
	   }
	
	printf("\n");
	
	// omision de llaves con 1 sola instruccion:
	
	for (cuadra=0; cuadra<N; cuadra++)		// cuadra= cuadra +1; cuadra+=1; cuadra++;
	   printf("cuadra= %d\n", cuadra);
	
	printf("\n");  

	// conteo descendente:
	
	for (k= N-1; k>=0; k--)				// k--, disminuye k en 1
	   printf("k= %d\n", k);
	   
	printf("\n");
	
	// conteo de 2 en 2:
	
	for (k=0; k<N; k= k+2)
	   printf("k= %d\n", k);
	   
	printf("\n");
	
	// conteo de 3 en 3:
	
	for (k=0; k<N; k+=3)
	   printf("k= %d\n", k);
	   
	printf("\n");
	
	// los primeros N pares:
	
	for (k=0; k<N; k++)
	   {
	   	 x= 2*k;
	   	 printf("x= %d\n", x);
	   }
	   
	printf("\n");
	
	
	// los primeros N impares:
	
	for (k=0; k<N; k++)
	   {
	   	 x= 2*k+1;
	   	 printf("x= %d\n", x);
	   }
	
	
	for (a=0; a<N; a++)
	   printf("a= %d", a);
	   
	   
	/*
	
	
	
	codigo;
	
	
	
	*/
	   
	a= cuadra*k+x;
	   
	return 0;
}


/* 
	for (inicializacion; condicion; actualizacion)
      {
      	ciclo;
	  }
*/



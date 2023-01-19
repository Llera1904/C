#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main(int argc, char *argv[])
{
	Arbol arbol= NULL;
	Elemento *elementos= NULL;
	int numeros[24]= {72, 7, 13, 9, 23, 12, 78, 55, 17, 41, 36, 99, 32, 31, 63, 28, 10, 30, 67, 2, 8, 5, 88, 43};
	int N= 24, k=0;
	int sw= FALSO;
	
	sw= crearArbol(&arbol);
	  
	elementos= (Elemento *) malloc(N*sizeof(Elemento));
	
	if (arbol!=NULL)
	  {
	  	for (k=0; k<N; k++)
	  	   {
	  	   		crearElemento(&(elementos[k]));
	  	   		escribirDato(elementos[k], numeros[k]);
	  	   		insertarElemento(arbol, elementos[k]);
	  	   		recorrerArbolEnOrden(arbol);
		   }
		   
		printf("\nRecorrido en orden:\n");
		recorrerArbolEnOrden(arbol);	
			
		printf("\nRecorrido en preorden:\n");
		recorrerArbolPreOrden(arbol);
		
		printf("\nRecorrido en postorden:\n");		
		recorrerArbolPostOrden(arbol);
		
		printf("\nRecorrido descendente:\n");	
		recorrerArbolEnOrdenDescendente(arbol);
		   
	  	for (k=0; k<N; k++)
	  	   {
	  	   		eliminarElemento(arbol, elementos[k]);
	  	   		recorrerArbolEnOrden(arbol);
		   }

		printf("A\n");
		destruirArbol(&arbol);
		
		printf("B\n");
		for (k=N-1; k>=0; k--)
		   destruirElemento(&(elementos[k]));
		   
		printf("C\n");
		
		free(elementos);
	  }
	  
	return 0;
}

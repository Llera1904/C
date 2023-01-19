#include <stdio.h>
#include <stdlib.h>
#include "libarr.h"

int main(int argc, char *argv[])
{
	int arreglo[10];
	int L= 10, max=10;
	int x=0, pos=-1, k=0;
	
	inicializarArreglo(arreglo, L);
	imprimirArreglo(arreglo, L);
	
	inicializarAleatoriamente(arreglo, L, max);
	imprimirArreglo(arreglo, L);
	
	printf("numero deseado a buscar: ");
	scanf("%d", &x);
	
	pos= buscarNumeroArreglo(arreglo, L, x);
	if (pos!=NOLOCALIZADO)
	  printf("A Ubicacion en el arreglo= %d\n", pos);
	else
	  printf("A No localizado\n");
	  
	ordenarArreglo(arreglo, L);
	imprimirArreglo(arreglo, L);
	
	for (k=0; k<L; k++)
	   printf("%d ", arreglo[k]);
	   
	printf("\n");
	 
	/* 
	pos= buscarNumeroArregloFulminante(arreglo, L, x);
	if (pos!=NOLOCALIZADO)
	  printf("B Ubicacion en el arreglo= %d\n", pos);
	else
	  printf("B No localizado\n");
	  
	pos= buscarNumeroArregloFulminante(arreglo, -1*L, x);
	if (pos!=NOLOCALIZADO && pos!=LONGITUDNEGATIVA)
	  printf("C Ubicacion en el arreglo= %d\n", pos);
	else
	  {
	  	if (pos==NOLOCALIZADO)
	  	  printf("C No localizado\n");
	  	if (pos==LONGITUDNEGATIVA)
	  	  printf("C Longitud del arreglo es negativa");
	  }
	*/
	
	return 0;
}


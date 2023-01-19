#ifndef	LIBARR_C
#define	LIBARR_C

#include <stdio.h>
#include <stdlib.h>
#include "libarr.h"


void inicializarArreglo(int arr[], int N)
{
	int k=0;
	
	for (k=0; k<N; k++)
       arr[k]= 0;
}

void imprimirArreglo(int arr[], int N)
{
	int k=0;
	
	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}

void inicializarAleatoriamente(int arr[], int N, int lim)
{
	int k=0;
	
	srand(time(NULL));
	
	for (k=0; k<N; k++)
	   arr[k]= rand()%lim;
}

int buscarNumeroArreglo(int arr[], int N, int num)
{
	int k=0;
	int localidad= NOLOCALIZADO;
	
	for (k=0; k<N; k++)   
	   {
	   	  if (arr[k]==num)
	   	    {			   
	   	   		localidad= k;
	   	   		break;
	   	   	}
	   }
	
	// printf("instruccion afuera del ciclo\n");
	
	return(localidad);	
}

int buscarNumeroArregloFulminante(int arr[], int N, int num)
{
	int k=0;
	int localidad= NOLOCALIZADO;
	
	if (N<=0)
	  return(LONGITUDNEGATIVA);
	
	for (k=0; k<N; k++)   
	   {
	   	  if (arr[k]==num)
	   	    {			   
	   	   		localidad= k;
	   	   		return(localidad);
	   	   	}
	   }
	   
	printf("instruccion afuera del ciclo\n");
	   
	return(localidad);	
}

// return: concluye la ejecucion de la funcion

void ordenarArreglo(int arr[], int N)
{
	int i=0, j=0;
	int aux= 0;
	
	for (i=0; i<N; i++)
	   {
	   		for (j=i+1; j<N; j++)
	   		   {
	   		   		if (arr[j]<arr[i])	
	   		   		  {
	   		   		  		aux= arr[i];
	   		   		  		arr[i]= arr[j];
	   		   		  		arr[j]= aux;
					  }
			   }
	   }
	
}

#endif

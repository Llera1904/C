#ifndef ELEMENTO_C
#define ELEMENTO_C

#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"


int crearElemento(Elemento *e)
{
	Elemento x= NULL;
	
	x= (Elemento) malloc(sizeof(t_elemento));
	
	if (x==NULL)
	  return(FALSO);
	  
	*e= x;  
	
	return(VERDADERO);
}

int destruirElemento(Elemento *e)
{
	Elemento aux= NULL;
	
	if (e==NULL)
	  return(FALSO);
	  
	aux= *e;	  
	free(aux);
	
	*e= NULL;
	
	return(VERDADERO);
}

int escribirDato(Elemento e, int dato)
{
	if (e==NULL)
	  return(FALSO);
	  
	e->dato= dato;
	
	return(VERDADERO);
}

int leerDato(Elemento e, int *dato)
{
	if (e==NULL)
	  return(FALSO);
	  
	*dato= e->dato;
	//printf("dato: %d\n", e->dato);
	
	return(VERDADERO);
}

int compararElementos(Elemento a, Elemento b)
{
	if (a==NULL || b==NULL)
	  return(DIFERENTE);
	  
	if (a->dato < b->dato)
	  return(MENOR);
	  
	if (a->dato > b->dato)
	  return(MAYOR);
	  
	return(IGUAL);
}

#endif

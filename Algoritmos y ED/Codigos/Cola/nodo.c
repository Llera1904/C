#ifndef NODO_C
#define NODO_C

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int crearNodo(Nodo *n)
{
	Nodo m= NULL;
	
	m= (Nodo) malloc(sizeof(t_nodo));
	
	if (m==NULL)
	  return(FALSO);
	
	m->enlaceA= NULL;
	m->elem= NULL;
	m->enlaceB= NULL;
	
	*n= m;
	
	return(VERDADERO);
}

int destruirNodo(Nodo *n)
{
	Nodo aux= NULL;
	
	if (*n==NULL)
	  return(FALSO);
	  
	aux= *n;
	  
	aux->elem= NULL;	//la destrucción del elemento se realiza por separado

	aux->enlaceA= NULL;	
	aux->enlaceB= NULL;
		
	free(aux);
	
	*n= NULL;
	
	return(VERDADERO);
}

int escribirElemento(Nodo n, Elemento e)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->elem= e;					// copia de direcciones
		
	return(VERDADERO);
}

int leerElemento(Nodo n, Elemento *e)
{
	if (n==NULL)
	  return(FALSO);
	  
	*e= n->elem;				// copia de direcciones
	
	return(VERDADERO);
}

int conectarEnlaceA(Nodo n, Nodo eA)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceA= eA;				// copia de la referencia
	
	return(VERDADERO);
}

int conectarEnlaceB(Nodo n, Nodo eB)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceB= eB;
	
	return(VERDADERO) ;
}

/* funcion ejemplo para multiples enlaces
int conectarEnlaceX(Nodo n, Nodo eX, int k)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaces[k]= eX;
	
	return(VERDADERO) ;
}
*/

int consultarEnlaceA(Nodo n, Nodo *eA)
{
	if (n==NULL)
	  return(FALSO);
	  
	*eA= n->enlaceA;
	
	return(VERDADERO) ;
}

int consultarEnlaceB(Nodo n, Nodo *eB)
{
	if (n==NULL)
	  return(FALSO);
	  
	*eB= n->enlaceB;
	
	return(VERDADERO) ;
}

int desconectarEnlaceA(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceA= NULL;
	
	return(VERDADERO) ;
}

int desconectarEnlaceB(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceB= NULL;
	
	return(VERDADERO) ;
}

#endif

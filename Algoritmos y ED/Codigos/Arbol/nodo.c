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
	
	m->enlaceDer= NULL;
	m->elem= NULL;
	m->enlaceIzq= NULL;
	
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

	aux->enlaceDer= NULL;	
	aux->enlaceIzq= NULL;
		
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

int conectarEnlaceDerecho(Nodo n, Nodo eA)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceDer= eA;				// copia de la referencia
	
	return(VERDADERO);
}

int conectarEnlaceIzquierdo(Nodo n, Nodo eB)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceIzq= eB;
	
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

int consultarEnlaceDeerecho(Nodo n, Nodo *eA)
{
	if (n==NULL)
	  return(FALSO);
	  
	*eA= n->enlaceDer;
	
	return(VERDADERO) ;
}

int consultarEnlaceIzquierdo(Nodo n, Nodo *eB)
{
	if (n==NULL)
	  return(FALSO);
	  
	*eB= n->enlaceIzq;
	
	return(VERDADERO) ;
}

int desconectarEnlaceDerecho(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceDer= NULL;
	
	return(VERDADERO) ;
}

int desconectarEnlaceIzquierdo(Nodo n)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->enlaceIzq= NULL;
	
	return(VERDADERO) ;
}

#endif

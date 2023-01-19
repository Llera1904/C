#ifndef NODO_C
#define NODO_C

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int crearNodo(Nodo *n, int grado)
{
	Nodo m= NULL;
	int k=0;
	
	if (grado<0)
	  return(FALSO);	  
	
	m= (Nodo) malloc(sizeof(t_nodo));
	
	if (m==NULL)
	  return(FALSO);
	
	m->elem= NULL;
	m->grado= grado;
	m->enlaces= (Nodo *) malloc(grado*sizeof(Nodo));
	
	if (m->enlaces==NULL)
	  {
	  	free(m);
	  	return(FALSO);
	  }
	
	for (k=0; k<grado; k++)
	   m->enlaces[k]= NULL;
	
	*n= m;
	
	return(VERDADERO);
}

int destruirNodo(Nodo *n)
{
	Nodo aux= NULL;
	int k=0;
	
	if (*n==NULL)
	  return(FALSO);
	  
	aux= *n;
	  
	aux->elem= NULL;	//la destrucción del elemento se realiza por separado

	for (k=0; k<aux->grado; k++)
	   aux->enlaces[k]= NULL;
	   
	free(aux->enlaces);
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

int conectarEnlace(Nodo fuente, Nodo destino)
{
	int k=0;
	
	if (fuente==NULL)
	  return(FALSO);
	  
	for (k=0; k<fuente->grado; k++)
	   if (fuente->enlaces[k]==NULL)
	     {
	     	fuente->enlaces[k]= destino;
	     	return(VERDADERO);
	     }
	     
	return(FALSO);
}

int conectarEnlacePuerto(Nodo fuente, Nodo destino, int puerto)
{
	if (fuente==NULL)
	  return(FALSO);
	  
	if (puerto<0 || puerto>=fuente->grado)
	  return(FALSO);
	  
	if (fuente->enlaces==NULL)
	  return(FALSO);
	
	fuente->enlaces[puerto]= destino;
	
	return(VERDADERO);
}

int consultarEnlace(Nodo fuente, Nodo *destino, int puerto)
{
	if (fuente==NULL)
	  return(FALSO);
	  
	if (puerto<0 || puerto>=fuente->grado)
	  return(FALSO);
	  
	if (fuente->enlaces==NULL)
	  return(FALSO);
	
	*destino= fuente->enlaces[puerto];
	
	return(VERDADERO);
}

int consultarEnlaces(Nodo fuente, Nodo **conexiones, int *grado)
{
	if (fuente==NULL)
	  return(FALSO);
	  
	if (fuente->enlaces==NULL)
	  return(FALSO);
	
	*conexiones= fuente->enlaces;
	*grado= fuente->grado;
	
	return(VERDADERO);
}

int desconectarEnlacePuerto(Nodo fuente, int puerto)
{
	int k=0;
	
	if (fuente==NULL)
	  return(FALSO);
	  
	if (puerto<0 || puerto>=fuente->grado)
	  return(FALSO);
	  
	if (fuente->enlaces==NULL)
	  return(FALSO);
	  
	fuente->enlaces[puerto]= NULL;
		 
	return(VERDADERO);
}

int desconectarEnlace(Nodo fuente, Nodo destino)
{
	int k=0;
	
	if (fuente==NULL)
	  return(FALSO);
	  
	if (fuente->enlaces==NULL)
	  return(FALSO);
	  
	fuente->enlaces[k]= NULL;
	for (k=0; k<fuente->grado; k++)
	   if (fuente->enlaces[k]==destino)
	     {
	     	fuente->enlaces[k]= NULL;
	     	return(VERDADERO);
		 }
		 
	return(FALSO);
}

#endif

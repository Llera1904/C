#ifndef ARBOL_C
#define ARBOL_C

#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

int crearArbol(Arbol *b)
{
	Arbol a= NULL;
	
	a= (Arbol) malloc(sizeof(t_arbol));
	
	if (a!=NULL)
	  {
	  	a->cantidad=0;
	  	a->raiz= NULL;
	  	*b= a;				// copia direccion donde se encuentra el arbol a
	  	return(VERDADERO);
	  }
	
	*b= NULL;
	
	return(FALSO);
}

int insertarElemento(Arbol a, Elemento e)
{
	Nodo nuevo= NULL;
	
	if (a==NULL)
	  return(FALSO);
	  
	nuevo= insertarElementoRecursivo(a->raiz, e);  
	  
	if (a->raiz==NULL)
	    a->raiz= nuevo;
	  
	if (nuevo!=NULL)
	  a->cantidad++;  
	
	return(VERDADERO);  
}


Nodo insertarElementoRecursivo(Nodo central, Elemento e)
{
	Nodo nuevo= NULL;
	Nodo izq= NULL, der= NULL;
	
	if (central==NULL)
	  {
	  	crearNodo(&nuevo);
	  	if (nuevo!=NULL)
	  	  nuevo->elem= e;
	  	return(nuevo);  
	  }
	  
	izq= central->enlaceIzq;
	der= central->enlaceDer;
	
	if (compararElementos(e, central->elem)==MENOR)	// e < central->elem
	  {
	  	nuevo= insertarElementoRecursivo(izq, e);
	  	if (izq==NULL)
	  	  central->enlaceIzq= nuevo;
	  }	  
	else	// if (e>=central->elem)
	  {
	  	nuevo= insertarElementoRecursivo(der, e);
	  	if (der==NULL)
	  	  central->enlaceDer= nuevo;
	  }	 
	  
   return(nuevo);	   
}

int buscarElemento(Arbol a, Elemento e)
{
	Nodo nodo= NULL;
	
	if (a==NULL)
	  return(FALSO);
	
	if (a->raiz!=NULL)
	  nodo= buscarElementoRecursivo(a->raiz, e);
	  
	if (nodo==NULL)
	  return(FALSO);    
	
	return(VERDADERO);
}

Nodo buscarElementoRecursivo(Nodo central, Elemento e)
{
	Nodo localizado=NULL;
	
	if (central==NULL)
	  return(NULL);
	  
	if (compararElementos(e, central->elem)==IGUAL)
	  return(central);
	  
	if (compararElementos(e, central->elem)==MENOR) // e < central->elem
	  localizado= buscarElementoRecursivo(central->enlaceIzq, e);	     	  
	else// if (e>central->elem)
	  localizado= buscarElementoRecursivo(central->enlaceDer, e);
	  
	return(localizado);  
}

Nodo buscarMinimo(Nodo central)
{
	Nodo min= NULL;
	
	if (central==NULL)
	  return(NULL);
	  
	min= central;
	
	while (min->enlaceIzq!=NULL)
	     min= min->enlaceIzq;

	return(min);	
}

Nodo buscarMaximo(Nodo central)
{
	Nodo max= NULL;
	
	if (central==NULL)
	  return(NULL);
	  
	max= central;
	
	while (max->enlaceDer!=NULL)
	     max= max->enlaceDer;

	return(max);	
}

int recorrerArbolEnOrden(Arbol a)
{
	if (a==NULL)
	  return(FALSO);
	  
	if (a->raiz==NULL)
	  return(FALSO);
	  
	recorrerNodosEnOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	  
}

void recorrerNodosEnOrden(Nodo central)
{
	int dato=0;
	
	if (central==NULL)
	  return;
	  
	recorrerNodosEnOrden(central->enlaceIzq);
	
	leerDato(central->elem, &dato);
	printf("%d ", dato);
	
	recorrerNodosEnOrden(central->enlaceDer);
}

int recorrerArbolPreOrden(Arbol a)
{
	if (a==NULL)
	  return(FALSO);
	  
	if (a->raiz==NULL)
	  return(FALSO);
	  
	recorrerNodosPreOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	  
}

void recorrerNodosPreOrden(Nodo central)
{
	int dato=0;
	
	if (central==NULL)
	  return;

	leerDato(central->elem, &dato);
	printf("%d ", dato);
		  
	recorrerNodosPreOrden(central->enlaceIzq);
	recorrerNodosPreOrden(central->enlaceDer);
}

int recorrerArbolPostOrden(Arbol a)
{
	if (a==NULL)
	  return(FALSO);
	  
	if (a->raiz==NULL)
	  return(FALSO);
	  
	recorrerNodosPostOrden(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	  
}

void recorrerNodosPostOrden(Nodo central)
{
	int dato= 0;
	
	if (central==NULL)
	  return;
	  
	recorrerNodosPostOrden(central->enlaceIzq);	
	recorrerNodosPostOrden(central->enlaceDer);
	
	leerDato(central->elem, &dato);
	printf("%d ", dato);
}

int recorrerArbolEnOrdenDescendente(Arbol a)
{
	if (a==NULL)
	  return(FALSO);
	  
	if (a->raiz==NULL)
	  return(FALSO);
	  
	recorrerNodosEnOrdenDescendente(a->raiz);
	
	printf("\n");
	
	return(VERDADERO);	  
}

void recorrerNodosEnOrdenDescendente(Nodo central)
{
	int dato= 0;
	if (central==NULL)
	  return;
	  
	recorrerNodosEnOrdenDescendente(central->enlaceDer);
	
	leerDato(central->elem, &dato);
	printf("%d ", dato);
	
	recorrerNodosEnOrdenDescendente(central->enlaceIzq);
}

int eliminarElemento(Arbol a, Elemento e)
{
	int sw= FALSO;

	if (a==NULL)
	  return(FALSO);
	
	if (a->raiz!=NULL)
	  sw= eliminarElementoRecursivo(&(a->raiz), e);
	
	return(sw);
}

int eliminarElementoRecursivo(Nodo *foco, Elemento e)
{
	Nodo localizado=NULL;
	Nodo central= NULL, eliminar=NULL, eIzq= NULL, eDer= NULL;
	Nodo cIzq= NULL, cDer= NULL;
	Nodo max= NULL, min= NULL;
	int sw= FALSO;
	
	central = *foco;
	
	if (central==NULL)
	  return(FALSO);

    cIzq= central->enlaceIzq;
    cDer= central->enlaceDer;
    
    // printf("%d\n", central->dato);
    
    if (compararElementos(e, central->elem)==IGUAL)
      {
      	printf("\neliminando: %d\n", e->dato);
      	if (cIzq!=NULL)
      	  {
      	  	max= buscarMaximo(cIzq);
      	  	max->enlaceDer= cDer;
      	  	destruirNodo(&central);
      	    *foco= cIzq;
      	  	return(VERDADERO);
		  }
		else
		  {
      	  	destruirNodo(&central);
      		*foco= cDer;
      	  	return(VERDADERO);
		  }
		
		/*
		if (cDer!=NULL)
		  {
		  	min= buscarMinimo(cDer);
      	  	min->enlaceIzq= cIzq;
      	  	*foco= cDer;
      	  	destruirNodo(&central);
      	  	return(VERDADERO);
		  }*/
	  }
	  
	if (compararElementos(e, central->elem)==MENOR)
	  {
	    sw= eliminarElementoRecursivo(&(central->enlaceIzq), e);
	    if (sw==VERDADERO)
	      return(VERDADERO);
	  }    
	  
	if (compararElementos(e, central->elem)==MAYOR)
	  {
	    sw= eliminarElementoRecursivo(&(central->enlaceDer), e);
	    if (sw==VERDADERO)
	      return(VERDADERO);	    
	  }    
	
	return(sw);  
}

void destruirArbol(Arbol *b)
{
	Arbol a= NULL;
	int sw= FALSO;
	
	a= *b;
	
	if (a==NULL)
	  return;
	  
	if (a->raiz!=NULL)
	  destruirNodosRecursivamente(a->raiz);

	  
	if (a->raiz!=NULL)
	  destruirNodo(&(a->raiz));
	  
	a->raiz= NULL;
	a->cantidad= 0;
	
	free(a); 
	*b= NULL;
	 
}

void destruirNodosRecursivamente(Nodo central)
{
	Nodo izq=NULL, der=NULL;
	
	if (central==NULL)
	  return;
	  
	izq= central->enlaceIzq;
	der= central->enlaceDer;
	
	if (izq!=NULL)
	  {	  
	    central->enlaceIzq= NULL;
	    destruirNodosRecursivamente(izq);   
	  }
	  
	if (der!=NULL)
	  {	  
	    central->enlaceDer= NULL;
	    destruirNodosRecursivamente(der);   
	  }
	  
	if (izq==NULL && der==NULL)
	  destruirNodo(&central);
}

#endif

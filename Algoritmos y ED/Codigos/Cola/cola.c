#ifndef COLA_C
#define COLA_C

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

// Cola = (struct cola *)
// t_cola = (struct cola)

int crearCola(Cola *c)
{
	Cola q= NULL;

	q= (Cola) malloc(sizeof(t_cola));

	if (q==NULL)
	  return(FALSO);

	q->primero= NULL;
	q->ultimo= NULL;
	q->longitud= 0;

	*c= q;

	return(VERDADERO);
}


int insertarElemento(Cola c, Elemento e)
{
	Nodo n= NULL;
	int sw= FALSO;
	
	if (c==NULL)
	  return(FALSO);
	
	sw= crearNodo(&n);
	
	if (sw==VERDADERO)
		{
			sw= escribirElemento(n, e);
			if (sw==VERDADERO)
				{
					if (c->longitud==0)
					  c->primero= n;
					else
					  conectarEnlaceA(c->ultimo, n);
					  					  
					c->ultimo= n;
					(c->longitud)++;
					
					return(VERDADERO);
				}
		}
		
	return(FALSO);
}

int quitarElemento(Cola c, Elemento *e)
{
	int sw= FALSO;
	Nodo siguiente= NULL;
	
	if (c==NULL)
	  return(FALSO);
	  
	if (c->longitud==0)
	  return(FALSO);
	  						
	sw= leerElemento(c->primero, e);
	
	if (sw==VERDADERO)
		{
			sw= consultarEnlaceA(c->primero, &siguiente);			
			if (sw==VERDADERO)
				{				
					sw= desconectarEnlaceA(c->primero);
					if (sw==VERDADERO)
						{		
							sw= destruirNodo(&(c->primero));
							if (sw==VERDADERO)
								{	
									c->primero= siguiente;
									(c->longitud)--;
							
									if (c->longitud==0)
							  			{
							  				c->primero= NULL;
							  				c->ultimo= NULL;
							  			}
							  		return(VERDADERO);
							  	}							
						}
				}
		}
		
	return(FALSO);
}

int consultarPrimero(Cola c, Elemento *e)
{
	int sw= FALSO;
	
	if (c==NULL)
	  return(FALSO);
	  
	if (c->longitud==0 || c->primero==NULL)
	  return(FALSO);
	  
	sw= leerElemento(c->primero, e);
	  
	return(sw);
}

int destruirCola(Cola *q)
{
	Cola c= NULL;
	Nodo siguiente= NULL;
	int sw= FALSO;
	
	c= *q;
		
	if (c==NULL)
	  return(FALSO);
	  
	while(c->primero!=NULL)
	{
		sw= consultarEnlaceA(c->primero, &siguiente);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= desconectarEnlaceA(c->primero);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= destruirNodo(&(c->primero));
		if (sw==FALSO)
		  return(FALSO);
		
		c->primero= siguiente;
		c->longitud--;
	}
	
	c->primero= NULL;
	c->ultimo= NULL;
	free(c);
	
	*q= NULL;
	
	return(VERDADERO);
}

int imprimirCola(Cola c)
{
	Nodo siguiente= NULL, nodo= NULL;
	Elemento e= NULL;
	int sw= FALSO;
	int dato= 0;
			
	printf("<");
	if (c==NULL)
	  return(FALSO);
	  
	nodo= c->primero;
	  
	while(nodo!=NULL)
	{
		leerElemento(nodo, &e);
		leerDato(e, &dato);
		printf("%d, ", dato);
		
		sw= consultarEnlaceA(nodo, &siguiente);
		if (sw==FALSO)
		  return(FALSO);
		  
		nodo= siguiente;
	}
	printf(">\n");
	return(VERDADERO);
}

#endif

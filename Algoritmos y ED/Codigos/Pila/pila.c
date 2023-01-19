#ifndef PILA_C
#define PILA_C
#include "pila.h"

int crearPila(Pila *p)
{
	Pila q= NULL;
	
	q= (Pila) malloc(sizeof(t_pila));
	
	if (q==NULL)
	  return(FALSO);
	  
	q->base= NULL;
	q->tope= NULL;
	q->longitud= 0;
	
	*p= q;
	
	return(VERDADERO);
}


int insertarElemento(Pila p, Elemento e)
{
	Nodo n= NULL;
	int sw= FALSO;
	
	if (p==NULL)
	  return(FALSO);
	
	sw= crearNodo(&n);
	
	if (sw==VERDADERO)
		{
			sw= escribirElemento(n, e);
			if (sw==VERDADERO)
				{
					if (p->longitud==0)
					  p->base= n;
					else
					  conectarEnlaceA(n, p->tope);
					  
					p->tope= n;
					(p->longitud)++;
					return(VERDADERO);
				}
		}
		
	return(FALSO);
}

int quitarElemento(Pila p, Elemento *e)
{
	int sw= FALSO;
	Nodo abajo= NULL;
	
	if (p==NULL)
	  return(FALSO);
	  
	if (p->longitud==0)
	  return(FALSO);
	  
	sw= leerElemento(p->tope, e);
	
	if (sw==VERDADERO)
		{
			sw= consultarEnlaceA(p->tope, &abajo);			
			if (sw==VERDADERO)
				{				
					sw= desconectarEnlaceA(p->tope);
					if (sw==VERDADERO)
						{		
							sw= destruirNodo(&(p->tope));
							if (sw==VERDADERO)
								{	
									p->tope= abajo;
									(p->longitud)--;
							
									if (p->longitud==0)
							  			{
							  				p->tope= NULL;
							  				p->base= NULL;
							  			}
							  			
							  		return(VERDADERO);
							  	}							
						}
				}
		}
		
	return(FALSO);
}

int consultarTope(Pila p, Elemento *e)
{
	int sw= FALSO;
	
	if (p==NULL)
	  return(FALSO);
	  
	if (p->longitud==0 || p->tope==NULL || p->base==NULL)
	  return(FALSO);
	  
	sw= leerElemento(p->tope, e);
	  
	return(sw);
}

int destruirPila(Pila *q)
{
	Pila p= NULL;
	Nodo siguiente= NULL;
	int sw= FALSO;
	
	p= *q;
	
	if (p==NULL)
	  return(FALSO);
	  
	while(p->tope!=NULL)
	{
		sw= consultarEnlaceA(p->tope, &siguiente);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= desconectarEnlaceA(p->tope);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= destruirNodo(&(p->tope));
		if (sw==FALSO)
		  return(FALSO);
		
		p->tope= siguiente;
		p->longitud--;
	}
	
	p->tope= NULL;
	p->base= NULL;
	free(p);
	
	*q= NULL;
	
	return(VERDADERO);
}

int imprimirPila(Pila p)
{
	Nodo siguiente= NULL, nodo= NULL;
	Elemento e= NULL;
	int sw= FALSO;
	int dato= 0;
			
	printf("<");
	if (p==NULL)
	  return(FALSO);
	  
	nodo= p->tope;
	  
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

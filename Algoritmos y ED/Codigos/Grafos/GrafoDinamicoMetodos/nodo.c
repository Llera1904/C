#ifndef NODO_C
#define NODO_C

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int crearNodo(Nodo *n, int id, int status)
{
	Nodo m= NULL;
	int k=0;
	
	m= (Nodo) malloc(sizeof(t_nodo));
	
	if (m==NULL)
	  return(FALSO);
	
	m->id= id;
	m->elem= NULL;
	
	m->profundidad= -1;
	m->peso= 0;
	m->gradEnt= 0;
	m->gradSal= 0;

	m->enlace= NULL;
	m->entrada= NULL;
	m->salida= NULL;

	m->status= status;
	*n= m;
	
	return(VERDADERO);
}

int destruirNodo(Nodo *n)
{
	Nodo m= NULL, aux= NULL, sig= NULL;
	int k=0;
	
	if (*n==NULL)
	  return(FALSO);
	  
	m= *n;
	  
	m->enlace= NULL;
	m->entrada= NULL;
	m->salida= NULL;
	
	//desconectarCompletamente(m);

	free(m);
	
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

int establecerProfundidad(Nodo n, int p)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->profundidad= p;
		
	return(VERDADERO);	
}

int establecerPeso(Nodo n, int w)
{
	if (n==NULL)
	  return(FALSO);
	  
	n->peso= w;
		
	return(VERDADERO);		
}

int consultarID(Nodo n, int *id)
{
	if (n==NULL)
	  return(FALSO);
	  
	*id= n->id;
		
	return(VERDADERO);		
}

int consultarProfundidad(Nodo n, int *p)
{
	if (n==NULL)
	  return(FALSO);
	  
	*p= n->profundidad;
		
	return(VERDADERO);		
}

int consultarGradoEntrada(Nodo n, int *g)
{
	if (n==NULL)
	  return(FALSO);
	  
	*g= n->gradEnt;
		
	return(VERDADERO);	
}

int consultarGradoSalida(Nodo n, int *g)
{
	if (n==NULL)
	  return(FALSO);
	  
	*g= n->gradSal;
		
	return(VERDADERO);	
}

int consultarPeso(Nodo n, int *w)
{
	if (n==NULL)
	  return(FALSO);
	  
	*w= n->peso;
		
	return(VERDADERO);		
}

int consultarStatus(Nodo n, int *status)
{
	if (n==NULL)
	  return(FALSO);
	  
	*status= n->status;
		
	return(VERDADERO);		
}

int conectarEnlace(Nodo fuente, Nodo destino)
{
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	fuente->enlace= destino;
		
	return(VERDADERO);	
}

int conectarEntrada(Nodo centro, Nodo entrada)
{
	if (centro==NULL || entrada==NULL)
	  return(FALSO);
	  
	centro->entrada= entrada;
		
	return(VERDADERO);	
}

int conectarSalida(Nodo centro, Nodo salida)
{
	if (centro==NULL || salida==NULL)
	  return(FALSO);
	  
	centro->salida= salida;
		
	return(VERDADERO);	
}

int consultarEnlace(Nodo *destino, Nodo fuente)
{
	if (fuente==NULL)
	  return(FALSO);
	  
	*destino= fuente->enlace;
		
	return(VERDADERO);	
}

int consultarEntrada(Nodo *entrada, Nodo centro)
{
	if (centro==NULL)
	  return(FALSO);
	  
	*entrada= centro->entrada;
		
	return(VERDADERO);	
}

int consultarSalida(Nodo *salida, Nodo centro)
{
	if (centro==NULL)
	  return(FALSO);
	  
	*salida= centro->salida;
		
	return(VERDADERO);	
}

int desconectarEnlace(Nodo fuente)
{
	if (fuente==NULL)
	  return(FALSO);
	  
	fuente->enlace= NULL;
		
	return(VERDADERO);
}

int desconectarEntrada(Nodo centro)
{
	if (centro==NULL)
	  return(FALSO);
	  
	centro->entrada= NULL;
		
	return(VERDADERO);	
}

int desconectarSalida(Nodo centro)
{
	if (centro==NULL)
	  return(FALSO);
	  
	centro->salida= NULL;
		
	return(VERDADERO);	
}

int consultarConexion(Nodo *arista, Nodo fuente, Nodo destino)
{
	Nodo aux= NULL;
	int sw= FALSO;
	
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	aux= fuente->salida;
	
	while(aux!=NULL)
	{
		if (aux->salida==destino)
		  {
			*arista= aux;
		  	return(VERDADERO);
		  }
		  
		aux= aux->enlace;
	}
	
	return(FALSO);	
}

int agregarConexionSalida(Nodo fuente, Nodo destino, int peso)
{
	Nodo arista= NULL, ultimo= NULL, aux= NULL;
	int sw= FALSO;
	
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	sw= crearNodo(&arista, (fuente->gradSal)+1, ARISTA);
	if (sw==FALSO)
	  return(FALSO);
	  
	arista->entrada= fuente;
	arista->salida= destino;
	arista->peso= peso;
	  
	if (fuente->salida==NULL)
	  {
	  	fuente->salida= arista;
	  	fuente->gradSal= 1;
	  	return(VERDADERO);
	  }
	
	aux= fuente->salida;
	
	while(aux!=NULL)
	{
		if (aux->salida==destino)
		  {
		  	destruirNodo(&arista);
		  	return(VERDADERO);
		  }
		ultimo= aux;
		aux= aux->enlace;
	}
	
	ultimo->enlace= arista;
	(fuente->gradSal)++;
	
	return(VERDADERO);
}

int agregarConexionEntrada(Nodo fuente, Nodo destino, int peso)
{
	Nodo arista= NULL, ultimo= NULL, aux= NULL;
	int sw= FALSO;
	
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	sw= crearNodo(&arista, (destino->gradEnt)+1, ARISTA);
	if (sw==FALSO)
	  return(FALSO);
	  
	arista->entrada= fuente;
	arista->salida= destino;
	arista->peso= peso;
	  
	if (destino->entrada==NULL)
	  {
	  	destino->entrada= arista;
	  	destino->gradEnt= 1;
	  	return(VERDADERO);
	  }
	
	aux= destino->entrada;
	
	while(aux!=NULL)
	{
		if (aux->entrada==fuente)
		  {
		  	destruirNodo(&arista);
		  	return(VERDADERO);
		  }
		ultimo= aux;
		aux= aux->enlace;
	}
	
	ultimo->enlace= arista;
	(destino->gradEnt)++;
	
	return(VERDADERO);
}

int agregarConexionNodos(Nodo fuente, Nodo destino, int peso)
{
	int sw= FALSO;
	
	sw= agregarConexionEntrada(fuente, destino, peso);
	if (sw==FALSO)
	  return(FALSO);
	
	sw= agregarConexionSalida(fuente, destino, peso);
	if (sw==FALSO)
	  {
	  	// remover arista de entrada;
	  	return(FALSO);
	  }
	
	return(VERDADERO);
}

int removerConexionSalida(Nodo fuente, Nodo destino)
{
	Nodo arista= NULL, ant= NULL, aux= NULL, sig= NULL;
	int sw= FALSO;
	
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	aux= fuente->salida;
	
	while(aux!=NULL)
	{
		sig= aux->enlace;
		
		if (aux->salida==destino)
		  {
		  	destruirNodo(&aux);
		  	if (ant==NULL)
		  	  fuente->salida= sig;
		  	else
		  	  ant->enlace= sig;
		  	  
		  	(fuente->gradSal)--;
		  	  
		  	return(VERDADERO);
		  }
		  
		ant= aux;
		aux= aux->enlace;
	}
	
	return(VERDADERO);	
}

int removerConexionEntrada(Nodo fuente, Nodo destino)
{
	Nodo arista= NULL, ant= NULL, aux= NULL, sig= NULL;
	int sw= FALSO;
	
	if (fuente==NULL || destino==NULL)
	  return(FALSO);
	  
	aux= destino->entrada;
	
	while(aux!=NULL)
	{
		sig= aux->enlace;
		
		if (aux->entrada==fuente)
		  {
		  	destruirNodo(&aux);
		  	if (ant==NULL)
		  	  destino->entrada= sig;
		  	else
		  	  ant->enlace= sig;
		  	  
		  	(destino->gradEnt)--;
		  	  
		  	return(VERDADERO);
		  }
		ant= aux;
		aux= aux->enlace;
	}
	
	return(VERDADERO);	
}

int removerConexionNodos(Nodo fuente, Nodo destino)
{
	int sw= FALSO;
	
	sw= removerConexionEntrada(fuente, destino);
	if (sw==FALSO)
	  return(FALSO);
	
	sw= removerConexionSalida(fuente, destino);
	if (sw==FALSO)
	  {
	  	// agregar arista de entrada;
	  	return(FALSO);
	  }
	
	return(VERDADERO);
}

int desconectarCompletamente(Nodo centro)
{
	int sw= FALSO;
	
	sw= desconectarEntradas(centro);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= desconectarSalidas(centro);
	if (sw==FALSO)
	  return(FALSO);
	
	return(VERDADERO);
}

int desconectarEntradas(Nodo destino)
{
	Nodo arista= NULL, sig= NULL;
	int sw= FALSO;
	
	if (destino==NULL)
	  return(FALSO);
	  
	arista= destino->entrada;
	
	while(arista!=NULL)
	{
		sw= removerConexionSalida(arista->entrada, destino);	
		if (sw==FALSO)
		  return(FALSO);
		  
		sig= arista->enlace;
		
		sw= destruirNodo(&arista);
		if (sw==FALSO)
		  return(FALSO);
		  
		arista= sig;
		destino->entrada= arista;
		(destino->gradEnt)--;
	}
	
	destino->entrada= NULL;
	
	return(VERDADERO);
}

int desconectarSalidas(Nodo fuente)
{
	Nodo arista= NULL, sig= NULL;
	int sw= FALSO;
	
	if (fuente==NULL)
	  return(FALSO);
	  
	arista= fuente->salida;
	
	while(arista!=NULL)
	{
		sw= removerConexionEntrada(fuente, arista->salida);	
		if (sw==FALSO)
		  return(FALSO);
		  
		sig= arista->enlace;
		
		sw= destruirNodo(&arista);
		if (sw==FALSO)
		  return(FALSO);
		  
		arista= sig;
		fuente->salida= arista;
		
		(fuente->gradSal)--;
	}
	
	fuente->salida= NULL;
	
	return(VERDADERO);
}

int compararID(Nodo centro, int id)
{
	
	if (centro==NULL)
	  return(FALSO);
	  
	// printf(" id: %d :: %d\n", centro->id, id);
	
	if (centro->id==id)
	  return(VERDADERO);
	  
	return(FALSO);
}

#endif

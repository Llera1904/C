#ifndef GRAFODINAMICO_C
#define GRAFODINAMICO_C

#include <stdio.h>
#include <stdlib.h>

#include "grafodinamico.h"

// Creacion y destruccion:
int crearGrafo(GrafoDinamico *g)
{
	GrafoDinamico q= NULL;
	int k=0, c=0;
	  
	q= (GrafoDinamico) malloc(sizeof(t_grafodinamico));
	
	if (q!=NULL)
	  {
	  	q->inicial= NULL;
	  	q->final= NULL;
	  	q->numAristas= 0;
	  	q->numVertices= 0;
		*g= q;
	  	return(VERDADERO);
	  }

	return(FALSO);
}

int cargarMatrizAdyacencia(GrafoDinamico g, int **matriz, int *arrID, int cantidad)
{
	Nodo *nodos= NULL;
	int i=0, j=0;
	int sw= FALSO;
	
	if (g==NULL || matriz==NULL || arrID==NULL || cantidad<=0)
	  return(FALSO);
	
	nodos= (Nodo *) malloc(cantidad*sizeof(Nodo));
	if (nodos==NULL)
	  return(FALSO);
	  
	for (i=0; i<cantidad; i++)
	   {
			sw= buscarNodo(g, &(nodos[i]), arrID[i]);
			if (sw==FALSO)
			  {
			  	free(nodos);
			  	return(FALSO);
			  }
	   }
	
	for (i=0; i<cantidad; i++)
	   {
	  	  for (j=0; j<cantidad; j++)
	         {	      	
	      		if (matriz[i][j]!=0)
	      		  sw= agregarConexion(g, arrID[i], arrID[j], matriz[i][j]);
	      		else 
	      	  	  sw= quitarConexion(g, arrID[i], arrID[j]);
	      	
	      		if (sw==FALSO)
	      		  {
	      		  	free(nodos);
	      	      	return(FALSO);
	      	      }
		     }
	   }
	
	return(VERDADERO);
}

int destruirGrafo(GrafoDinamico *g)
{
	GrafoDinamico q= NULL;
	Nodo aux= NULL, sig= NULL;
	int sw= FALSO;
	int nE=0, nS=0;
	
	q= *g;
	
	if (q==NULL)
	  return;

	aux= q->inicial;
	
	while(aux!=NULL)
	{
		sw= desconectarCompletamente(aux);
		(q->numAristas)-= aux->gradSal;
		
		if (sw==FALSO)
		  return(FALSO);
		  
		aux= aux->enlace;
	}
	
	aux= q->inicial;
	
	while(aux!=NULL)
	{
		sig= aux->enlace;
		
		sw= destruirNodo(&aux);
		if (sw==FALSO)
		  return(FALSO);
		  
		aux= sig;
		
		(q->numVertices)--;
	}
	
	q->numVertices= 0;
	q->numAristas= 0;
	free(q); 
	*g= NULL;
	
	return(VERDADERO);
}

// Insercion de datos:
int insertarElemento(GrafoDinamico g, Elemento e, int id)
{
	Nodo n= NULL, aux= NULL, existente=NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	sw= buscarNodo(g, &existente, id);
	if (sw==VERDADERO)
	  return(FALSO);
	  
	sw= crearNodo(&n, id, VERTICE);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= escribirElemento(n, e);
	if (sw==FALSO)
	  {
	  	destruirNodo(&n);
	  	return(FALSO);
	  }

	if (g->numVertices==0 || g->inicial==NULL || g->final==NULL)
	  {
	  	g->inicial= n;
	  	g->final= n;
	  	g->numVertices=1;
	  	return(VERDADERO);
	  }
	else
	  {
	  	sw= conectarEnlace(g->final, n);
	  	if (sw==FALSO)
	  	  {
	  	    destruirNodo(&n);
	  	    return(FALSO);
	  	  }
	  	g->final= n;
	  	(g->numVertices)++;
	  }
	  
	return(VERDADERO);
}

int agregarConexion(GrafoDinamico g, int idFte, int idDest, int peso)
{
	Nodo fuente= NULL, destino= NULL, aux= NULL;
	Nodo arista= NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	sw= buscarNodo(g, &fuente, idFte);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= buscarNodo(g, &destino, idDest);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= agregarConexionNodos(fuente, destino, peso);
	if (sw==FALSO)
	  return(FALSO);
	  
	(g->numAristas)++;
	
	return(VERDADERO);
}

// Consulta
int consultarElemento(GrafoDinamico g, Elemento *e, int id)
{
	Nodo aux= NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	sw= buscarNodo(g, &aux, id);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= leerElemento(aux, e);
	
	return(sw);
}

int buscarNodo(GrafoDinamico g, Nodo *n, int id)
{
	Nodo aux= NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->numVertices==0)
	  return(FALSO);
	  
	aux= g->inicial;
	
	while(aux!=NULL)
	{
		if (aux->id==id)
		  {
		  	*n= aux;
		  	return(VERDADERO);
		  }
		  
		aux= aux->enlace;
	}

	return(FALSO);
}

int consultarPonderacion(GrafoDinamico g, int *peso, int idFte, int idDest)
{
	Nodo arista= NULL, fuente= NULL, destino= NULL;
	int sw= FALSO, w= 0;
	
	if (g==NULL)
	  return(FALSO);
	  
	sw= buscarNodo(g, &fuente, idFte);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= buscarNodo(g, &destino, idDest);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= consultarConexion(&arista, fuente, destino);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= consultarPeso(arista, &w);
	if (sw==FALSO)
	  return(FALSO);
	  
	*peso= w;
	
	return(VERDADERO);	
}

// Eliminacion:
int eliminarElemento(GrafoDinamico g, Elemento *e, int id)
{
	Nodo m= NULL, ant= NULL, aux= NULL, sig= NULL;
	int k=0;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->numVertices==0 || g->inicial==NULL || g->final==NULL)
	  return(FALSO);
	  
	aux= g->inicial;
	
	while(aux!=NULL)
	{
		sig= aux->enlace;
		
		if (aux->id==id)
		  {
		  	// eliminarAristasHaciaElNodo;
		  	
		  	sw= desconectarCompletamente(aux);
		  	if (sw==FALSO)
		  	  return(FALSO);
		  	  
		  	if (ant!=NULL)
		  	  ant->enlace= sig;
		  	else
		  	  g->inicial= sig;
			  
		  	if (sig==NULL)
		  	  g->final= ant;
		  	  
		  	sw= leerElemento(aux, e);
		  	if (sw==FALSO)
		  	  return(FALSO);
		  	  
		  	destruirNodo(&aux);
		  	(g->numVertices)--;
		  	
		  	return(VERDADERO);
		  }
		  
		ant= aux;
		aux= sig;
	}

	return(FALSO);
}

int quitarConexion(GrafoDinamico g, int idFte, int idDest)
{
	Nodo fuente= NULL, destino= NULL;
	Nodo ant= NULL, aux= NULL, sig= NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	sw= buscarNodo(g, &fuente, idFte);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= buscarNodo(g, &destino, idDest);
	if (sw==FALSO)
	  return(FALSO);

	sw= removerConexionNodos(fuente, destino);
	
	return(sw);
}

int generarArbolAmplitud(GrafoDinamico *arbol, GrafoDinamico g, int id)
{
	GrafoDinamico sub= NULL;
	Nodo aux= NULL, raiz= NULL;
	Elemento e= NULL;
	int *visitados= NULL;
	int sw= FALSO;
	int k=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->inicial==NULL)
	  return(FALSO);
	  
	sw= crearGrafo(&sub);
	if (sw==FALSO)
	  return(FALSO);
	
	for (k=0; k<g->numVertices; k++)
		{
	    	sw= consultarElemento(g, &e, k);
	    	if (sw==FALSO)
	    	  break;
	    	  
	   		sw= insertarElemento(sub, e, k);
	   		if (sw==FALSO)
	    	  break;
	   	}
	   	
	if (k<g->numVertices)
	  {	
	  	destruirGrafo(&sub);
	  	return(FALSO);
	  }
	
	aux= g->inicial;
	while(aux!=NULL)
	{
		aux->profundidad= NOVISITADO;
		aux= aux->enlace;
	}
	
	sw= buscarNodo(g, &raiz, id);
	if (sw==FALSO)
	  return(FALSO);
	   
	raiz->profundidad= 0;	// nodo raiz, origen, profundidad cero.
	
	sw= recorrerGrafoAmplitud(sub, g, raiz, id, 0);
	if (sw==FALSO)
	  destruirGrafo(&sub);
	
	*arbol= sub;
	
	return(sw);
}

int recorrerGrafoAmplitud(GrafoDinamico arb, GrafoDinamico g, Nodo centro, int id, int vecindario) // Nodo vecindario // cola
{
	Nodo arista= NULL, fuente= NULL, destino= NULL, aux= NULL;
	int descendientes= FALSO;
	int k=0, sw= FALSO;
	
	aux= g->inicial;
	
	while (aux!=NULL)
	{		  
		if (aux->profundidad==vecindario)
		  {	
		  	sw= consultarSalida(&arista, aux);
			if (sw==FALSO)
	  		  return(FALSO);
	  	
			sw= buscarNodo(g, &fuente, aux->id);
			if (sw==FALSO)
	  		  return(FALSO);
	
			printf("habitante: %d :: vecindario: %d\n", aux->id, vecindario);
			
			while(arista!=NULL)
			{
				destino= arista->salida;
		
				if (destino->profundidad==NOVISITADO)
		  		  {
		  			sw= agregarConexion(arb, fuente->id, destino->id, vecindario+1);
		  			if (sw==FALSO)
		  	  		  return(FALSO);
		  	  
		  			destino->profundidad= vecindario+1;
		  			descendientes= VERDADERO;
		  		  }
		  		  
				arista= arista->enlace;
			}
		  }
		  
		aux= aux->enlace;
	}
	
	if (descendientes==VERDADERO)
		{
			sw= recorrerGrafoAmplitud(arb, g, destino, destino->id, vecindario+1);
		  	if (sw==FALSO)
		  	  return(FALSO);
		}


	return(VERDADERO);
}

int generarArbolProfundidad(GrafoDinamico *arbol, GrafoDinamico g, int id)
{
	GrafoDinamico sub= NULL;
	Nodo aux= NULL, raiz= NULL;
	Elemento e= NULL;
	int *visitados= NULL;
	int sw= FALSO;
	int k=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->inicial==NULL)
	  return(FALSO);
	  
	sw= crearGrafo(&sub);
	if (sw==FALSO)
	  return(FALSO);
	
	for (k=0; k<g->numVertices; k++)
		{
	    	sw= consultarElemento(g, &e, k);
	    	if (sw==FALSO)
	    	  break;
	    	  
	   		sw= insertarElemento(sub, e, k);
	   		if (sw==FALSO)
	    	  break;
	   	}
	   	
	if (k<g->numVertices)
	  {	
	  	destruirGrafo(&sub);
	  	return(FALSO);
	  }
	
	aux= g->inicial;
	while(aux!=NULL)
	{
		aux->profundidad= NOVISITADO;
		aux= aux->enlace;
	}
	
	sw= buscarNodo(g, &raiz, id);
	if (sw==FALSO)
	  return(FALSO);
	   
	raiz->profundidad= 0;	// nodo raiz, origen, profundidad cero.
	
	sw= recorrerGrafoProfundidad(sub, g, raiz, id, 0);
	if (sw==FALSO)
	  destruirGrafo(&sub);

	*arbol= sub;
	
	return(sw);
}

int recorrerGrafoProfundidad(GrafoDinamico arb, GrafoDinamico g, Nodo centro, int id, int nivel) // Nodo vecindario // cola
{
	Nodo arista= NULL, fuente= NULL, destino= NULL;
	int descendientes= FALSO;
	int k=0, sw= FALSO;
	
	if (centro->profundidad==NOVISITADO)
	  centro->profundidad= nivel;
	
	printf("centro: %d :: nivel: %d\n", id, nivel);
	
	sw= consultarSalida(&arista, centro);
	if (sw==FALSO)
	  return(FALSO);
		  			  
	sw= buscarNodo(g, &fuente, id);	
	if (sw==FALSO)
	  return(FALSO);
	
	while(arista!=NULL)
	{
		destino= arista->salida;
		
		if (destino->profundidad==NOVISITADO)
		  {
		  	sw= agregarConexion(arb, fuente->id, destino->id, nivel+1);
		  	if (sw==FALSO)
		  	  return(FALSO);
		  			  
		  	destino->profundidad= nivel+1;
		  	sw= recorrerGrafoProfundidad(arb, g, destino, destino->id, nivel+1);
		  	if (sw==FALSO)
		  	  return(FALSO);
		  }
		arista= arista->enlace;
	}
	
	return(VERDADERO);
}

int imprimirGrafo(GrafoDinamico g)
{
	Nodo vertice= NULL, arista= NULL;
	Nodo fuente= NULL, destino= NULL;
	Elemento eA= NULL, eB= NULL;
	int datoA= 0, datoB= 0;
	int sw= FALSO, indicador= FALSO;;
	int i=0, j=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->numVertices<=0)
	  return(FALSO);
	  
	if (g->inicial==NULL || g->final==NULL)
	  return(FALSO);
	  
	vertice= g->inicial;
	
	while(vertice!=NULL)
	{
		fuente= vertice;
		
		sw= leerElemento(fuente, &eA);
	   	if (sw==FALSO)
	   	  return(FALSO);
	   	  
		sw= leerDato(eA, &datoA);
	   	if (sw==FALSO)
	   	  return(FALSO);
		
		arista= vertice->salida;
				
		indicador= FALSO;
		
		while(arista!=NULL)
		{
			destino= arista->salida;
	   		   		  	  
	   		sw= leerElemento(destino, &eB);
	   		if (sw==FALSO)
	   		  return(FALSO);
	   		   		  	  
	   		sw= leerDato(eB, &datoB);
	   		if (sw==FALSO)
	   		  return(FALSO);
	   		   		  	
	   		printf(" <%d, %d> : %d |", datoA, datoB, arista->peso);
			
			arista= arista->enlace;		  
			j++;
			
			indicador= VERDADERO;

		}
		
		vertice= vertice->enlace;
		i++;
		
		if (indicador==VERDADERO)
		  printf("\n");
	}
	   
	printf("\n");
	
	return(VERDADERO);	
}


#endif



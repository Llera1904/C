#ifndef GRAFO_C
#define GRAFO_C

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

// Creacion y destruccion:
int crearGrafo(Grafo *g, int cantidad)
{
	Grafo q= NULL;
	int k=0, c=0;
	
	if (cantidad<=0)
	  return(FALSO);
	  
	q= (Grafo) malloc(sizeof(t_grafo));
	
	if (q!=NULL)
	  {
	  	q->cantidad= cantidad;
	  	q->nodos= (Nodo *) malloc(cantidad*sizeof(Nodo));
	  	
	  	if (q->nodos!=NULL)
	  	  {	  	
	  			q->conexiones= (int **) malloc(cantidad*sizeof(int *));
	  	
	  			if (q->conexiones!=NULL)
	  	  	      {
	  	  			for (k=0; k<cantidad; k++)
	  	  	   		   {
	  	  	   		   		q->nodos[k]= NULL;
	  	  	     			q->conexiones[k]= (int *) malloc(cantidad*sizeof(int));
	  	  	     			if (q->conexiones[k]==NULL)
	  	  	                  break;
	  	  	                  
	  	  	                for (c=0; c<cantidad; c++)
	  	  	                   q->conexiones[k][c]= 0;
	  	  	   		   }
	  	
	  				if (k==cantidad)
	  		  		  {
						*g= q;
	  		  			return(VERDADERO);
	  		  		  }
	  		  
	  				for ( ; k>=0; k--)
	  		  		   free(q->conexiones[k]);
	  		   
	  				free(q->conexiones);
		  		  }
		
			free(q->nodos);
		  }
		  
		free(q);
	  }

	return(FALSO);
}

int cargarMatrizAdyacencia(Grafo g, int **matriz, int cantidad)
{
	int i=0, j=0;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->nodos==NULL || g->conexiones==NULL || g->cantidad!=cantidad)
	  return(FALSO);
	  
	for (i=0; i<cantidad; i++)
	   if (g->nodos[i]==NULL)
	     return(FALSO);
	
	for (i=0; i<cantidad; i++)
	   for (j=0; j<cantidad; j++)
	      {
	      	g->conexiones[i][j]= matriz[i][j];
	      	
	      	if (matriz[i][j]!=0)
	      	  sw= conectarEnlacePuerto(g->nodos[i], g->nodos[j], j);
	      	else 
	      	  sw= desconectarEnlacePuerto(g->nodos[i], j);
	      	
	      	if (sw==FALSO)
	      	  return(FALSO);
		  }
	
	return(VERDADERO);
}

void destruirGrafo(Grafo *g)
{
	Grafo q= NULL;
	int sw= FALSO;
	int k=0;
	
	q= *g;
	
	if (q==NULL)
	  return;

	if (q->nodos!=NULL)
	  {
	  	for (k=0; k<q->cantidad; k++)
	  	   destruirNodo(&(q->nodos[k]));
	  	   
	  	free(q->nodos);
	  }
	  
	if (q->conexiones!=NULL)
	  {
	    for (k=0; k<q->cantidad; k++)
	       if (q->conexiones[k]!=NULL)
	         free(q->conexiones[k]);
	         
	    free(q->conexiones);
	  }

	free(q); 
	*g= NULL;
}

// Insercion de datos:
int insertarElemento(Grafo g, Elemento e, int id)
{
	Nodo n= NULL;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (id<0 || id>=g->cantidad)
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[id]!=NULL)
	  return(FALSO);
	  
	sw= crearNodo(&n, g->cantidad);
	if (sw==FALSO)
	  return(FALSO);
	  
	sw= escribirElemento(n, e);
	if (sw==FALSO)
	  {
	  	destruirNodo(&n);
	  	return(FALSO);
	  }

	g->nodos[id]= n;
	
	return(VERDADERO);
}

int agregarConexion(Grafo g, int idFte, int idDest, int peso)
{
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if ((idFte<0 || idFte>=g->cantidad) || (idDest<0 || idDest>=g->cantidad))
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[idFte]==NULL || g->nodos[idDest]==NULL)
	  return(FALSO);
	
	if (g->conexiones==NULL)
	  return(FALSO);
	  
	if (g->conexiones[idFte]==NULL || g->conexiones[idDest]==NULL)
	  return(FALSO);
	  
	sw= conectarEnlacePuerto(g->nodos[idFte], g->nodos[idDest], idDest);
	if (sw==FALSO)
	  return(FALSO);
	  
	g->conexiones[idFte][idDest]= peso;
	
	return(VERDADERO);
}

// Consulta
int consultarElemento(Grafo g, Elemento *e, int id)
{
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (id<0 || id>=g->cantidad)
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[id]==NULL)
	  return(FALSO);
	  
	sw= leerElemento(g->nodos[id], e);
	
	return(sw);
}

int consultarPonderacion(Grafo g, int *peso, int idFte, int idDest)
{
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if ((idFte<0 || idFte>=g->cantidad) || (idDest<0 || idDest>=g->cantidad))
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[idFte]==NULL || g->nodos[idDest]==NULL)
	  return(FALSO);
	
	if (g->conexiones==NULL)
	  return(FALSO);
	  
	if (g->conexiones[idFte]==NULL || g->conexiones[idDest]==NULL)
	  return(FALSO);

	*peso= g->conexiones[idFte][idDest];
	
	return(VERDADERO);	
}

// Eliminacion:
int eliminarElemento(Grafo g, Elemento *e, int id)
{
	int k=0;
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (id<0 || id>=g->cantidad)
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[id]==NULL)
	  return(FALSO);
	  
	sw= leerElemento(g->nodos[id], e);
	if (sw==FALSO)
	  return(FALSO);
	  
	for (k=0; k<g->cantidad; k++)
	   {
	   		if (g->conexiones[id][k]!=0)
	   		  {
	   		 	 sw= desconectarEnlacePuerto(g->nodos[id], k);
	   		 	 if (sw==FALSO)
	   		 	   return(FALSO);
	   		 	   
	   		  	 g->conexiones[id][k]=0;
	   		  } 
	   		  
	   		if (g->conexiones[k][id]!=0)
	   		  {
	   		 	 sw= desconectarEnlacePuerto(g->nodos[k], id);
	   		 	 if (sw==FALSO)
	   		 	   return(FALSO);
	   		 	   
	   		  	 g->conexiones[k][id]=0;
	   		  } 
	   }
	   
	sw= destruirNodo(&(g->nodos[id]));
	
	return(sw);
}

int quitarConexion(Grafo g, int idFte, int idDest)
{
	int sw= FALSO;
	
	if (g==NULL)
	  return(FALSO);
	  
	if ((idFte<0 || idFte>=g->cantidad) || (idDest<0 || idDest>=g->cantidad))
	  return(FALSO);
	  
	if (g->nodos==NULL)
	  return(FALSO);
	  
	if (g->nodos[idFte]==NULL || g->nodos[idDest]==NULL)
	  return(FALSO);
	
	if (g->conexiones==NULL)
	  return(FALSO);
	  
	if (g->conexiones[idFte]==NULL || g->conexiones[idDest]==NULL)
	  return(FALSO);
	  
	sw= desconectarEnlacePuerto(g->nodos[idFte], idDest);
	if (sw==FALSO)
	  return(FALSO);
	  
	g->conexiones[idFte][idDest]= 0;
	
	return(VERDADERO);	
}

int generarArbolAmplitud(Grafo *arbol, Grafo g, int id)
{
	Grafo sub= NULL;
	Elemento e= NULL;
	int *visitados= NULL;
	int sw= FALSO;
	int k=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (id<0 || id>=g->cantidad)
	  return(FALSO);
	  
	if (g->nodos==NULL || g->conexiones==NULL)
	  return(FALSO);
	  
	sw= crearGrafo(&sub, g->cantidad);
	if (sw==FALSO)
	  return(FALSO);
	
	for (k=0; k<g->cantidad; k++)
		{
	    	sw= consultarElemento(g, &e, k);
	    	if (sw==FALSO)
	    	  break;
	    	  
	   		sw= insertarElemento(sub, e, k);
	   		if (sw==FALSO)
	    	  break;
	   	}
	   	
	if (k<g->cantidad)
	  {	
	  	destruirGrafo(&sub);
	  	return(FALSO);
	  }
	   
	visitados= (int *) malloc(g->cantidad*sizeof(int));
	
	for (k=0; k<g->cantidad; k++)
	   visitados[k]= NOVISITADO;
	   
	visitados[id]= 0;	// nodo raiz, origen, profundidad cero.
	
	sw= recorrerGrafoAmplitud(sub, g, visitados, g->nodos[id], id, 0);
	if (sw==FALSO)
	  destruirGrafo(&sub);
	
	*arbol= sub;
	
	free(visitados);
	
	return(sw);
}


int recorrerGrafoAmplitud(Grafo arb, Grafo g, int *visitados, Nodo centro, int id, int vecindario) // Nodo vecindario // cola
{
	int descendientes= FALSO;
	int c=0, k=0, sw= FALSO;
	
	for (c=0; c<g->cantidad; c++)
	   {
	   		if (visitados[c]==vecindario)
	   		{
			    id= c;
			    printf("habitante: %d :: vecindario: %d\n", id, vecindario);
			    	
			    for (k=0; k<g->cantidad; k++)
			       {				   
	   					if (g->conexiones[id][k]!=0 && visitados[k]==NOVISITADO)
	     	  	  		  {
	     					arb->conexiones[id][k]= vecindario+1; // g->conexiones[id][k];
	     					sw= conectarEnlacePuerto(arb->nodos[id], arb->nodos[k], k);
	     					if (sw==FALSO)
	     		  	  		  return(FALSO);
	     					visitados[k]= vecindario+1;
	     					descendientes= VERDADERO;
		 	  	  		  }
		 	  	   }
		    }
	   }
	     
	if (descendientes==VERDADERO)
	  {
	  	sw= recorrerGrafoAmplitud(arb, g, visitados, g->nodos[id], id, vecindario+1);
	    	 if (sw==FALSO)
	    	   return(FALSO);
	  }
	   	   
	return(VERDADERO);
}

/*
int recorrerGrafoAmplitud(Grafo arb, Grafo g, int *visitados, Nodo centro, int id, int vecindario) // Nodo vecindario // cola
{
	int descendientes= FALSO;
	int k=0, sw= FALSO;
	
	if (visitados[id]==NOVISITADO);
	  visitados[id]= vecindario;
	
	printf("centro: %d :: vecindario: %d\n", id, vecindario);
	
	vecindario++;
	for (k=0; k<g->cantidad; k++)
	   {
	   		if (g->conexiones[id][k]!=0 && visitados[k]==NOVISITADO)
	     	  {
	     		arb->conexiones[id][k]= vecindario; // g->conexiones[id][k];
	     		sw= conectarEnlacePuerto(arb->nodos[id], arb->nodos[k], k);
	     		if (sw==FALSO)
	     		  return(FALSO);
	     		visitados[k]= vecindario;
	     		descendientes= VERDADERO;
		 	  }
	   }
	     
	if (descendientes==VERDADERO)
	  for (k=0; k<g->cantidad; k++)
	     if (g->conexiones[id][k]!=0 && visitados[k]==vecindario)
	       {
	     	 sw= recorrerGrafoAmplitud(arb, g, visitados, g->nodos[k], k, vecindario);
	    	 if (sw==FALSO)
	    	   return(FALSO);
	   	   }
	   	   
	return(VERDADERO);
}*/

int generarArbolProfundidad(Grafo *arbol, Grafo g, int id)
{
	Grafo sub= NULL;
	Elemento e= NULL;
	int *visitados= NULL;
	int sw= FALSO;
	int k=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (id<0 || id>=g->cantidad)
	  return(FALSO);
	  
	if (g->nodos==NULL || g->conexiones==NULL)
	  return(FALSO);
	  
	sw= crearGrafo(&sub, g->cantidad);
	if (sw==FALSO)
	  return(FALSO);
	
	for (k=0; k<g->cantidad; k++)
		{
	    	sw= consultarElemento(g, &e, k);
	    	if (sw==FALSO)
	    	  break;
	    	  
	   		sw= insertarElemento(sub, e, k);
	   		if (sw==FALSO)
	    	  break;
	   	}
	   	
	if (k<g->cantidad)
	  {	
	  	destruirGrafo(&sub);
	  	return(FALSO);
	  }
	   
	visitados= (int *) malloc(g->cantidad*sizeof(int));
	
	for (k=0; k<g->cantidad; k++)
	   visitados[k]= NOVISITADO;
	   
	visitados[id]= 0;	// nodo raiz, origen, profundidad cero.
	
	sw= recorrerGrafoProfundidad(sub, g, visitados, g->nodos[id], id, 0);
	if (sw==FALSO)
	  destruirGrafo(&sub);
	  
	*arbol= sub;
	
	free(visitados);
	
	return(VERDADERO);
}

int recorrerGrafoProfundidad(Grafo arb, Grafo g, int *visitados, Nodo centro, int id, int nivel) // Nodo vecindario // cola
{
	int descendientes= FALSO;
	int k=0, sw= FALSO;
	
	if (visitados[id]==NOVISITADO);
	  visitados[id]= nivel;
	  
	printf("centro: %d :: nivel: %d\n", id, nivel);
	
	for (k=0; k<g->cantidad; k++)
	   if (g->conexiones[id][k]!=0 && visitados[k]==NOVISITADO)
	     {
	     	arb->conexiones[id][k]= nivel+1;
	     	sw= conectarEnlacePuerto(arb->nodos[id], arb->nodos[k], k);
	     	if (sw==FALSO)
	     	  return(FALSO);
	     	visitados[k]= nivel+1;
	     	recorrerGrafoProfundidad(arb, g, visitados, g->nodos[k], k, nivel+1);
		 }
		 
	return(VERDADERO);
}

int imprimirGrafo(Grafo g)
{
	Elemento eA= NULL, eB= NULL;
	int datoA= 0, datoB= 0;
	int sw= FALSO, aristas= FALSO;
	int i=0, j=0;
	
	if (g==NULL)
	  return(FALSO);
	  
	if (g->cantidad<=0)
	  return(FALSO);
	  
	if (g->nodos==NULL || g->conexiones==NULL)
	  return(FALSO);
	  
	printf("Vertices V:\n");
	for (i=0; i<g->cantidad; i++)
	   {
			sw= leerElemento(g->nodos[i], &eA);
	   		if (sw==FALSO)
	   		  return(FALSO);
	   		  
	   		sw= leerDato(eA, &datoA);
	   		if (sw==FALSO)
	   		  return(FALSO);
	   		   		  	  
	   		printf("%d, ", datoA);
	   }
	printf("\n");
	   		   		  	  
	printf("Aristas E:\n");
	for (i=0; i<g->cantidad; i++)
	   {
	   		if (g->nodos[i]==NULL || g->conexiones[i]==NULL)
	   		  return(FALSO);
	   		  
	   		aristas= FALSO;
	   		for (j=0; j<g->cantidad; j++)
	   		   {
	   		   		if (g->conexiones[i][j]!=0)
	   		   		  {
	   		   		  	if (g->nodos[j]==NULL)
	   		   		  	  return(FALSO);
	   		   		  	  
	   		   		  	sw= leerElemento(g->nodos[i], &eA);
	   		   		  	if (sw==FALSO)
	   		   		  	  return(FALSO);
	   		   		  	  
	   		   		  	sw= leerElemento(g->nodos[j], &eB);
	   		   			if (sw==FALSO)
	   		   		  	  return(FALSO);
	   		   		  	  
	   		   		  	datoA= -1;
	   		   		  	datoB= -1;
	   		   		  	  
	   		   		  	sw= leerDato(eA, &datoA);
	   		   			if (sw==FALSO)
	   		   		  	  return(FALSO);
	   		   		  	  
	   		   		  	sw= leerDato(eB, &datoB);
	   		   			if (sw==FALSO)
	   		   		  	  return(FALSO);
	   		   		  	
	   		   		  	printf(" <%d, %d> : %d |", datoA, datoB, g->conexiones[i][j]);
						aristas= VERDADERO;
					  }
			   }
			if (aristas==VERDADERO)
			  printf("\n");
	   }
	   
	printf("\n\n");
	   
	return(VERDADERO);	
}

#endif


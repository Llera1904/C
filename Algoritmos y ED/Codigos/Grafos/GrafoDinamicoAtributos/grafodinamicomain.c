#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "grafodinamico.h"

int **crearMatriz(int M, int N);
void imprimirMatriz(int **mat, int M, int N);
void destruirMatriz(int **mat, int M);

int **crearMatrizDiagonal(int N);
int **crearMatrizCircular(int N);
int **crearMatrizAleatoria(int N, int orden);
int **crearMatrizBidireccional(int N, int orden);
int **crearMatrizTablero(int N);
int **crearMatrizArbol(int profundidad);

int main(int argc, char *argv[])
{
	GrafoDinamico grafo= NULL;
	GrafoDinamico arbolAmplitud= NULL, arbolProfundidad= NULL;
	Elemento *elementos= NULL, e= NULL;
	int *identificadores= NULL;
	int **adyacencia= NULL;
	int N= 7, k=0, profundidad=0, grado=0, raiz;
	int opcion= -1, sw= FALSO;
	
	srand(time(NULL));
	  
	printf("Grafo: \n");
	printf("0. Diagonal\n");
	printf("1. Circular\n");
	printf("2. Tablero\n");
	printf("3. Aleatorio Dirigido\n");
	printf("4. Aleatorio No Dirigido\n");
	printf("5. Arbol\n");
	printf("Opcion= ");
	
	scanf("%d", &opcion);
	  
	switch(opcion)
	{
		case 0: {
					printf("0. Diagonal\n");
					printf("Numero vertices= ");
					scanf("%d", &N);
					adyacencia= crearMatrizDiagonal(N);
					break;
				}
				
		case 1: {
					printf("1. Circular\n");
					printf("Numero vertices= ");
					scanf("%d", &N);
					adyacencia= crearMatrizCircular(N);
					break;
				}
		
		case 2: {
					printf("2. Tablero\n");
					printf("Numero vertices= ");
					scanf("%d", &N);
					adyacencia= crearMatrizTablero(N);
					break;
				}
				
		case 3: {
					printf("3. Aleatorio Dirigido\n");
					printf("Numero vertices= ");
					scanf("%d", &N);
					printf("Grado (aristas por nodo)= ");
					scanf("%d", &grado);
					adyacencia= crearMatrizAleatoria(N, grado);
					break;
				}
				
		case 4: {
					printf("4. Aleatorio No Dirigido\n");
					printf("Numero vertices= ");
					scanf("%d", &N);
					printf("Grado (aristas por nodo)= ");
					scanf("%d", &grado);
					adyacencia= crearMatrizBidireccional(N, grado);
					break;
				}
				
		case 5: {
					printf("5. Arbol\n");
					printf("Profundidad= ");
					scanf("%d", &profundidad);
					N= pow(2.0, profundidad+1) -1;
					adyacencia= crearMatrizArbol(profundidad);
					break;
				}
				
		default: return(-1);
		
	}
	
	if (adyacencia==NULL)
	  return(-1);
	
	imprimirMatriz(adyacencia, N, N);
	
	sw= crearGrafo(&grafo);
	if (sw==FALSO)
	  return(-1);
	  
	elementos= (Elemento *) malloc(N*sizeof(Elemento));
	identificadores= (int *) malloc(N*sizeof(int));
	
	if (elementos==NULL || identificadores==NULL)
	  {
	  	destruirGrafo(&grafo);
	  	destruirMatriz(adyacencia, N);
		  
		if (elementos!=NULL)
		  free(elementos);
		  
		if (identificadores!=NULL)
		  free(identificadores); 	
	  	return(-1);
	  }
	  
	if (grafo!=NULL)
	  {
	  	printf("Creando vertices...\n");
	  	for (k=0; k<N; k++)
	  	   {
	  	   		identificadores[k]= k;
	  	   		
	  	   		sw= crearElemento(&(elementos[k]));
	  	   		if (sw==FALSO)
	  	   		  break;
	  	   		  
	  	   		sw= escribirDato(elementos[k], k);
	  	   		if (sw==FALSO)
	  	   		  break;
	  	   		  
	  	   		sw= insertarElemento(grafo, elementos[k], k);
	  	   		if (sw==FALSO)
	  	   		  break;
	  	   }
	  	   
	  	if (sw==FALSO)
	  	  {
	  	  	destruirGrafo(&grafo);
	  	  	for (k=k-1; k>=0; k--)
	  	       destruirElemento(&(elementos[k]));
	  	    destruirMatriz(adyacencia, N);
	  	    free(elementos);
	  	    free(identificadores);
	  	    return(-1);
	  	  }
	  	   
	  	sw= cargarMatrizAdyacencia(grafo, adyacencia, identificadores, N);
	  	if (sw==VERDADERO)
	  	  {
	  	  	sw= imprimirGrafo(grafo);
	  	  	if (sw==VERDADERO)
	  	  	  {
	  	  	  	printf("Vertice raiz= ");
	  	  	  	scanf("%d", &raiz);
	  	  	  	
	  	  	  	printf("Generando arbol por amplitud:\n");
	  	  	  	sw= generarArbolAmplitud(&arbolAmplitud, grafo, raiz);
	  	  	  	if (sw==VERDADERO)
	  	  	  	  imprimirGrafo(arbolAmplitud);
	  	  	  	else
	  	  	  	  destruirGrafo(&arbolAmplitud);
	  	  	  	  
	  	  	  	printf("Generando arbol por profundidad:\n");
	  	  	  	sw= generarArbolProfundidad(&arbolProfundidad, grafo, raiz);
	  	  	  	if (sw==VERDADERO)
	  	  	  	  imprimirGrafo(arbolProfundidad);
	  	  	  	else
	  	  	  	  destruirGrafo(&arbolProfundidad);	  	  	  	
			  }
		  }

	 
	  	for (k=N-1; k>=0; k--)
	  	   {
	  	   		eliminarElemento(arbolProfundidad, &e, k);
	  	   		eliminarElemento(arbolAmplitud, &e, k);
	  	   		eliminarElemento(grafo, &e, k);
		   }

		destruirGrafo(&arbolProfundidad);
		destruirGrafo(&arbolAmplitud);						
		destruirGrafo(&grafo);

		destruirMatriz(adyacencia, N);
		
		for (k=N-1; k>=0; k--)
		   destruirElemento(&(elementos[k]));
		
		free(elementos);
		free(identificadores);
	  }
	  
	printf("Fin de programa\n");
	
	return 0;
}

int **crearMatriz(int M, int N)
{
	int **mat= NULL;
	int i=0, j=0;
	 
	mat= (int **) malloc(M*sizeof(int *));
	
	for (i=0; i<M; i++)
	   {
	   		mat[i]= (int *) malloc(N*sizeof(int));
	   		
	   		if (mat[i]!=NULL)
	   		  for (j=0; j<N; j++)
	   		     mat[i][j]= 0;
	   		else
	   		  break;
	   }
	
	if (i!=M)
	  {
	  	for (; i>=0; i--)
	       free(mat[i]);
	    free(mat);
	    mat= NULL;
	  }
	
	return(mat);
}

int **crearMatrizDiagonal(int N)
{	 
	int **mat= NULL;
	int k=0;
	
	mat= crearMatriz(N, N);
	
	for (k=0; k<N; k++)  
	   mat[k][k]= 1;
	   
	return(mat);
}

int **crearMatrizCircular(int N)
{
	int **mat= NULL;
	int k=0, L=N-1;
	
	mat= crearMatriz(N, N);
	
	for (k=0; k<L; k++)  
	   mat[k][k+1]= 1;
	
	mat[L][0]= 1;
	
	return(mat);
}

int **crearMatrizAleatoria(int N, int orden)
{
	int **mat= NULL;
	int k=0, c=0, aristas=0;
	
	mat= crearMatriz(N, N);
	
	for (k=0; k<N; k++) 
	   {
	   		aristas= 0;
	   		while(aristas<orden)
	   		{
	   			c= rand()%N;
	   			
	   			while (mat[k][c]!=0 || k==c)
	   			     c= rand()%N;
	   			     
	   			mat[k][c]= 1;
			    aristas++;	
			}
	   }
	   
	return(mat);
}

int **crearMatrizBidireccional(int N, int orden)
{
	int **mat= NULL;
	int k=0, c=0;
	int *aristas= NULL;
	int disponibles=0;
	
	mat= crearMatriz(N, N);
	aristas= (int *) malloc(N*sizeof(int));
	
	for (k=0; k<N; k++)
	   aristas[k]= 0;
	
	for (k=0; k<N; k++) 
	   {
	   		disponibles=0;
	   		
	   		for (c=0; c<N; c++)
	   		   if (k!=c && mat[k][c]==0 && aristas[c]<orden)
	   		     disponibles++;
	   		     
	   		while(aristas[k]<orden && disponibles>0)
	   		{
	   			c= rand()%N;
	   			
	   			while (mat[k][c]!=0 || aristas[c]>=orden || k==c)
	   			     c= rand()%N;
	   			     
	   			mat[k][c]= 1;
	   			mat[c][k]= 1;
	   			
			    (aristas[k])++;
			    (aristas[c])++;
			    disponibles--;
			}
	   }
	   
/*	for (k=0; k<N; k++)
	   mat[k][k]= 0;*/
	   
	free(aristas);
	
	return(mat);
}

int **crearMatrizTablero(int N)
{
	int **mat= NULL;
	int k=0, c=0, aristas=0;
	
	mat= crearMatriz(N, N);
	
	for (k=0; k<N; k++) 
	   for (c=(k+1)%2; c<N; c+=2) 
	      mat[k][c]= 1;
	      
	return(mat);
}

int **crearMatrizArbol(int profundidad)
{
	int **mat= NULL;
	int k=0, c=1, aristas=0;
	int N=0;
	
	N= (int) (pow(2, profundidad+1) - 1);
	
	mat= crearMatriz(N, N);
	
	for (k=0, c=1; k<N && c<N; k++) 
	   {
	   		if (c>=N)
	   		  break;
	   		
	   		mat[k][c]= 1;
	   		mat[c][k]= 1;
	   		c++;
	   		
	   		if (c>=N)
	   		  break;
	   		  
	   		mat[k][c]= 1;
	   		mat[c][k]= 1;
	   		c++;
	   }
	      
	return(mat);
}

void imprimirMatriz(int **mat, int M, int N)
{
	int i=0, j=0;
	
	if (mat==NULL)
	  return;
	  
	for (i=0; i<M; i++)
	   {
	   		if (mat[i]==NULL)
	   		  return;
	   		  
	   		for (j=0; j<N; j++)
	   		   printf("%d\t", mat[i][j]);
	   		printf("\n");
	   }
}

void destruirMatriz(int **mat, int M)
{
	int k=0;
	
	if (mat==NULL)
	  return;
	  
	for (k=0; k<M; k++)
	   if (mat[k]!=NULL)
	     free(mat[k]);
	
	free(mat);
}



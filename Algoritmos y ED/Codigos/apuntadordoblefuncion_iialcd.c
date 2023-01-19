#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **crearMatriz(int M, int N);
void destruirMatriz(int **mat, int M);
void inicializarMatriz(int **mat, int M, int N);
void desplegarMatriz(int **mat, int M, int N);
void multiplicarMatrices(int **matC, int **matA, int **matB, int M, int N, int L);

int main(int argc, char *argv[])
{
	int **matriz= NULL;
	int **mA=NULL, **mB=NULL, **mC=NULL;
	int M= 3, N= 3, L=3;
	
	srand(time(NULL));
		 
	matriz= crearMatriz(M, N);
	inicializarMatriz(matriz, M, N);
	desplegarMatriz(matriz, M, N);
	destruirMatriz(matriz, M);
	
	mA= crearMatriz(M, L);
	mB= crearMatriz(L, N);
	mC= crearMatriz(M, N);
	
	inicializarMatriz(mA, M, L);
	inicializarMatriz(mB, L, N);
	
	printf("\nmatriz A:\n");
	desplegarMatriz(mA, M, L);
	
	printf("\nmatriz B:\n");
	desplegarMatriz(mB, L, N);
	
	multiplicarMatrices(mC, mA, mB, M, N, L);

	printf("\nmatriz C:\n");
	desplegarMatriz(mC, M, N);
	
	destruirMatriz(mC, M);
	destruirMatriz(mB, L);
	destruirMatriz(mA, M);
	
	return 0;
}

int **crearMatriz(int M, int N)
{
	int **mat= NULL;
	int i=0;
	
	mat= (int **) malloc(M*sizeof(int *));
	
	for (i=0; i<M; i++)
	   mat[i]= (int *) malloc(N*sizeof(int));
	   
	return(mat);
}

void destruirMatriz(int **mat, int M)
{
	int i=0;
	
	if (mat==NULL)
	  return;
	
	for (i=0; i<M; i++)
	   {   
	   		if (mat[i]!=NULL)
	   		  free(mat[i]);
	   }
	   
	free(mat);
}

void inicializarMatriz(int **mat, int M, int N)
{
	int i=0, j=0;
	
	if (mat==NULL)
	  return;
	
	for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	      mat[i][j]= rand()%100;
}


void desplegarMatriz(int **mat, int M, int N)
{
	int i=0, j=0;
	
	if (mat==NULL)
	  return;
	
	for (i=0; i<M; i++)
	   {
	   		for (j=0; j<N; j++)
	      	   printf("%d\t", mat[i][j]);
	   		printf("\n");   
	   }
}

// C= A*B;

void multiplicarMatrices(int **matC, int **matA, int **matB, int M, int N, int L)
{
	int i=0, j=0, k=0;
	
	if (matC==NULL || matA==NULL || matB==NULL)
	  return;
	
	for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	      {
	      	matC[i][j]= 0;
	      	
	      	for (k=0; k<L; k++)
	      	   matC[i][j]+= matA[i][k] * matB[k][j];
		  }
}








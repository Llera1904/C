#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void desordenarMatriz(int **arr, int N);
void inimatrizAleatoria(int **arr, int N);
void imprimirMatriz(int **arr, int N);
void multiMatrices(int **matrizA, int **MatrizB, int **matrizC, int N);
void multimatricesTranspuesta(int **matrizA, int **matrizB, int **matrizC, int N);
int **transpuestaMatriz(int **matriz, int N);

int main(int argc, char *argv[])  
{
	int i= 0, j= 0;
	int N= 8;
	int *arr= NULL;
	int **matrizA= NULL, **matrizB= NULL, **matrizC= NULL;
	int **matrizTranspuesta= NULL;
	
	srand(time(NULL));
	
	// Creacion de matrices
	matrizA= (int **) malloc(N*sizeof(int *));
	matrizB= (int **) malloc(N*sizeof(int *));
	matrizC= (int **) malloc(N*sizeof(int *)); // Matriz resultado
	
	for (i= 0; i<N; i++)
	   {
	   	    matrizA[i]= (int *) malloc(N*sizeof(int));
	   	    matrizB[i]= (int *) malloc(N*sizeof(int));
	   	    matrizC[i]= (int *) malloc(N*sizeof(int));
	   }
		
	inimatrizAleatoria(matrizA, N);	
	inimatrizAleatoria(matrizB, N);
	//desordenarMatriz(matrizB, N);
	
	for (i= 0; i<N; i++) // Inicializa matriz resultado
	   for (j= 0; j<N; j++)
	      matrizC[i][j]= 0;
	
	printf("MATRIZ A\n");   
	imprimirMatriz(matrizA, N);
	printf ("\n\n");
	printf("MATRIZ B\n");   
	imprimirMatriz(matrizB, N);
	printf ("\n\n");
	printf("MATRIZ C\n");   
    imprimirMatriz(matrizC, N);
    
    /*multiMatrices(matrizA, matrizB, matrizC, N);
    
    for (i= 0; i<N; i++) // Inicializa matriz resultado
	   for (j= 0; j<N; j++)
	      matrizC[i][j]= 0;*/
    
    printf("\n");	
    printf("TranspuestaB\n");
    matrizTranspuesta= transpuestaMatriz(matrizB, N);
    imprimirMatriz(matrizTranspuesta, N);
    
    multimatricesTranspuesta(matrizA, matrizTranspuesta, matrizC, N);
    
    for (i= 0; i<N; i++)
	   {
	   	    matrizA[i]= NULL;
	   	    matrizB[i]= NULL;
	   	    matrizC[i]= NULL;
	   }
	
	free(matrizA);
	free(matrizB);
	free(matrizC);
		
	return 0;
}

void inimatrizAleatoria(int **arr, int N)
{
	int i= 0, j= 0;
	int aleatorio= 0;
	
	//srand(time(NULL));
	
	for (i=0; i<N; i++)
	   for (j=0; j<N; j++)
	      {
	      	aleatorio= rand()%42;
	        arr[i][j]= aleatorio;	
	        //printf("%d ", aleatorio);
		  }	   
}

void desordenarMatriz(int **arr, int N)
{
	int i= 0, j= 0;
	int aleatorio1= 0, aleatorio2= 0, num= 0;
	
	//srand(time(NULL));
	
	for (i=0; i<N; i++)
	   for (j=0; j<N; j++)
	      {
	      	aleatorio1= rand()%N;
	      	aleatorio2= rand()%N;
	      	
	      	//printf("%d %d  ", aleatorio1, aleatorio2);
	      	
	   	    num= arr[i][j];
	   	    arr[i][j]= arr[aleatorio1][aleatorio2];
	   	    arr[aleatorio1][aleatorio2]= num;
		  }	   
}

void imprimirMatriz(int **arr, int N)
{
	int i= 0, j= 0;	
	
	for (i=0; i<N; i++)
	   {
	   	 for (j=0; j<N; j++)
	        printf("[%d][%d]= %d\t", i, j, arr[i][j]);
	     printf("\n");
	   }		    
}

void multiMatrices(int **matrizA, int **matrizB, int **matrizC, int N)
{
	int i= 0, j= 0, k= 0;
	       
	for (i= 0; i<N; i++)   
	    for (j= 0; j<N; j++)
		   for (k= 0; k<N; k++)   
		      matrizC[i][j]= matrizC[i][j] + (matrizA[i][k]*matrizB[k][j]);
	
	printf("\n");
	printf("Multiplicacion\n");	      
	imprimirMatriz(matrizC, N);		           
}

int **transpuestaMatriz(int **matriz, int N)
{
	int i= 0, j= 0;
	int **matrizAux= NULL; 
	
	matrizAux= (int **) malloc(N*(sizeof(int *)));
	
	for (i= 0; i<N; i++) 
       matrizAux[i]= (int *) malloc(N*(sizeof(int)));
	
	for (i= 0; i<N; i++)   
	    for (j= 0; j<N; j++)
	       matrizAux[j][i]= matriz[i][j];
	
	return(matrizAux);
}

void multimatricesTranspuesta(int **matrizA, int **matrizB, int **matrizC, int N)
{
	int i= 0, j= 0, k= 0;
	       
	for (i= 0; i<N; i++)   
	    for (j= 0; j<N; j++)
	       for (k= 0; k<N; k++)   
		      matrizC[i][j]= matrizC[i][j] + (matrizA[i][k]*matrizB[j][k]);
	
	printf("\n");
	printf("MultiplicacionTranspuesta\n");	      
	imprimirMatriz(matrizC, N);		           
}

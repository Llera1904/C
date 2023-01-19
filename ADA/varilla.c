#include <stdio.h>
#include <stdlib.h>

int **partirVarilla(int *precios, int N);
void imprimirArreglo(int *arr, int N);
void imprimirSolucion(int ***matrizSolucion, int N);

int main(int argc, char *argv[]) 
{
    int precios[11]= {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int i= 0, j= 0;
	int n= 2; // Arreglos
	int N= 11; // Tamaño de arreglos
	int **matrizSolucion= NULL;
	
	// Tabla de precios
	printf ("Precios por longitud: \n");
	printf ("Longitud ");
	for (i=0; i<N; i++)
	   printf ("\t%d", i);

	printf("\n"); 
	
	printf ("Precio\t");     
	for (i=0; i<N; i++)
	   printf ("\t%d", precios[i]);
	   
	printf("\n");
	printf("\n");
	
	matrizSolucion= partirVarilla(precios, N); // Corta las varillas
	
	// Imprimir cada arreglo
	printf("Tabla de soluciones:\n");
	
	printf ("Resultado ");
	for (j= 0; j<N; j++) 
	   printf("\t%d", matrizSolucion[0][j]); // r
	   
	printf("\n");
	
	printf ("Solucion ");
	for (j= 0; j<N; j++) 
	   printf("\t%d", matrizSolucion[1][j]); // s
	   
	printf("\n");
	printf("\n");
	   
	// Solucion segun la longitud de varilla deseada
	imprimirSolucion(&matrizSolucion, 9);
	
	// Liberamos memoria 
	for (i= 0; i<n; i++)
	   {
	   	 free(matrizSolucion[i]);
	   	 matrizSolucion[i] = NULL;
	   } 
	   
	free(matrizSolucion);
	   		         	   
	return 0;
}

// Trabajamos con una matriz de 2x10 para meter las soluciones
int **partirVarilla(int *precios, int N)
{
	int **matrizSolucion= NULL;
	int maximo= 0;
	int n= 2, m= N;
	int i= 0, j= 0;
	
	matrizSolucion= (int **) malloc(n*sizeof(int *));
	
	for (i= 0; i<n; i++) 
	   matrizSolucion[i]= (int *) malloc(m*sizeof(int));
	
	// Inicializa la matriz
	for (j= 0; j<m; j++) 
       matrizSolucion[0][j]= 0; // r

	for (j= 0; j<m; j++) 
	   matrizSolucion[1][j]= 0; // s
	   
	// Inicio algoritmo
	for (j= 1; j<m; j++)
	   {
	   	 maximo= -100000000; // Menos infinito
	   	 for (i= 1; i<=j; i++)
	   	    {
	   	    	if (maximo < (precios[i] + matrizSolucion[0][j-i]))
	   	    	  {
	   	    	  	maximo = precios[i] + matrizSolucion[0][j-i]; // r
	   	    	  	matrizSolucion[1][j]= i; //s
				  }
				  
				matrizSolucion[0][j]= maximo; // r
			}
	   }   
	   
	return(matrizSolucion);
}

void imprimirSolucion(int ***matrizSolucion, int N)// Recibe la tabla solucion
{
	int **solucion= NULL;
	
	solucion= *matrizSolucion;
	
	printf("Como partir la varilla de longitud %d :\n", N);
		printf("Tamaños: ");
	
	//Busca en memoria 
	while (N > 0)
	     {
	     	printf("%d ", solucion[1][N]); 
	     	N = N - solucion[1][N];
		 }
}

void imprimirArreglo(int *arr, int N)
{
	int i= 0;
	
	for (i= 0; i<N; i++)
	   printf ("%d ", arr[i]);
	   
	printf("\n");   
}

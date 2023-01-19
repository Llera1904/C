#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void imprimirArreglo(int *arr, int N);
void desordenarArreglo(int *arr, int N);
int contrataUno (int *score, int N, int K);

int main(int argc, char *argv[]) 
{
	int i= 0;
	int N= 10; // Candidatos
	int candidato= 0; // Numero de candidato contratado	
	float K= N/2.7;
	int *calificaciones = NULL; // Arreglo calificaciones
	
	srand(time(NULL));	
	
	K= lround(K); // Redondeamos
	printf("Valor de K: %0.2f\n\n", K); 
	
	calificaciones = (int *) malloc(N*sizeof(int));
	
	for (i=0; i<N; i++) // Inicializamos el arreglo 
	   calificaciones[i]= rand()%50;
	   
	imprimirArreglo(calificaciones, N); 
	desordenarArreglo(calificaciones, N);
	
	printf("\nCalificaciones despues de aleatorizar el arreglo\n"); 
	imprimirArreglo(calificaciones, N); 
	  
	candidato= contrataUno (calificaciones, N, K); // Llamamos al algoritmo para contratar
	printf("\n\nCandidato contratado: %d\n", candidato); 
	  		         	   
	return 0;
}

void imprimirArreglo(int *arr, int N)
{
	int i= 0;
	
	for (i= 0; i<N; i++)
	   printf ("%d ", arr[i]);
	   
	printf("\n");   
}

void desordenarArreglo(int *arr, int N)
{
	int i= 0;
	int aleatorio= 0, num= 0;
	
	srand(time(NULL));
	
	for (i=0; i<N; i++)
	   {
	   	  aleatorio= rand()%N;
	   	  num= arr[i];
	   	  arr[i]= arr[aleatorio];
	   	  arr[aleatorio]= num;
	   }
}

int contrataUno (int *score, int N, int K)
{
    int i= 0;
	int bestScore= -999999;
	
	for (i=0; i<K; i++) 
	   if (score[i] > bestScore)
	     bestScore= score[i];
	     
    for (i= K; i<N; i++)
       if (score[i] > bestScore)
         return i;
         
    return N;
}





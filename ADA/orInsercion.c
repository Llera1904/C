#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirArreglo(int *arr, int N);
void desordenarArreglo(int *arr, int N);
void ordenamientoInsercion(int *arr, int N);

int main(int argc, char *argv[]) 
{
	int N= 10, ref= 0, aleatorio= 0, num= 0;
	int i= 0, j= 0;
	int *arr= NULL;
	
	arr= (int *) malloc(N*sizeof(int));
	
	for (i= 0; i<N; i++)
	   arr[i]= i;
	
	imprimirArreglo(arr, N);
	desordenarArreglo(arr, N);
	imprimirArreglo(arr, N);   
	
	ordenamientoInsercion(arr, N);
	imprimirArreglo(arr, N);
	      	   
	return 0;
}

void imprimirArreglo(int *arr, int N)
{
	int i= 0;
	
	for (i= 0; i<N; i++)
	   printf ("%d ", arr[i]);
	   
	printf("\n\n");   
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

void ordenamientoInsercion(int *arr, int N)
{
	int i=0, j=0;
	int ref=0;
	
	for (i=0; i<N; i++)
	   {
	   	 ref= arr[i];
	   	 
	   	 for (j= i-1; j>=0 && ref<arr[j]; j--)
	   	    arr[j+1]= arr[j];	   	    	
	   	    
	   	    
	   	 arr[j+1]= ref;
	   	 
	   	 //imprimirArreglo(arr, N);
	   }
}

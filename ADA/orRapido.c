#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirArreglo(int *arr, int N);
void desordenarArreglo(int *arr, int N);
void ordenamientoRapido(int *arr, int inf, int sup);
int partirArreglo(int *arr, int inf, int sup);

int main(int argc, char *argv[]) 
{
	int N= 100, inf= 0, sup= N-1;
	int i= 0;
	int *arr= NULL;
	
	arr= (int *) malloc(N*sizeof(int));
	
	for (i= 0; i<N; i++)
	   arr[i]= i;
	
	imprimirArreglo(arr, N);
	desordenarArreglo(arr, N);
	imprimirArreglo(arr, N);   
	
	ordenamientoRapido(arr, inf, sup);
	imprimirArreglo(arr, N);
	      	   
	free(arr);      	   
	      	   
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

void ordenamientoRapido(int *arr, int inf, int sup)
{
	int pivote= 0, aux= 0, k=0;
	
	if (inf>sup)
	  return;
	  	  	
	pivote= partirArreglo(arr, inf, sup);
	
	ordenamientoRapido(arr, inf, pivote-1);		// arr izquierdo
	ordenamientoRapido(arr, pivote+1, sup);		// arr derecho
}

int partirArreglo(int *arr, int inf, int sup)
{
	int i=inf, pivote=sup;
	int aux=0;
	
	while(i<pivote)
	   {
	   	 if (arr[i]>arr[pivote])			// comparacion de referencias
	   	   {	
			  if (i+1<pivote)
			    {								
	   	   	  		aux= arr[pivote-1];		
	   	   	  		arr[pivote-1]= arr[pivote];
	   	   	  	}
	   	   	  else
				aux= arr[pivote];
				
	   	   	  arr[pivote]= arr[i];
	   	   	  arr[i]= aux; 	   	  
	   	   	  pivote--;
		   }
		 else
		   i++;
	   }
	
	return(pivote);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirArreglo(int *arr, int N);
void imprimirArregloEspecial(int *arr, int inf, int sup);
void desordenarArreglo(int *arr, int N);
void ordenarPorRecombinacion(int *arr, int inf, int sup, int N);
void recombinar(int *arr, int inf, int mitad, int sup);

int main(int argc, char *argv[]) 
{
	int N= 100, ref= 0, aleatorio= 0, num= 0;
	int inf= 0, sup= N-1;
	int i= 0, j= 0;
	int *arr= NULL;
	
	arr= (int *) malloc(N*sizeof(int));
	
	for (i= 0; i<N; i++)
	   arr[i]= i;
	
	imprimirArreglo(arr, N);
	desordenarArreglo(arr, N);
	imprimirArreglo(arr, N);   
	
	ordenarPorRecombinacion(arr, inf, sup, N);
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

void imprimirArregloEspecial(int *arr, int inf, int sup)
{
	int k=0;
	
	for (k=inf; k<=sup; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}

void ordenarPorRecombinacion(int *arr, int inf, int sup, int N)
{
	int mitad=0, k=0;
	
	if (inf>=sup)
	  return;
	  
	mitad= inf+(sup-inf)/2;
	
	ordenarPorRecombinacion(arr, inf, mitad, N+1);
	ordenarPorRecombinacion(arr, mitad+1, sup, N+1);
	
	recombinar(arr, inf, mitad, sup);
	
}

void recombinar(int *arr, int inf, int mitad, int sup)
{
	int i=0, j=0, k=0, q=0;
	int *aux= NULL;
	int L= sup - inf + 1;
	
	aux= (int *) malloc(L*sizeof(int));
	
	for (k=0, i=inf, j=mitad+1; k<L; k++)
	   {
	   	 if (arr[i] < arr[j] && i<=mitad || j>sup)
	   	   {
	   	   	 	aux[k]= arr[i];
	   	   	 	i++;
		   }
		 else
		   {
		   	 if (arr[i] >= arr[j] && j<=sup || i>mitad)
		   	   {				  
		   	   		aux[k]= arr[j];
		   	   		j++;
		   	   }
		   }
	   }
	   
	for (k=0, q= inf; k<L; k++, q++)
	   arr[q]= aux[k];
	   
	free(aux);
}

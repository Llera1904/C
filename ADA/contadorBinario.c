#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int *arr, int N);
int cuenta (int **arr, int N, int costo);


int main(int argc, char *argv[]) 
{
	int i= 0;
	int N= 8; // Tamaño arreglo
	int numeroCuenta= 16; // Veces que contara
	int costo= 0;
	int *numeroBinario = NULL; 
	
    numeroBinario = (int *) malloc(N*sizeof(int));
    
    for (i=0; i<N; i++) // Inicializa arreglo
       numeroBinario[i]= 0;
      
	imprimirArreglo(numeroBinario, N); 

    printf("\n");  
    
    for (i=0; i<numeroCuenta; i++)
       costo= cuenta (&numeroBinario, N, costo);

	//imprimirArreglo(numeroBinario, N); 
	printf("\nCosto: %d\n", costo);  
	
	free(numeroBinario);
	  		         	   
	return 0;
}

void imprimirArreglo(int *arr, int N)
{
	int i= 0;
	
	for (i= N-1; i>=0; i--)
	   printf ("%d ", arr[i]);
	   
	printf("\n");   
}

int cuenta (int **arr, int N, int costo)
{
    int i= 0;
    //int costo= 0;
    int *numeroBinario= NULL;
    
    numeroBinario = *arr;
	
    while (i < N && numeroBinario[i] == 1)
         {
         	numeroBinario[i]= 0;
         	i+= 1;  
			costo+=1;	
		 }
		 
	if (i < N)
	  {
	  	numeroBinario[i]= 1;
	    costo+=1; 
	  }	
	  
	imprimirArreglo(numeroBinario, N); 
	
	return costo;  
}

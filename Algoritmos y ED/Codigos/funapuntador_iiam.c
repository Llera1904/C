#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int N);
void imprimirArreglo(int *arr, int N);
void destruirArreglo(int *arr);

int main(int argc, char *argv[]) 
{
	int *q= NULL;
	int N= 1000;
	
	q= crearArreglo(N);
	imprimirArreglo(q, N);
	destruirArreglo(q);
	
	return 0;
}

int *crearArreglo(int N)
{
	int *arr= NULL;
	int k=0;
	
	arr= (int *) malloc(N*sizeof(NULL));
	
	for (k=0; k<N; k++)
	   arr[k]=0;
	   
	return(arr);
}

void imprimirArreglo(int *arr, int N)
{
	int k=0;
	
	if (arr==NULL)
	  return;

	for (k=0; k<N; k++)
	   printf("%d\n", arr[k]);  
}

void destruirArreglo(int *arr)
{
	if (arr==NULL)
	  return;
	  
	free(arr);
}

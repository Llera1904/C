#include <stdio.h>
#include <stdlib.h>

#define OK 		1
#define ERROR	0

int *crearArreglo(int N);
int crearArregloSeguro(int **arrEnvuelto, int N);

void destruirArreglo(int *arr);
void imprimir(int *arr, int N);

int main(int argc, char *argv[]) 
{
	int *tren= NULL;
	int N= 10, bandera= OK;
	
	//tren= crearArreglo(N);
	
	bandera= crearArregloSeguro(&tren, N);
	
	imprimir(tren, N);
	
	destruirArreglo(tren);
	
}

int *crearArreglo(int N)
{
	int *arr= NULL;
	int k=0;
	
	arr= (int *) malloc(N*sizeof(int));
	
	for (k=0; k<N; k++)
		arr[k]= 13*k;
  	
	return(arr);
}

void destruirArreglo(int *arr)
{
	free(arr);
}

void imprimir(int *arr, int N)
{
	int k=0;
	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);	
	
}

int crearArregloSeguro(int **arrEnvuelto, int N)
{
	int *arr= NULL;
	int k=0;
	
	if (N<=0)
	  return(ERROR);
	
	arr= (int *) malloc(N*sizeof(int));
	
	if (arr==NULL)
	  return(ERROR);
	
	for (k=0; k<N; k++)
		arr[k]= 13*k;
		
	*arrEnvuelto= arr; // return(arr);
  	
	return(OK);
}



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int arr[100];		// declaracion de un arreglo de 100 enteros
	int N= 100, k=0;
	int x=0;	
	
	arr[4]= 15;			// escritura en la celda 4, el valor 15
	x= arr[4];			// lectura del valor contenido en la celda 4
	
	printf("x= %d\n", x);
	
	k= 21;
	
	arr[k]= 42;
	x= arr[k];
	
	printf("x= %d\n", x);
	
	printf("arreglo[%d]= %d\n", 4, arr[4]);
	printf("arreglo[%d]= %d\n", k, arr[k]);

	// consulta de las celdas del arreglo:
		
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, arr[k]);
	   
	// inicializacion del arreglo:
	   
	for (k=0; k<N; k++)
	   arr[k]= 0;
	   
	// consulta de las celdas del arreglo:
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, arr[k]);
	   
	printf("\n");
	
	// inicializacion del arreglo:
	   
	for (k=0; k<N; k++)
	   arr[k]= 2*k;
	   
	// consulta de las celdas del arreglo:
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, arr[k]);

	return 0;
}

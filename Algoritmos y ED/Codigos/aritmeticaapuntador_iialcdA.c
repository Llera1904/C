#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *arr= NULL;
	int N= 10, k=0;
	int *q= NULL, *lim= NULL;
	
	arr= (int *) malloc(N*sizeof(int));
	
	printf("creacion: &arr= %X  arr= %X  *arr= %d\n", &arr, arr, *arr);
	
	for (k=0; k<N; k++)
	   arr[k]= 21*k;
	
	arr[0]= 1541;
	   
	printf("inicializacion: &arr= %X  arr= %X  *arr= %d\n", &arr, arr, *arr);
	   
	printf("\nContenido:\n");
	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);	   
	   
	printf("\nDirecciones de celdas:\n");
	
	for (k=0; k<N; k++)
	   printf("direccion de [%d]: %X\n", k, &(arr[k]));
	   
	q= arr;			// copia de direccion que guarda arr hacia q
		
	printf("\nAccesos via aritmetica de apuntadores:\n");
	
	for (q=arr, k=0; k<N; q=q+1, k++)			// salto de 1 en 1 en celdas
	   printf("[%d]= %d\n", k, *q);				// salta el tamanho del entero
	   
	lim= arr + N;			// determinar la direccion limite del arreglo
							
	printf("\nAcceso utilizando el apuntador limite:\n");
	
	for (q=arr, k=0; q<lim; q=q+1, k++)
	   printf("[%d]= %d\n", k, *q);
	   
	printf("\nSaltos de 3 en 3 celdas:\n");
	
	for (q=arr, k=0; q<lim; q=q+3, k+=3)
	   printf("[%d]= %d     #%X\n", k, *q, q);
	   
	for (q=arr, k=0; q<lim; q++, k++)
	   *q= 13*k;
	
	printf("\nContenido actualizado:\n");
	
	for (q=arr, k=0; q<lim; q++, k++)
	   printf("[%d]= %d     #%X\n", k, *q, q);
	   
	free(arr);
	arr= NULL;
	q= NULL;
	
	return 0;
}





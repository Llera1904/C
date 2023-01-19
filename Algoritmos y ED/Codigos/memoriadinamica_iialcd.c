#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int *arr= NULL;
	int N= 100, k=0;
	
	//int arreglo[1000];
	
	printf("char (bytes)= %d\n", sizeof(char));
	printf("int (bytes)= %d\n", sizeof(int));
	printf("float (bytes)= %d\n", sizeof(float));
	printf("double (bytes)= %d\n", sizeof(double));
	
	printf("int * (bytes)= %d\n", sizeof(int *));
	
	printf("void (bytes)= %d\n", sizeof(void));
	printf("void * (bytes)= %d\n", sizeof(void *));
	

	// reservar un arreglo de N enteros:
	arr= (int *) malloc(N*sizeof(int));
	
	// escritura y lectura de las celdas del arreglo:
	
	for (k=0; k<N; k++)
	   arr[k]= 19*k;
	
	arr[0]= 1732;
	
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, arr[k]);
	
	// &arr es la direccion del apuntador
	// arr contiene la direccion del arreglo dinamico
	// *arr accede a la primera celda del arreglo dinamico
	
	printf("\n&arr=%X arr= %X *arr= %d\n", &arr, arr, *arr);
		
	// liberacion:
	free(arr);
	
	return 0;
}

// malloc: memory allocation
// void* malloc (size_t size);

// Nota: el apuntador y el arreglo son entidades diferentes
// que estan relacionadas por la referencia del apuntador
// hacia la zona de memoria donde reside el arreglo

// Coloquialmente nos referimos al apuntador como el arreglo
// dinamico

// "%X": hexadecimal, "%d": decimal


 




#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int *arr= NULL;			// arreglo dinamico
							// int arr[164]: arreglo estatico
	int N= 164;				// 164 int's= 164*4 bytes= 856 bytes
							// int: 4 bytes=32 bits
	int k=0;
	
	arr= (int *) malloc(N*sizeof(int));		// creacion del arreglo
	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);		// lecturas de arreglo
	   
	for (k=0; k<N; k++)
	   arr[k]= 3*k;
	   
	printf("\n\n");
	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);		// escrituras en arreglo
	
	free(arr);								// liberacion de memoria
	arr= NULL;
	
	return 0;
}

// void *malloc(numbytes);
// memory allocation: apartado de memoria

// void *= apuntador generico
// (int *): conversion, casting

// java: new = malloc (C)
// java: new = new (C++)
// C: free = delete(C++)
// java: (actualmente) no existe delete 
// java: mecanismo recoleccion de basura



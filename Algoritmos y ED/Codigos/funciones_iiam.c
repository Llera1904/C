#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *arr= NULL;
	int *q= NULL, *w= NULL;
	int N= 10, k=0;
	
	arr= (int *) malloc(N*sizeof(int));
	   
	for (k=0; k<N; k++)
	   arr[k]= 17*k;
	   
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, arr[k]);
	   
	printf("\n");
	   
	q= arr;
	w= q;
	arr= NULL;			// el asignar el valor de NULL a un apuntador
						// no libera la memoria
	
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, q[k]);
	   
	printf("\n");
	 
	free(q);			// el liberar memoria no asigna automaticamente
						// el valor de NULL al apuntador

	q= NULL;
	//w= NULL;
	
	for (k=0; k<N; k++)
	   printf("arr[%d]= %d\n", k, w[k]);
	   
	printf("\n");
	
	return 0;
}

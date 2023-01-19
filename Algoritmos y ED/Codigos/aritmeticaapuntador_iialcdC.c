#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int x=17;
	int *p= NULL, *q= NULL, *arr= NULL, *lim=NULL;
	int N= 100, k=0;
	
	p= &x;
	
	printf("&p= %X  p= %X   *p= %d\n", &p, p, *p);
	
	arr= (int *) malloc(N*sizeof(int));
	
	printf("&arr= %X  arr= %X   *arr= %d\n", &arr, arr, *arr);
	
	for (k=0; k<N; k++)
	   arr[k]= 29*k;
	   
	arr[0]= 1731;
	
	printf("\nInicializacion del arreglo dinamico:\n");
	   
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	printf("&arr= %X  arr= %X   *arr= %d\n", &arr, arr, *arr);
	
	printf("\nDirecciones de memoria de las celdas del arreglo dinamico:\n");
	  
	for (k=0; k<N; k++)
	   printf("&[%d]= %X\n", k, &(arr[k]));
	   
	q= arr;
	
	//q= q+1;		avanza al entero siguiente
	
	printf("&q= %X  q= %X   *q= %d\n", &q, q, *q);
	
	printf("\nConsulta de la memoria via q:\n");
	
	for (k=0, q=arr; k<N; k++, q=q+1)
	   printf("[%d]= %d    %X\n", k, *q, q);
	   
	   
	printf("\nConsulta de la memoria via q de 8 en 8:\n");
	
	lim= arr + N;
	
	for (k=0, q=arr; q<lim; k+=8, q+=8)		// q= q+8;
	   printf("[%d]= %d    %X\n", k, *q, q);
	   
	free(arr);
	
	return 0;
}






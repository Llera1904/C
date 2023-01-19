#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int x= 46, N= 100, k=0;
	int *p= NULL, *q= NULL, *lim=NULL;
	int *arr= NULL;
	
	p= &x;
	
	printf("&p= %X p= %X *p= %d\n", &p, p, *p);
	
	arr= (int *) malloc(N*sizeof(int));
	
	printf("&arr= %X arr= %X *arr= %d\n", &arr, arr, *arr);
	
	printf("\nInicializacion:\n");
	for (k=0; k<N; k++)
	   arr[k]= 25*k;
	   
	arr[0]= 1305;
	   
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	printf("\nDirecciones de memoria:\n");
	
	for (k=0; k<N; k++)
	   printf("&[%d]= %X\n", k, &(arr[k]));
	   
	printf("&arr= %X arr= %X *arr= %d\n", &arr, arr, *arr);
	
	q= arr;
	
	printf("\nContenido de la zona de memoria via apuntador q:\n");
	for (k=0, q=arr; k<N; k++, q=q+1)
	   printf("[%d]= %d\n", k, *q);
	   
	printf("\nDirecciones de la zona de memoria via apuntador q:\n");
	for (k=0, q=arr; k<N; k++, q=q+1)
	   printf("&[%d]= %X\n", k, q);
	
	lim= arr + N;
	
	printf("\nSaltos de 6 en 6 enteros:\n");
	for (k=0, q=arr; q<lim; k+=6, q+=6)
	   printf("[%d]= %d\t#%X\n", k, *q, q);
	   
	   
	
	
	free(arr);
	
	return 0;
}

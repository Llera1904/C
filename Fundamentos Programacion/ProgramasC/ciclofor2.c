#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int k=0, N=10;
	int i=0, j=0;
	
	for (k=0; k<N; k++)
	   printf("%d\n", k);
	   
	printf("\n");
	
	// conteo de potencias, avance logaritmico:
	
	for (k=1; k<N; k= k*2)
	   printf("%d\n", k);
	   
	printf("\n");
	
	// dobles contadores:
	
	for (i=0, j=0; i<N && j<N; i++, j++)
	   printf("i= %d, j= %d\n", i, j);
	   
	printf("\n");

	// carreras de contadores: AND
	
	for (i=0, j=0; i<N && j<N; i++, j+=2)
	   printf("i= %d, j= %d\n", i, j);
	   
	printf("meta: i= %d, j= %d\n", i, j);
	
	
	// carreras de contadores: OR
	
	for (i=0, j=0; i<N || j<N; i++, j+=2)
	   printf("i= %d, j= %d\n", i, j);
	   
	printf("meta: i= %d, j= %d\n", i, j);


	// carreras de contadores: AND logaritmico
	
	
	for (i=1, j=0; i<N && j<N; i= i*2, j+=2)
	   printf("i= %d, j= %d\n", i, j);
	   
	printf("meta: i= %d, j= %d\n\n\n", i, j);

	// for anidados:
	
	N= 60;
	for (i=0; i<N; i++)
	   {
	   	 for (j=0; j<N; j++)
	   	    {
	   	    	printf("i= %d, j= %d\n", i, j);
			}
	   }
	/*   
	for (i=0; i<N; i++)
	   {
	   	 for (j=0; j<N; j++)
	   	    {
	   	    	k= i*j;
	   	    	printf("%d\t", k);
			}
		 printf("\n");
	   }*/
	   
	 for (k=0; k<24; k++)
	    for (i=0; i<60; i++)
	       for (j=0; j<60; j++)
			  printf("hora= %d, min= %d, seg= %d\n", k, i, j);
	   
	
	return 0;
}

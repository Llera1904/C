#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int arr[10]= {11, 13, 59, 18, 1, 21, 42, 93, 72, 33};
	int N= 10, k=0, i=0, j=0;
	int mitad= 0, suma=0, promedio=0;
	int fuente=0, destino=0, aux=0;
	
	printf("contenido del arreglo: \n");	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	printf("\nsentido inverso arreglo: \n");	
	for (k= N-1; k>=0; k--)
	   printf("[%d]= %d\n", k, arr[k]);
	   	   
	printf("\ncasillas pares:\n");	
	for (k=0; k<N; k+=2)
       printf("[%d]= %d\n", k, arr[k]);
       
	printf("\ncasillas impares:\n");	
	for (k=1; k<N; k+=2)
       printf("[%d]= %d\n", k, arr[k]);
       
    printf("\nprimera mitad del arreglo:\n");
    for (k=0, mitad= N/2; k<mitad; k++)
       printf("[%d]= %d\n", k, arr[k]);
    
    // for ( ; k<N; k++)
    // se puede omitir la inicializacion de k
    // si se continua trabajando con el ultimo valor
    // de k (k=5), con el que se detuvo el ciclo
    // anterior
    
    printf("\nsegunda mitad del arreglo:\n");
    for (k=mitad; k<N; k++)
       printf("[%d]= %d\n", k, arr[k]);
       
    printf("\npromedio de los valores del arreglo:\n");
    for (k=0; k<N; k++)
       suma+= arr[k]; 		//suma= suma + arr[k];
    
    promedio= suma/N;
    
    printf("suma= %d \t promedio= %d\n", suma, promedio);
    
    // arreglos aleatorios:
    
    // inicializacion del generador de numeros aleatorios:
    srand(time(NULL));
    
    // generacion de numeros aleatorios entre 0 y 100 (excluyendo 100)
    for (k=0; k<N; k++)
       arr[k]= rand()%100;
    
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	for (fuente=0; fuente<N; fuente++)
	   {
	   	  destino= rand()%N;	// valores entre 0 y N-1
	   	  
	   	  // intercambio:
		  // las 3 instrucciones deben ejecutarse en secuencia
		  // y sin interrupciones
	   	  
	   	  aux= arr[destino];	   	  
	   	  arr[destino]= arr[fuente];			 	   	  
	   	  arr[fuente]= aux;	   	  
	   }
	   
	printf("\narreglo barajeado: \n");	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	// ordenamiento de numeros:
	
	for (i=0; i<N; i++)
	   {
	   		for (j=i+1; j<N; j++)
	   		   {
	   		   		if (arr[j]>arr[i])
	   		   		  {
	   		   		  	aux= arr[j];	   	  
	   	  				arr[j]= arr[i];			 	   	  
	   	  				arr[i]= aux;	
					  }
			   }
	   }
	   
	printf("\narreglo ordenado: \n");	
	for (k=0; k<N; k++)
	   printf("[%d]= %d\n", k, arr[k]);
	   
	return 0;
}

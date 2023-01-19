#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERDADERO	1
#define FALSO		0

void ordenamientoSeleccion(int *arr, int N);
void ordenamientoInsercion(int *arr, int N);
void ordenamientoBurbuja(int *arr, int N);
void ordenamientoMezcla(int *arr, int N);
int busquedaBinaria(int *arr, int N, int num);
int busquedaLineal(int *arr, int N, int num);

void imprimirArreglo(int *arr, int N);
void desordenar(int *arr, int N);

int main(int argc, char *argv[])
{
	int arr[16]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int N= 16;
	
	imprimirArreglo(arr, N);
	desordenar(arr, N);
	imprimirArreglo(arr, N);
	ordenamientoBurbuja(arr, N);
	printf ("\n");
	imprimirArreglo(arr, N);
	
	return;
}

/*int main(int argc, char *argv[])
{
	//int arr[9]= {6, 5, 3, 1, 9, 0, 8, 7, 4};
	//int arr[8]= {6, 5, 3, 1, 8, 7, 2, 4};
	int arr[8]= {60, 50, 30, 10, 80, 70, 20, 40};
	int N= 8, k=0, loc=-1;
	
	imprimirArreglo(arr, N);
	//ordenamientoSeleccion(arr, N);
	//ordenamientoInsercion(arr, N);
	//ordenamientoBurbuja(arr, N);
	ordenamientoMezcla(arr, N);
	
	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
	
	for (k=0; k<100; k++)
	   {	   
			//loc= busquedaLineal(arr, N, k);
			loc= busquedaBinaria(arr, N, k);
				
			printf("k= %d :: loc= %d\n\n", k, loc);
	   }
	
	return 0;
}*/

void ordenamientoSeleccion(int *arr, int N)
{
	int i=0, j=0;
	int aux=0;
	
	for (i=0; i<N; i++)		// pivote
	   {
	   		for (j=i+1; j<N; j++)	// referencia variable
	   		   {
	   		   		if (arr[i] > arr[j])	// comparacion ordenamiento ascendente	
	   		   		  {
	   		   		  	aux= arr[j];
	   		   		  	arr[j]= arr[i];
	   		   		  	arr[i]= aux;		// intercambio de celdas
					    //imprimirArreglo(arr, N);
					  }
			   }
	   }
}

void imprimirArreglo(int *arr, int N)
{
	int k=0;
	
	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}

void ordenamientoInsercion(int *arr, int N)
{
	int i=0, j=0;
	int ref=0;
	
	for (i=0; i<N; i++)
	   {
	   	 ref= arr[i];
	   	 
	   	 for (j= i-1; j>=0 && ref<arr[j]; j--)
	   	    arr[j+1]= arr[j];	   	    	
	   	    
	   	    
	   	 arr[j+1]= ref;
	   	 
	   	  imprimirArreglo(arr, N);
	   }
}

void ordenamientoBurbuja(int *arr, int N)
{
	int i=0, j=0;
	int aux=0;
	int intercambio= VERDADERO;
	int L= N-1;
	
	while(intercambio!=FALSO)	// O(N)
	{
		intercambio= FALSO;		// O(1)
		
		for (i=0; i<L-j; i++)		// O(N)
		   {
		   	 if (arr[i] > arr[i+1])		// O(1)
		   	   {
		   	   		aux= arr[i+1];
		   	   		arr[i+1]= arr[i];
		   	   		arr[i]= aux;
		   	   		intercambio= VERDADERO;
		   	   		//imprimirArreglo(arr, N);
			   }
		   }
		
		j++;   
	}
}

void ordenamientoMezcla(int *arr, int N)
{
	int *nuevo= NULL;
	int k=0, h=0, q=0, c=0;
	int L= 2*N, corte=0, medio=0;
	int i=0, j=0;
	
	nuevo= (int *) malloc(N*sizeof(int));
	
	for (q=0; q<N; q++)
	   nuevo[q]= 0;
	
	//k: tamaño del subarreglo, h: mitad del subarreglo
	// los dos ciclo for más internos, aunque están anidados
	// entre ambos generan una complejidad lineal
	// el más interno avanza k celdas, 1 por 1
	// el externo da saltos de k celdas, hasta alcanzar N
	// O(N/k)*O(k)= O(N)
	
	for (k=2, h=1; k<L; k*=2, h*=2)			// O(logN)
	   {
	   		// q: cual subarreglo se va a ordenar:
	   		
	   		for (q=0; q<N; q+=k)			// O(N/k): # subarreglos
	   		   {		
	   		   		corte= q+k;
	   		   		if (corte>N)
	   		   		  corte= N;
	   		   		medio= q+h;
	   		   		if (medio>N)
	   		   		  medio= N;
	   		   		
	   		   		i= q;
	   		   		j= medio;
	   		   		
	   		   		// printf("i= %d\n", i);
	   		   		// printf("j= %d\n", j);
	   		   		
	   		   		// intercalamiento ordenado de los numeros de los subarreglos:
	   		   		
	   		   		for (c=q; c<corte; c++)		// O(k) : # elementos dentro del subarreglo
					   {
					   		if (arr[i]<arr[j] && i<medio || j>=corte)
					   		  {
					   		  	nuevo[c]= arr[i];
					   		  	//printf("A= %d\n", nuevo[c]);
					   		  	i++;
							  }
							else
							{							
								if (arr[i]>=arr[j] && j<corte || i>=medio)
							  	  {
							  		nuevo[c]= arr[j];
							  		//printf("B= %d\n", nuevo[c]);
					   		  		j++;
							  	  }
							}
					   }					
			   }
			   
			for (q=0; q<N; q++)
			   arr[q]= nuevo[q];
			   
			imprimirArreglo(arr, N);
	   }	
	   
	free(nuevo);
}


int busquedaLineal(int *arr, int N, int num)
{
	int k=0;
	
	for (k=0; k<N; k++)		// O(N)
	   if (arr[k]==num)
	     return(k);

	return(-1);
}

int busquedaBinaria(int *arr, int N, int num)
{
	int inf=0, sup= N, mitad;
	
	while(inf<=sup)
	{
		mitad= inf + (sup-inf)/2;
		
		if (arr[mitad]==num)
		  return(mitad);
		  
		if (num<arr[mitad])
		  sup= mitad-1;
		else
		  inf= mitad+1;		  
	}
	
	return(-1);
}

void desordenar(int *arr, int N)
{
	int k=0, aleatorio=0;
	int num=0;
	
	srand(time(NULL));
	
	for (k=0; k<N; k++)
	   {
	   	  aleatorio= rand()%N;
	   	  // intercambiar el numero de la celda k con la celda r:
	   	  num= arr[k];
	   	  arr[k]= arr[aleatorio];
	   	  arr[aleatorio]= num;
	   }	
}


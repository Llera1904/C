#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOLOCALIZADO	-1

int buscarBinariamente(int *arr, int num, int inf, int sup, int N);
void ordenarRapidamente(int *arr, int inf, int sup);
void imprimirArreglo(int *arr, int N);
void desordenarArreglo(int *arr, int N);
void ordenarPorRecombinacion(int *arr, int inf, int sup, int N);
void recombinar(int *arr, int inf, int mitad, int sup);
void imprimirArregloEspecial(int *arr, int inf, int sup);

int main(int argc, char *argv[])
{
	int arr[8]= {5, 11, 12, 15, 20, 31, 35, 42};
	int N= 8;
	int num= 1724, inf=0, sup=N-1;
	int pos= NOLOCALIZADO;
	
	pos= buscarBinariamente(arr, num, inf, sup, 0);
	printf("el numero %d se encuentra en la posicion %d\n", num, pos);
	
	desordenarArreglo(arr, N);
	imprimirArreglo(arr, N);
	ordenarRapidamente(arr, inf, sup);
	//ordenarPorRecombinacion(arr, inf, sup, N);
	imprimirArreglo(arr, N);
	
	return 0;
}

int buscarBinariamente(int *arr, int num, int inf, int sup, int N)
{
	int mitad= 0, localidad= NOLOCALIZADO;
	int k=0;
	
	if (inf>sup)
	  return(NOLOCALIZADO);
	
	mitad= inf + (sup-inf)/2;
		// mitad= (sup-inf)/2;
	    // mitad= inf + mitad;

	if (num==arr[mitad])
	  return(mitad);
	  
	if (num>arr[mitad])
	  localidad= buscarBinariamente(arr, num, mitad+1, sup, N);		// arr derecho
	else
	  localidad= buscarBinariamente(arr, num, inf, mitad-1, N);		// arr izquierdo
	
	return(localidad);
}

//quicksort:
void ordenarRapidamente(int *arr, int inf, int sup)
{
	int pivote= 0, aux= 0, k=0;
	
	if (inf>sup)
	  return;
	  
	for (k=0; k<inf; k++)
	   printf("   ");
	
	
	imprimirArregloEspecial(arr, inf, sup);
	  	
	pivote= permutarArreglo(arr, inf, sup);
	
	ordenarRapidamente(arr, inf, pivote-1);		// arr izquierdo
	
	/*for (k=0; k<pivote; k++)
	   printf("   ");
	printf("%d\n", arr[pivote]);*/
	
	ordenarRapidamente(arr, pivote+1, sup);		// arr derecho
	
	for (k=0; k<inf; k++)
	   printf("   ");
	   
	imprimirArregloEspecial(arr, inf, sup);
}

int permutarArreglo(int *arr, int inf, int sup)
{
	int k=inf, pivote=sup;
	int aux=0;
	
	while(k<pivote)
	   {
	   	 if (arr[k]>arr[pivote])			// comparacion de referencias
	   	   {	
	   	     // permutacion:
	   	     
			  if (k+1<pivote)
			    {								
	   	   	  		aux= arr[pivote-1];		
	   	   	  		arr[pivote-1]= arr[pivote];
	   	   	  	}
	   	   	  else
				aux= arr[pivote];
				
	   	   	  arr[pivote]= arr[k];
	   	   	  arr[k]= aux; 	   	  
	   	   	  pivote--;
		   }
		 else
		   k++;
	   }
	
	return(pivote);
}

void desordenarArreglo(int *arr, int N)
{
	int k=0, q=0, aux=0;
	
	srand(time(NULL));
	
	for (k=0; k<N; k++)
	   {
	   	 q= rand()%N;
	   	 aux= arr[q];
		 arr[q]= arr[k];
		 arr[k]= aux; 
	   }	
}

void imprimirArreglo(int *arr, int N)
{
	int k=0;
	
	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}

void ordenarPorRecombinacion(int *arr, int inf, int sup, int N)
{
	int mitad=0, k=0;
	
	if (inf>=sup)
	  return;
	  
	mitad= inf+(sup-inf)/2;
	
	for (k=0; k<inf; k++)
	   printf("   ");
	
	
	printf("entrada: ");
	imprimirArregloEspecial(arr, inf, sup);
	
	ordenarPorRecombinacion(arr, inf, mitad, N+1);
	ordenarPorRecombinacion(arr, mitad+1, sup, N+1);
	
	recombinar(arr, inf, mitad, sup);
	
	printf("salida:");
	
	for (k=0; k<inf; k++)
	   printf("   ");
	   
	imprimirArregloEspecial(arr, inf, sup);
}

void recombinar(int *arr, int inf, int mitad, int sup)
{
	int i=0, j=0, k=0, q=0;
	int *aux= NULL;
	int L= sup - inf + 1;
	
	aux= (int *) malloc(L*sizeof(int));
	
	for (k=0, i=inf, j=mitad+1; k<L; k++)
	   {
	   	 if (arr[i] < arr[j] && i<=mitad || j>sup)
	   	   {
	   	   	 	aux[k]= arr[i];
	   	   	 	i++;
		   }
		 else
		   {
		   	 if (arr[i] >= arr[j] && j<=sup || i>mitad)
		   	   {				  
		   	   		aux[k]= arr[j];
		   	   		j++;
		   	   }
		   }
	   }
	   
	for (k=0, q= inf; k<L; k++, q++)
	   arr[q]= aux[k];
	   
	free(aux);
}

void imprimirArregloEspecial(int *arr, int inf, int sup)
{
	int k=0;
	
	for (k=inf; k<=sup; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}





					   
					   
					   

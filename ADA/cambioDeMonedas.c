#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int *arr, int N);
void darCambio(int N, int cantCambio, int* cantBilletes, int **arrSol1, int**arrSol2);

int main(int argc, char *argv[]) 
{
	//int denomBilletes []= {100, 25, 10, 5, 1};
	int denomBilletes []= {100, 50 ,20 ,10, 5, 2, 1};
	//int cantCambio= 289;
	int cantCambio= 2543;
	int i= 0;
	//int N= 5;
	int N= 7;
	
	int *denominacion= NULL;
	int *numBilletes= NULL;
	
	denominacion= (int *) malloc(N*sizeof(int));
	numBilletes= (int *) malloc(N*sizeof(int));
	
	//Inicializa los arreglos
	for (i= 0; i<N; i++) 
	   {
	   	 denominacion[i]= denomBilletes [i];
	   	 numBilletes[i]= 0;
	   }
	
	printf("\n");
	
	printf ("Cambio: %d $\n", cantCambio);
	printf ("Billetes disponibles: \n");
	for (i=0; i<N; i++)
	   printf ("\tDenominacion: \t%d\t$\n ", denomBilletes[i]);
	   
	darCambio(N, cantCambio, denomBilletes, &denominacion, &numBilletes);
	
	printf("\n");
	
	printf ("Aqui tiene su cambio\n");
	for (i=0; i<N; i++)
	   printf ("\t%d billetes de \t%d\t$\n ", numBilletes[i], denominacion[i]);
	   		         	   
	return 0;
}

void imprimirArreglo(int *arr, int N)
{
	int i= 0;
	
	for (i= 0; i<N; i++)
	   printf ("%d ", arr[i]);
	   
	printf("\n");   
}

//En lugar de retornar dos valores, trabajo con dos arreglos solucion
//donde en la funcion modifico directamente sus valores con apuntadores.

void darCambio(int N, int cantCambio, int* denomBilletes, int **arr1, int**arr2)
{
	int *arrSol1= NULL;
	int *arrSol2= NULL;
	int suma= 0, cant= 0;
	int i= 0;
	
	arrSol1= *arr1;
	arrSol2= *arr2;
	
	/*for (i= 0; i<N; i++) 
	   {
	   	 arrSol1[i]= 1;
	   	 arrSol2[i]= 1;
	   }*/ //Verificacion de que se este trabajando con los arreglos afuera de la funcion.
	
	while (i<N && suma<=cantCambio)
	     {
	     	if ((suma+denomBilletes[i])<=cantCambio)
	     	  {
	     	  	suma+=denomBilletes[i];
	     	  	cant++;
			  }
			else
			  {
			  	if (cant>0)
			  	  {
			  	  	arrSol1 [i]= denomBilletes[i];
			  	  	arrSol2 [i]= cant;
			  	  	cant= 0;
				  }
				i++;
			  }
		 }	
}

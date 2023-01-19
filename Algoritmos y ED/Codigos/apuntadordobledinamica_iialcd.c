#include <stdio.h>
#include <stdlib.h>


//char *argv[] = char **argv; 
// c:\programa.exe	parametro1 parametro2 ...
// ./programa
// int argc: contador de argumentos
// arg[0]= "programa.exe"
// arg[1]= "parametro1"
// arg[2]= "parametro2"
// ...

int main(int argc, char *argv[]) 
{
	// int mat[10][10];	// matriz estatica	
	int **mat= NULL;	// matriz dinamica
	int M= 10, N= 10;	// M filas, N columnas
	int i=0, j=0;

	// matriz =  arreglo de apuntadores sencillos
	// y cada apuntador sencillo haga referencia a un arreglo dinamico
	
	// Creacion de la matriz dinamica:
	
	// apuntador doble:
	mat= (int **) malloc (M*sizeof(int *));	
	// arr= (int *) malloc(L*sizeof(int));
	
	// apuntadores sencillos:
	for (i=0; i<M; i++)
	   mat[i]= (int *) malloc(N*sizeof(int));
	   
	// Inicializacion de la matriz:
	
	for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	      mat[i][j]= i*j;
	      
	// Despliegue de contenido:
	
	for (i=0; i<M; i++)
	   {
	    	for (j=0; j<N; j++)
	      	   printf("%d\t", mat[i][j]);	      	   
	      	printf("\n");
	   }
	   
	// Liberacion de memoria dinamica de la matriz:
	
	// liberacion de apuntadores sencillos:	
	for (i=0; i<M; i++)
	   {
	   		free(mat[i]);
	   		mat[i]= NULL;
	   }

	// liberacion del apuntador doble:		   
	free(mat);
	
	mat= NULL;
	
	return 0;
}

// recordatorio: arreglo dinamico de longitud L
// int *arr= NULL;
// arr= (int *) malloc(L*sizeof(int));


/* Efecto simetrico de creacion y destruccion:

	mat= (int **) malloc (M*sizeof(int *));	
	for (i=0; i<M; i++)
	   mat[i]= (int *) malloc(N*sizeof(int));	   

	for (i=0; i<M; i++)
	   free(mat[i]);
	free(mat);
*/





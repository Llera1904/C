#include <stdio.h>
#include <stdlib.h>

void moverDisco(char dest, char aux, char fte, int N, int *cont, int nivel);

int main(int argc, char *argv[]) 
{
	char fuente= 'A', auxiliar= 'B', destino= 'C';
	int N= 64, contador= 0, nivel=0;
	
	moverDisco(destino, auxiliar, fuente, N, &contador, nivel);
	
	return 0;
}

void moverDisco(char dest, char aux, char fte, int N, int *cont, int nivel)
{
	int k=0;
	
	if (N==0)
	  return;
	 
	// mover N-1 discos de la torre fuente al auxiliar:  
	moverDisco(aux, dest, fte, N-1, cont, nivel+1);
		
	// identacion:
	for (k=0; k<nivel; k++)
	   printf("    ", nivel);
	   
	printf("nivel= %d ::  \t\t", nivel);
		
	// mover último disco de la torre fuente al destino:	
	printf("%d. Mover disco %d: de %c a %c\n", *cont, N, fte, dest);
	(*cont)++;
	
	// mover N-1 discos de la torre auxiliar al destino:
	moverDisco(dest, fte, aux, N-1, cont, nivel+1);
}

/*Versión esencial:
void moverDisco(char dest, char aux, char fte, int N)
{
	int k=0;
	
	if (N==0)
	  return;	 

	moverDisco(aux, dest, fte, N-1);		
	
	printf("Mover disco %d: de %c a %c\n", N, fte, dest);

	moverDisco(dest, fte, aux, N-1);
}*/



#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{
	Lista l= NULL;
	Elemento e= NULL;
	int k=0, x=0;
	int N= 5;	
	
	crearLista(&l);
	
	for (k=0; k<N; k++)
	 	{
	 		crearElemento(&e);
	 		escribirDato(e, 4*k+18);
			insertarElementoPosicionVariante(l, e, k);
			imprimirLista(l);
		}
		
	crearElemento(&e);
	escribirDato(e, 42);
	insertarElementoPosicionVariante(l, e, 2);
	imprimirLista(l);
	N++;

	consultarElementoPosicion(l, &e, 2);
	leerDato(e, &x);
	printf("dato de prueba= %d\n", x);
	
	// Prueba 0:
	/*
	for (k=N-1; k>=0; k--)
	 	{
	 		quitarElementoPosicion(l, &e, k);
	 		leerDato(e, &x);
	 		printf("%d\n", x);
	 		imprimirLista(l);
	 		destruirElemento(&e);
		}*/
	
	
	// Prueba 1:
	/*for (k=0; k<N; k++)
	 	{
	 		quitarElementoPosicion(l, &e, k);
	 		leerDato(e, &x);
	 		printf("%d\n", x);
	 		imprimirLista(l);
	 		destruirElemento(&e);
		}*/
		
	// Prueba 2:
	for (k=0; k<N; k++)
	 	{
	 		quitarElementoPosicion(l, &e, 0);
	 		leerDato(e, &x);
	 		printf("%d\n", x);
	 		imprimirLista(l);
	 		destruirElemento(&e);
		}
		
	destruirLista(&l);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(int argc, char *argv[])
{
	Pila p= NULL;
	Elemento e= NULL;
	int k=0, x=0, y=0;
	int N= 10;	
	
	crearPila(&p);
	
	for (k=0; k<N; k++)
	 	{
	 		crearElemento(&e);
	 		y= 13*k+21;
	 		printf("%d\n", y);
	 		escribirDato(e, y);	// 138
			insertarElemento(p, e);
			imprimirPila(p);
		}
	
	printf("\n");
	
	for (k=0; k<N; k++)
	 	{
	 		quitarElemento(p, &e);
	 		leerDato(e, &x);
	 		destruirElemento(&e);
	 		printf("%d\n", x);
	 		imprimirPila(p);
		}
	
	destruirPila(&p);
	return 0;
}

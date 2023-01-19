#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "elemento.h"

int main(int argc, char *argv[])
{
	Cola c= NULL;
	Elemento e= NULL;
	int k=0, x=0;
	int N= 10;
	int sw= FALSO;	
	
	sw= crearCola(&c);
	
	if (sw==FALSO)
	  return 0;
	
	for (k=0; k<N; k++)
	 	{
	 		crearElemento(&e);
	 		escribirDato(e, 13*k+21);
			insertarElemento(c, e);
			imprimirCola(c);
		}
	
	for (k=0; k<N; k++)
	 	{
	 		quitarElemento(c, &e);
	 		leerDato(e, &x);
	 		printf("%d\n", x);
	 		imprimirCola(c);
		}
	
	destruirCola(&c);
	return 0;
}

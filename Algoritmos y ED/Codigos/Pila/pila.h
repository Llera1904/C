#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

typedef struct pila
{
	Nodo base;
	Nodo tope;
	int longitud;
}	t_pila, *Pila;

// Pila * = (struct pila **)
// Pila   = (struct pila *)
// t_pila = (struct pila)

int crearPila(Pila *p);
int insertarElemento(Pila p, Elemento e);
int quitarElemento(Pila p, Elemento *e);
int consultarTope(Pila p, Elemento *e);
int destruirPila(Pila *q);
int imprimirPila(Pila p);

#endif

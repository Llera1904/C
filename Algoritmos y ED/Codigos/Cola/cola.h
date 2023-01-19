#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "elemento.h"

typedef struct cola
{
	Nodo primero;
	Nodo ultimo;
	int longitud;
}	t_cola, *Cola;

// Cola = (struct cola *)

int crearCola(Cola *c);
int insertarElemento(Cola c, Elemento e);
int quitarElemento(Cola c, Elemento *e);
int consultarPrimero(Cola c, Elemento *e);
int destruirCola(Cola *q);
int imprimirCola(Cola c);

#endif

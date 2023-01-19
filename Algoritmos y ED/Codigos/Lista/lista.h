#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "elemento.h"

#define ADELANTE	0
#define REVERSA		1

typedef struct lista
{
	Nodo primero;
	Nodo ultimo;
	int longitud;
}	t_lista, *Lista;

// Lista = (struct lista *)
// t_lista = (struct lista)

int crearLista(Lista *l);
int destruirLista(Lista *y);
int consultarPrimero(Lista l, Elemento *e);
int consultarUltimo(Lista l, Elemento *e);
int consultarElementoPosicion(Lista l, Elemento *e, int posicion);
int insertarElementoPosicion(Lista l, Elemento e, int posicion);
int quitarElementoPosicion(Lista l, Elemento *e, int posicion);
int insertarElementoPosicionVariante(Lista l, Elemento e, int posicion);
int imprimirLista(Lista l);

#endif

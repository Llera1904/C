#ifndef NODO_H
#define NODO_H

#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

typedef struct nodo
{
	struct nodo *enlaceDer;
	Elemento elem;
	struct nodo *enlaceIzq;
	// struct nodo *enlaceC;
	// struct nodo **enlaces; 	// arreglo a apuntadores
}t_nodo, *Nodo;

// Nodo = (struct nodo *)
// Nodo *= (struct nodo **)

int crearNodo(Nodo *n);
int destruirNodo(Nodo *n);
int escribirElemento(Nodo n, Elemento e);
int leerElemento(Nodo n, Elemento *e);

// conexion:
int conectarEnlaceDerecho(Nodo n, Nodo eA);
int conectarEnlaceIzquierdo(Nodo n, Nodo eB);

// consulta:
int consultarEnlaceDerecho(Nodo n, Nodo *eA);
int consultarEnlaceIzquierdo(Nodo n, Nodo *eB);

//desconexion:
int desconectarEnlaceDerecho(Nodo n);
int desconectarEnlaceIzquierdo(Nodo n);

#endif

/*
// referencia a multiples nodos
typedef struct nodo
{
	struct nodo *enlaceA;
	struct nodo **coleccion;	// arreglo dinamico de nodos
	struct nodo *enlaceB;
	// struct nodo *enlaceC;
	// struct nodo **enlaces; 	// arreglo a apuntadores
}t_nodo, *Nodo;
*/




#ifndef NODO_H
#define NODO_H

#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

typedef struct nodo
{
	struct nodo **enlaces;
	Elemento elem;
	int grado;
}t_nodo, *Nodo;

// Nodo = (struct nodo *)
// Nodo *= (struct nodo **)

int crearNodo(Nodo *n, int grado);
int destruirNodo(Nodo *n);
int escribirElemento(Nodo n, Elemento e);
int leerElemento(Nodo n, Elemento *e);

// conexion:
int conectarEnlace(Nodo fuente, Nodo destino);
int conectarEnlacePuerto(Nodo fuente, Nodo destino, int puerto);

// consulta:
int consultarEnlace(Nodo fuente, Nodo *destino, int puerto);
int consultarEnlaces(Nodo fuente, Nodo **conexiones, int *grado);

// desconexion:
int desconectarEnlace(Nodo fuente, Nodo destino);
int desconectarEnlacePuerto(Nodo fuente, int puerto);

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




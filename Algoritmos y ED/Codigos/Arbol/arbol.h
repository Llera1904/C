#ifndef ARBOL_H
#define ARBOL_H

#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

typedef struct arbol
{
  Nodo raiz;
  int cantidad;
} t_arbol, *Arbol;

// Arbol = (struct arbol *)
// Arbol * = (struct arbol **)
// t_arbol = (struct arbol)

// Creacion y destruccion:
int crearArbol(Arbol *b);
void destruirArbol(Arbol *b);
void destruirNodosRecursivamente(Nodo central);

// Insercion de datos:
int insertarElemento(Arbol a, Elemento e);
Nodo insertarElementoRecursivo(Nodo central, Elemento e);

// Busqueda:
int buscarElemento(Arbol a, Elemento e);
Nodo buscarElementoRecursivo(Nodo central, Elemento e);
Nodo buscarMinimo(Nodo central);
Nodo buscarMaximo(Nodo central);

// Recorridos:
int recorrerArbolEnOrden(Arbol a);
void recorrerNodosEnOrden(Nodo central);
int recorrerArbolPreOrden(Arbol a);
void recorrerNodosPreOrden(Nodo central);
int recorrerArbolPostOrden(Arbol a);
void recorrerNodosPostOrden(Nodo central);
int recorrerArbolEnOrdenDescendente(Arbol a);
void recorrerNodosEnOrdenDescendente(Nodo central);

// Eliminacion:
int eliminarElemento(Arbol a, Elemento e);
int eliminarElementoRecursivo(Nodo *foco, Elemento e);


#endif

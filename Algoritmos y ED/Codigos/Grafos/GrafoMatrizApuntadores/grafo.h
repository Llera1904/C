#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

#define VISITADO 	 0
#define NOVISITADO 	-1

typedef struct grafo
{
  Nodo *nodos;
  int **conexiones;
  int cantidad;
} t_grafo, *Grafo;

// Grafo = (struct grafo *)
// Grafo * = (struct grafo **)
// t_grafo = (struct grafo)

// Creacion y destruccion:
int crearGrafo(Grafo *g, int cantidad);
int cargarMatrizAdyacencia(Grafo g, int **matriz, int cantidad);
void destruirGrafo(Grafo *g);

// Insercion de datos:
int insertarElemento(Grafo g, Elemento e, int id);
int agregarConexion(Grafo g, int idFte, int idDest, int peso);

// Consulta
int consultarElemento(Grafo g, Elemento *e, int id);
int consultarPonderacion(Grafo g, int *peso, int idFte, int idDest);

// Eliminacion:
int eliminarElemento(Grafo g, Elemento *e, int id);
int quitarConexion(Grafo g, int idFte, int idDest);

int generarArbolAmplitud(Grafo *arbol, Grafo g, int id);
int recorrerGrafoAmplitud(Grafo arb, Grafo g, int *visitados, Nodo centro, int id, int vecindario);

int generarArbolProfundidad(Grafo *arbol, Grafo g, int id);
int recorrerGrafoProfundidad(Grafo arb, Grafo g, int *visitados, Nodo centro, int id, int nivel);

int imprimirGrafo(Grafo g);


#endif

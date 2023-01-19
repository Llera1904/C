#ifndef GRAFODINAMICO_H
#define GRAFODINAMICO_H

#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

#define VISITADO 	 0
#define NOVISITADO 	-1


typedef struct grafodinamico
{
  Nodo inicial;
  Nodo final;
  int numAristas;
  int numVertices;
} t_grafodinamico, *GrafoDinamico;

// GrafoDinamico = (struct grafodinamico *)
// GrafoDinamico * = (struct grafodinamico **)
// t_grafodinamico = (struct grafodinamico)

// Creacion y destruccion:
int crearGrafo(GrafoDinamico *g);
int cargarMatrizAdyacencia(GrafoDinamico g, int **matriz, int *arrID, int cantidad);
int destruirGrafo(GrafoDinamico *g);

// Insercion de datos:
int insertarElemento(GrafoDinamico g, Elemento e, int id);
int agregarConexion(GrafoDinamico g, int idFte, int idDest, int peso);

// Consulta
int consultarElemento(GrafoDinamico g, Elemento *e, int id);
int consultarPonderacion(GrafoDinamico g, int *peso, int idFte, int idDest);

// Eliminacion:
int eliminarElemento(GrafoDinamico g, Elemento *e, int id);
int quitarConexion(GrafoDinamico g, int idFte, int idDest);

int generarArbolAmplitud(GrafoDinamico *arbol, GrafoDinamico g, int id);
int recorrerGrafoAmplitud(GrafoDinamico arb, GrafoDinamico g, Nodo centro, int id, int vecindario);

int generarArbolProfundidad(GrafoDinamico *arbol, GrafoDinamico g, int id);
int recorrerGrafoProfundidad(GrafoDinamico arb, GrafoDinamico g, Nodo centro, int id, int nivel);

int imprimirGrafo(GrafoDinamico g);


/*
typedef struct grafo
{
  Nodo *nodos;
  int cantidad;
} t_grafo, *Grafo;
*/

// generarMatrizAdyacencia
/*
typedef struct nodo
{
	struct nodo *enlaces;
	Elemento elem;
	int grado;
	int profundidad;
	int id;
}t_nodo, *Nodo;
*/

#endif

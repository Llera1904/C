#ifndef NODO_H
#define NODO_H

#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

#define VERTICE		0
#define ARISTA		1

typedef struct nodo
{
	int id;
	
	struct nodo *enlace;
	struct nodo *entrada;
	struct nodo *salida;
	
	Elemento elem;
	
	int profundidad;
	int gradEnt;
	int gradSal;
	int peso;
	
	int status;
	
}t_nodo, *Nodo;

// Nodo = (struct nodo *)
// Nodo *= (struct nodo **)

int crearNodo(Nodo *n, int id, int status);
int destruirNodo(Nodo *n);
int escribirElemento(Nodo n, Elemento e);
int leerElemento(Nodo n, Elemento *e);

int establecerProfundidad(Nodo n, int p);
int establecerPeso(Nodo n, int w);

int consultarID(Nodo n, int *id);
int consultarProfundidad(Nodo n, int *p);
int consultarGradoEntrada(Nodo n, int *g);
int consultarGradoSalida(Nodo n, int *g);
int consultarPeso(Nodo n, int *w);
int consultarStatus(Nodo n, int *status);

// conexion:
int conectarEnlace(Nodo fuente, Nodo destino);
int conectarEntrada(Nodo centro, Nodo entrada);
int conectarSalida(Nodo fuente, Nodo salida);


// consulta:
int consultarEnlace(Nodo *destino, Nodo fuente);
int consultarEntrada(Nodo *entrada, Nodo centro);
int consultarSalida(Nodo *salida, Nodo centro);

// desconexion:
int desconectarEnlace(Nodo fuente);
int desconectarEntrada(Nodo centro);
int desconectarSalida(Nodo centro);

// agregacion de conexiones:
int agregarConexionNodos(Nodo fuente, Nodo destino, int peso);
int agregarConexionEntrada(Nodo fuente, Nodo destino, int peso);
int agregarConexionSalida(Nodo fuente, Nodo destino, int peso);

// removimiento de conexiones:
int removerConexionNodos(Nodo fuente, Nodo destino);
int removerConexionEntrada(Nodo fuente, Nodo destino);
int removerConexionSalida(Nodo fuente, Nodo destino);

// consultaConexion:
int consultarConexion(Nodo *arista, Nodo fuente, Nodo destino);

// desconexiones:
int desconectarCompletamente(Nodo centro);
int desconectarEntradas(Nodo destino);
int desconectarSalidas(Nodo fuente);

//




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




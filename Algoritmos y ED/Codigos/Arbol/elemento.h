#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <stdio.h>
#include <stdlib.h>

#define VERDADERO 	1
#define FALSO		0

#define MAYOR		1
#define IGUAL		0
#define MENOR		-1
#define DIFERENTE   -42

typedef struct elemento
{
	int dato;
}	t_elemento, *Elemento;

int crearElemento(Elemento *e);
int destruirElemento(Elemento *e);
int escribirDato(Elemento e, int dato);
int leerDato(Elemento e, int *dato);
int compararElementos(Elemento a, Elemento b);

// Elemento *= (struct elemento **)
// Elemento = (struct elemento *)
// t_elemento = (struct elemento)
// void *malloc(tamaño);

#endif

#ifndef	LIBARR_H
#define	LIBARR_H

#include <stdio.h>
#include <stdlib.h>

//#include "\folder\sub\lib.h"
//#include "/folder/sub/lib.h"
//#include "\\folder\\sub\\lib.h"
//#include "//folder//sub//lib.h"

#define VERDADERO	1
#define FALSO		0
#define NOLOCALIZADO		-1
#define LONGITUDNEGATIVA	-2

void inicializarArreglo(int arr[], int N);
void imprimirArreglo(int arr[], int N);
void inicializarAleatoriamente(int arr[], int N, int lim);
int buscarNumeroArreglo(int arr[], int N, int num);
int buscarNumeroArregloFulminante(int arr[], int N, int num);
void ordenarArreglo(int arr[], int N);

#endif

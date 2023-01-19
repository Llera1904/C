#include <stdio.h>	// libreria de entrada/salida standard
#include <stdlib.h>	// libreria manejo de memoria
#include <math.h>	// libreria de funciones matematicas

// comentario 1 sola linea

// funcion principal: main
	// int argc: contador argumentos
	// char *argv[]: argumentos = char **
// int: tipo de dato de salida del programa
	
int main(int argc, char *argv[])
{	// inicio del cuerpo de la funcion

	printf("hola multiverso!\n");	// imprime mensaje en consola
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	return 0;		// termino del programa sin problemas
}	// final del cuerpo de la funcion

//#include <libreria.h>		// libreria de C
//#include "libreria.h"		// libreria de usuario
// library = biblioteca
// bookstore = libreria

/* comentario
	linea 0
	linea 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
	int dado= 0;
	int contador= 0;
	int caras= 6;
	int limite= 3;
	
	// time(NULL);			// el tiempo en segundos transcurridos
							// desde el 1 de enero de 1970
							
	srand(time(NULL));	// inicializacion del generador de numeros
						// aleatorios
	
	dado= rand();		// generador de numeros aleatorios
	dado= dado%caras;		// modulo: residuo= 0, 1, 2, 3, 4, 5
	//dado= dado%n		// modulo: residuo= 0, 1, 2, ..., n-1
	dado++;
	
	printf("dado fuera del while= %d\n", dado);
	
	while(dado!=6)
	{
		dado= rand();
		printf("numero aleatorio= %d\n", dado);
		dado= dado % caras;
		dado++;
		contador++;
		printf("Lanzamiento= %d, valor del dado= %d\n", contador, dado);
		
		if (contador==limite)
		  break;				// break: rompe el ciclo
	}
	
	printf("fin de lanzamientos\n");
	
	return 0;
}

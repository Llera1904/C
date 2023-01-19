#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char cad[60]="Hola, Tlaloc. Queremos lluvia! x27";
	int N= 60, k=0;
	int i=0, j=0;
	char aux= ' ';
	
	// impresion completa del arreglo:
	
	for (k=0; k<N; k++)
	   printf("[%d]= %c\n", k, cad[k]);
	   
	printf("\n");
	
	// impresion de cadena hasta alcanzar fin de cadena
	
	for (k=0; cad[k]!='\0'; k++)
	   printf("[%d]= %c\n", k, cad[k]);
	   
	printf("\n");
	// impresion "instantanea"
	
	printf("%s", cad);
	
	printf("\n");
	
	// version artesanal:
	
	for (k=0; cad[k]!='\0'; k++)
	   printf("%c", cad[k]);	
	   
	// ordenamiento de caracteres de una cadena
	
	for (i=0; cad[i]!='\0'; i++)
	   {
	   	 for (j=i+1; cad[j]!='\0'; j++)
	   	    {
	   	    	if (cad[j]<cad[i])
				  {
				  	aux= cad[j];
					cad[j]= cad[i];
					cad[i]= aux;
				  }	
			}
	   }
	
	printf("\n");
	   
	for (k=0; cad[k]!='\0'; k++)
	   printf("%c", cad[k]);
	
	return 0;
}

// Caracteres especiales:
/*
	'\0' : fin de cadena
	'\n' : salto de linea
	'\t' : tabulador
	' '  : espacio
	'\r' : retorno de carro 
*/

// Especificadores de formato:
/*
	%c : caracter
	%s : cadena de caracteres
*/




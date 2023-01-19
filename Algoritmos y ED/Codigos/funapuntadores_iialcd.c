#include <stdio.h>
#include <stdlib.h>

#define OK		0
#define ERROR	-1
#define ETIQUETA -2

char *crearCadena(int N);
void destruirCadena(char *cad);
void imprimirCadena(char *cad);
void copiarCadenas(char *dest, char *fte);
void escribirLetraReferencia(char *w);
char escribirLetraPorRetorno(char w);
void escribirLetraPorValor(char w);
void invertirCadena(char *dest, char *fte);
int obtenerLongitudCadena(char *cad, int *N);

void destruirCadenaSegura(char **cad);

/*int main(int argc, char *argv[])
{
	char letra= ' ';
	
	letra= 'A';
	escribirLetraPorValor(letra);			// w= letra;
	printf("valor: letra= %c\n", letra);
	
	letra= 'A';
	letra= escribirLetraPorRetorno(letra);	// w= letra;
	printf("retorno: letra= %c\n", letra);
	
	letra= 'A';
	escribirLetraReferencia(&letra);	// w= &letra;	
	printf("referencia: letra= %c\n", letra);
}*/

int main(int argc, char *argv[])
{
	char *str= NULL; 		// string	
	char spiderman[100]= "peter parker";
	int N= 60, M=0;
	char letra= 'A';
	int sw= ERROR;
	
	str= crearCadena(N);
	
	//printf("printf: %s\n", spiderman);
	
	imprimirCadena(str);	
	imprimirCadena(spiderman);
	
	copiarCadenas(str, spiderman);
	imprimirCadena(str);
	
	invertirCadena(str, spiderman);
	imprimirCadena(str);
	
	sw= obtenerLongitudCadena(spiderman, &M);		// L= &M;
	if (sw==OK)
	  printf("La cadena tiene %d caracteres\n", M);
	else
	  printf("Error de apuntador nulo\n");
		
	destruirCadena(str);
	str= NULL;
	
	// destruirCadenaSegura(&str);
	
	//printf("&str= %X   str=%X   *str= %c\n", &str, str, *str);
	//printf("&str= %X   str=%X\n", &str, str);
		
	return 0;
}

void escribirLetraReferencia(char *w)	// recibe la direccion de la variable
{
	*w= 'D';	// la modificacion se ve reflejada al regresar
				// a la funcion que hizo la invocacion
}

char escribirLetraPorRetorno(char w)
{
	w= 'C';			// asignara el valor de 'J' a la variable que capture
					// el valor de retorno de la funcion
	return(w);
	//return('J');
}

void escribirLetraPorValor(char w)	// recibe una copia del valor de la variable
{
	w= 'B';		// la modificacion NO se vera reflejada al regresar
				// a la funcion que hizo la invocacion
}

char *crearCadena(int N)
{
	char *cad= NULL;
	//int k=0;
	
	cad= (char *) malloc(N*sizeof(char));
	
	cad[0]= '\0';
	
	/*for (k=0; k<N; k++)
	   cad[k]= '@';
	   	
	cad[N-1]= '\0';*/
	   
	return(cad);
}

void destruirCadena(char *cad)
{
	// printf("&cad= %X   cad=%X   *cad= %c\n", &cad, cad, *cad);
	free(cad);
	//cad= NULL;
}

void destruirCadenaSegura(char **cad)
{
	char *q= NULL;
	
	q= *cad;
	
	printf("&q= %X   q=%X   *q= %c\n", &q, q, *q);
	
	//printf("&cad= %X   cad=%X   *cad= %c\n", &cad, cad, *cad);
	free(q);
	*cad= NULL;
}

void imprimirCadena(char *cad)			// cad = str;
{
	int k=0;
	
	for (k=0; cad[k]!='\0'; k++)
	   printf("%c", cad[k]);
	
	printf("\n");	   
}

void copiarCadenas(char *dest, char *fte)
{
	int k=0;
	
	for (k=0; fte[k]!='\0'; k++)
	   dest[k]= fte[k];
	   
	dest[k]= '\0';	   
}

void invertirCadena(char *dest, char *fte)
{
	int k=0, c=0, N=0;
	
	// "peter parker"	=> 	"rekrap retep"
	// "peter parker'\0'"	=> 	"rekrap retep'\0'"
	
	// k: cadena fuente,	c: cadena destino
	
	for (k=0; fte[k]!='\0'; k++);
	
	N= k;
	
	for (k=N-1, c=0; k>=0; k--, c++)
	   dest[c]= fte[k];
	   
	dest[N]= '\0';
}

// calcular la longitud de una cadena

int obtenerLongitudCadena(char *cad, int *L)  // L= &M;
{
	int k=0;
	
	if (cad==NULL)
	  return(ERROR);
	  
	for (k=0; cad[k]!='\0'; k++);
	
	*L= k;
	
	return(OK);		// OK: "ALL CORRECT" "Zero Kills"
}

/*
// buscar una letra dentro de la cadena
// buscar una subcadena dentro de una cadena
// concatenar cadenas y la deja en una tercera


str= NULL;
	
	sw= obtenerLongitudCadena(str, &M);
	if (sw==OK)
	  printf("La cadena tiene %d caracteres\n", M);
	else
	  printf("Error de apuntador nulo\n");
	
	letra= 'A';
	escribirLetraReferencia(&letra);	// w= &letra;	
	printf("referencia: letra= %c\n", letra);
	
	letra= 'A';
	escribirLetraPorValor(letra);	// w= &letra;	
	printf("valor: letra= %c\n", letra);
	
	letra= 'A';
	letra= escribirLetraPorRetorno(letra);	// w= &letra;	
	printf("retorno: letra= %c\n", letra);

	//str= crearCadena(N);
	//copiarCadenas(str, "hola a todos");
	//imprimirCadena(str);
	//destruirCadena(str);
	
*/

// %s: especificador de formato
//     de impresion de cadenas de caracteres 

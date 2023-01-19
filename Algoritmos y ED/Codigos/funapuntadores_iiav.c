#include <stdio.h>
#include <stdlib.h>

char *crearCadena(int N);
void destruirCadena(char *cad);
void imprimirCadena(char *cad);
void copiarCadenas(char *dest, char *fte);
void escribirLetra(char *w);

int main(int argc, char *argv[])
{
	char *str= NULL; 		// string
	char spiderman[100]= "peter parker";
	int N= 60;
	char letra= 'A';
	
	str= crearCadena(N);
	imprimirCadena(str);
	
	imprimirCadena(spiderman);
	copiarCadenas(str, spiderman);
	imprimirCadena(str);
	
	destruirCadena(str);
	
	escribirLetra(&letra);	// w= &letra;
	
	printf("letra= %c\n", letra);
	
	return 0;
}

char *crearCadena(int N)
{
	char *cad= NULL;
	int k=0;
	
	cad= (char *) malloc(N*sizeof(char));
	
	cad[0]= '\0';
	
	/* for (k=0; k<N; k++)
	   cad[k]= '@';	
	cad[N-1]= '\0'; */ 
	   
	return(cad);
}

void destruirCadena(char *cad)
{
	free(cad);
	// cad= NULL;
}

void imprimirCadena(char *cad)
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

void escribirLetra(char *w)
{
	*w= 'C';
}




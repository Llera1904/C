#include <stdio.h>
#include <stdlib.h>

/* comentarios */

int main(int argc, char *argv[]) 
{
	int hora= -5, temp= 21;		// hora y temperatura
	
	printf("hora= ");
	scanf("%d", &hora);
	
	// prueba A: barra de caracicaturas
	
	if (hora==16)
	  {
	     printf("A.if> Son las cuatro de la tarde!\n");
	     printf("Me estoy perdiendo las caricaturas\n");
      }
	else
	  {
	  	printf("A.else> No son las cuatro de la tarde!\n");
	  	printf("Podre sobrevivir sin las caricaturas\n");
	  }
	  

	// prueba B: algo diferente a caricaturas
	
	if (hora!=16)
	  printf("B.if> No son las cuatro de la tarde!\n");
	else
	  printf("B.else> Son las cuatro de la tarde!\n");
	  
	  
	// prueba C: eleccion de ropa por el horario:
	
	if (hora<=7 || hora>=18)		// ||
	  printf("C.if> Llevare un sueter\n");
	else
	  printf("C.else> No quiero llevar sueter\n");
	  
	// prueba D: horario de actividades
	
	if (hora>13 && hora<22)
	  printf("D.if> Realizar actividades\n");
	else
	  printf("D.else> Despejarse\n");
	  
	
	// prueba E: inclusion de la variable temperatura:
	
	printf("temperatura= ");
	scanf("%d", &temp);
	
	if ((hora<=7 || hora>=18) || temp<10)
			
	  printf("E.if> Llevare un sueter\n");
	else
	  printf("E.else> No quiero llevar sueter\n");
	  
	return 0;
}

// %c: especificador de formato de caracter

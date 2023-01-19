#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VERDADERO		1
#define FALSO			0
#define CARTESIANO		1
#define POLAR			0

// TAD: tipo abstracto de datos numero complejo:

// rueda:

typedef struct complejo
{
	float real;
	float imaginario;
	float magnitud;
	float argumento;	
}t_complejo, *Complejo;

// t_complejo = (struct complejo)				// tamaño de la estructura
// Complejo =   (struct complejo *)				// IMPORTANTE
// Complejo *=  (struct complejo **)
// Complejo **= (struct complejo ***)


// int *arr= (int *) malloc(N*sizeof(int));

// struct complejo *c= (struct complejo *) malloc(1*sizeof(struct complejo));

// Complejo c= (Complejo) malloc(sizeof(t_complejo));

// i= sqrt(-1);
// z= real + i imaginario;			z= x+iy;
// z= magnitud*exp(i*argumento);	z= r*exp(i*arg);

Complejo crearNumeroComplejo(float a, float b, int formato);
// Estructura crearEstructura(...);

int crearNumeroComplejoReferencia(Complejo *z, float a, float b, int formato);
// int crearEstructuraReferencia(Estructura *e);

void imprimirNumeroComplejo(Complejo z, int formato);
// void desplegarEstructura(Estructura e);

int destruirNumeroComplejo(Complejo *z);
// int destruirEstructura(Estructura *e);

// Operaciones de la estructura: insercion, eliminacion
int sumarNumerosComplejos(Complejo *z, Complejo z0, Complejo z1);
int multiplicarNumerosComplejos(Complejo *z, Complejo z0, Complejo z1);

// Operaciones de consulta: control sobre atributos de la estructura:
int obtenerComponenteReal(Complejo z, float *x);
int obtenerComponenteImaginaria(Complejo z, float *y);
int obtenerMagnitud(Complejo z, float *r);
int obtenerArgumento(Complejo z, float *a);

int main(int argc, char *argv[]) 
{
	Complejo zA= NULL;
	Complejo zB= NULL;
	Complejo zC= NULL;
	
	// creacion convencional:
	zA= crearNumeroComplejo(1.0, 0.0, CARTESIANO);		// a= 1;
	
	// creacion por referencia: &e
	crearNumeroComplejoReferencia(&zB, 1.0, M_PI/2.0, POLAR);	// b= i;	
	crearNumeroComplejoReferencia(&zC, 0.0, 0.0, CARTESIANO);  //c= 0;
	
	printf("zA= ");
	imprimirNumeroComplejo(zA, CARTESIANO);
	printf("zA= ");
	imprimirNumeroComplejo(zA, POLAR);	
	
	printf("zB= ");
	imprimirNumeroComplejo(zB, CARTESIANO);
	printf("zB= ");
	imprimirNumeroComplejo(zB, POLAR);

	sumarNumerosComplejos(&zC, zA, zB);
	printf("zC= zA + zB = ");
	imprimirNumeroComplejo(zC, CARTESIANO);
	printf("zC= zA + zB = ");
	imprimirNumeroComplejo(zC, POLAR);	
	
	multiplicarNumerosComplejos(&zC, zA, zB);
	printf ("zC= zA * zB = ");
	imprimirNumeroComplejo(zC, CARTESIANO);
	printf ("zC= zA * zB = ");
	imprimirNumeroComplejo(zC, POLAR);

	destruirNumeroComplejo(&zC);
	destruirNumeroComplejo(&zB);
	destruirNumeroComplejo(&zA);
	
	return 0;
}

Complejo crearNumeroComplejo(float a, float b, int formato)
{
	Complejo z= NULL;	// declaracion de una variable de estructura
	//int *arr= NULL;
	
	//arr= (int *) malloc(N*sizeof(int));

	// crear dinamicamente la estructura:
	z= (Complejo) malloc(sizeof(t_complejo));					// IMPORTANTE
	
	// verificacion de consistencia:
	if (z==NULL)
	  return(NULL);
	  
	// asignacion de valores a los atributos segun formato:
	if (formato==CARTESIANO)
	  {
	  	// asignacion directa:
	  	// sin apuntadores: z.atributo= x;
	  	// con apuntadores: z->atributo= x;
	  	
		z->real= a;				// x= a
		z->imaginario= b;		// y= b
	
		// conversion:
		z->magnitud= sqrt(a*a+b*b);		// r= sqrt(x^2+y^2)
		z->argumento= atan2(b,a);		// arg= atan(y/x)
	  }
	else
	  {
	  	z->magnitud= a;			// r= a 
	  	z->argumento= b;		// arg= b
	  	
	  	z->real= a*cos(b);			// x= r*cos(arg);
	  	z->imaginario= a*sin(b);	// y= r*sin(arg);
	  }
	  
	// regresar el valor:
	return(z);	
}
									
int crearNumeroComplejoReferencia(Complejo *z, float a, float b, int formato)
{
	Complejo c= NULL;
	
	// creacion convencional:
	c= crearNumeroComplejo(a, b, formato);
	
	if (c==NULL)
	  {
	  	*z= NULL;
	  	return(FALSO);
	  }
	
	// acceder al contenido de la referencia:
	*z= c;											// IMPORTANTE
	
	return(VERDADERO);
}

void imprimirNumeroComplejo(Complejo z, int formato)
{
	if (z==NULL)
	  return;
	
	if (formato==CARTESIANO)  
	  printf("%0.4f + i %0.4f\n", z->real, z->imaginario);
	else
	  printf("%0.4f e^(i %0.4f PI)\n", z->magnitud, z->argumento/M_PI);	
}

int destruirNumeroComplejo(Complejo *z)
{
	if (*z==NULL)
	  return(FALSO);

	// liberar antes contenido de la estructura si es necesario
		  
	free(*z);
	
	// asignacion del valor NULL al contenido del apuntador:
	*z= NULL;
	
	return(VERDADERO);
}

int sumarNumerosComplejos(Complejo *z, Complejo z0, Complejo z1)
{
	float x=0.0, y=0.0;
	
	// resultado es un apuntador que funciona por referencia
	// contenido a donde apunta z: *z
	// acceso a atribiutos: (*z)->atributo
	
	if (*z==NULL || z0==NULL || z1==NULL)
	  return(FALSO);
	
	// operacion/asignacion directa
	(*z)->real= z0->real + z1->real;						// IMPORTANTE
	(*z)->imaginario= z0->imaginario + z1->imaginario;

	x= (*z)->real;
	y= (*z)->imaginario;
	
	// conversion: actualizacion/consistencia de datos
	
	(*z)->magnitud= sqrt(x*x+y*y);
	(*z)->argumento= atan2(y, x);
	
	return(VERDADERO);
}

int multiplicarNumerosComplejos(Complejo *z, Complejo z0, Complejo z1)
{
	float r=0.0, a=0.0;
	
	if (*z==NULL || z0==NULL || z1==NULL)
	  return(FALSO);
	  
	// calculo directo:
	(*z)->magnitud= (z0->magnitud) * (z1->magnitud);
	(*z)->argumento= (z0->argumento) + (z1->argumento);

	r= (*z)->magnitud;
	a= (*z)->argumento;
	
	// conversion:
	
	(*z)->real= r*cos(a);
	(*z)->imaginario= r*sin(a);
	
	return(VERDADERO);
}

int obtenerComponenteReal(Complejo z, float *x)
{
	if (z==NULL)
	  return(FALSO);
	
	// consulta por referencia:	
	*x= z->real;
	
	return(VERDADERO);
}

int obtenerComponenteImaginaria(Complejo z, float *y)
{
	if (z==NULL)
	  return(FALSO);
	  
	*y= z->imaginario;
	return(VERDADERO);
}

int obtenerMagnitud(Complejo z, float *r)
{
	if (z==NULL)
	  return(FALSO);
	  
	*r= z->magnitud;
	return(VERDADERO);
}

int obtenerArgumento(Complejo z, float *a)
{
	if (z==NULL)
	  return(FALSO);
	  
	*a= z->argumento;
	return(VERDADERO);
}


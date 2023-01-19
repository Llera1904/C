#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Notacion UML: Unified Modelling Language

double calcularAreaPabellon(double a);
double calcularAreaAnillo(double a);
double calcularAreaCirculo(double radio);
double calcularAreaTriangulo(double lado);
double calcularAreaRombo(double lado);
double calcularAreaParalelogramo(double lado);
double calcularAreaLego(double a);

int main(int argc, char *argv[])
{
	double areaUtil=0.0;
	double w= 13;
	
	areaUtil= calcularAreaPabellon(w);		// a= w;	a= 13;
	areaUtil+= 2*calcularAreaPabellon(7);
	areaUtil+= calcularAreaPabellon(3);
	
	printf("area util para el proyecto arquitectonico= %0.4lf", areaUtil);
	
	return 0;
}

// Pabellon:

double calcularAreaPabellon(double a)
{
	double area=0.0;
	
	area+= calcularAreaAnillo(a);
	area+= calcularAreaTriangulo(a);
	area+= calcularAreaRombo(a);
	area+= calcularAreaParalelogramo(a);
	area+= calcularAreaLego(a);
	
	return(area);
}

// Figuras Intermedias:

double calcularAreaAnillo(double a)
{
	double areaExterior=0.0, areaInterior=0.0;
	double areaAnillo=0.0;
	
	areaExterior= calcularAreaCirculo(30*a);
	areaInterior= calcularAreaCirculo(20*a);
	areaAnillo= areaExterior-areaInterior;
	
	return(areaAnillo);
}


double calcularAreaParalelogramo(double lado)
{
	double area=0.0;
	
	area= 2*calcularAreaRombo(lado);
	return(area);
}

double calcularAreaLego(double a)
{
	double area=0.0;
	
	area= 8*a*a;
	area-= 2*calcularAreaCirculo(a/2.0);
	
	return(area);
}


// Figuras Basicas:

double calcularAreaCirculo(double radio)
{
	double area=0.0;
	
	area= M_PI*radio*radio;
	return(area);
}

double calcularAreaTriangulo(double lado)
{
	double area=0.0;
	
	area= (sqrt(3)/8.0)*(lado*lado);
	return(area);
}

double calcularAreaRombo(double lado)
{
	return(lado*lado);
}

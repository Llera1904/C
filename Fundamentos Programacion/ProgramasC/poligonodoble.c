#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
	int N= 6;
	double lado= 1.0;
	double area= 0.0, perimetro=0.0;
	double alpha=0.0, radio=0.0;
	
	printf("Numero de lados del poligono N= ");
	scanf("%d", &N);
	
	printf("lado del poligono= ");
	scanf("%lf", &lado);			// %lf: especificador de formato
									// para datos double
	
	perimetro= ((double) N)*lado;	// conversion de tipo de datos
									// casting
	
	// calculo directo compactado:								
	//area= (((double) N)/4)*(lado*lado)/tan(M_PI/((double) N));
	
	// factores:
	
	/*
	area= ((double) N)/4.0;
	area= area*(lado*lado);				// x= x*b; es equivalente a x*= b;
	area= area/tan(M_PI/(double)N);		// x= x/b;  x/=b;
    */
    
    // notacion compacta:
	/*area= ((double) N)/4.0;
	area*= lado*lado;				
	area/= tan(M_PI/(double)N);*/
	
	// x= x+1;	x+=1;	x++;
	// x= x+b;	x+=b;   
	// c= c+1;  c+=1;	c++;
	// c sharp	c# = (c++)++;
	
	// calculos intermedios:
	
	alpha= M_PI/((double) N);
	radio= lado/(2.0*sin(alpha));
	area= (((double) N)/4.0);
	area*= lado*sqrt(4.0*radio*radio-lado*lado);		// square root
	
	printf("area= %0.20lf\n", area);
	printf("perimetro= %0.20lf\n", perimetro);
		
	return 0;
}


	// itoa, atoi, integer to array, array to integer
	
	

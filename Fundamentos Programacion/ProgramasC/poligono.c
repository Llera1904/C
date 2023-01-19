#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
	int N= 6;
	float lado= 1.0;
	float area=0.0, perimetro=0.0;
	float alpha=0.0, radio=0.0;
	
	printf("Numero de lados del poligono N= ");
	scanf("%d", &N);
	
	printf("lado del poligono= ");
	scanf("%f", &lado);
	
	perimetro= ((float) N)*lado;	// conversion de tipo de datos
									// casting
	
	// calculo directo compactado:								
	//area= (((float) N)/4)*(lado*lado)/tan(M_PI/((float) N));
	
	// factores:
	
	/*
	area= ((float) N)/4.0;
	area= area*(lado*lado);				// x= x*b; es equivalente a x*= b;
	area= area/tan(M_PI/(float)N);		// x= x/b;  x/=b;
    */
    
    // notacion compacta:
	/*area= ((float) N)/4.0;
	area*= lado*lado;				
	area/= tan(M_PI/(float)N);*/
	
	// x= x+1;	x+=1;	x++;
	// x= x+b;	x+=b;   
	// c= c+1;  c+=1;	c++;
	// c sharp	c# = (c++)++;
	
	// calculos intermedios:
	
	alpha= M_PI/((float) N);
	radio= lado/(2.0*sin(alpha));
	area= (((float) N)/4.0);
	area*= lado*sqrt(4.0*radio*radio-lado*lado);		// square root
	
	printf("area= %0.20f\n", area);
	printf("perimetro= %0.20f\n", perimetro);
		
	return 0;
}


	// itoa, atoi, integer to array, array to integer
	
	
	

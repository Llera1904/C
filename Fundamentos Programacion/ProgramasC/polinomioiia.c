#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float evaluarPolinomio(float *coeficientes, float x, int N);
float *crearArreglo(int N);
float destruirArreglo(float *arr);
void imprimirPolinomio(float *coef, float resultado, int N);
void leerPolinomio(float *coef, int *grado);
float evaluarPolinomioRecursivo(float *coeficientes, float x, int N);

int main(int argc, char *argv[])
{
	float *polinomio= NULL;
	int MAX= 100, N=0;
	float x= 0.0, y=0.0;
	
	polinomio= crearArreglo(MAX);
	leerPolinomio(polinomio, &N);
	printf("x= ");
	scanf("%f", &x);
	
	//y= evaluarPolinomio(polinomio, x, N);
	y= evaluarPolinomioRecursivo(polinomio, x, N);
	imprimirPolinomio(polinomio, x, N);	
	
	printf("p(%0.2f)= %0.2f\n", x, y);
	
	destruirArreglo(polinomio);
	
	return 0;
}

float evaluarPolinomio(float *coeficientes, float x, int N)
{
  int k=0;	
  float resultado=0;
  
  for (k=0; k<=N; k++)
     {
     	resultado+= coeficientes[k]*pow(x,k);
	 }
	
  return(resultado);
}

float *crearArreglo(int N)
{
	float *arr= NULL;
	int k=0;
	
	arr= (float *) malloc(N*sizeof(N));
	
	for (k=0; k<N; k++)
	   arr[k]= 0.0;
	
	return(arr);
}

float destruirArreglo(float *arr)
{
	free(arr);
}

void imprimirPolinomio(float *coef, float x, int N)
{
	int k=0;
	
	printf("x= \n", x);
	printf("p(%0.2f)= ", x);
	
	for (k=N; k>=0; k--)
	   {
	     printf("%0.2f * (%0.2f)^%d", coef[k], x, k);
	     
	     if (k!=0)
	       printf(" + ");
       }
       
	printf("\n");
}

void leerPolinomio(float *coef, int *grado)
{
	int N= 0.0, k=0;
	float c=0.0;
	
	printf("N= ");
	scanf("%d", &N);
	
	*grado= N;
	
	for (k=0; k<=N; k++)
	   {
	     printf("a_%d= ", k);
	     scanf("%f", &c);
	     coef[k]= c;
	   }
}

float evaluarPolinomioRecursivo(float *coeficientes, float x, int N)
{
  float resultado=0;
  
  if (N<0)
    return(0);
  
  resultado= coeficientes[N]*pow(x,N);
  resultado+= evaluarPolinomioRecursivo(coeficientes, x, N-1);
 	
  return(resultado);
}


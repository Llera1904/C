#include <stdio.h>
#include <stdlib.h>

void fun(int n, int lim);
void fA(int n, int lim)	;
void f();
void funConteo(int nivel, int lim, int *conteo);
void funCondeContarBinario(int nivel, int nodo, int lim, int *conteo);
void funCondeContarBaseTres(int nivel, int nodo, int lim, int *conteo);
void funCondeContarCualquierBase(int nivel, int nodo, int lim, int *conteo, int base);
void funCondeContarBinarioCodigo(int nivel, int nodo, int lim, int *conteo, int *codigo);
void funCondeContarBinarioCodigoPar(int nivel, int nodo, int lim, int *conteo, int *codigo);
void funCondeContarBinarioCodigoImpar(int nivel, int nodo, int lim, int *conteo, int *codigo);

int main(int argc, char *argv[]) 
{
	int n=0, lim=4, contador=0, raiz=0, base=2;
	int *arr= NULL;
	int L= lim-1;
	
	arr= (int *) malloc(L*sizeof(int));
	
	//fun(n, lim);
	
	//funConteo(n, lim, &contador);
	//funCondeContarBinario(n, raiz, lim, &contador);
	//funCondeContarBaseTres(n, raiz, lim, &contador);
	//funCondeContarCualquierBase(0, raiz, lim, &contador, base);
	
	// funCondeContarBinarioCodigo(n, raiz, lim, &contador, arr);
	
	//funCondeContarBinarioCodigoPar(n, raiz, lim, &contador, arr);
	funCondeContarBinarioCodigoImpar(n, raiz, lim, &contador, arr);
	
	
	printf("conteo= %d\n", contador);
	
	free(arr);
	
	return 0;
}

void fun(int n, int lim)
{
	int k=0;
	
	if (n>=lim)
	  return;
	  
		for (k=0; k<n; k++)
	   	   printf("   ");	   
		printf("f%d\n", n);
	
	fun(n+1, lim);
	
	fun(n+1, lim);
	
	/*for (k=0; k<n; k++)
	   	   printf("   ");	   
	    printf("f%d\n", n);*/
}


void f()
{
	f();
}

void fA(int n, int lim)			// for
{
	if (n>=lim)
	  return;
	  
	printf("n= %d\n", n);
	fA(n+1, lim);
}

void funConteo(int nivel, int lim, int *conteo)
{
	int k=0;
	
	if (nivel>=lim)
	  return;
	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		
		printf("nivel= %d  conteo=%d\n", nivel, *conteo);
	
	funConteo(nivel+1, lim, conteo);	
	funConteo(nivel+1, lim, conteo);
}


// nivel, nodo y lim se pasan por copia, conteo por referencia
void funCondeContarBinario(int nivel, int nodo, int lim, int *conteo)
{
	int k=0;
	
	if (nivel>=lim)
	  return;
	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	printf("0: \n");
	funCondeContarBinario(nivel+1, 2*nodo+0, lim, conteo);		// ruta 0	
	printf("1: \n");
	funCondeContarBinario(nivel+1, 2*nodo+1, lim, conteo);		// ruta 1
	
}

void funCondeContarBaseTres(int nivel, int nodo, int lim, int *conteo)
{
	int k=0;
	
	if (nivel>=lim)
	  return;
	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	//codigo[nivel]= 0;
	funCondeContarBaseTres(nivel+1, 3*nodo+0, lim, conteo);		// ruta 0	
	
	////codigo[nivel]= 1;
	funCondeContarBaseTres(nivel+1, 3*nodo+1, lim, conteo);		// ruta 1
	
	//codigo[nivel]= 2;
	funCondeContarBaseTres(nivel+1, 3*nodo+2, lim, conteo);		// ruta 2
}

void funCondeContarCualquierBase(int nivel, int nodo, int lim, int *conteo, int base)
{
	int k=0;
	
	if (nivel>=lim)
	  return;
	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	for (k=0; k<base; k++)
	   funCondeContarCualquierBase(nivel+1, base*nodo+k, lim, conteo, base);		// ruta k	
}


// codigo: arreglo dinamico lineal de longitud L= lim-1
void funCondeContarBinarioCodigo(int nivel, int nodo, int lim, int *conteo, int *codigo)
{
	int k=0, L= lim-1;
	
	if (nivel>=lim)
	  {
	  	/*for (k=0; k<L; k++)
	  	   printf("%d ", codigo[k]);
	  	   
	  	printf("\n");*/	  	
	    return;
	  }
	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	// impresion del codigo/ruta que siguio de la raiz a la hoja
	
	if (nivel==L)
	  {
	  	for (k=0; k<nivel; k++)
	   	   printf("       ");
	   	   
	    for (k=0; k<L; k++)
	  	   printf("%d ", codigo[k]);
	    printf("\n");
	  }
	  	   
	//printf("0: \n");
	codigo[nivel]= 0;
	funCondeContarBinarioCodigo(nivel+1, 2*nodo+0, lim, conteo, codigo);		// ruta 0	
	
	//printf("1: \n");
	codigo[nivel]= 1;
	funCondeContarBinarioCodigo(nivel+1, 2*nodo+1, lim, conteo, codigo);		// ruta 1
	
}

void funCondeContarBinarioCodigoPar(int nivel, int nodo, int lim, int *conteo, int *codigo)
{
	int k=0, L= lim-1;
	
	if (nivel>=lim)
	  return;

	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	// impresion del codigo/ruta que siguio de la raiz a la hoja
	
	if (nivel==L)
	  {
	  	for (k=0; k<nivel; k++)
	   	   printf("       ");
	   	   
	    for (k=0; k<L; k++)
	  	   printf("%d ", codigo[k]);
	    printf("\n");
	  }
	  	   
	//printf("0: \n");
	codigo[nivel]= 0;
	funCondeContarBinarioCodigoPar(nivel+1, 2*nodo+0, lim, conteo, codigo);		// ruta 0	
	
	//printf("1: \n");
	
	if (nivel<L-1)
	  {
	    codigo[nivel]= 1;
	    funCondeContarBinarioCodigoPar(nivel+1, 2*nodo+1, lim, conteo, codigo);		// ruta 1
      }
}

void funCondeContarBinarioCodigoImpar(int nivel, int nodo, int lim, int *conteo, int *codigo)
{
	int k=0, L= lim-1;
	
	if (nivel>=lim)
	  return;

	  
	(*conteo)++;
	  
		for (k=0; k<nivel; k++)
	   	   printf("   ");	   
		printf("nivel= %d  nodo= %d  conteo= %d\n", nivel, nodo, *conteo);
	
	// impresion del codigo/ruta que siguio de la raiz a la hoja
	
	if (nivel==L)
	  {
	  	for (k=0; k<nivel; k++)
	   	   printf("       ");
	   	   
	    for (k=0; k<L; k++)
	  	   printf("%d ", codigo[k]);
	    printf("\n");
	  }
	  	   
	//printf("0: \n");
	
	if (nivel<L-1)
	  {	
			codigo[nivel]= 0;
			funCondeContarBinarioCodigoImpar(nivel+1, 2*nodo+0, lim, conteo, codigo);		// ruta 0	
      }	
	//printf("1: \n");
	
	codigo[nivel]= 1;
	funCondeContarBinarioCodigoImpar(nivel+1, 2*nodo+1, lim, conteo, codigo);		// ruta 1

}


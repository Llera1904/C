#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	int matA[10][6], matB[6][9], matC[10][9];
	int M=10, L=6, N=9;
	int i=0, j=0, k=0;
	
	/*
	matA[0][0]= 1;	matA[0][1]= 2;
	matA[1][0]= -3;	matA[1][1]= 0;
	
	matB[0][0]= 3;	matB[0][1]= 5;
	matB[1][0]= 4;	matB[1][1]= 1;
	*/
	
	// matA: MxL
	
	for (i=0; i<M; i++)
	   for (k=0; k<L; k++)
	      matA[i][k]= i*k;
	      
	printf("\n\nA=\n");
	
	for (i=0; i<M; i++)
	   {
	   	 for (k=0; k<L; k++)
	   	    printf("%d\t", matA[i][k]);
	   	    
	   	 printf("\n");
	   }
	      
	// matB: LxN
	
	for (k=0; k<L; k++)
	   for (j=0; j<N; j++)
	      matB[k][j]= k*j;
	      
	printf("\n\nB=\n");
	
	for (k=0; k<L; k++)
	   {
	   	 for (j=0; j<N; j++)
	   	    printf("%d\t", matB[k][j]);
	   	    
	   	 printf("\n");
	   }
	      
	// matC: MxN
	
	for (i=0; i<M; i++)
	   for (j=0; j<N; j++)
	      matC[i][j]= 0;

	// multiplicacion de matrices:
	
	for (i=0; i<M; i++)
	   {
	   		for (j=0; j<N; j++)
	   		   {
	   		   		matC[i][j]= 0;
	   		   		
	   		   		for (k=0; k<L; k++)
					   matC[i][j]+= matA[i][k]*matB[k][j];	   
	   		   		// matC[i][j]= matC[i][j] + matA[i][k]*matB[k][j];	
			   }
	   }
	   
	   
	// resultado:
	
	printf("\n\nC=\n");
	
	for (i=0; i<M; i++)
	   {
	   	 for (j=0; j<N; j++)
	   	    printf("%d\t", matC[i][j]);
	   	    
	   	 printf("\n");
	   }
	
	return 0;
}

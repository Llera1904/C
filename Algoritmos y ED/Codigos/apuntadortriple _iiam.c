#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	int ***vol= NULL;
	int L= 10, M= 10, N= 10;
	int i=0, j=0, k=0;
	
	int *p= NULL, x= 6, y=0;
	
	p= &x;	
	y= (int) p;
	
	printf("p= %X p= %d y= %d", p, p, y); 
	
	vol= (int ***) malloc(L*sizeof(int **));
	
	for (i=0; i<L; i++)
	   {
	   		vol[i]= (int **) malloc(M*sizeof(int *));
	   		
	   		for (j=0; j<M; j++)
	   		   {
	   		   		vol[i][j]= (int *) malloc(N*sizeof(int));
						  
					for (k=0; k<N; k++)
					   vol[i][j][k]= (int) i*j*k;	  	
			   }
	   }
	   
	   
	for (i=0; i<L; i++)
	   {  		
	   		for (j=0; j<M; j++)
	   		   {						  
					for (k=0; k<N; k++)
					   printf("%d\t", vol[i][j][k]);	 
					   
					printf("\n"); 	
			   }
			
			printf("\n\n");
	   }
	
	
	for (i=0; i<L; i++)
	   {	   		
	   		for (j=0; j<M; j++)
	   		   {
	   		   		free(vol[i][j]);
			   }
			   
			free(vol[i]);
	   }
	   
	free(vol);
	
	
	return 0;
}

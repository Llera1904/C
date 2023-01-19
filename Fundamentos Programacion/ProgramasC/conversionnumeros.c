#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	long long int digitos[100];
	long long int N=0, k=0, b=0, x=0;
	long long int q=0, r=0, n=0;
	char caracter= ' ';
	
	printf("base b= ");
	scanf("%lli", &b);
	
	printf("digitos N= ");
	scanf("%lli", &N);
	
	// lectura de N digitos:
	
	for (k=0; k<N; k++)
	   {
	   		printf("[%lli]= ", k);
	   		scanf("%lli", &n);
	   		digitos[k]= n;
	   }
	   
	printf("\n");
	
	// escritura de N digitos:
	
	for (k=0; k<N; k++)
	   printf("[%lli]= %lli\n", k, digitos[k]);	
	
	   
	// conversion base b a base 10:
	
	for (k=0; k<N; k++)
	   x+= (digitos[k])*pow(b, k);
	
	printf("x en base 10= %lli\n", x);

	printf("\n");
	
	printf("base b= ");
	scanf("%lli", &b);
	
	printf("numero x= ");
	scanf("%lli", &x);
	
	for (k=0; k<N; k++)
	   digitos[k]= 0;
	   
	k= 0;
	n= x;
	q= -1;
	
	while(q!=0)
	{
		q= n/b;
		r= n%b;
		n= q;
		digitos[k]= r;
		k++;
	}
	
	for (k=N-1; k>=0; k--)
	   printf("%lli ", digitos[k]);	
	   
	printf("\n");
	
	// impresion con ASCII:
	
	for (k=N-1; k>=0; k--)
	   {
	   	  if (digitos[k]>=0 && digitos[k]<=9)
			caracter= digitos[k] + 48;
			
		  if (digitos[k]>9)
		    caracter= digitos[k] + 55; 
		
		  printf("%c ", caracter);
	   }	
	
	printf("\n");
	
	return 0;
}


// int = 			32 bits, 		%d
// long int = 		32 bits, 		%ld
// long long int =  64 bits,		%lli


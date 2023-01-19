#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int **d= NULL;
	int *p= NULL, *q= NULL;
	int x= 13, y=0;
	
	printf("bytes apuntador int : %d  bytes\n", sizeof(int ));
	printf("bytes apuntador int *: %d  bytes\n", sizeof(int *));
	printf("bytes apuntador int **: %d  bytes\n", sizeof(int **));
	printf("bytes apuntador int ***: %d  bytes\n", sizeof(int ***));
	
	p= &x;		// apuntador sencillo hace referencia a tipo de dato basico
	
	d= &p;		// apuntador doble hace referencia al apuntador sencillo;
	
	q= *d;		// se accede al contenido a donde hace referencia el
				// apuntador doble (*d) y se almacena en el apuntador sencillo q
				
	y= *q;		// y terminara con el valor de x
	
	printf("y= %d\n", y);	
	
	printf("\nDirecciones de memoria: \n");
	printf("&x= %X   x= %d\n", &x, x);
	printf("&p= %X   p= %X  *p=%d\n", &p, p, *p);
	printf("&d= %X   d= %X  *d=%X   **d= %d\n", &d, d, *d, **d);
		
	return 0;
}








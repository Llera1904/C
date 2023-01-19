#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char x= 'A';
	
	printf("caracter= %c\n", x);
	printf("codigo ASCII= %d\n", x);
	printf("hexadecimal= %X\n\n", x);
	
	x=x+5;
	
	printf("caracter (+5)= %c\n", x);
	printf("codigo ASCII (+5)= %d\n", x);
	printf("hexadecimal (+5)= %X\n\n", x);
	
	printf("letra o digito= ");
	scanf("%c", &x);
	
	printf("caracter= %c\n", x);
	printf("codigo ASCII= %d\n", x);
	printf("hexadecimal= %X\n", x);	
	
	return 0;
}

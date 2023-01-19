#include <stdio.h>
#include <stdlib.h>

/*int main(int argc, char *argv[])
{
	int opcion=0;
	
	printf("cancion: ");
	scanf("%d", &opcion);
	
	switch(opcion)
	{
		case 0: {
					printf("Alice in Chains - Would\n");
					break;
				}
				
		case 1: {
					printf("The Cure - Lovesong\n");
					break;
				}
				
		case 2: 	printf("Soda Stereo - Signos\n");
					break;
				
				
		case 3: {
					printf("Depeche Mode - Walking in my Shoes\n");
					break;
				}

		case 4: {
					printf("Caifanes - Dioses Ocultos\n");
					break;
				}	
				
		case 5: {
					printf("Santa Sabina - Insomnio\n");
					break;
				}
				
		default: {
					printf("Opcion no valida\n");
					break;
				 }			
				
	}
	
	return 0;
}*/

int main(int argc, char *argv[])
{
	char opcion=0;
	
	printf("cancion: ");
	scanf("%c", &opcion);
	
	switch(opcion)
	{
		case 'A': {
					printf("Alice in Chains - Would\n");
					break;
				}
				
		case 'a': {
					printf("alice in chains - would\n");
					break;
				}
				
		case 'B': {
					printf("The Cure - Lovesong\n");
					break;
				}
				
		case 'C': 	printf("Soda Stereo - Signos\n");
					break;
				
				
		case 'D': {
					printf("Depeche Mode - Walking in my Shoes\n");
					break;
				}

		case 'E': {
					printf("Caifanes - Dioses Ocultos\n");
					break;
				}	
				
		case 'F': {
					printf("Santa Sabina - Insomnio\n");
					break;
				}
				
		default: {
					printf("Opcion no valida\n");
					break;
				 }			
				
	}
	
	return 0;
}

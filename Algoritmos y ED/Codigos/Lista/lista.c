#ifndef LISTA_C
#define LISTA_C

#include "lista.h"

int crearLista(Lista *l)
{
	Lista y= NULL;

	y= (Lista) malloc(sizeof(t_lista));

	if (y==NULL)
	  return(FALSO);

	y->primero= NULL;
	y->ultimo= NULL;
	y->longitud= 0;

	*l= y;

	return(VERDADERO);
}


int consultarPrimero(Lista l, Elemento *e)
{
	int sw= FALSO;
	
	if (l==NULL)
	  return(FALSO);
	  
	if (l->longitud==0 || l->primero==NULL)
	  return(FALSO);
	  
	sw= leerElemento(l->primero, e);
	  
	return(sw);
}

int consultarUltimo(Lista l, Elemento *e)
{
	int sw= FALSO;
	
	if (l==NULL)
	  return(FALSO);
	  
	if (l->longitud==0 || l->ultimo==NULL)
	  return(FALSO);
	  
	sw= leerElemento(l->ultimo, e);
	  
	return(sw);
}


int consultarElementoPosicion(Lista l, Elemento *e, int posicion)
{
	Nodo actual=NULL, siguiente= NULL, anterior=NULL;
	int sw= FALSO;
	int k=0;
	
	if (l==NULL)
	  return(FALSO);
	  
	if (l->longitud==0 || l->primero==NULL || l->ultimo==NULL)
	  return(FALSO);
	  
	if (posicion<0 || posicion>=l->longitud)
	  return(FALSO);
	
	if (posicion<(l->longitud)/2)
	  {
	  	actual= l->primero;
		k= 0;
	
		while(actual!=NULL)
		{
			if (k==posicion)
		  	  break;
		  
			consultarEnlaceA(actual, &siguiente);
			actual= siguiente;
			k++;
		}
	  }
	else
	  {
	  	actual= l->ultimo; 
		k= l->longitud - 1;
	
		while(actual!=NULL)
		{
			if (k==posicion)
		  	  break;
		  
		  	// consultarEnlaceB(aux, &aux); // evitar este tipo de invocaciones
		  									// debido a la potencial presencia
		  									// de colisiones dentro de la
		  									// funcion
		  
			consultarEnlaceB(actual, &anterior);
			actual= anterior;
			k--;
		}
	  }
	  
	sw= leerElemento(actual, e);
	  
	return(sw);
}

int destruirLista(Lista *y)
{
	Lista l= NULL;
	Nodo aux= NULL;
	int sw= FALSO;
	
	l= *y;
	
	if (l==NULL)
	  return(FALSO);
		  
	while(l->primero!=NULL)
	{
		sw= consultarEnlaceA(l->primero, &aux);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= desconectarEnlaceA(l->primero);
		if (sw==FALSO)
		  return(FALSO);
		  
		sw= destruirNodo(&(l->primero));
		if (sw==FALSO)
		  return(FALSO);
		
		l->primero= aux;
		l->longitud--;
	}
	
	l->primero= NULL;
	l->ultimo= NULL;
	free(l);
	
	*y= NULL;
	
	return(VERDADERO);
}

int insertarElementoPosicion(Lista l, Elemento e, int posicion)
{
	Nodo nuevo= NULL, aux=NULL, contiguo=NULL, sig= NULL;
	int sw= FALSO;
	int k=0;
		
	if (l==NULL)
	  return(FALSO);	
	
	sw= crearNodo(&nuevo);
	
	if (sw==VERDADERO)
		{			
			sw= escribirElemento(nuevo, e);
			if (sw==VERDADERO)
				{					
					if (l->longitud==0)
						{									
					  		l->primero= nuevo;
					  		(l->longitud)++;
					  	}
					else
					    {						
							aux= l->primero;
						
							for (k=0; k<l->longitud; k++)
							   {
									if (aux==NULL)
								  	  break;								  
								
									if (k==posicion)
									  {										
										consultarEnlaceA(aux, &contiguo);
										
										desconectarEnlaceA(aux);
										desconectarEnlaceB(contiguo);
										
										conectarEnlaceA(aux, nuevo);
										conectarEnlaceB(contiguo, nuevo);										
										
										conectarEnlaceB(nuevo, aux);
										conectarEnlaceA(nuevo, contiguo);
										
										(l->longitud)++;

										break;
									  }
									  
									consultarEnlaceA(aux, &sig);
									aux= sig;
							   }		
					
						}
					
					if (posicion==l->longitud-1)
					  l->ultimo= nuevo;
					
					return(VERDADERO);					
				}
		}
		
	return(FALSO);
}

int quitarElementoPosicion(Lista l, Elemento *e, int posicion)
{
	Nodo nuevo= NULL, aux=NULL, anterior= NULL, contiguo=NULL, sig= NULL;
	int sw= VERDADERO;
	int k=0;
		
	if (l==NULL)
	  return(FALSO);
	
	if (l->longitud==0)
	  return(FALSO);
	

	if (l->longitud==1)
	  {			
		leerElemento(l->primero, e);
		destruirNodo(&(l->primero));
		l->primero= NULL;
		l->ultimo= NULL;
		l->longitud= 0;
		return(VERDADERO);
	  }
	else
	  {
		aux= l->primero;
		for (k=0; k<l->longitud; k++)
		   {
				if (aux==NULL)
				  break;
				  
				// printf(" %d >> ", k);
							  
				if (k==posicion)
				  {															
					leerElemento(aux, e);
										
					consultarEnlaceA(aux, &contiguo);
					consultarEnlaceB(aux, &anterior);
							
					if (aux!=NULL)
					  {	  		
					    desconectarEnlaceA(aux);
					    desconectarEnlaceB(aux);
					  }
					  
					if (anterior!=NULL)
					  {					  
					  	desconectarEnlaceA(anterior);
					    conectarEnlaceA(anterior, contiguo);
					  }
					
					if (contiguo!=NULL)
					  {					  
					  	desconectarEnlaceB(contiguo);
					  	conectarEnlaceB(contiguo, anterior);
					  }
										
					destruirNodo(&aux);
										
					if (posicion==0)
					  l->primero= contiguo;
										  
					if (posicion==l->longitud-1)
					  l->ultimo= anterior;

					(l->longitud)--;
										
					return(VERDADERO);
				  }
								
				consultarEnlaceA(aux, &sig);							
				aux= sig;
			}	
										
	  }
					
	return(FALSO);
}

int insertarElementoPosicionVariante(Lista l, Elemento e, int posicion)
{
	Nodo nuevo= NULL, aux=NULL, contiguo=NULL, anterior= NULL, sig= NULL;
	int sw= FALSO;
	int k=0, ini=0, delta=0, lim=0, sentido=0;
		
	if (l==NULL)
	  return(FALSO);	
	
	sw= crearNodo(&nuevo);
	if (sw==FALSO)
	  return(FALSO);
	
	sw= escribirElemento(nuevo, e);
	if (sw==FALSO)
	  return(FALSO);
	  
	if (l->longitud==0)
	  {									
		l->primero= nuevo;
		l->ultimo= nuevo;
		l->longitud= 1;
		return(VERDADERO);
	  }
	
	if (posicion==0)
	  {
		conectarEnlaceA(nuevo, l->primero);
		conectarEnlaceB(l->primero, nuevo);
		l->primero= nuevo;
		(l->longitud)++;
		return(VERDADERO);
	  }	
							  
	if (posicion==l->longitud)
	  {
		conectarEnlaceA(l->ultimo, nuevo);
		conectarEnlaceB(nuevo, l->ultimo);
		l->ultimo= nuevo;
		(l->longitud)++;
							  	
		return(VERDADERO);
	  }

	if (posicion>=0 && posicion<l->longitud)
	  {
	  	if (posicion<(l->longitud)/2)
	  	  {	
			sentido= ADELANTE;		
			aux= l->primero;
			ini=0;
			lim= l->longitud;
			delta= 1;
		  }
		else		  
		  {
		  	sentido= REVERSA;
		  	aux= l->ultimo;
		  	ini= l->longitud-1;
		  	lim= -1;
		  	delta= -1;
		  }
																	  										
		for (k=ini; k!=lim; k=k+delta)
		   {
			 if (aux==NULL)
			   break;										
		
			 if (k==posicion)
			   {										
				 consultarEnlaceB(aux, &anterior);
										
				 desconectarEnlaceB(aux);
				 desconectarEnlaceA(anterior);
										
				 conectarEnlaceA(anterior, nuevo);
			 	 conectarEnlaceB(nuevo, anterior);
										
				 conectarEnlaceA(nuevo, aux);
				 conectarEnlaceB(aux, nuevo);	// issue
										
				 (l->longitud)++;

				 return(VERDADERO);
			   }
					
			 if (sentido==ADELANTE)				  
			   consultarEnlaceA(aux, &sig);
			 else
			   consultarEnlaceB(aux, &sig);
			   
			 aux= sig;
		   }
      }
		
	return(FALSO);
}

int imprimirLista(Lista l)
{
	Nodo siguiente= NULL, nodo= NULL;
	Elemento e= NULL;
	int sw= FALSO;
	int dato= 0;
			
	printf("<");
	if (l==NULL)
	  return(FALSO);
	  
	nodo= l->primero;
	  
	while(nodo!=NULL)
	{
		leerElemento(nodo, &e);
		leerDato(e, &dato);
		printf("%d, ", dato);
		
		sw= consultarEnlaceA(nodo, &siguiente);
		if (sw==FALSO)
		  return(FALSO);
		  
		nodo= siguiente;
	}
	printf(">\n");
	return(VERDADERO);
}

#endif

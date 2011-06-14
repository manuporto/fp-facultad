#ifndef __PILA_H__
#define __PILA_H__

#include <stdlib.h>
#include <string.h>

#if !defined(NULL)
	#define NULL 0	
#endif

#if !defined(FALSE)
	#define FALSE 0	
#endif	

#if !defined(TRUE)
	#define TRUE 1	
#endif

typedef struct TNodoPila
{
	void* Elem;
	struct TNodoPila *Siguiente;	
} TNodoPila;

typedef struct  a
{
	TNodoPila* Tope;
	int TamanioDato;
} TPila; 

void P_Crear(TPila *pP, int TamanioDato);
void P_Vaciar(TPila *pP);
int P_Vacia(TPila P);
int P_Agregar(TPila *pP, void* pE);
int P_Sacar(TPila *pP, void* pE);
	
#endif

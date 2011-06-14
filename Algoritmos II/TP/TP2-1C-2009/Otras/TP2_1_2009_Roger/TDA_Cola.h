/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 *****************************************************************************/ 

/* TDA Cola
 * Archivo: TDA_Cola.h
 * version: 1.0
 */

#ifndef TDA_COLA_H_
	#define TDA_COLA_H_

	#if !defined(NULL)
   	#define NULL 0
	#endif

	#if !defined(FALSE)
   	#define FALSE 0
	#endif

	#if !defined(TRUE)
	   #define TRUE 1
	#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipo de estructura de los nodos de la cola */

typedef struct TNodoCola
{
   void* Elem;
   struct TNodoCola *Siguiente;
} TNodoCola;


/* Tipo de estructura de la cola */

typedef struct
{
   TNodoCola *Primero, *Ultimo;
   int TamanioDato;
} TCola;

/******************************************************************************/
/* Definicion de primitivas */
/*--------------------------*/

/* C_Crear
   Pre: C no fue creada.
   Post: C creada y vacía.
*/

void C_Crear(TCola *pC, int TamanioDato);
/*----------------------------------------------------------------------------*/
/*
   C_Vaciar
	Pre: C creada.
	Post: C vacía.
*/

void C_Vaciar(TCola *pC);
/*----------------------------------------------------------------------------*/
/* C_Vacia
	Pre: C creada.
	Post: Si C está vacía devuelve TRUE, sino FALSE.
*/

int C_Vacia(TCola C);
/*----------------------------------------------------------------------------*/
/* C_Agregar
	Pre: C creada.
	Post: E se agregó como último elemento de C.
	Devuelve FALSE si no pudo agregar E, sino devuelve TRUE.
*/

int C_Agregar(TCola *pC, void* pE);
/*----------------------------------------------------------------------------*/
/* C_Sacar
	Pre: C creada y no vacia.
	Post: Se extrajo de C el primer elemento y se devuelve en E.
	Si no pudo extraer el elemento (porque la cola estaba vacía) devuelve FALSE,
	sino devuelve TRUE.
*/

int C_Sacar(TCola *pC, void* pE);
/*----------------------------------------------------------------------------*/

#endif

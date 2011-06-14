/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 *****************************************************************************/ 

/* TDA Pila
 * Archivo: TDA_Pila.h
 * version: 1.0
 */

#ifndef TDA_PILA_H_
	#define TDA_PILA_H_

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

/* Tipo de estructura de los nodos de la pila */

typedef struct TNodoPila
   {
      void* Elem;
      struct TNodoPila *Siguiente;
   } TNodoPila;

/* Tipo de estructura de la pila */
   typedef struct
   {
      TNodoPila *Tope;
      int TamanioDato;
   } TPila;

/******************************************************************************/
/* Definicion de primitivas */
/*--------------------------*/

/* P_Crear
   Pre: P no fue creada.
   Post: P creada y vacía.
*/
   void P_Crear(TPila *pP, int TamanioDato);
/******************************************************************************/
/* P_Vaciar
   Pre: P creada.
   Post: P vacía.
*/
   void P_Vaciar(TPila *pP);
/******************************************************************************/
/* P_Vacia
   Pre: P creada.
   Post: Si P está vacía devuelve TRUE, sino FALSE.
*/
   int P_Vacia(TPila P);
/******************************************************************************/
/* P_Agregar
   Pre: P creada.
   Post: E se agregó como Tope de P.
   Devuelve FALSE si no pudo agregar E, sino devuelve TRUE.
*/
   int P_Agregar(TPila *pP, void* pE);
/******************************************************************************/
/* P_Sacar
   Pre: P creada y no vacia.
   Post: Se extrajo de P el tope y se devuelve en E.
   Si no pudo extraer el elemento (porque la pila estaba vacía) devuelve FALSE,
   sino devuelve TRUE.
*/
   int P_Sacar(TPila *pP, void* pE);
/******************************************************************************/

#endif

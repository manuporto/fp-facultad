/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/


#ifndef __AB_H__
#define __AB_H__

#include <stdlib.h>

#define IZQ    1
#define DER    2
#define PAD    3
#define RAIZ   4

/* tipo de elemento que se guarda en los nodos */
typedef void* TelemAB;

/* Tipo de estructura de los nodos */
typedef struct TNodoAB
{
   TelemAB elem;
   struct TNodoAB *izq, *der;
} TNodoAB;

/* Tipo de estructura del arbol binario */
typedef struct TAB
{
   TNodoAB *raiz,*cte;
   int tamdato;
} TAB;

/*----------------------------------------------------------------------------*/
/* Definicion de Primitivas */
/*--------------------------*/

void AB_Crear(TAB *a,int tdato);

void AB_ElemCte(TAB a,void *elem);

void AB_ModifCte(TAB *a,void *elem);

void AB_MoverCte(TAB *a,int mov,int *error);

void AB_Vaciar(TAB *a);

int AB_Vacio(TAB a);

void AB_Insertar(TAB *a,int mov,void *elem,int *error);

/*
   Toma el subarbol de origen que comienza en el hijo del corriente indicado
   por mov y lo copia a destino. Origen debe ser un arbol creado y no vacio,
   y destino debe ser un arbol no creado. mov acepta RAIZ, IZQ y DER.
   Devuelve 1 si pudo realizar la copia, 0 en caso contrario.
*/
int AB_CopiarSubarbol ( const TAB* origen , TAB* destino , int mov );

/*
   Toma el arbol origen y lo copia al hijo del corriente de destino indicado
   por movim. La variable origen debe ser un arbol creado, y destino debe
   ser un arbol creado y con el corriente en un nodo hoja. Movim acepta IZQ y DER.
   Devuelve 1 si pudo realizar la copia, 0 en caso contrario.
*/
int AB_PegarSubarbol ( const TAB* origen , TAB* destino , int mov );

#endif
/*----------------------------------------------------------------------------*/

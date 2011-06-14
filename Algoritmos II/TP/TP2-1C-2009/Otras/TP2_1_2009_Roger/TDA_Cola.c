/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 *****************************************************************************/ 

/* TDA Cola
 * Archivo: TDA_Cola.c
 * version: 1.0
*/

#include "TDA_Cola.h"
#include <malloc.h>
#include <memory.h>

/*****************************************************************************/
/* Implementacion de primitivas */
/*------------------------------*/

void C_Crear(TCola *pC, int TamanioDato)
{
   pC->Primero = pC->Ultimo = NULL;
   pC->TamanioDato = TamanioDato;
}

/*---------------------------------------------------------------------------*/

void C_Vaciar(TCola *pC)
{
   TNodoCola *pAux = pC->Primero;
   TNodoCola *pSig;
   while (pAux)
   {
      pSig = pAux->Siguiente;
      free(pAux->Elem);
      free(pAux);
      pAux = pSig;
   }
   pC->Primero = pC->Ultimo = NULL;
}

/*---------------------------------------------------------------------------*/

int C_Vacia(TCola C)
{
   return (C.Primero==NULL);
}

/*---------------------------------------------------------------------------*/

int C_Agregar(TCola *pC, void* pE)
{
   TNodoCola *pNodo = (TNodoCola*) malloc(sizeof(TNodoCola));
   if (!pNodo)
      return FALSE;
   else
   {
      if (pC->Ultimo)
         pC->Ultimo->Siguiente = pNodo;
      if (!pC->Primero) //Está vacía
         pC->Primero = pNodo;

      pNodo->Siguiente = NULL;
      pC->Ultimo = pNodo;
      pNodo->Elem = malloc (pC->TamanioDato);
      memcpy(pNodo->Elem, pE, pC->TamanioDato);
      return TRUE;
   }
}
/*---------------------------------------------------------------------------*/

int C_Sacar(TCola *pC, void* pE)
{
   TNodoCola *pAux = pC->Primero;
   pC->Primero = pC->Primero->Siguiente;
   if (!pC->Primero)
      pC->Ultimo = NULL;
   memcpy(pE, pAux->Elem, pC->TamanioDato);
   free(pAux->Elem);
   free(pAux);
   return TRUE;
}
/*---------------------------------------------------------------------------*/

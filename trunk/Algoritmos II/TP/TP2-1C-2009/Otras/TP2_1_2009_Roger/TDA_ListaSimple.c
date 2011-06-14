/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 *****************************************************************************/ 

/* TDA ListaSimple
 * Archivo: TDA_ListaSimple.c
 * version: 1.0
*/

#include "TDA_ListaSimple.h"
#include <malloc.h>
#include <memory.h>

/*****************************************************************************/
/* Implementacion de primitivas */
/*------------------------------*/

void ls_Crear(TListaSimple *pLs, int TamanioDato)
{
   pLs->Corriente = NULL;
   pLs->Primero = NULL;
   pLs->TamanioDato = TamanioDato;
}

/*---------------------------------------------------------------------------*/

void ls_Vaciar(TListaSimple *pLs)
{
   TNodoSimple *pNodo, *siguiente;
   for(pNodo = pLs->Primero;(pNodo);pNodo=siguiente)
   {
      siguiente = pNodo->Siguiente;
      free(pNodo->Elem);
      free(pNodo);
   }
   pLs->Primero=pLs->Corriente=NULL;
}

/*---------------------------------------------------------------------------*/

int ls_Vacia(TListaSimple Ls)
{
   return (Ls.Primero == NULL);
}

/*---------------------------------------------------------------------------*/

void ls_ElemCorriente(TListaSimple Ls, void *pE)
{
   memcpy(pE, Ls.Corriente->Elem, Ls.TamanioDato);
}

/*---------------------------------------------------------------------------*/

void ls_ModifCorriente(TListaSimple *pLs, void* pE)
{
   memcpy(pLs->Corriente->Elem, pE, pLs->TamanioDato);
}

/*---------------------------------------------------------------------------*/

int ls_MoverCorriente(TListaSimple *pLs, TMovimiento_Ls M)
{
   switch (M)
   {
      case LS_PRIMERO:   pLs->Corriente=pLs->Primero;
                         break;
      case LS_SIGUIENTE: if (pLs->Corriente->Siguiente==NULL)
                            return FALSE;
                         else
                            pLs->Corriente=pLs->Corriente->Siguiente;
                         break;
      case LS_ANTERIOR:return FALSE;
   }
   return TRUE;
}

/*---------------------------------------------------------------------------*/

void ls_BorrarCorriente(TListaSimple *pLs)
{
   TNodoSimple *PNodo=pLs->Corriente;
   if (pLs->Corriente==pLs->Primero)
   {
      pLs->Primero = pLs->Corriente->Siguiente;
      pLs->Corriente = pLs->Primero;
   }
   else
   {
      TNodoSimple *PAux=pLs->Primero;
      while (PAux->Siguiente!=pLs->Corriente)
         PAux = PAux->Siguiente;
      PAux->Siguiente=pLs->Corriente->Siguiente;
      if (PAux->Siguiente) //Si no es el último
         pLs->Corriente = PAux->Siguiente;
      else
         pLs->Corriente = PAux; //Si es el último queda en el anterior al
                                 //borrado
   }
   free(PNodo->Elem);
   free(PNodo);
}

/*---------------------------------------------------------------------------*/

int ls_Insertar(TListaSimple *pLs, TMovimiento_Ls M, void* pE)
{
   TNodoSimple *pNodo = (TNodoSimple*) malloc(sizeof(TNodoSimple));
   if (!pNodo)
      return FALSE; //No hay memoria disponible
   if ((pLs->Primero == NULL) || (M==LS_PRIMERO) ||
      ((M==LS_ANTERIOR) && (pLs->Primero==pLs->Corriente)))
   {
      //Si está vacía o hay que insertar en el primero o
      //hay que insertar en el anterior y el actual es el primero
      pNodo->Siguiente = pLs->Primero;
      pLs->Primero = pLs->Corriente = pNodo;
   }
   else
   {
      if (M == LS_SIGUIENTE)
      {
         pNodo->Siguiente = pLs->Corriente->Siguiente;
         pLs->Corriente->Siguiente = pNodo;
      }
      else //LS_ANTERIOR
      {
         TNodoSimple *pAux=pLs->Primero;
         while (pAux->Siguiente!=pLs->Corriente)
            pAux = pAux->Siguiente;
         pAux->Siguiente = pNodo;
         pNodo->Siguiente = pLs->Corriente;
      }
   }
   pNodo->Elem = malloc (pLs->TamanioDato);
   memcpy(pNodo->Elem, pE, pLs->TamanioDato);
   pLs->Corriente=pNodo;
   return TRUE;
}

/*---------------------------------------------------------------------------*/

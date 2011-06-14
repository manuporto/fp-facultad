/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/

#include "AB.h"
#include <memory.h>

/*----------------------------------------------------------------------------*/


int AB_CopiarSubarbolAux (TAB* origen, TAB* destino, int mov)
{
    TNodoAB *cteAux, *cteAux2;
    TNodoAB *nodoAux;
    int error = 0;

    nodoAux = (TNodoAB*)malloc(sizeof(TNodoAB));
    nodoAux->izq = NULL;
    nodoAux->der = NULL;

    if (nodoAux)
    {
        nodoAux->elem = malloc(destino->tamdato);
        if (nodoAux->elem)
        {
            memcpy(nodoAux->elem,origen->cte->elem,destino->tamdato);

            if (destino->raiz == NULL)
            {
                destino->raiz = nodoAux;
                destino->cte = nodoAux;
            }
            else
            {
                switch (mov)
                {
                    case IZQ :  destino->cte->izq = nodoAux;
                                break;
                    case DER :  destino->cte->der = nodoAux;
                                break;
                    default :   error = 1;
                                break;
                }
                destino->cte = nodoAux;
                if (error == 1)
                {
                    free (nodoAux->elem);
                    free (nodoAux);
                }
            }

            if (origen->cte->izq != NULL)
            {
                cteAux = origen->cte;
                origen->cte = origen->cte->izq;
                cteAux2 = destino->cte;
                AB_CopiarSubarbolAux (origen,destino,IZQ);
                origen->cte = cteAux;
                destino->cte = cteAux2;
            }
            if (origen->cte->der != NULL)
            {
                cteAux = origen->cte;
                origen->cte = origen->cte->der;
                cteAux2 = destino->cte;
                AB_CopiarSubarbolAux (origen,destino,DER);
                origen->cte = cteAux;
                destino->cte = cteAux2;
            }
            return 1;
        }
        else free (nodoAux);
    }
    return 0;
}

int AB_CopiarSubarbol (const TAB* origen, TAB* destino, int mov )
{
    TAB *ab;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));


    destino->raiz = NULL;
    destino->cte = NULL;
    destino->tamdato = origen->tamdato;


    if ((mov==IZQ) && (ab->cte->izq != NULL))
    {
        ab->cte=ab->cte->izq;
        AB_CopiarSubarbolAux (ab,destino,IZQ);
        free(ab);
        return 1;
    }

    if ((mov==DER) && (ab->cte->der !=NULL))
    {
        ab->cte=ab->cte->der;
        AB_CopiarSubarbolAux (ab,destino,IZQ);
        free(ab);
        return 1;
    }

    free(ab);
    return 0;
}

int AB_PegarSubarbol (const TAB* origen, TAB* destino, int mov )
{

    if ((mov == IZQ) && (destino->cte->izq == NULL))
    {
        destino->cte->izq = origen->raiz;
        return 1;
    }
    if ((mov == DER) && (destino->cte->der == NULL))
    {
        destino->cte->der = origen->raiz;
        return 1;
    }

    return 0;
}


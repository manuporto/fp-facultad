#include <stdio.h>

typedef struct tnodo{
        struct tnodo *sig;
        void *telem;
        }nodo;

typedef struct{
        nodo *pri,*cte;
        int tamaniodato;
        }TDA_LS;

int Borrar_siguiente_corriente (TDA_LS *tda){

    if (tda->cte->sig == NULL) return 0;
    
    nodo *aux;

    aux=tda->cte->sig;
    tda->cte->sig=tda->cte->sig->sig;
    free (aux);
    return 1;
}

//PRE: Lista no vacía
//POST: Devuelve 1 si pudo eliminarlo, 0 si no.

int main (int argc, char** argv[]){
    printf ("Compilo");
    getchar();
}

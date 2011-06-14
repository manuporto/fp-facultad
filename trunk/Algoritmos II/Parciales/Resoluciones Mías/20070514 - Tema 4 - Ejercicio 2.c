#include <stdio.h>

typedef struct tnodo {
        struct tnodo *sig;
        void *telem;
        }nodo;
        
typedef struct {
        nodo *tope;
        int tamaniodato;
        }TDA_Pila;

int Pila_Sacar_N (TDA_Pila *tda, int N, void* elemento){
    if (tda->tope == NULL) return 0;
    
    nodo *aux;
    int contador = 1;
    aux = tda->tope;
    while ((contador<N) && (aux->sig!=NULL)){
          aux=aux->sig;
          contador++;
          }
          
    if (contador==N){
       memcpy (elemento,aux->telem,tda->tamaniodato);
       return 1;
    }
    return 0;
}

//PRE: N mayor o igual a 1; hay suficiente memoria; Me envía el elemento
//POST: Devuelve 0 si hubo error y 1 si sacó el elemento. Lo devuelve en la variable 'elemento')

int main (int argc, char** argv[]){
    printf ("Compilo");
    getchar();
}

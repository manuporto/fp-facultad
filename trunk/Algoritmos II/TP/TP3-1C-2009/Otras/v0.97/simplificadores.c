#include "simplificadores.h"

int SimplificarConstante(const TAB* origen, TAB* destino){
/* Esta función no hace nada. No se puede simplificar una constante */
return 0;
}
int SimplificarVariable(const TAB* origen, TAB* destino){
/* Esta función no hace nada. No se puede simplificar una variable */
return 0;
}


/*
0 - Obtengo los dos
1 - Obtengo sólo el de la izquierda
2 - Obtengo sólo el de la derecha
*/
/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
void obtenerLiterales (TAB* origen, TLiteral *litIzq, TLiteral *litDer,int modo)
{
    int error;

    if ((modo==0) || (modo==1))
    {
        AB_MoverCte(origen,IZQ,&error);
        AB_ElemCte(*origen,litIzq);

        AB_MoverCte(origen,PAD,&error);
    }
    if ((modo==0) || (modo==2))
    {
        AB_MoverCte(origen,DER,&error);
        AB_ElemCte(*origen,litDer);

        AB_MoverCte(origen,PAD,&error);
    }
}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarSuma(const TAB* origen, TAB* destino){

    TLiteral litIzq, litDer;
    TAB *origenAux2;
    char *izq;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,0);
    Literal_AString(&litIzq,&izq);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"0")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    if (strcmp(izq,"0")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,DER) == 1)
        {
            AB_MoverCte(origenAux2,IZQ,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    free(origenAux2);
    return 0;
}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarResta(const TAB* origen, TAB* destino)
{
    TLiteral litIzq, litDer;
    TAB *origenAux2;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,0);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"0")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }
    free(origenAux2);
    return 0;
}


/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarProducto(const TAB* origen, TAB* destino){
    TLiteral litIzq, litDer;
    TAB *origenAux2;
    char *izq;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,0);
    Literal_AString(&litIzq,&izq);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"1")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    if (strcmp(izq,"1")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,DER) == 1)
        {
            AB_MoverCte(origenAux2,IZQ,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    if (strcmp(der,"0")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,DER) == 1)
        {
            AB_MoverCte(origenAux2,IZQ,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    if (strcmp(izq,"0")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    free(origenAux2);
    return 0;

}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarDivision(const TAB* origen, TAB* destino){
    TLiteral litIzq, litDer, auxLit;
    TAB *origenAux2;
    char *izq;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,0);
    Literal_AString(&litIzq,&izq);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"1")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    if ((strcmp(izq,der)==0) && (strcmp(izq,"0")!=0) && (litIzq.clase == LIT_CONSTANTE))
    {
        Literal_Crear(&auxLit, "1",VAR);
        AB_Crear(destino,sizeof(TLiteral));
        AB_Insertar(destino,RAIZ,&auxLit,&error);
        free(origenAux2);
        return 1;
    }

    free(origenAux2);
    return 0;

}

/*
PRE: La variable es distinta de cero, por lo dado en el enunciado. Por eso, x^0, dará 1.
*/
/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarPotencia(const TAB* origen, TAB* destino){
    TLiteral litIzq, litDer, auxLit;
    TAB *origenAux2;
    char *izq;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,0);
    Literal_AString(&litIzq,&izq);
    Literal_AString(&litDer,&der);

    if ((strcmp(izq,"0")==0) && (atoi(der)>0) && (litDer.clase == LIT_CONSTANTE))
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }


    if ((strcmp(der,"0")==0) && (strcmp(izq,"0")!=0))
    {
        Literal_Crear(&auxLit, "1",VAR);
        AB_Crear(destino,sizeof(TLiteral));
        AB_Insertar(destino,RAIZ,&auxLit,&error);
        free(origenAux2);
        return 1;
    }


    if (strcmp(der,"1")==0)
    {
        if (AB_CopiarSubarbol(origenAux2,destino,IZQ) == 1)
        {
            AB_MoverCte(origenAux2,DER,&error);
            AB_BorrarCte(origenAux2);
            free(origenAux2);
            return 1;
        }
        free(origenAux2);
        return 0;
    }

    free(origenAux2);
    return 0;
}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarSeno(const TAB* origen, TAB* destino){

    TLiteral litIzq, litDer, auxLit;
    TAB *origenAux2;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,2);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"0")==0)
    {
        Literal_Crear(&auxLit, "0",VAR);
        AB_Crear(destino,sizeof(TLiteral));
        AB_Insertar(destino,RAIZ,&auxLit,&error);
        free(origenAux2);
        return 1;
    }
    free(origenAux2);
    return 0;
}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarCoseno(const TAB* origen, TAB* destino){
    TLiteral litIzq, litDer, auxLit;
    TAB *origenAux2;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,2);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"0")==0)
    {
        Literal_Crear(&auxLit, "1",VAR);
        AB_Crear(destino,sizeof(TLiteral));
        AB_Insertar(destino,RAIZ,&auxLit,&error);
        free(origenAux2);
        return 1;
    }
    free(origenAux2);
    return 0;
}

/**
@function
@name
@description
@return
@param
@param
@param
@author
@see -
*/
int SimplificarLogaritmo(const TAB* origen, TAB* destino){
    TLiteral litIzq, litDer, auxLit;
    TAB *origenAux2;
    char *der;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    obtenerLiterales (origenAux2,&litIzq,&litDer,2);
    Literal_AString(&litDer,&der);

    if (strcmp(der,"1")==0)
    {
        Literal_Crear(&auxLit, "0",VAR);
        AB_Crear(destino,sizeof(TLiteral));
        AB_Insertar(destino,RAIZ,&auxLit,&error);
        free(origenAux2);
        return 1;
    }
    free(origenAux2);
    return 0;
}

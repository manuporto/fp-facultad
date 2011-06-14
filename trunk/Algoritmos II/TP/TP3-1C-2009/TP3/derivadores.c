#include "derivadores.h"

/*
0 - Obtengo los dos
1 - Obtengo sólo el de la izquierda
2 - Obtengo sólo el de la derecha
*/
void DobtenerLiterales (TAB* origen, TLiteral *litIzq, TLiteral *litDer,int modo)
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


int DerivarVariable(const TAB* origen, TAB* destino){

    TLiteral litAux;
    TAB *origenAux2;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    Literal_Crear(&litAux,"1",VAR);
    AB_Crear(destino,sizeof(TLiteral));
    AB_Insertar(destino,RAIZ,&litAux,&error);

    free(origenAux2);
    return 1;
}

int DerivarConstante(const TAB* origen, TAB* destino){
    TLiteral litAux;
    TAB *origenAux2;
    int error;

    origenAux2=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux2,origen,sizeof(TAB));

    Literal_Crear(&litAux,"0",VAR);
    AB_Crear(destino,sizeof(TLiteral));
    AB_Insertar(destino,RAIZ,&litAux,&error);

    free(origenAux2);
    return 1;
}

int DerivarSuma(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TLiteral auxLit;
    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));

/*    printf ("Entra a DerivarSuma\n");*/

    AB_ElemCte(*ab,&auxLit);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);
    AB_MoverCte(ab,IZQ,&error);
    AB_ElemCte(*ab,&auxLit);

    Literal_Derivar(&auxLit,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,IZQ);

    AB_MoverCte(ab,PAD,&error);
    AB_MoverCte(&auxAB,PAD,&error);   /* CUIDADO ACA, ¿hace falta moverse de nuevo a padre? */

    AB_MoverCte(ab,DER,&error);
    AB_ElemCte(*ab,&auxLit);
    Literal_Derivar(&auxLit,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));

    free(ab);
    return 1;
}

int DerivarResta(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TLiteral auxLit;
    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));

/*    printf ("Entra a DerivarResta\n");*/

    AB_ElemCte(*ab,&auxLit);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);
    AB_MoverCte(ab,IZQ,&error);
    AB_ElemCte(*ab,&auxLit);

    Literal_Derivar(&auxLit,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,IZQ);

    AB_MoverCte(ab,PAD,&error);
    AB_MoverCte(&auxAB,PAD,&error);

    AB_MoverCte(ab,DER,&error);
    AB_ElemCte(*ab,&auxLit);
    Literal_Derivar(&auxLit,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;
}


int DerivarProducto(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TAB ABIzq;
    TAB ABDer;

    TLiteral auxLit, litIzq, litDer;
    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));

/*    printf ("Entra a DerivarProducto\n");*/

    Literal_Crear(&auxLit,"+",VAR);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    DobtenerLiterales (ab, &litIzq, &litDer,0);
    AB_CopiarSubarbol(ab,&ABIzq,IZQ);
    AB_CopiarSubarbol(ab,&ABDer,DER);

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_MoverCte(ab,IZQ,&error);

    Literal_Derivar(&litIzq,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,IZQ);

    AB_PegarSubarbol(&ABDer,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    AB_PegarSubarbol(&ABIzq,&auxAB,IZQ);

    AB_MoverCte(ab,PAD,&error);

    AB_MoverCte(ab,DER,&error);

    Literal_Derivar(&litDer,ab,&auxAB2);
    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;
}

int DerivarDivision(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TAB ABIzq;
    TAB ABDer;
    TAB ABDer2;
    TLiteral auxLit, litIzq, litDer;

    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));
/*
    printf ("Entra a DerivarDivision\n");
*/
    AB_ElemCte(*ab,&auxLit);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    Literal_Crear(&auxLit,"-",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    DobtenerLiterales (ab, &litIzq, &litDer,0);
    AB_CopiarSubarbol(ab,&ABIzq,IZQ);
    AB_CopiarSubarbol(ab,&ABDer,DER);
    AB_CopiarSubarbol(ab,&ABDer2,DER);

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_MoverCte(ab,IZQ,&error);

    Literal_Derivar(&litIzq,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,IZQ);

    AB_PegarSubarbol(&ABDer,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    AB_PegarSubarbol(&ABIzq,&auxAB,IZQ);

    AB_MoverCte(ab,PAD,&error);

    AB_MoverCte(ab,DER,&error);

    Literal_Derivar(&litDer,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);
    AB_MoverCte(&auxAB,PAD,&error);

    Literal_Crear(&auxLit,"^",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    Literal_Crear(&auxLit,"2",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    AB_MoverCte(&auxAB,PAD,&error);

    AB_PegarSubarbol(&ABDer2,&auxAB,IZQ);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;
}

int DerivarPotencia(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB ABIzq;
    TAB ABDer;
    TAB ABDer2;
    TLiteral auxLit;

    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    AB_CopiarSubarbol(ab,&ABIzq,IZQ);
    AB_CopiarSubarbol(ab,&ABDer,DER);
    AB_CopiarSubarbol(ab,&ABDer2,DER);

    AB_PegarSubarbol(&ABDer,&auxAB,IZQ);

    Literal_Crear(&auxLit,"^",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);
    AB_PegarSubarbol(&ABIzq,&auxAB,IZQ);

    Literal_Crear(&auxLit,"-",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    AB_PegarSubarbol(&ABDer2,&auxAB,IZQ);

    Literal_Crear(&auxLit,"1",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    memcpy(destino,&auxAB,sizeof(TAB));

    free(ab);
    return 1;
}

int DerivarSeno(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TAB ABDer;

    TLiteral auxLit, litIzq, litDer;

    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));


    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    DobtenerLiterales (ab, &litIzq, &litDer,2);

    AB_CopiarSubarbol(ab,&ABDer,DER);

    Literal_Crear(&auxLit,"cos",VAR);

    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_PegarSubarbol(&ABDer,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);

    AB_MoverCte(ab,DER,&error);
    Literal_Derivar(&litDer,ab,&auxAB2);


    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;
}

int DerivarCoseno(const TAB* origen, TAB* destino){
    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TAB ABDer;

    TLiteral auxLit, litIzq, litDer;

    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    Literal_Crear(&auxLit,"(-1)",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_MoverCte(&auxAB,PAD,&error);

    DobtenerLiterales (ab, &litIzq, &litDer,2);
    AB_CopiarSubarbol(ab,&ABDer,DER);

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,DER,&auxLit,&error);

    Literal_Crear(&auxLit,"sin",VAR);

    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_PegarSubarbol(&ABDer,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);

    AB_MoverCte(ab,DER,&error);
    Literal_Derivar(&litDer,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;
}

int DerivarLogaritmo(const TAB* origen, TAB* destino){

    TAB *ab;
    TAB auxAB;
    TAB auxAB2;
    TAB ABDer;

    TLiteral auxLit, litIzq, litDer;

    int error;

    ab=(TAB*)malloc(sizeof(TAB));
    memcpy(ab,origen,sizeof(TAB));

    AB_Crear(&auxAB,sizeof(TLiteral));
    AB_Crear(&auxAB2,sizeof(TLiteral));

    Literal_Crear(&auxLit,"*",VAR);
    AB_Insertar(&auxAB,RAIZ,&auxLit,&error);

    DobtenerLiterales (ab, &litIzq, &litDer,2);
    AB_CopiarSubarbol(ab,&ABDer,DER);

    Literal_Crear(&auxLit,"/",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    Literal_Crear(&auxLit,"1",VAR);
    AB_Insertar(&auxAB,IZQ,&auxLit,&error);

    AB_MoverCte(&auxAB,PAD,&error);

    AB_PegarSubarbol(&ABDer,&auxAB,DER);

    AB_MoverCte(&auxAB,PAD,&error);

    AB_MoverCte(ab,DER,&error);
    Literal_Derivar(&litDer,ab,&auxAB2);

    AB_PegarSubarbol(&auxAB2,&auxAB,DER);

    memcpy(destino,&auxAB,sizeof(TAB));
    free(ab);
    return 1;

}

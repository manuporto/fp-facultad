#include  "TDA_Expresion.h"

int Expresion_Crear(TExpresion *expr)
{
    AB_Crear(&(expr->expresion),sizeof(TLiteral));
    expr->infijo = NULL;
    expr->var = NULL;
    return 1;
}


int ParsearAux (TExpresion *expr, TPila *sufijo, int mov)
{
    int error;
    int tipoOperador;
    TLiteral auxLiteral;

    if (P_Vacia(*sufijo)) return 0;

    P_Sacar(sufijo,&auxLiteral);
    tipoOperador = Literal_EsOperador(&auxLiteral); /* 2: Binario. 1: Unario. 0: no operador. */
/*    printf ("%s es operador: %i\n",auxLiteral.valor,tipoOperador);
    printf ("Elem a ingresar: %s\n",auxLiteral.valor);
*/    AB_Insertar((&expr->expresion),mov,&auxLiteral,&error);

    if (tipoOperador==2)
    {
        ParsearAux (expr, sufijo, DER);
        ParsearAux (expr, sufijo, IZQ);
    }

    if (tipoOperador==1)
    {
        ParsearAux (expr, sufijo, DER);
    }

    AB_MoverCte(&(expr->expresion),PAD,&error);

    return 0;
}
/*
1  - OK
-1 - Error. Sintaxis.
-2 - Error. Otro.
*/
int Expresion_Parsear (TExpresion* expr, const char* string, const char* var)
{
    TPila sufijo;

    expr->infijo = (char*)malloc(sizeof(char)*strlen(string)+1);
    expr->var = (char*)malloc(sizeof(char)*strlen(var)+1);

    strcpy(expr->infijo,string);
    strcpy(expr->var,var);

    P_Crear(&sufijo,sizeof(TLiteral));

    if (infijo_a_sufijo(string,var,&sufijo)==0) return -1;

    if (P_Vacia(sufijo)) return -2;

/*    P_Sacar(&sufijo,&auxLiteral);
    printf ("Elem a ingresar: %s\n",auxLiteral.valor);
    AB_Insertar((&expr->expresion),RAIZ,&auxLiteral,&error);*/
    /* obtengo el primer elemento de la pila y lo ingreso en la raíz del árbol */


    ParsearAux (expr,&sufijo,RAIZ);

    P_Vaciar(&sufijo);
    return 1;
}

/*void AStringInOrden (TAB ab,int MOV)
{
    TLiteral eab;
    int error;

    AB_MoverCte(&ab,MOV,&error);
    if ( !error )
    {
        AStringInOrden(ab,IZQ);
        AB_ElemCte(ab,&eab);
        printf ("%s",eab.valor);
        AStringInOrden(ab,DER);
    }
}
*/


/* Creemos que funcionaba bien, hay que ver el tema de paréntesis */

void AStringInOrden (TAB ab,int MOV,char **string,int *size)
{
    TLiteral eab;
    int error;

    AB_MoverCte(&ab,MOV,&error);

    if ( !error )
    {
        AB_ElemCte(ab,&eab);

        if (Literal_EsOperador(&eab)!=0)
        {
            *size = (*size) + 1;
            *string=(char*)realloc(*string,sizeof(char)*(*size));
            strcat(*string,"(");
        }

        AStringInOrden(ab,IZQ,string,size);

        AB_ElemCte(ab,&eab);
        *size = (*size) + 3;
        *string=(char*)realloc(*string,sizeof(char)*(*size));
         strcat(*string,eab.valor);

        AStringInOrden(ab,DER,string,size);

        AB_ElemCte(ab,&eab);

        if (Literal_EsOperador(&eab)!=0)
        {
            *size = (*size) + 1;
            *string=(char*)realloc(*string,sizeof(char)*(*size));
            strcat(*string,")");
        }
    }
}


int Expresion_AString(const TExpresion* expr, char** string)
{
    int size =0; /* Aquí yace el error */

    *string = NULL;

    *string=(char*)malloc(sizeof(char));
    *string = '\0';

    AStringInOrden (expr->expresion,RAIZ,string,&size);
    printf ("\n\n\n");
    return 0;
}




void SimplificarOrden (TAB *ab,TAB *ab2,int MOV)
{
    TLiteral eab;
    int error;
    int auxLiteral;

    AB_MoverCte(ab,MOV,&error);
    if ( !error )
    {
        SimplificarOrden(ab,ab2,IZQ);
        SimplificarOrden(ab,ab2,DER);

        AB_ElemCte(*ab,&eab);

        auxLiteral = Literal_Simplificar(&eab,ab,ab2);
        if (auxLiteral == 1)
        {
            AB_MoverCte(ab,PAD,&error);   /* ANALIZAR SIMPLIF EN LA RAIZ */
            if (MOV == IZQ)
            {
                AB_MoverCte(ab,MOV,&error);
                AB_BorrarCte(ab);
/*
                ab->cte->izq = NULL;
*/
                AB_PegarSubarbol(ab2,ab,MOV);
                memcpy(ab2,ab,sizeof(TAB));
            }
            else
                if (MOV == DER)
                {
                    AB_MoverCte(ab,MOV,&error);
                    AB_BorrarCte(ab);
/*
                    ab->cte->der = NULL;
*/
                    AB_PegarSubarbol(ab2,ab,MOV);
                    memcpy(ab2,ab,sizeof(TAB));
                }
                else
                    if (MOV == RAIZ)
                    {
                        memcpy(ab,ab2,sizeof(TAB));
                    }
        }
        else AB_MoverCte(ab,PAD,&error);
    }
}


int Expresion_Simplificar(const TExpresion* expr, TExpresion* simpl)
{
    TAB *origenAux;
    TAB *origenAux2;
    TAB ABIzq;
    TAB ABDer;
    int error;
    TLiteral litAux;

    origenAux=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux,&(expr->expresion),sizeof(TAB));

    origenAux2=(TAB*)malloc(sizeof(TAB));

    AB_Crear(origenAux2,sizeof(TLiteral));
    AB_Crear(&ABIzq,sizeof(TLiteral));
    AB_Crear(&ABDer,sizeof(TLiteral));


    AB_MoverCte(origenAux,RAIZ,&error);
    AB_ElemCte(*origenAux,&litAux);
    AB_Insertar(origenAux2,RAIZ,&litAux,&error);

    AB_CopiarSubarbol(origenAux,&ABIzq,IZQ);
    AB_CopiarSubarbol(origenAux,&ABDer,DER);
    AB_PegarSubarbol(&ABIzq,origenAux2,IZQ);
    AB_PegarSubarbol(&ABDer,origenAux2,DER);

    SimplificarOrden (origenAux2,&(simpl->expresion),RAIZ);
    if (AB_Vacio(simpl->expresion)==1)
    {
        free(origenAux);
        free(origenAux2);
        return 0;
    }

    free(origenAux);
    free(origenAux2);
    return 1;
}


/*
int Expresion_Simplificar(const TExpresion* expr, TExpresion* simpl)
{
    TAB *origenAux;

    origenAux=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux,&(expr->expresion),sizeof(TAB));

    SimplificarOrden (origenAux,&(simpl->expresion),RAIZ);
    if (AB_Vacio(simpl->expresion)==1)
        (simpl->expresion) = (expr->expresion);

    free(origenAux);
    return 1;
}
*/

/*int tipoOperador (TLiteral *lit)
{
    char *valor;

    Literal_AString(lit,&valor);
    if (strcmp(valor,"+")==0) return SUMA;
    if (strcmp(valor,"-")==0) return RESTA;
    if (strcmp(valor,"*")==0) return PRODUCTO;
    if (strcmp(valor,"/")==0) return DIVISION;
    if (strcmp(valor,"^")==0) return POTENCIA;
    if (strcmp(valor,"sin")==0) return SIN;
    if (strcmp(valor,"cos")==0) return COS;
    if (strcmp(valor,"ln")==0) return LOG;
    return ERR;
}
*/

int Expresion_Derivar(const TExpresion* expr, TExpresion* deriv)
{
    TAB *origenAux;
    int error;
    TLiteral auxLit;

    origenAux=(TAB*)malloc(sizeof(TAB));
    memcpy(origenAux,&(expr->expresion),sizeof(TAB));

    AB_MoverCte(origenAux,RAIZ,&error);
    if (!error)
    {
        AB_ElemCte(*origenAux,&auxLit);
        if (Literal_Derivar (&auxLit,origenAux,&(deriv->expresion)) == 1)
        {
            free(origenAux);
            return 1;
        }
    }

    free(origenAux);
    return 0;
}

void destruirPosOrden (TAB ab,int MOV)
{
    TLiteral eab;
    int error;

    AB_MoverCte(&ab,MOV,&error);
    if ( !error )
    {
        destruirPosOrden(ab,IZQ);
        destruirPosOrden(ab,DER);
        AB_ElemCte(ab,&eab);
        Literal_Destruir(&eab);
    }
}


void Expresion_Destruir(TExpresion* expr)
{
    destruirPosOrden(expr->expresion,RAIZ);
    AB_Vaciar(&(expr->expresion));
    free(expr->infijo);
    expr->infijo = NULL;
    free(expr->var);
    expr->var = NULL;
}

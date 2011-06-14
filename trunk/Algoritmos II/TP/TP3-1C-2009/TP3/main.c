#include <stdio.h>
#include <stdlib.h>
/*#include "literal.h"
#include "TDA_Expresion.h"
*/
#include "opciones.h"
#include "cmemdbg.h"


void PreOrden (TAB ab,int MOV,int nivel)
{
    TLiteral eab;
/*    int eab;*/
    int error;
    int i;


    AB_MoverCte(&ab,MOV,&error);
    if ( !error )
    {
        AB_ElemCte(ab,&eab);
/*        for (i=0;i<nivel;i++)
        {
            printf ("-");
        }
*/        printf (" %s\n",eab.valor);
/*        printf ("%i\n",eab);*/

        PreOrden(ab,DER,nivel+1);
        PreOrden(ab,IZQ,nivel+1);
    }
}

void InOrden (TAB ab,int MOV)
{
    int eab;
    int error;

    AB_MoverCte(&ab,MOV,&error);
    if ( !error )
    {
        InOrden(ab,IZQ);
        AB_ElemCte(ab,&eab);
        printf ("%i\n",eab);
        InOrden(ab,DER);
    }
}

void PostOrden (TAB ab,int MOV)
{
    int eab;
    int error;

    AB_MoverCte(&ab,MOV,&error);
    if ( !error )
    {
        PostOrden(ab,IZQ);
        PostOrden(ab,DER);
        AB_ElemCte(ab,&eab);
        printf ("%i\n",eab);
    }
}

int main(int argc, char* argv[])
{

    opciones (argc,argv);
    PrintMemoryLeakInfo();

    return 0;
}

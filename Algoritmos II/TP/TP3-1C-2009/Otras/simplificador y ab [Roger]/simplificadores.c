#include "simplificadores.h"

int get_literales ( const TAB *ptroAB , TLiteral* lit_i , TLiteral* lit_d )
{
   int error;

   AB_MoverCte ( ptroAB , IZQ , &error );
   if ( error ) return 0;
   AB_ElemCte ( *ptroAB , lit_i );
   AB_MoverCte ( ptroAB , PAD , &error );
   AB_MoverCte ( ptroAB , DER , &error );
   if ( error ) return 0;
   AB_ElemCte ( *ptroAB , lit_d );
   AB_MoverCte ( ptroAB , PAD , &error );
}
/*----------------------------------------------------------------------------*/

int SimplificarConstante(const TAB* origen, TAB* destino) { return 0; }
int SimplificarVariable(const TAB* origen, TAB* destino) { return 0; }

/*----------------------------------------------------------------------------*/
int SimplificarSuma(const TAB* origen, TAB* destino)
{
   TLiteral lit_izq, lit_der;
   int error , movimiento = -1;

   error = get_literales ( origen , &lit_izq , &lit_der );
   if ( !error ) return 0;

   if ( ( lit_izq.clase!= LIT_CONSTANTE ) && ( lit_der.clase!=LIT_CONSTANTE ) )
      return 0;

   if ( (lit_izq.clase == LIT_CONSTANTE )  && ( atoi ( lit_izq.valor ) == 0 ) )
      movimiento = DER;

   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
            movimiento = IZQ;

  return ( AB_CopiarSubarbol ( origen , destino , movimiento ) );
}
/*----------------------------------------------------------------------------*/
int SimplificarResta(const TAB* origen, TAB* destino)
{
   TLiteral lit_izq , lit_der;
   int error , movimiento = -1;

   error = get_literales ( origen , &lit_izq , &lit_der );
   if ( !error ) return 0;

   if ( ( lit_izq.clase!= LIT_CONSTANTE ) && ( lit_der.clase!=LIT_CONSTANTE ) )
      return 0;

   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
      movimiento = IZQ;

  return ( AB_CopiarSubarbol ( origen , destino , movimiento ) );
}
/*----------------------------------------------------------------------------*/
int SimplificarProducto(const TAB* origen, TAB* destino)
{
   TLiteral lit_izq , lit_der;
   int error , movimiento = -1;

   error = get_literales ( origen , &lit_izq , &lit_der );
   if ( !error ) return 0;

   if ( ( lit_izq.clase!= LIT_CONSTANTE ) && ( lit_der.clase!=LIT_CONSTANTE ) )
      return 0;

   if ( (lit_izq.clase == LIT_CONSTANTE )  && ( atoi ( lit_izq.valor ) == 0 ) )
      movimiento = IZQ;

   if ( (lit_izq.clase == LIT_CONSTANTE )  && ( atoi ( lit_izq.valor ) == 1 ) )
      movimiento = DER;

   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
      movimiento = DER;

   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 1 ) )
      movimiento = IZQ;

  return ( AB_CopiarSubarbol ( origen , destino , movimiento ) );
}
/*----------------------------------------------------------------------------*/
int SimplificarDivision(const TAB* origen, TAB* destino)
{
   TLiteral lit_izq, lit_der;
   int error , movimiento = -1;

   error = get_literales ( origen , &lit_izq , &lit_der );
   if ( !error ) return 0;

   if ( ( lit_izq.clase!= LIT_CONSTANTE ) && ( lit_der.clase!=LIT_CONSTANTE ) )
      return 0;

   if ( (lit_der.clase==LIT_CONSTANTE) && ( atoi(lit_der.valor))==0 )
         return -1; /* error al dividir por 0 */

   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 1 ) )
      movimiento = IZQ;

   if ( (lit_izq.clase==LIT_CONSTANTE) && (atoi( lit_izq.valor ) == 0) )
      {
         AB_Insertar ( destino , RAIZ , &lit_izq , &error );
         return 1;
      }
   /* A/A  A es constante  y A != 0  */
   if ( (lit_izq.clase==LIT_CONSTANTE)  && (lit_der.clase==LIT_CONSTANTE) )
      {
         if ( !(strcmp( lit_izq.valor,lit_der.valor) ) && ( atoi( lit_izq.valor ) != 0 ))
            {
               lit_izq.valor[0] = '1';
               lit_izq.valor[1] = '\0';
               AB_Insertar ( destino , RAIZ , &lit_izq , &error );
               return 1;
            }
      }
  return ( AB_CopiarSubarbol ( origen , destino , movimiento ) );
}
/*----------------------------------------------------------------------------*/
int SimplificarPotencia(const TAB* origen, TAB* destino)
{
   TLiteral lit_izq , lit_der;
   int error , movimiento = -1;

   error = get_literales ( origen , &lit_izq , &lit_der );
   if ( !error ) return 0;

   if ( ( lit_izq.clase!= LIT_CONSTANTE ) && ( lit_der.clase!=LIT_CONSTANTE ) )
      return 0;

   /* exp^1 */
   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 1 ) )
      movimiento = IZQ;
   /* exp^0 */
   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
   {
      if ( (lit_izq.clase == LIT_CONSTANTE )  && ( atoi ( lit_izq.valor ) == 0 ))
         return -1; /* error 0^0 */
         else
         {
            lit_der.valor[0] = '1';
            lit_der.valor[1] = '\0';
            AB_Insertar ( destino , RAIZ , &lit_der , &error );
            return 1;
         }
   }
   /* 0^A */
   if ( (lit_izq.clase == LIT_CONSTANTE )  && ( atoi ( lit_izq.valor ) == 0 ) )
   {
      if ( (lit_der.clase == LIT_CONSTANTE)
            && ( (atoi( lit_der.valor) == -1 ) || ( atoi(lit_der.valor) == 0 ) ) )
               return -1; /* error: ( 0 ^ 0 ) ó ( 0 ^ -1 ) */
               else
                  {
                     AB_Insertar ( destino , RAIZ , &lit_izq , &error );
                     return 1;
                  }
   }
  return ( AB_CopiarSubarbol ( origen , destino , movimiento ) );
}
/*----------------------------------------------------------------------------*/
int SimplificarSeno(const TAB* origen, TAB* destino)
{
   TLiteral lit_der;
   int error;

   AB_MoverCte ( origen , DER , &error );
   AB_ElemCte ( *origen , &lit_der );
   AB_MoverCte ( origen , PAD , &error );

   if ( lit_der.clase != LIT_CONSTANTE )
      return 0;
   /* sen ( 0 ) */
   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
   {
      AB_Insertar ( destino , RAIZ , &lit_der , &error );
      return 1;
   }
}
/*----------------------------------------------------------------------------*/
int SimplificarCoseno(const TAB* origen, TAB* destino)
{
   TLiteral lit_der;
   int error;

   AB_MoverCte ( origen , DER , &error );
   AB_ElemCte ( *origen , &lit_der );
   AB_MoverCte ( origen , PAD , &error );

   if ( lit_der.clase != LIT_CONSTANTE )
      return 0;
   /* cos ( 0 ) */
   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 0 ) )
   {
      lit_der.valor[0] = '1';
      lit_der.valor[1] = '\0';
      AB_Insertar ( destino , RAIZ , &lit_der , &error );
      return 1;
   }
}
/*----------------------------------------------------------------------------*/
int SimplificarLogaritmo(const TAB* origen, TAB* destino)
{
   TLiteral lit_der;
   int error;

   AB_MoverCte ( origen , DER , &error );
   AB_ElemCte ( *origen , &lit_der );
   AB_MoverCte ( origen , PAD , &error );

   if ( lit_der.clase != LIT_CONSTANTE )
      return 0;
   /* ln ( 1 ) */
   if ( (lit_der.clase == LIT_CONSTANTE )  && ( atoi ( lit_der.valor ) == 1 ) )
   {
      lit_der.valor[0] = '0';
      lit_der.valor[1] = '\0';
      AB_Insertar ( destino , RAIZ , &lit_der , &error );
      return 1;
   }
}
/*----------------------------------------------------------------------------*/

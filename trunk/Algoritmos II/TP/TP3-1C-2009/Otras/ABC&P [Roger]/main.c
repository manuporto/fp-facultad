#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

/* Recorridos de un arbol */
/*------------------------*/

#define DATOS_ELEM "Elemento del nodo: %d\n"


void procesar( void* eab )
{
   fprintf ( stdout , DATOS_ELEM , (int) eab );
}

/* PreOrden:
   Primero se procesa el nodo corriente, luego el subárbol izquierdo, y luego el subárbol derecho.
*/
void PreOrden(TAB ab, int MOV)
{
   TelemAB eab;
   int error;

   AB_MoverCte(&ab,MOV,&error);
   if ( !error )
   {
      AB_ElemCte(ab,&eab);
      procesar(eab);
      PreOrden(ab,IZQ);
      PreOrden(ab,DER);
   }
}
/*----------------------------------------------------------------------------*/
/* InOrden:
   Primero se procesa el subárbol izquierdo, luego el nodo corriente, y luego el subárbol derecho.
*/

void InOrden(TAB ab, int MOV)
{
   TelemAB eab;
   int error;

   AB_MoverCte(&ab,MOV,&error);
   if ( !error )
   {
      InOrden(ab,IZQ);
      AB_ElemCte(ab,&eab);
      procesar(eab);
      InOrden(ab,DER);
   }
}
/*----------------------------------------------------------------------------*/
/* PosOrden
   Primero se procesa el subárbol izquierdo, luego el subárbol derecho, y luego el nodo corriente.
*/
void PosOrden(TAB ab, int MOV)
{
   TelemAB eab;
   int error;

   AB_MoverCte(&ab,MOV,&error);
   if ( !error )
   {
      PosOrden(ab,IZQ);
      PosOrden(ab,DER);
      AB_ElemCte(ab,&eab);
      procesar(eab);
   }
}
/*----------------------------------------------------------------------------*/

int main( int argc , char* argv[] )
{
   TAB ab , ac ,ad;
   int error;
   int cinco = 5 , tres = 3 , uno = 1, dos = 2 , seis = 6;
   int cuatro = 4;

   AB_Crear ( &ab , sizeof (int));
   AB_Insertar ( &ab , RAIZ , &cinco , &error );
   AB_Insertar ( &ab , IZQ , &cuatro , &error );
   AB_MoverCte ( &ab , RAIZ , &error );
   AB_Insertar ( &ab , DER , &seis , &error );
   printf ( "\n Arbol ab: \n\n" );
   PreOrden (ab , RAIZ );

   AB_Crear ( &ad , sizeof (int) );
   AB_Insertar ( &ad , RAIZ , &dos , &error );
   AB_Insertar ( &ad , IZQ , &uno , &error );
   AB_MoverCte ( &ad , RAIZ , &error );
   AB_Insertar ( &ad , DER , &tres , &error );
   printf ( "\n Arbol ad: \n\n" );
   PreOrden (ad , RAIZ );


   error = AB_CopiarSubarbol ( &ad , &ac , RAIZ );
   if ( !error ) return -1;
   printf ( "\n ad se copia en ac: \n\n" );
   PreOrden (ac , RAIZ );
   AB_MoverCte ( &ab , RAIZ , &error );
   AB_MoverCte ( &ab , IZQ , &error );

   error = AB_PegarSubarbol ( &ac , &ab , IZQ );
   if ( !error ) return -1;
   printf ( "\n Se pega el arbol ac en ab: \n\n" );
   InOrden ( ab , RAIZ );

   AB_Vaciar ( &ab );
   AB_Vaciar ( &ac );
   AB_Vaciar ( &ad );

   scanf ( "%" , error );
   return 0;
}

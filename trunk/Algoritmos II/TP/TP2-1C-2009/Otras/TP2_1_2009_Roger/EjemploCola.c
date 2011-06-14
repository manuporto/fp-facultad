#include <stdio.h>
#include <stdlib.h>

#include "TDA_Cola.c"

int main (int argc, char **argv){
	Tcola cola;
	char s = 's', o = 'o' , l = 'l' , h = 'h' , a = 'a';
	char carAux;
	int k , errorCode;
	
	
	C_Crear ( &cola , sizeof ( char ) );
	C_Agregar ( &cola , &s );
	C_Agregar ( &cola , &o );
	C_Agregar ( &cola , &l );
	
	for ( k = 0 ; k < 3 ; k++)
	{
		C_Sacar ( &cola , &carAux );
		printf ( "Caracter : %\n" , carAux );
	}
	
	scanf ( "%" , errorCode );
	
	return 0;
}

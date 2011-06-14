#ifndef _TDA_EXPRESION_H_
#define _TDA_EXPRESION_H_

#include "literal.h"
#include "AB.h"
#include "cmemdbg.h"

/*Typedef enum{VACIA,LLENA,DERIV}tEstado;*/

typedef struct texpresion{
	TAB expresion;
    char* infijo;
    char *var;
}TExpresion;



/* PRIMITIVAS DEL TDA */


/*
DESCRIP:  Crea una expresion vacia.

PRE:  Expr debe apuntar a una variable de tipo TExpresion sin crear.

POST:  Devuelve 1 si pudo crear la expresion, 0 en cualquier otro
	   caso.
*/

int Expresion_Crear(TExpresion *expr);


/*
DESCRIP:  Parsea la expresion dada en string y la guarda
		  en expr. Asume que var es la variable independiente.

PRE:  Asume que var es la variable independiente.
	  Expr debe ser una variable de tipo TExpresion
	  creada, string debe ser una cadena de caracteres
	  no vacia y var debe ser una cadena de caracteres
	  de longitud 1 o vacia.

POST: Devuelve 1 si pudo parsear
	  la expresion, -1 si hubo error de sintaxis y -2 en
	  cualquier otro caso.
Nota: para implementar esta primitiva debe utilizarse
la funcion infijo a sufijo del TDA Literal.
*/
int Expresion_Parsear(TExpresion* expr, const char* string, const char* var);


/*
DESCRIP:  Guarda en deriv la derivada de expr.

PRE:  Expr debe apuntar a una expresion creada y con al menos un
	  string parseado (no vacia) y deriv debe apuntar a
	  una variable de tipo TExpresion vacia.

POST:  Devuelve 1 si pudo derivar la expresion,
	   0 en cualquier otro caso.
*/
int Expresion_Derivar(const TExpresion* expr, TExpresion* deriv);


/*
DESCRIP:  Guarda en simpl una copia simplificada de expr.

PRE:  Expr debe apuntar a una expresion creada y con al
	  menos un string parseado (no vacia) y simpl debe
	  apuntar a una variable de tipo TExpresion vacia.

POST: Devuelve 1 si pudo simplificar la expresion, 0 en
	  cualquier otro caso.
*/
int Expresion_Simplificar(const TExpresion* expr, TExpresion* simpl);


/*
DESCRIP:  Devuelve en string un puntero a una cadena de
		  caracteres con la expresion expr en formato infijo.

PRE:  Expr debe ser una expresion creada y con al menos
	  un string parseado, y string debe apuntar a NULL.


POST:  Devuelve 1 si pudo convertir la expresion, 0
	   en cualquier otro caso.

Nota: Debera utilizarse la funcion realloc de
la biblioteca standard de C para redimensionar la
cadena string.
*/
int Expresion_AString(const TExpresion* expr, char** string);


/*
DESCRIP:  Destruye expr.

PRE: expr debe ser una expresion creada.

POST: Devuelve 1 si pudo destruir la expresion, 0 en cualquier otro
	  caso.
*/
void Expresion_Destruir(TExpresion* expr);


/* FIN PRIMITIVAS DEL TDA_EXPRESION */

#endif

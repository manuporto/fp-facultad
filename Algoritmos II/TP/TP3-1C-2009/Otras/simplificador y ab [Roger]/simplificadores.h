#ifndef _SIMPLIFICADORES_H_
#define _SIMPLIFICADORES_H_

#include "ab.h"
#define MAX_VALOR 14

typedef enum {LIT_CONSTANTE, LIT_PARIZQ, LIT_PARDER, LIT_OPERADOR, LIT_VARIABLE } LITERAL_CLASE;

typedef struct {
	LITERAL_CLASE clase;
	char valor[MAX_VALOR];
	int prioridad;
	int binario;

	int (*derivar)(const TAB* origen, TAB* destino);
	int (*simplificar)(const TAB* origen, TAB* destino);
} TLiteral;
/******************************************************************************/

int SimplificarConstante(const TAB* origen, TAB* destino);
int SimplificarVariable(const TAB* origen, TAB* destino);
int SimplificarSuma(const TAB* origen, TAB* destino);
int SimplificarResta(const TAB* origen, TAB* destino);
int SimplificarProducto(const TAB* origen, TAB* destino);
int SimplificarDivision(const TAB* origen, TAB* destino);
int SimplificarPotencia(const TAB* origen, TAB* destino);
int SimplificarSeno(const TAB* origen, TAB* destino);
int SimplificarCoseno(const TAB* origen, TAB* destino);
int SimplificarLogaritmo(const TAB* origen, TAB* destino);

#endif

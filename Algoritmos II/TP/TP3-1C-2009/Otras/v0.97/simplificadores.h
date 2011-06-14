#ifndef _SIMPLIFICADORES_H_
#define _SIMPLIFICADORES_H_

#include "AB.h"
#include "literal.h"
/* #include "cmemdbg.h" */

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

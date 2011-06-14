#ifndef _DERIVADORES_H_
#define _DERIVADORES_H_

#include "AB.h"
#include "literal.h"
/* #include "cmemdbg.h" */


int DerivarVariable(const TAB* origen, TAB* destino);
int DerivarConstante(const TAB* origen, TAB* destino);
int DerivarSuma(const TAB* origen, TAB* destino);
int DerivarResta(const TAB* origen, TAB* destino);
int DerivarProducto(const TAB* origen, TAB* destino);
int DerivarDivision(const TAB* origen, TAB* destino);
int DerivarPotencia(const TAB* origen, TAB* destino);
int DerivarSeno(const TAB* origen, TAB* destino);
int DerivarCoseno(const TAB* origen, TAB* destino);
int DerivarLogaritmo(const TAB* origen, TAB* destino);

#endif

#ifndef _LITERAL_H_
#define _LITERAL_H_

#include "AB.h"
#include "Pila.h"
#include "constantes.h"

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

int Literal_Crear(TLiteral* lit, const char* p, const char* var);
int Literal_Destruir(TLiteral* lit);

int Literal_EsOperador(const TLiteral* lit);
int Literal_AString(const TLiteral* lit, char** string);

int Literal_Derivar(const TLiteral* lit, const TAB* origen, TAB* destino);
int Literal_Simplificar(const TLiteral* lit, const TAB* origen, TAB* destino);

int infijo_a_sufijo(const char* infijo, const char* var, TPila* sufijo);

#endif

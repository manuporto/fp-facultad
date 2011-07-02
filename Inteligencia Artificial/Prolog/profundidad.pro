/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: PROFUNDIDAD.PRO
 Purpose: Obtener la profundidad de una lista genérica
 Written by: Visual Prolog
 Comments: 
******************************************************************************/

include "parciales.inc"


domains
	lista = elemento*
	elemento = l(lista);e(Integer)

predicates
	nondeterm profundidad (lista,Integer,Integer)
	nondeterm mayor (Integer,Integer,Integer)

clauses
	profundidad ([],N,N).
	profundidad ([l(Ca)|Co],X,Y) :- X1 = X+1, profundidad (Ca,X1,N1), profundidad (Co,X,N2), mayor (N1,N2,Y).
	profundidad ([e(_)|Co],X,Y) :- profundidad (Co,X,N), mayor (X,N,Y).

	mayor (X,Y,Z) :- X>Y,Z=X.
	mayor (X,Y,Z) :- Y>=X, Z=Y.

goal

	profundidad ([e(1),e(2),l([e(3),e(4),l([e(5),l([e(6),e(7)])]),e(8)]),e(9)],1,Profundidad).

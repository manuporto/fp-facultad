/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: PROFUNDIDAD2.PRO
 Purpose: Obtener la profundidad de una lista genérica (sí, de nuevo. Para practicar).
 Written by: Visual Prolog
 Comments:
******************************************************************************/

include "parciales.inc"

domains
	lista = elemento*
	elemento = e(Symbol);l(lista)

predicates
	nondeterm profundidad(lista,Integer,Integer)
	nondeterm mayor(Integer,Integer,Integer)

clauses
	profundidad ([],N,N).

	profundidad ([e(_)|Co],N,M):-
		profundidad(Co,N,M1),
		mayor(N,M1,M).

	profundidad ([l(Ca)|Co],N,M):-
		N1=N+1,
		profundidad(Ca,N1,M1),
		profundidad(Co,N,M2),
		mayor(M1,M2,M).

	mayor (A,B,C):-
		A>B,C=A.
	mayor (A,B,C):-
		B>=A,C=B.

goal
	profundidad ([e(a),e(b),l([e(c),e(d),l([e(e),l([e(f),l([e(a),e(b)]),e(g)])]),e(h)]),e(i)],1,Profundidad). % {a,b,[c,d,(e,(f,g),h),i],j}		
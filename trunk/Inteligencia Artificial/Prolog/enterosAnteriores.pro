/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: ENTEROSANTERIORES.PRO
 Purpose: Obtener los enteros positivos menores a un número
 Written by: Visual Prolog
 Comments:
******************************************************************************/

include "parciales.inc"

domains
	lista = Integer*

predicates
	nondeterm enterosAnteriores (Integer,lista)

clauses
	enterosAnteriores (0,[]).

	enterosAnteriores (N,[Ca|Co]) :-
		N>0,
		Ca = N,
		N1 = N - 1,
		enterosAnteriores (N1,Co).
goal
	
	enterosAnteriores (5,L).
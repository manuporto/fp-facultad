/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: ADYACENTES.PRO
 Purpose: Hacer predicado que determina si dos elementos están adyacentes en una lista (al derecho o invertidos).
 Written by: Visual Prolog
 Comments:
******************************************************************************/

include "parciales.inc"

domains
	lista = Integer*

predicates
	nondeterm adyacentes(lista,Integer,Integer)

clauses

	adyacentes ([Ca|[Ca1|_]],Ca,Ca1).

	adyacentes ([Ca|[Ca1|_]],Ca1,Ca).

	adyacentes ([_|Co],X,Y):-
		adyacentes(Co,X,Y).

goal
	adyacentes ([1,8,4,3],3,4).
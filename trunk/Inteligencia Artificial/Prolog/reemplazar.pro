/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: REEMPLAZAR.PRO
 Purpose: Dada una lista, y dos números. Reemplazar todas las ocurrencias del primer número, por el segundo
 Written by: Visual Prolog
 Comments:
******************************************************************************/

include "parciales.inc"

domains
	lista = Integer*

predicates
	nondeterm reemplazar (lista,Integer,Integer,lista)

clauses
	reemplazar ([X],X,Y,[Y]).

	reemplazar ([W],X,Y,[Z]):-
		W<>X,
		Z=Y.

	reemplazar ([Ca|Co],X,Y,[Ca1|Co1]):-
		Ca = X,
		Ca1=Y,
		reemplazar (Co,X,Y,Co1).

	reemplazar ([Ca|Co],X,Y,[Ca1|Co1]):-
		Ca <> X,
		Ca1=Ca,
		reemplazar (Co,X,Y,Co1).

goal
	reemplazar ([1,2,3],4,5,Lista).

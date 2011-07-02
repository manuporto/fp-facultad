/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: 28NOV08.PRO
 Purpose: Practicar
 Written by: Fepe Laser
 Comments: Definir un predicado que ordene una lista.

******************************************************************************/

include "parciales.inc"

domains
	lista = Integer*

predicates
	nondeterm imprimir (lista)
	nondeterm ordenar (lista,lista)
	nondeterm eliminar (lista,Integer,lista)
	nondeterm minimo (lista,Integer)
	nondeterm menor (Integer,Integer,Integer)

clauses
	imprimir ([]).
	imprimir ([Elem]) :- write (Elem).
	imprimir ([Ca|Co]) :- write (Ca), write("\t"),imprimir(Co).

	eliminar ([Elem],Elem,[]).
	eliminar ([Ca|Co],Ca,Co).
	eliminar ([Ca|Co],X,[Ca|L]) :- eliminar(Co,X,L).

	menor (A,B,C) :- A<B,C=A.
	menor (A,B,C) :- A>=B,C=B.

	minimo ([Elem],Elem).
	minimo ([Ca|[Ca1|Co1]],X) :- Ca1 < Ca, minimo ([Ca|Co1],Y),menor (Ca1,Y,X).
	minimo ([Ca|[Ca1|Co1]],X) :- Ca1 >= Ca, minimo ([Ca1|Co1],Y),menor (Ca,Y,X).

	ordenar ([],[]).
	ordenar ([Elem],[Elem]).
	ordenar ([Ca|Co],[X|L]) :-
		minimo ([Ca|Co],X),
		eliminar ([Ca|Co],X,L1),
		ordenar (L1,L).

goal
	ordenar ([1,2,3],Ordenada),

	write ("\n").

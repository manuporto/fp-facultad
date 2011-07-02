/*****************************************************************************

		Copyright (c) My Company

 Project:  PARCIALES
 FileName: 16NOV07.PRO
 Purpose: Práctica
 Written by: Fepe Laser
 Comments: 
 	1) Hacer un predicado que devuelva en una lista, los enteros de N a 1
 	2) Escriba un predicado que, dada una lista, retorne el menor de sus elementos
 	3) Hacer un predicado que reemplaza un elemento por otro en una lista.
 
******************************************************************************/

include "parciales.inc"

/*
Ejemplos: 

	1) enterosAnteriores (3,L) -> L = [3,2,1]
	2) menor ([2,3,56,1,23],X) -> X = 1
	3) reemplazar ([1,3,4,1,6,8], 1,7,L) -> L = [7,3,4,7,8]

*/

domains
	lista = Integer*

predicates
	nondeterm enterosAnteriores(Integer,lista)
	nondeterm menor (lista,Integer)
	nondeterm reemplazar (lista,Integer,Integer,lista)
	

clauses
	enterosAnteriores(0,[]).
	enterosAnteriores(N,[Ca|Co]) :-
		N>0,
		N1=N-1,
		Ca = N,
		enterosAnteriores(N1,Co).
	
	menor ([Ca],Ca).
	menor ([Elem1|[Elem2|Co]],X) :- Elem1 < Elem2, menor ([Elem1|Co],X).
	menor ([Elem1|[Elem2|Co]],X) :- Elem1 >= Elem2, menor ([Elem2|Co],X).

	reemplazar ([Elem],Elem,Elem2,[Elem2]).
	reemplazar ([X],Y,_,[Ca]) :- X<>Y,Ca=X.
	reemplazar ([Ca|Co],X,Y,[Ca2|Co2]) :- Ca = X, Ca2 = Y, reemplazar (Co,X,Y,Co2).
	reemplazar ([Ca|Co],X,Y,[Ca2|Co2]) :- Ca <> X, Ca2 = Ca, reemplazar (Co,X,Y,Co2).
	
goal
	enterosAnteriores(12,L),
	menor([2,3,8,3,1,5,8,1,3,12],X),
	reemplazar ([1,3,3,5,6,2],3,55,M).

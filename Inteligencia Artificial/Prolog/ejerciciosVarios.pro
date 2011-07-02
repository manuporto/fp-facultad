/*********************************************************************************************************************

		Copyright (c) Fepe Laser

 Project:  PARCIALES
 FileName: EJERCICIOSVARIOS.PRO
 Purpose: Practicar ejercicios varios de parciales
 Written by: Fepe Laser
 Comments: Ejercicios de parcial
 	1) Hacer un predicado que devuelva en una lista, los enteros de N a 1
 	2) Escriba un predicado que, dada una lista, retorne el menor de sus elementos
 	3) Hacer un predicado que reemplaza un elemento por otro en una lista.
	4) Hacer un predicado que ordene una lista
	5) Hacer predicado que determina si dos elementos est�n adyacentes en una lista (al derecho o invertidos).
	6) Obtener la profundidad de una lista gen�rica.
**********************************************************************************************************************/

include "parciales.inc"

domains
	listaDeEnteros = Integer*			% Lista de enteros

	listaGenerica = elementoGenerico*		% Lista de elementos gen�ricos
	elementoGenerico = e(symbol);l(listaGenerica)	% El elemento gen�rico puede ser texto (symbol) u otra lista gen�rica

predicates
	nondeterm enteros (Integer,listaDeEnteros)
	nondeterm menor (listaDeEnteros,Integer)
	nondeterm reemplazar (listaDeEnteros,Integer,Integer,listaDeEnteros)
	nondeterm ordenar (listaDeEnteros,listaDeEnteros)
	nondeterm quitar (listaDeEnteros,Integer,listaDeEnteros)
	nondeterm adyacentes (listaDeEnteros,Integer,Integer)
	nondeterm profundidad (listaGenerica,Integer,Integer)
	nondeterm mayor (Integer,Integer,Integer)

clauses
	% Ejercicio 1
	enteros (0,[]).					% Si me mandar el 0, devuelvo la lista vac�a (condici�n de corte)

	enteros (N,[Ca|Co]):-
		N > 0,					% Si es mayor a cero
		Ca = N,					% Pongo ese valor en la Cabeza de la lista a devolver
		N1 = N-1,				% Le resto uno, 
		enteros (N1,Co).			% Y llamo recursivamente
	

	% Ejercicio 2
	menor ([Elem],Elem).				% Si tiene un s�lo elemento, es el menor (condici�n de corte)

	menor ([Ca|[Ca1|Co]],Elem):-	
		Ca < Ca1,				% Si el primer elemento es m�s chico que el segundo
		menor ([Ca|Co],Elem).			% llamo de nuevo recursivamente, pero directamente le paso la lista sin el segundo elemento

	menor ([Ca|[Ca1|Co]],Elem):-
		Ca >= Ca1,				% Si en cambio el primero es m�s grande, 
		menor ([Ca1|Co],Elem).			% el que no paso, es el primero, pasando s�lo el segundo como cabeza de la nueva lista


	% Ejercicio 3
	reemplazar ([Elem1],Elem1,Elem2,[Elem2]).	% Si recibo una lista de un s�lo elemento, y es el que busco, devuelvo una lista cambi�ndolo por el nuevo (Condici�n de corte 1)

	reemplazar ([Elem],Elem1,_,[Elem3]):-		% Si es s�lo un elemento,
		Elem1 <> Elem,				% y no es el que tengo que reemplazar, 
		Elem3 = Elem.				% Devuelvo la lista con el elemento original. (Condici�n de corte 2)

	reemplazar ([Ca|Co],Elem1,Elem2,[Ca2|Co2]):- 	% Recibo una lista que tomo como Cabeza + Cola
		Ca = Elem1,				% Si la cabeza es el elemento que busco,
		Ca2 = Elem2,				% devuelvo el elemento nuevo como cabeza de la lista a devolver
		reemplazar (Co,Elem1,Elem2,Co2).	% Llamo recursivamente, pero s�lo pas�ndole la cola de la lista original, y me va a devolver el resultado en la cola de la lista nueva.

	reemplazar ([Ca|Co],Elem1,Elem2,[Ca2|Co2]):- 
		Ca <> Elem1,				% Igual que el anterior, pero si no es el que busco
		Ca2 = Ca,				% la cabeza de la lista a devolver, ser� el elemento original (la cabeza de la lista original)
		reemplazar (Co,Elem1,Elem2,Co2).	% Y llamo recursivamente de la misma forma que antes.

	% Ejercicio 4
	ordenar ([],[]).				% Si recibo una lista vac�a, devuelvo una vac�a

	ordenar ([Elem],[Elem]).			% Si tiene s�lo un elemento, ya est� ordenada

	ordenar (L,[Ca|Co]):-
		menor(L,Ca),				% Busco el menor de la lista, y lo pongo como cabeza de la lista ordenada a devolver
		quitar (L,Ca,M),			% Quito de la lista el menor que acabo de encontrar,
		ordenar (M,Co),!.			% y llamo recursivamente, ahora con la lista sin ese elemento, y lo que me devuelve, va a la cola de la lista ordenada a devolver.
							% El ! est� para que detener el backtracking, y evitar que d� m�s resultados, aunque no estoy 100% seguro de por qu� ac� hace falta, ya que no s� cu�ndo dar�a fail ah�.

	% Auxiliares Ejercicio 4 (para la funci�n Menor, uso la del ejercicio 2

	quitar ([],_,[]).				% Si tengo la lista vac�a, no importa el que haya que quitar, devuelvo vac�o (Condici�n de corte)

	quitar ([Ca],Elem,[Ca2]):-			% Si tengo s�lo un elemento,
		Ca <> Elem,				% y no es el que quiero eliminar
		Ca2 = Ca.				% devuelvo lo mismo

	quitar ([Ca|Co],Ca,Co).				% Si tengo s�lo un elemento, y es el que quiero eliminar, devuelvo la cola

	quitar ([Ca|Co],Elem,[Ca2|Co2]):-
		Ca <> Elem,				% Si la cabeza de la lista original, no es el quiero quitar,
		Ca2 = Ca,				% dejo la cabeza y
		quitar (Co,Elem,Co2).			% llamo recursivamente, trabajando con las colas.


	% Ejercicio 5

	adyacentes ([Ca|[Ca1|_]],A,B):-
		Ca = A,					% Si el primer elemento es el primero de los buscados, 
		Ca1 = B.				% Y el segundo, es el otro, termina y devuelve verdadero.

	adyacentes ([Ca|[Ca1|_]],A,B):-
		Ca = B,					% Si el primer elemento es el segundo de los buscados
		Ca1 = A.				% Y el segundo, es el otro, termina y devuelve verdadero.

	adyacentes ([_|[Ca1|Co1]],A,B):-
		adyacentes ([Ca1|Co1],A,B).		% Saco el primer elemento, y pruebo de nuevo.


	% Ejercicio 6

	profundidad ([],N,N).				% Si recibo una lista vac�a, la profundidad hasta ahora, es la que devuelvo

	profundidad ([l(Ca)|Co],N,P):-			% Como el primer elemento es una lista,
		N1 = N+1,				% Sumo 1 a la profundidad actual.
		profundidad (Ca,N1,P1),			% Busco la profundidad de lo que haya dentro de la primera lista
		profundidad (Co,N,P2),			% Busco la profundidad de lo que haya en la cola
		mayor (P1,P2,P).			% Devuelvo el mayor de esos dos llamados

	profundidad ([e(_)|Co],N,P):-			% Si la primera parte de la lista es un elemento,
		profundidad (Co,N,P1),			% Lo ignoro y busco la profundidad de la cola
		mayor (N,P1,P).				% Devuelvo el mayor entre la profundidad hasta ahora (N) y la de la cola (P1)

	% Auxiliares Ejercicio 6

	mayor (X,Y,Z):-	X>Y,Z=X.			% Si X es mayor a Y, devuelvo X
	mayor (X,Y,Z):-	Y>=X,Z=Y.			% Si Y es mayor a X, devuelvo Y

goal

	enteros (10,EnterosAnteriores),

	menor ([51,12,3,4,5],Menor),

	reemplazar ([1,2,3,4,3],3,5,Reemplazado),

	ordenar ([3,2,4,6,2,3,2],Ordenada),
	
%	adyacentes ([3,1,2,2,2,2,1,1,1,1,3,3,3,3,4,8,1,5,3,2],8,1),  % Debe analizarse s�lo, comentando todos los dem�s

	profundidad ([e(a),e(b),l([e(c),e(d),l([e(e),l([e(f),e(g)])]),e(h)]),e(i)],1,Profundidad). % {a,b,[c,d,(e,(f,g)),h],i}

/*****************************************************************************

		Copyright (c) My Company

 Project:  TP1
 FileName: MICRO.PRO
 Purpose: TP
 Written by: Bessone, Alex | Ribotta, Mariano
 Comments:
******************************************************************************/

include "tp1.inc"

domains
	listaGenerica = elemento*
	elemento = s(Symbol);i(Integer)

	listaDeSymbol = Symbol*
	listaDeInteger = Integer*
	estado = estado(Symbol,Integer) % Ciudad, Cantidad de Pasajeros

predicates
	nondeterm recorrido (estado,estado,listaDeSymbol,listaDeInteger,listaDeSymbol,listaGenerica) % Inicial,Final,ListaParadas,ListaPasajeros,Recorrido

	nondeterm avanzar (estado,estado,listaDeSymbol)
	nondeterm peaje (estado)
	nondeterm yaPase (Symbol,listaDeSymbol)
	nondeterm imprimir (listaGenerica)
	nondeterm rutas (Symbol,Symbol)

clauses

% Base de datos global

	peaje (estado("Dolores",_)).
	peaje (estado("Costa Azul",_)).

	rutas ("Capital Federal","Magdalena").
	rutas ("Magdalena","Capital Federal").

	rutas ("Capital Federal","Chascomús").
	rutas ("Chascomús","Capital Federal").

	rutas ("Chascomús","Dolores").
	rutas ("Dolores","Chascomús").

	rutas ("Dolores","Conesa").
	rutas ("Conesa","Dolores").

	rutas ("Dolores","Maipú").
	rutas ("Maipú","Dolores").

	rutas ("Maipú","Mar del Plata").
	rutas ("Mar del Plata","Maipú").

	rutas ("Magdalena","Pipinas").
	rutas ("Pipinas","Magdalena").

	rutas ("Pipinas","Conesa").
	rutas ("Conesa","Pipinas").

	rutas ("Conesa","Costa Azul").
	rutas ("Costa Azul","Conesa").

	rutas ("Conesa","Pinamar").
	rutas ("Pinamar","Conesa").

	rutas ("Costa Azul","Pinamar").
	rutas ("Pinamar","Costa Azul").

	rutas ("Pinamar","Mar del Plata").
	rutas ("Mar del Plata","Pinamar").


% Estrategia de control

	recorrido (estado(Ciudad,0),estado(Ciudad,0),[],[],_,Recorrido) :-
		Recorrido = [s("Frené en"),s(Ciudad),s(". Fin del recorrido.\n")].

	recorrido (estado(Ciudad,N),estado(Ciudad,0),[],[],_,Recorrido) :-
		N<>0,
		Recorrido = [s("Frené en"),s(Ciudad),s(", abrí las puertas,"),s("descargué a las"),i(N),s("personas restantes y"),s("cerré las puertas."),s("Fin del recorrido.\n")].

	recorrido (estado(Ciudad,N),EstadoFinal,[Ciudad|Co1],[P|Co2],CiudadesVisitadas,Recorrido):-
		peaje (estado(Ciudad,N)),
		P1 = N - P,
		avanzar (estado(Ciudad,P1),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,Co1,Co2,[Ciudad|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Frené en"),s(Ciudad),s(", pagué peaje,"),s("abrí las puertas,"),s("descargué"),i(P),s("personas (quedan "),i(P1),s("),"),s("cerré las puertas,"), s("arranqué y"),s("avancé.\n")|Recorrido2].

	recorrido (estado(Ciudad1,N),EstadoFinal,[],[],CiudadesVisitadas,Recorrido):-
		peaje (estado(Ciudad1,N)),
		avanzar (estado(Ciudad1,N),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,[],[],[Ciudad1|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Frené en"),s(Ciudad1),s(", pagué peaje,"),s("arranqué y"),s("avancé.\n")|Recorrido2].

	recorrido (estado(Ciudad1,N),EstadoFinal,[Ciudad2|Co1],ListaPasajeros,CiudadesVisitadas,Recorrido):-
		Ciudad1 <> Ciudad2,
		peaje (estado(Ciudad1,N)),
		avanzar (estado(Ciudad1,N),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,[Ciudad2|Co1],ListaPasajeros,[Ciudad1|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Frené en"),s(Ciudad1),s(", pagué peaje,"),s("arranqué y"),s("avancé.\n")|Recorrido2].


	recorrido (estado(Ciudad,N),EstadoFinal,[Ciudad|Co1],[P|Co2],CiudadesVisitadas,Recorrido):-
		not(peaje (estado(Ciudad,N))),
		P1 = N - P,
		avanzar (estado(Ciudad,P1),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,Co1,Co2,[Ciudad|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Frené en"),s(Ciudad),s(", abrí las puertas,"),s("descargué"),i(P),s("personas (quedan "),i(P1),s(")"),s("cerré las puertas,"), s("arranqué y"),s("avancé.\n")|Recorrido2].


	recorrido (estado(Ciudad,N),EstadoFinal,[],[],CiudadesVisitadas,Recorrido):-
		not(peaje (estado(Ciudad,N))),
		avanzar (estado(Ciudad,N),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,[],[],[Ciudad|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Pasé por"),s(Ciudad),s("\n")|Recorrido2].

	recorrido (estado(Ciudad,N),EstadoFinal,[Ciudad2|Co],ListaPasajeros,CiudadesVisitadas,Recorrido):-
		Ciudad <> Ciudad2,
		not(peaje (estado(Ciudad,N))),
		avanzar (estado(Ciudad,N),Estado,CiudadesVisitadas),
		recorrido (Estado,EstadoFinal,[Ciudad2|Co],ListaPasajeros,[Ciudad|CiudadesVisitadas],Recorrido2),
		Recorrido = [s("Pasé por"),s(Ciudad),s("\n")|Recorrido2].


% Reglas

	avanzar (estado(CiudadInicial,N),estado(CiudadDestino,N),CiudadesVisitadas):-
		rutas (CiudadInicial,PosibleDestino),
		not(yaPase(PosibleDestino,CiudadesVisitadas)),
		CiudadDestino = PosibleDestino.
		

% Auxiliares


	imprimir ([]).

	imprimir ([s(A)|Co]):-
		write (A),
		write (" "),
		imprimir (Co).

	imprimir ([i(A)|Co]):-
		write (A),
		write (" "),
		imprimir (Co).


	yaPase (_,[]) :- fail.

	yaPase (Ciudad,[Ciudad|_]).

	yaPase (Ciudad,[Ca|Co]):-
		Ciudad <> Ca,
		yaPase (Ciudad,Co).

goal

	EstadoInicial = estado("Capital Federal",20),
	EstadoFinal = estado("Pipinas",0),

	recorrido (EstadoInicial,EstadoFinal,["Chascomús","Dolores"],[3,15],[],Recorrido),
	imprimir (Recorrido).

/*
Consideraciones
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	1.- El micro recorre las ciudades en el orden dado en la lista de las paradas.
	2.- El micro no pasa dos veces por la misma ciudad (lo considera un error).
	3.- Devuelve todos los posibles caminos entre las dos ciudades dadas, teniendo en cuenta las paradas.

*/
/*****************************************************************************

		Copyright (c) My Company

 Project:  JARRONES
 FileName: MAIN.PRO
 Purpose: Fill a vase
 Written by: Nosotros
 Comments: Hola
******************************************************************************/

domains
	jarron = jarron(Integer,Integer) /* Capacidad / Cantidad */
	estado = jarron*

predicates
	llenarJarron (jarron,jarron)
	vaciarJarron (jarron,jarron)
	nondeterm pasarDe(jarron,jarron,jarron,jarron) /* desde, hasta, desdeNuevo, hastaNuevo */
	nondeterm resolver (estado,estado,Integer,Symbol).

clauses

/* ESTRATEGIA DE CONTROL (PP) */

	resolver ([jarron (_,CantidadGrande),jarron(_,_)],[jarron (_,CantidadFinal),jarron(_,_)],_,Solucion) :- 
		CantidadGrande = CantidadFinal,
		write (Solucion).

	resolver ([jarron (CapacidadGrande,CantidadGrande),jarron(CapacidadChica,CantidadChica)],X,N,Solucion) :- N>0,CantidadGrande <> 2,
		pasarDe(jarron(CapacidadGrande,CantidadGrande),jarron(CapacidadChica,CantidadChica),JarronGrande,JarronChico),
		concat (Solucion,"Pasé de grande a chico\n",SolucionActualizada),
		N1 = N-1, resolver ([JarronGrande,JarronChico],X,N1,SolucionActualizada).

	resolver ([jarron (CapacidadGrande,CantidadGrande),jarron(CapacidadChica,CantidadChica)],X,N,Solucion) :- N>0,CantidadGrande <> 2,
		pasarDe(jarron(CapacidadChica,CantidadChica),jarron(CapacidadGrande,CantidadGrande),JarronChico,JarronGrande),
		concat (Solucion,"Pasé de chico a grande\n",SolucionActualizada),
		N1 = N-1, resolver ([JarronGrande,JarronChico],X,N1,SolucionActualizada).

	resolver ([jarron (CapacidadGrande,CantidadGrande),JarronChico],X,N,Solucion) :- N>0, CantidadGrande <> 2,
		vaciarJarron(jarron(CapacidadGrande,CantidadGrande),JarronGrande),
		concat (Solucion,"Vacío el grande\n",SolucionActualizada),
		N1 = N-1, resolver ([JarronGrande,JarronChico],X,N1,SolucionActualizada).

	resolver ([jarron (CapacidadGrande,CantidadGrande),jarron(CapacidadChica,CantidadChica)],X,N,Solucion) :- N>0, CantidadGrande <> 2,
		vaciarJarron(jarron(CapacidadChica,CantidadChica),JarronChico),
		concat (Solucion,"Vacío el chico\n",SolucionActualizada),
		N1 = N-1, resolver ([jarron(CapacidadGrande,CantidadGrande),JarronChico],X,N1,SolucionActualizada).

	resolver ([jarron (CapacidadGrande,CantidadGrande),JarronChico],X,N,Solucion) :- N>0, CantidadGrande <> 2,
		llenarJarron(jarron(CapacidadGrande,CantidadGrande),JarronGrande),
		concat (Solucion,"Lleno el grande\n",SolucionActualizada),
		N1 = N-1, resolver ([JarronGrande,JarronChico],X,N1,SolucionActualizada).

	resolver ([jarron (CapacidadGrande,CantidadGrande),jarron(CapacidadChica,CantidadChica)],X,N,Solucion) :- N>0, CantidadGrande <> 2,
		llenarJarron(jarron(CapacidadChica,CantidadChica),JarronChico),
		concat (Solucion,"Lleno el chico\n",SolucionActualizada),
		N1 = N-1, resolver ([jarron(CapacidadGrande,CantidadGrande),JarronChico],X,N1,SolucionActualizada).

/* /ESTRATEGIA DE CONTROL (PP) */

/* REGLAS DE PRODUCCIÓN */

	llenarJarron (jarron(Capacidad,Cantidad),Jarron) :- Capacidad <> Cantidad, Jarron = jarron(Capacidad,Capacidad).
	vaciarJarron (jarron(Capacidad,Cantidad),Jarron) :- Cantidad <> 0, Jarron = jarron(Capacidad,0).

	pasarDe(jarron(CapacidadDesde,CantidadDesde),jarron(CapacidadHasta,CantidadHasta),JarronDesde,JarronHasta) :- CantidadDesde <> 0, CantidadHasta <> CapacidadHasta,
		Falta = CapacidadHasta - CantidadHasta, Falta = 0, JarronDesde = jarron (CapacidadDesde,CantidadDesde), JarronHasta = jarron (CapacidadHasta,CantidadHasta).

	pasarDe(jarron(CapacidadDesde,CantidadDesde),jarron(CapacidadHasta,CantidadHasta),JarronDesde,JarronHasta) :- CantidadDesde <> 0, CantidadHasta <> CapacidadHasta,
		Falta = CapacidadHasta - CantidadHasta, Falta >= CantidadDesde, JarronDesde = jarron (CapacidadDesde,0), M = CantidadHasta + CantidadDesde, JarronHasta = jarron (CapacidadHasta,M).

	pasarDe(jarron(CapacidadDesde,CantidadDesde),jarron(CapacidadHasta,CantidadHasta),JarronDesde,JarronHasta) :- CantidadDesde <> 0, CantidadHasta <> CapacidadHasta,
		Falta = CapacidadHasta - CantidadHasta, Falta <> 0, Falta < CantidadDesde, N = CantidadDesde-Falta, JarronDesde = jarron (CapacidadDesde,N), JarronHasta = jarron (CapacidadHasta,CapacidadHasta).

/* /REGLAS DE PRODUCCIÓN */

goal
	Inicial = [jarron(4,0),jarron(3,0)],
	Final = [jarron(4,2),jarron(3,0)],

	resolver (Inicial,Final,10,"Solución:\n¯¯¯¯¯¯¯¯\n").	

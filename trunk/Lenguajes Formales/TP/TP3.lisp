(defun mascorto (lista &optional (menor nil))
	(if (null lista) menor
		(if (null menor) (mascorto (cdr lista) (car lista))
			(if ( < (length (car lista))(length menor))
				(mascorto (cdr lista) (car lista))
				(mascorto (cdr lista) menor)
			)
		)
	)
)

(defun maslargo (lista &optional (mayor nil))
	(if (null lista) mayor
		(if (null mayor) (maslargo (cdr lista) (car lista))
			(if ( > (length (car lista))(length mayor))
				(maslargo (cdr lista) (car lista))
				(maslargo (cdr lista) mayor)
			)
		)
	)
)

(defun devolverCortoLargoTodos (lista)
	(append
		(list 'Mas 'Corto)
		(list (mascorto lista))
		(list 'Mas 'Largo)
		(list (maslargo lista))
		(list 'Todos)
		lista
	)
)

(defun darvuelta (lista)
	(if (null lista) nil
		(append (darvuelta(cdr lista)) (list (car lista)))
	)
)

(defun GPS (i f)
	(devolverCortoLargoTodos (mapcar 'darvuelta (GPSaux i f (list (list i))) ))
)

(defun GPSaux (i f &optional (caminos (list (list i))))
	(if (null caminos) nil
		(if (eq (caar caminos) f)
			(append (list (car caminos)) (gpsaux i f (cdr caminos)))
			(gpsaux i f (append
							(mapcar
								'(lambda (x) (cons x (car caminos)))
								(diferencia (vecinos (caar caminos) grafo) (car caminos))
							)
							(cdr caminos)
					 )
			)
		)
	)
)

(defun pertenece (elem lista)
	(if (null lista) nil
		(if (eq elem (car lista))
			T
			(pertenece elem (cdr lista))
		)
	)
)		

(defun diferencia (lista1 lista2)
	(if (null lista1) nil
		(if (pertenece (car lista1) lista2)
			(diferencia (cdr lista1) lista2)
			(append (list (car lista1)) (diferencia (cdr lista1) lista2))
		)
	)
)

(defun vecinos (elem grafo) 

	(if (null grafo) nil
		(if (eq elem (caar grafo))
			(cadar grafo)
			(vecinos elem (cdr grafo))
		)
	)
)

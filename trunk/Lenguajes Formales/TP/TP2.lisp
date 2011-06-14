(defun eliminarposiciones (coordenada tab)
	(if (null coordenada)
		tab
		(eliminarposiciones
			(cdr coordenada)
			(eliminarnulos (elimfilcoldiagtodoslospares (car coordenada) tab))
		)
	)
)

(defun eliminarnulos (lista)
	(if (null lista) nil
		(if (null (car lista)) (eliminarnulos (cdr lista))
			(append (list (car lista)) (eliminarnulos (cdr lista)))
		)
	)
)

(defun elimfilcoldiagtodoslospares (coordenada tab)
	(if (null tab) nil
		(append
			(list (elimaux coordenada (car tab)))
			(elimfilcoldiagtodoslospares coordenada (cdr tab))
		)
	)
)

(defun elimaux (coordenada fila)
	(if (null fila) nil
		(if (OR
			(eq (caar fila) (car coordenada))
			(eq (cadar fila) (cadr coordenada))
			(eq (- (caar fila) (cadar fila)) (- (car coordenada) (cadr coordenada)))
			(eq (+ (caar fila) (cadar fila)) (+ (car coordenada) (cadr coordenada)))
			)
			(elimaux coordenada (cdr fila))
			(append (list (car fila)) (elimaux coordenada (cdr fila) ))
		)
	)
)

(defun tablero (n &optional(i '1))

	(if (> i n) nil
		(append (list (armarfila i n)) (tablero n (+ i 1)))
	)
)

(defun armarfila (i n &optional(j 1))
	(if (> j n) nil
		(append (list (list i j)) (armarfila i n (+ j 1)))
	)
)

(defun reinasaux (n posreinas)
	(reinas n posreinas
		(eliminarposiciones
			(eliminarnulos(mapcar 'car posreinas))
			(tablero n)
		)
	)
)

(defun darvuelta (lista)
	(if (null lista) nil
		(append (darvuelta(cdr lista)) (list (car lista)))
	)
)

(defun reinas (n &optional
		(posreinas (list (car (tablero n) ) ) )
		(tab (eliminarposiciones 
				(list (caar posreinas) )
				(tablero n)
			)
		)
	)

	(if (eq (length posreinas) n) (darvuelta(mapcar 'car posreinas))
		(if (< (length posreinas) (caaar posreinas))
			(reinasaux n (buscarlong2omas posreinas))
			(if (null tab)
				(reinasaux n (buscarlong2omas posreinas))
				(reinas
					n
					(cons (car tab) posreinas)
					(eliminarposiciones (list (caar tab)) tab)
				)
			)
		)
	)
)

(defun buscarlong2omas (posreinas)
	(if (null posreinas)
		nil
		(if (> (length (car posreinas)) '1)
			(cons (cdar posreinas) (cdr posreinas))
			(buscarlong2omas (cdr posreinas))
		)
	)
)

(defun reinasaux (n posreinas)
	(reinas n (cons (cdar posreinas) (cdr posreinas))
		(eliminarposiciones
			(cons (cadar posreinas) (mapcar 'car (cdr posreinas)))
			(tablero n)
		)
	)
)

(defun patternmat (P E &optional (L nil))
	(if (eq L 'nomatchea)
		'nomatchea
		(if (esvar P)
			(verif P (buscar P L) E L)
			(if (atom P)
				(if (eq P E)
					L
					'nomatchea
				)
				(patternmat (cdr P) (cdr E) (patternmat (car P) (car E) L) )
			)
		)
	)
)

; Si no hay asociación, devuelve (P E L)
; P
; asoc es un átomo, que puede ser un valor, o el string 'nohayasoc 
; E
; L
(defun verif (p asoc e L)
	(if (eq asoc 'nohayasoc)
		(append (list p e) L)
		(if (equal asoc e)
			L
			'nomatchea
		)
	)
)

; Busca si hay un valor asociado, si no lo hay, entonces no es variable
(defun esvar (V)
	(if (atom v)
		nil
		(eq (car v) '%)
	)
)

; Busca la variable V, en la lista L.
; Si la encuentra, devuelve su valor asociado
; Si no la encuentra, devuelve 'nohayasoc
; V es un atomo
; L es lista de la forma (variable1 valor1 variable2 valor2)
(defun buscar (V L)
	(if (null L)
		'nohayasoc
		(if (equal V (car L))
			(cadr L)
			(buscar V (cddr L))
		)
	)
)

; Supone que no hay redeclaraciones
(defun agregarmem (linea mem)
	(if (eq(length linea) 1)
		(append mem (list (nth 0 linea) 0))
		(append mem (list (nth 0 linea) (nth 2 linea)))
	)
)

; Busca 'variable' en 'mem' y modifica su valor por 'valor'
; Supone que existe
(defun modifmem (variable valor mem)
	(if (null mem)
		nil
		(if (eq (car mem) variable)
			(append (list variable valor) (cddr mem))
			(append (list (car mem)(cadr mem))(modifmem variable valor (cddr mem)))
		)
	)
)

(defun run (prg ent &optional (mem nil))
	(if (null prg) nil
		(if (eq (caar prg) 'int)
			(run (cdr prg) ent (agregarmem (cdar prg) mem))
			(if (eq (caar prg) 'main) (ejec (cadar prg) ent mem)
				'error
			)
		)
	)
)
	
(defun buscar (variable mem)
	(if (null mem)
		nil
		(if (eq (car mem) variable)
			(cadr mem)
			(buscar variable (cddr mem))
		)
	)
)

(defun esasignacion (L mem)
	(if (esvariable (car L) mem) T
		(OR (eq (car L) '++)(eq (car L) '--))
	)
)
			
(defun esvariable (A mem)
	(not (null (buscar A mem) ) )
)
;Pasa las variables a su valor
(defun operacionaux (cuenta mem)
	(if (null cuenta)
		nil
		(if (esvariable (car cuenta) mem)
			(append (list (buscar (car cuenta) mem)) (operacionaux (cdr cuenta) mem))
			(append (list (car cuenta)) (operacionaux (cdr cuenta) mem))
		)
	)
)

(defun peso (op)
	(case op
		((+ -) 1)
		((* /) 2)
		((> >= < <= =) 0)
	)
)

(defun operacion (cuenta &optional (op nil) (var nil))
	(if (and (null cuenta)(null op))
		(eval (car var))
		(if (null cuenta)
			(operacion
				cuenta
				(cdr op)
				(append (cddr var) (list (list (car op) (nth 1 var)(nth 0 var))))
			)
			
			(if (numberp (car cuenta))
				(operacion
					(cdr cuenta)
					op
					(append (list (car cuenta)) var)
				)
				(if (listp (car cuenta))
				(operacion
					(append (list (operacion (car cuenta)))(cdr cuenta))
					op
					var
				)
					(if (or (null op)(>(peso (car cuenta))(peso (car op))))
						(operacion
							(cdr cuenta)
							(append (list (car cuenta)) op)
							var
						)
						(operacion
							(cdr cuenta)
							(append (list (car cuenta)) (cdr op))
							(append (cddr var) (list (list (car op) (nth 1 var)(nth 0 var))))
						)
					)
				)
			)
		)
	)	
)

; Dada una expresion, devuelve el valor, puede haber cuentas, ser un numero o variable, etc.
(defun evaluar (prg mem)
	(if (null prg)
		nil
		(if (listp prg)
			(operacion (operacionaux prg mem))
			(if (esvariable prg mem)
				(buscar prg mem)
				prg
			)
		)
	)
)

(defun ejec (prg ent mem &optional (sal nil))
	(if (null prg) sal
		(cond
			(
				(eq (caar prg) 'scanf)
					(ejec
						(cdr prg)
						(cdr ent) ; Porque ya leí el primer elemento
						(modifmem (cadar prg) (car ent) mem)
						sal
					)
			)
			(
				(eq (caar prg) 'printf)
					(ejec
						(cdr prg)
						ent
						mem
						(append sal (list (evaluar (cadar prg) mem)))
					)
			)
			(
				(esasignacion (car prg) mem)
					(ejec
						(cdr prg)
						ent
						(asignacion (car prg) mem)
						sal
					)
			)
			(
				(eq (caar prg) 'if)
					(if (evaluar (cadar prg) mem)
						(ejec
							(append (nth 2 (car prg))(cdr prg))
							ent
							mem
							sal
						)
						(if (eq (length (car prg)) 5) ; Quiere decir que hay else
							(ejec
								(append (nth 4 (car prg))(cdr prg))
								ent
								mem
								sal
							)
							(ejec
								(cdr prg)
								ent
								mem
								sal
							)
						)
					)
			)
			(
				(eq (caar prg) 'while)
					(if (not (evaluar (cadar prg) mem))
						(ejec
							(cdr prg)
							ent
							mem
							sal
						)
						(ejec
							(append (nth 2 (car prg)) prg)
							ent
							mem
							sal
						)
					)
			)
		)
	)
)

(defun asignacion (L mem)
	(if (not (esvariable (car L) mem))
		(asignacion (reverse L) mem) ; ++v o --v
		(if (eq (nth 1 L) '=)
			(modifmem (car L) (evaluar (nth 2 L) mem) mem)
			(if (eq (nth 1 L) '++)
				(asignacion (list (car L) '= (list (car L) '+ '1)) mem)
				(if (eq (nth 1 L) '--)
					(asignacion (list (car L) '= (list (car L) '- '1)) mem)
					(asignacion (list (car L) '= (list (car L) (nth 1 L) (nth 3 L))) mem) ; v *= 2 -> v = v*2
				)
			)
		)
	)
)

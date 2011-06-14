/*******************************************************************************************/
/*	Author: 	An�bal Lovaglio												*/
/*	Date:		21/03/2008												*/
/*	Comments:	Ejercicio de ANSI C. Tipo de Dato Abstracto "Variable Array".				*/
/*			Emulador de vector de tama�o variable gen�rico.							*/
/*			Soporta agregados, modificaciones y eliminaciones, adem�s de acceso por posici�n	*/
/*			como cualquier vector. Tambi�n puede entregar una copia del vector con el tama�o	*/
/*			exacto requerido para que se lo manipule externamente.						*/
/*******************************************************************************************/

#include <string.h>
#include <stdlib.h>

#ifndef _VAR_ARRAY_H_
#define _VAR_ARRAY_H_

/* Definici�n de la estructura del TDA
	Campos:	array (void*): 	puntero con el que mantengo los datos almacenados, es decir, el vector
			a_size (int):	Capacidad reservada con la que cuenta el vector en cantidad de lugares p/elementos
			a_count(int):	Cantidad de elementos almacenados (Posiciones ocupadas)
			e_size(int):		Tama�o en bytes de los elementos del vector
*/
typedef struct Var_Array{
    void* array;
    int a_size, a_count, e_size;
}V_Array;

/***********************************************************************************************
	Inicializa l estructura, los contadores, y pide la primer tanda de memoria para comenzar.
	Arranca con lugar para 10 elementos, a partir de all�, duplicar� su tama�o cada vez que necesite m�s lugar
	Devolver� 0 si todo anduvo bien, o -1 si no pudo alocar la memoria para los primeros 10 elementos
************************************************************************************************/
int		VA_create	(V_Array* a, int elemsize);

/***********************************************************************************************
	Devuelve la cantidad de elementos que tiene ocupados el vector
	Espera que la estructura haya sido creada (Precondici�n)
************************************************************************************************/
int		VA_count	(V_Array a);

/***********************************************************************************************
	Agrega al final del vector un nuevo elemento recibido en elem		(append)
	Espera que la estructura haya sido creada (Precondici�n)
************************************************************************************************/
int		VA_add		(V_Array* a, void* elem);

/***********************************************************************************************
	Obtiene el i�simo elemento del vector, siempre que exista.
	Espera que la estructura haya sido creada (Precondici�n)
	Si est� vac�a o se pide un elemento fuera de los que hay, devuelve el error -1
************************************************************************************************/
int		VA_get_i	(V_Array a, int epos, void* elem);

/***********************************************************************************************
	Entrega una copia del vector completo con el tama�o exacto. Espera que la estructura haya sido inicializada.
	Cuidado: Devuelve una direcci�n de memoria que se aloc� dentro de la funci�n, pero es externa e independiente
	de la estructura del TDA y debe liberarse externamente.
************************************************************************************************/
void* 	VA_get		(V_Array* a);

/***********************************************************************************************
	Modifica un elemento del vector, a la posici�n que se indica en epos. Espera estructura creada
************************************************************************************************/
int		VA_set		(V_Array* a, int epos, void* elem);

/***********************************************************************************************
	Quita el i�simo elemento del vector. Devuelve lo mismo que VA_get_i
************************************************************************************************/
int		VA_remove	(V_Array* a, int epos);

/***********************************************************************************************
	Libera todos los recursos consumidos por la estructura. Debe estar creada.
************************************************************************************************/
void	VA_destroy	(V_Array* a);


#endif /* _VAR_ARRAY_H_*/

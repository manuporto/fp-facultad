#ifndef __TIN_INCIDENCIA_H__
#define __TIN_INCIDENCIA_H__

#include <stdio.h>
#include <stdlib.h>
#include "COLA.h"
#include "PILA.h"
#include <string.h>
#include "LISTASIMPLE.h"
#include "constantes.h"
/*#include "cmemdbg.h"*/

typedef enum { TIN_BUG, TIN_IMPRO, TIN_TASK, TIN_NEWFUNC} tipo_inci_t;
typedef enum { TIN_NONE=-1, TIN_FIXED=0, TIN_DONT_FIX, TIN_INCOMPLETE} resol_inci_t;
typedef enum { TIN_OPEN, TIN_PROGRESS, TIN_RESOLVED, TIN_REOPEN, TIN_CLOSED} stat_inci_t;
typedef enum { TIN_BLOCKING, TIN_CRITICAL, TIN_MAJOR, TIN_MINOR, TIN_TRIVIAL} prior_inci_t;


typedef struct{
    char* comm_date; /* fecha en la que se realiza el comentario*/
    int comm_user_id; /* ID del usuario que realiza el comentario*/
    char* comm_desc; /* Comentario*/
}inci_comment_t;


typedef struct{
    char* stat_date; /* Fecha en la que se cambio el estado*/
    int stat_user_id; /* Usuario que cambio el estado*/
    stat_inci_t stat_desc; /* Estado*/
}inci_status_t;


typedef struct{
    int inci_id; /* ID de la incidencia */
    tipo_inci_t inci_type; /* Tipo de incidencia*/
    prior_inci_t inci_priority; /* Prioridad de la incidencia*/
    int inci_user; /* ID del usuario que creo la incidencia*/
    int inci_assigned_user; /* ID del usuario al que se le asigno */
    char* inci_date_created;
    int inci_project_id;
    char* inci_summary;
    char* inci_description;
    resol_inci_t inci_resolved;
    char* inci_date_solved;
    TPila inci_stat_hist; /* historial de estados */
    TCola inci_comm; /* comentarios de la incidencia */
}TIN;


/*
---------------------------------------------------------------------------
INICIO DE PRIMITIVAS
---------------------------------------------------------------------------
*/

void TIN_CrearVacio (TIN *tin);

/*
FUNCIÓN: Crea una incidencia.

PRE: tin tiene suficiente memoria reservada para una estructura de tipo TIN.

POST: Si pudo crear la incidencia devuelve 0. Si hubo algún error devuelve -1.

PARÁMETROS: tin (Manipulador de la incidencia.)
            inci_id
            inci_type
            inci_priority
            inci_user
            inci_assigned_user
            inci_date_created
            inci_project_id
            inci_summary
            inci_description
*/

int TIN_Crear ( TIN* tin, int inci_id, tipo_inci_t inci_type, prior_inci_t inci_priority, int
inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char*
inci_summary, char* inci_description);


/*
FUNCIÓN: Libera la incidencia tin.

PRE: tin creado.

POST: Si devuelve 0, estructuras de control eliminadas y tin eliminada.
      Si devuelve-1 ocurrió algún error.

PARÁMETROS: Tin (Manipulador de la incidencia.)
*/

int TIN_Liberar( TIN* tin);


/*
FUNCIÓN: Registra un cambio de estado para la incidencia.

PRE: tin creado.

POST: Si devuelve 0, estado actualizado.
      Si devuelve -1 ocurrió algún error.

PARÁMETROS: tin (Manipulador de la incidencia.)
            fecha (Fecha en la que se realiza el cambio de estado)
            Usuario (Usuario que registra el cambio de estado)
            estado (Estado)
*/

int TIN_CambiarEstado( TIN* tin, char* fecha, int usuario, stat_inci_t estado);


/*
FUNCIÓN: Registra la resolucion de la incidencia, y pasa el estado de la misma a
         Resuelta (TIN_RESOLVED).

PRE: tin creado.

POST: Si devuelve 0, incidencia resuelta. Si devuelve
      -1 ocurrió algún error.

PARÁMETROS: tin (Manipulador de la incidencia.)
            fecha (Fecha en la que se resolvio la incidencia)
            Usuario (Usuario que registra la resolucion)
            resolucion (Tipo de resolucion)
*/

int TIN_Resolver( TIN* tin, char* fecha, int usuario, resol_inci_t resolucion, int cargaManual);


/*
FUNCIÓN: Registra un comentario para la incidencia.

PRE: tin abierto.

POST: Comentario registrado. Devuelve -1 si ocurrió algún error.

PARÁMETROS: tin (Manipulador de la incidencia.)
            fecha (Fecha en la que se realiza el comentario)
            Usuario (Usuario que registra el comentario)
            Comentario (Comentario de la incidencia.)

*/

int TIN_Comentar( TIN* tin, char* fecha, int usuario, char* comentario);


/*
FUNCIÓN: Obtiene los datos de una incidencia.

PRE:

POST: Si pudo obtener los datos devuelve 0. Si hubo algún error devuelve -1.

PARÁMETROS: tin (Manipulador de la incidencia.)
            inci_id
            inci_type
            inci_priority
            inci_user
            inci_assigned_user
            inci_date_created
            inci_project_id
            inci_summary
            inci_description
*/

int TIN_GetDatos ( TIN* tin, int* inci_id, tipo_inci_t* inci_type, prior_inci_t*
inci_priority, int* inci_user, int* inci_assigned_user, char** inci_date_created, int*
inci_project_id, char** inci_summary, char** inci_description,resol_inci_t* inci_resolved, char** inci_date_solved);

/*
FUNCIÓN: Lee el comentario, usuario y la fecha de todos los comentarios de la
         incidencia.

PRE: tin abierto. Comentarios apunta a una lista simple creada y vacía para
     contener objetos de tipo inci_comment_t

POST: Si devuelve 0 devolvió en comentarios una lista de objetos
      inci_comment_t con los datos de cada uno de los comentarios de la
      incidencia. La memoria reservada para los strings debe ser liberada por el
      invocador. Si devuelve -1 ocurrió un error y la lista permanece inalterada.

PARÁMETROS: tin (Manipulador de la incidencia.)
            comentarios (Lista donde se guardará la información de los comentarios.)

NOTA: En el enunciado pedía una lista, sin embargo siempre se necesitan listar todos los comentarios a la vez, por lo que es conveniente una Cola.
*/

int TIN_GetComentarios(TIN* tin, TCola* comentarios);

/*
FUNCIÓN: Lee el estado, usuario y la fecha de todos los cambios de estado de la
         incidencia.

PRE: tin abierto. Estados apunta a una lista simple creada y vacía para
     contener objetos de tipo inci_status_t.

POST: Si devuelve 0 devolvió en estados una lista de objetos inci_status_t
      con los datos de cada uno de los estados de la incidencia. La memoria
      reservada para los strings debe ser liberada por el invocador. Si devuelve -1
      ocurrió un error y la lista permanece inalterada.

PARÁMETROS: tin (Manipulador de la incidencia.)
            estados (Lista donde se guardará la información de los estados.)
NOTA: En el enunciado pedía una lista, sin embargo siempre se necesitan listar todos los estados a la vez, por lo que es conveniente una Cola.

*/

int TIN_GetEstados(TIN* tin, TPila* estados);



#endif /* __TIN_INCIDENCIA_H___ */

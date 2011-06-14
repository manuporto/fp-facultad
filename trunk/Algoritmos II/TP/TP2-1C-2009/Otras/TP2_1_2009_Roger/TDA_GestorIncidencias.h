#ifndef __TGI_GESTORINCIDENCIAS_H__
#define __TGI_GESTORINCIDENCIAS_H__

#include <stdio.h>
#include <stdlib.h>
#include "TDA_Incidencia.h"

typedef struct user_t{
    int user_id;
    char* user_name;
}user_t;

typedef struct project_t{
    int project_id;
    char* project_name;
}project_t;

typedef struct{
    TListaSimple incidencias;
    TListaSimple proyectos;
    TListaSimple usuarios;
}TGI;


/*
---------------------------------------------------------------------------
INICIO DE PRIMITIVAS
---------------------------------------------------------------------------
*/

/*
FUNCI�N: Crea un gestor de incidencias.

PRE: tgi tiene suficiente memoria reservada para una estructura de tipo TGI.
     Proyectos es la ruta al archivo de proyectos, alocada y terminada en \0.
     Usuarios es la ruta al archivo de proyectos, alocada y terminada en \0.

POST: Si el archivo existe y est� versionado, lo abre y devuelve 0. Si el archivo
      existe y no est� versionado, inicializa la funcionalidad de versionado y
      devuelve 1. Si hubo alg�n error devuelve -1.

PAR�METROS: tgi (Manipulador del gestor de incidencias.)
            ruta (Ruta al archivo a abrir.)
*/

int TGI_Crear ( TGI* tgi, const char* proyectos, const char* usuarios);


/*
FUNCI�N: Cierra el gestor tgi.

PRE: tgi creado.

POST: Si devuelve 0, gestor cerrado. Si devuelve -1 ocurri� alg�n error.

PAR�METROS: tgi (Manipulador del gestor de incidencias.)
*/

int TGI_Cerrar( TGI* tgi);


/*
FUNCI�N: Agrega una incidencia en el gestor de incidencias.

PRE: tgi creado.

POST: Devuelve el ID de la incidencia creada si no hubo error. Si devuelve -1 no
      existe el ID del proyecto. Si devuelve �2 no existe el id del usuario. Si
      devuelve �3 ocurri� otro error.

PAR�METROS: tgi (El manipulador del gestor de incidencias.)
*/

int TIN_AgregarIncidencia (const TGI* tgi, tipo_inci_t inci_type, prior_inci_t inci_priority,
int inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char*
inci_summary, char* inci_description);


/*
FUNCI�N: Recupera los datos de una incidencia del gestor de incidencias.

PRE: tgi creado. tin tiene memoria reservada para una estructura de tipo TIN.

POST: Si devuelve 0 devolvi� en tin la incidencia. La memoria de los strings debe
      ser liberada por el invocador. Si devuelve -1 no existe la incidencia inci. Si
      devuelve -2 ocurri� otro error.

PAR�METROS: tgi (El manipulador del gestor de incidencias.)
            inci (El Id de la incidencia que se desea consultar.)
            tin (Estructura donde se guardar� la informaci�n de la incidencia.)
*/

int TIN_GetIncidencia( const TGI* tgi, int inci, TIN* tin);


/*
FUNCI�N: Lee las incidencias asignadas a un usuario.

PRE: tgi creado. incidencias apunta a una cola creada y vac�a para contener
     objetos de tipo TIN.

POST: Si devuelve 0 devolvi� en incidencias las incidencias del usuario. La
      memoria de los strings debe ser liberada por el invocador. Si devuelve -1 no
      existen incidencias para el usuario. Si devuelve -2 ocurri� otro error.

PAR�METROS: tgi (El manipulador del gestor de incidencias.)
            usuario (El ID del usuario para quien se desean consultar las incidencias.)
            incidencias (Cola donde se guardar� la informaci�n de las incidencias.)
*/

int TIN_GetIncidenciasUsuario( const TGI* tgi, int usuario, TCola* incidencias);


/*
FUNCI�N: Lee las incidencias pertenecientes a un proyecto.

PRE: tgi creado. incidencias apunta a una cola creada y vac�a para contener
     objetos de tipo TIN.

POST: Si devuelve 0 devolvi� en incidencias las incidencias del usuario. La
      memoria de los strings debe ser liberada por el invocador. Si devuelve -1 no
      existen incidencias para el usuario. Si devuelve -2 ocurri� otro error.

PAR�METROS: tgi (El manipulador del gestor de incidencias.)
            proyecto (El ID del proyecto para quien se desean consultar las incidencias.)
            incidencias (Lista donde se guardar� la informaci�n de las incidencias.)
*/

int TIN_GetIncidenciasProyecto( const TGI* tgi, int proyecto, TListaSimple* incidencias);



/*
FUNCI�N: Agrega un usuario.

PRE:

POST: Agrega un usuario al archivo.
      Devuelve 1 si pudo agregar al usuario exitosamente.
      Devuelve 0 si no pudo agregarlo con �xito.

PAR�METROS: TGI
            user_id (id del usuario)
            user_name (nombre del usuario)
            archUsuario (ruta del archivo de usuarios)
*/

int AgregarUsuario(TGI *tgi,char *archUsuario, int user_id, char* user_name);

/*
FUNCI�N: Agrega un usuario.

PRE:

POST: Agrega un usuario al archivo.
      Devuelve 1 si pudo agregar al usuario exitosamente.
      Devuelve 0 si no pudo agregarlo con �xito.

PAR�METROS: TGI
            project_id (id del projecto)
            project_name (nombre del projecto)

*/

int AgregarProyecto(TGI *tgi,char *archProyecto, int project_id, char* project_name);

#endif /* __TGI_GESTORINCIDENCIAS_H__ */

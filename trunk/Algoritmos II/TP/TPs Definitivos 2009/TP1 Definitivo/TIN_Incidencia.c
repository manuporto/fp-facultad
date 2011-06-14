#include "TIN_Incidencia.h"

/**
@function
@name TIN_CrearVacio
@description Crea la pila y la cola necesarias para almacenar los estados y los comentarios de una incidencia.
@return void
@param tin:TIN*
@author Batman
@see -
*/
void TIN_CrearVacio (TIN *tin)
{
    P_Crear (&(tin->inci_stat_hist),sizeof(inci_status_t));
    C_Crear (&(tin->inci_comm),sizeof(inci_comment_t));
}

/**
@function
@name TIN_Crear
@description Recibe todos los elementos de una incidencia y arma un elemento del tipo TIN que recibe por parámetro.
@return int
@param tin:TIN*
@param inci_id:int
@param inci_type:tipo_inci_t
@param inci_priority:prior_inci_t
@param inci_user:int
@param inci_assigned_user:int
@param inci_date_created:char*
@param inci_project_id:int
@param inci_summary:char*
@param inci_description:char*
@author Batman
@see -
*/
int TIN_Crear ( TIN* tin, int inci_id, tipo_inci_t inci_type, prior_inci_t inci_priority, int
inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char*
inci_summary, char* inci_description){

    tin->inci_id = inci_id;
    tin->inci_type = inci_type;
    tin->inci_priority = inci_priority;
    tin->inci_user = inci_user;
    tin->inci_assigned_user = inci_assigned_user;
    tin->inci_date_created = inci_date_created;
    tin->inci_project_id = inci_project_id;
    tin->inci_summary = inci_summary;
    tin->inci_description = inci_description;

    /* Seteamos el estado de resuelto, a incompleto por defecto */
    tin->inci_resolved = TIN_NONE;

    tin->inci_date_solved = (char*)malloc(sizeof(char)*(strlen(inci_date_created)+1));
    strcpy(tin->inci_date_solved,inci_date_created);

    /* Creamos la pila */
    P_Crear (&(tin->inci_stat_hist),sizeof(inci_status_t));

    C_Crear (&(tin->inci_comm),sizeof(inci_comment_t));
    return RES_OK;
}

/**
@function
@name TIN_Liberar
@description Elimina y libera todas las estructuras que forman parte del TIN.
@return int
@param tin:TIN*
@author Batman
@see -
*/
int TIN_Liberar( TIN* tin){

    int sacar = 10;

    inci_status_t statusaux;
    inci_comment_t commaux;

    free (tin->inci_date_created);
    tin->inci_date_created = NULL;
    free (tin->inci_summary);
    tin->inci_summary = NULL;

    free (tin->inci_description);
    tin->inci_description = NULL;

    free (tin->inci_date_solved);
    tin->inci_date_solved = NULL;

    while (!P_Vacia(tin->inci_stat_hist))
    {
        sacar = P_Sacar(&(tin->inci_stat_hist),&statusaux);
        free (statusaux.stat_date);
        statusaux.stat_date= NULL;
    }

    while (!C_Vacia(tin->inci_comm))
    {
        C_Sacar(&(tin->inci_comm),&commaux);
        free (commaux.comm_date);
        commaux.comm_date= NULL;
        free (commaux.comm_desc);
        commaux.comm_desc= NULL;
    }
    C_Vaciar(&(tin->inci_comm));
    return RES_OK;
}

/**
@function
@name TIN_Comentar
@description Ingresa un comentario a la cola de comentarios del TIN
@return int
@param tin:TIN*
@param fecha:char*
@param usuario:int
@param comentario:char*
@author Batman
@see -
*/
int TIN_Comentar( TIN* tin, char* fecha, int usuario, char* comentario)
{
    inci_comment_t commAux;

    commAux.comm_date = fecha;
    commAux.comm_desc = comentario;
    commAux.comm_user_id = usuario;

    if (C_Agregar(&(tin->inci_comm),&commAux) == FALSE) return RES_ERR;
    else return RES_OK;
}

/**
@function
@name TIN_CambiarEstado
@description Agrega un estado a la pila de estados, determinándolo como el estado actual de la incidencia.
@return int
@param tin:TIN*
@param fecha:char*
@param usuario:int
@param estado:stat_inci_t
@author Batman
@see -
*/
int TIN_CambiarEstado( TIN* tin, char* fecha, int usuario, stat_inci_t estado)
{

    inci_status_t statusaux;

    statusaux.stat_date=(char*)malloc(sizeof(char)*(strlen(fecha)+1));
    strcpy(statusaux.stat_date,fecha);
    statusaux.stat_desc = estado;
    statusaux.stat_user_id = usuario;
    if (P_Agregar(&(tin->inci_stat_hist),&statusaux) == FALSE) return RES_ERR;
    else return RES_OK;
}


/**
@function
@name TIN_Resolver
@description Cambia el estado de resolución de una incidencia y agrega dicho estado a la pila correspondiente.
@return int
@param tin:TIN*
@param fecha:char*
@param usuario:int
@param resolucion:resol_inci_t
@param cargaManual:int
@author Batman
@see -
*/
int TIN_Resolver( TIN* tin, char* fecha, int usuario, resol_inci_t resolucion, int cargaManual){

    inci_status_t statusaux;

    if (tin->inci_assigned_user != usuario) return RES_ERR; /* Sólo puede resolverlo el usuario asignado */
    else
    {
        tin->inci_resolved = resolucion;
        tin->inci_date_solved=(char*)malloc(sizeof(char)*(strlen(fecha)+1));
        strcpy(tin->inci_date_solved,fecha);

        if (cargaManual) /*Si la carga es manual, agrego el estado, si es automática, ya viene cargado */
        {
            statusaux.stat_date=(char*)malloc(sizeof(char)*(strlen(fecha)+1));
            strcpy(statusaux.stat_date,fecha);
            statusaux.stat_desc = TIN_RESOLVED;
            statusaux.stat_user_id = usuario;
            if (P_Agregar(&(tin->inci_stat_hist),&statusaux) == FALSE) return ERR_MEM;
        }
    }
    return RES_OK;
}


/**
@function
@name TIN_GetDatos
@description Obtiene los datos de una incidencia y los devuelve en variables separadas.
@return int
@param tin:TIN*
@param inci_id:int*
@param inci_type:tipo_inci_t*
@param inci_priority:prior_inci_t*
@param inci_user:int*
@param inci_assigned_user:int*
@param inci_date_created:char**
@param inci_project_id:int*
@param inci_summary:char**
@param inci_description:char**
@param inci_resolved:resol_inci_t*
@param inci_date_solved:char**
@author Batman
@see -
*/
int TIN_GetDatos ( TIN* tin, int* inci_id, tipo_inci_t* inci_type, prior_inci_t*
inci_priority, int* inci_user, int* inci_assigned_user, char** inci_date_created, int*
inci_project_id, char** inci_summary, char** inci_description,resol_inci_t* inci_resolved, char** inci_date_solved){

    *inci_id = tin->inci_id;
    *inci_type = tin->inci_type;
    *inci_priority = tin->inci_priority;
    *inci_user = tin->inci_user;
    *inci_assigned_user = tin->inci_assigned_user;
    *inci_date_created = tin->inci_date_created;
    *inci_project_id = tin->inci_project_id;
    *inci_summary = tin->inci_summary;
    *inci_description = tin->inci_description;
    *inci_resolved = tin->inci_resolved;
    *inci_date_solved = tin->inci_date_solved;
    return RES_OK;
}


/**
@function
@name TIN_GetComentarios
@description Obtiene todos los comentarios de una incidencia y los devuelve en una cola
@return int
@param tin:TIN*
@param comentarios:TCola*
@author Batman
@see -
*/
int TIN_GetComentarios(TIN* tin, TCola* comentarios){

    TCola colaAux;
    inci_comment_t commAux;

    C_Crear (&colaAux,sizeof(inci_comment_t));

    while(!C_Vacia(tin->inci_comm))
    {
         C_Sacar(&(tin->inci_comm),&commAux);
         C_Agregar(comentarios,&commAux);
         C_Agregar(&colaAux,&commAux);
    }

    while(!C_Vacia(colaAux))
    {
        C_Sacar (&colaAux,&commAux);
        C_Agregar (&(tin->inci_comm),&commAux);
    }
    C_Vaciar (&colaAux);

    return RES_OK;
}


/**
@function
@name TIN_GetEstados
@description Obtiene todos los estados que tuvo una incidencia y los devuelve en una pila
@return int
@param tin:TIN*
@param estados:TPila*
@author Batman
@see -
*/
int TIN_GetEstados(TIN* tin, TPila* estados)
{
    TPila pilaAux;
    inci_status_t statAux;

    P_Crear (&pilaAux,sizeof(inci_status_t));

    while(!P_Vacia(tin->inci_stat_hist))
    {
         P_Sacar(&(tin->inci_stat_hist),&statAux);
         P_Agregar(&pilaAux,&statAux);
    }

    while(!P_Vacia(pilaAux))
    {
        P_Sacar (&pilaAux,&statAux);
        P_Agregar (&(tin->inci_stat_hist),&statAux);
        P_Agregar (estados,&statAux);
    }

    return RES_OK;
}

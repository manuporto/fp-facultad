/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/ 

/* TDA Incidencia
 * Archivo: TIN_Incidencia.c
 * version: 1.0
*/

#include "TIN_Incidencia.h"
#include <malloc.h>
#include <memory.h>


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
    TLista inci_stat_hist; /* historial de estados */
    TLista inci_comm; /* comentarios de la incidencia */
}TIN;

/******************************************************************************/
/* Implementacion de primitivas */
/*------------------------------*/

int TIN_Crear ( TIN* tin, int inci_id, tipo_inci_t inci_type, prior_inci_t inci_priority, int inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char* inci_summary, char* inci_description)
{
	char *pAux = NULL;
	int tamanio;
	
	tin->inci_id = inci_id;
	tin->inci_type = ini_type;
	tin->inci_user = inci_user;
	tin->inci_assigned_user = inci_assigned_user;
	tin->inci_project_id = inci_project_id;
	
	tamanio = strlen ( inci_date_created );
	tin->inci_date_created = (char*) malloc ( sizeof(tamanio) +1 );
	if ( !tin->inci_date_created )
		return -1; /* error al alojar memoria */

	memcopy ( tin->inci_date_created , inci_date_created , tamanio );
	
	tamanio = strlen ( inci_summary );
	tin->inci_summary = (char*) malloc ( sizeof(tamanio) +1 );
	if ( !tin->inci_summary )
		return -1; /* error al alojar memoria */
		
	memcopy ( tin->inci_summary , inci_summary , tamanio );

	/* inicializacion de las estructuras de listas */
	
	ls_Crear ( &tin->inci_stat_hist , sizeof( inci_status_t) );
	ls_Crear ( &tin->inci_comm , sizeof ( inci_comment_t ) );
	
	return RES_OK;
}

/*----------------------------------------------------------------------------*/

int TIN_Liberar( TIN* tin)
{
	free ( tin->inci_date_created );
	free ( tin->inci_summary );
	
	ls_vaciar ( tin->ini_stat_hist );
	ls_vaciar ( tin->inci_comm );
	
	return RES_OK;
}

/*----------------------------------------------------------------------------*/

int TIN_CambiarEstado( TIN* tin, tFecha fecha, char* usuario, char* estado)
{
	
	
	
	return RES_OK;
}

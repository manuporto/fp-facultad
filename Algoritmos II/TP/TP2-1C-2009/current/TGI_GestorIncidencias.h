#ifndef __TGI_GESTORINCIDENCIAS_H__
#define __TGI_GESTORINCIDENCIAS_H__

#include <stdio.h>
#include <stdlib.h>
#include "TIN_Incidencia.h"
#include "LISTASIMPLE.h"
#include "constantes.h"
/*#include "cmemdbg.h"*/


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


int TGI_CambiarEstadoIn (TGI *tgi, const int inci_id, const int stat_user_id, const char* stat_date, const char* stat_desc);

int TGI_GetIncidencia (const TGI *tgi, int inci_id, TIN* tin);

int TGI_GetHistorialEstadoIn (const TGI *tgi, int inci_id, TCola* estados);

int TGI_GetComentariosIn (const TGI *tgi, int inci_id, TCola* comentarios);

int TGI_GetIncidenciasUsuario (const TGI *tgi, int inci_user, TCola *incidencias);

int TGI_GetIncidenciasProyecto (const TGI *tgi, int project_id, TCola *incidencias);

int TGI_AgregarComentario(TGI *tgi,const int inci_id, const int comm_user_id, const char* comm_date, const char* comm_desc);

int TGI_AgregarUsuario(TGI *tgi, char* user_name);

int TGI_AgregarProyecto(TGI *tgi, char* project_name);

int TGI_AgregarIncidencia (TGI* tgi, tipo_inci_t inci_type, prior_inci_t inci_priority, int inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char* inci_summary, char* inci_description);

int TGI_ArmarArchivos (TGI *tgi, const char* archProyectos, const char* archUsuarios, const char* archIncidencias);

int TGI_Crear (TGI *tgi, const char* archProyectos, const char* archUsuarios, const char* archIncidencias);

int TGI_Cerrar (TGI *tgi);

#endif /* __TGI_GESTORINCIDENCIAS_H__ */

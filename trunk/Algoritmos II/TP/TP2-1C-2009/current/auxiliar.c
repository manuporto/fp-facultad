#include "auxiliar.h"

/**
@function
@name validarTipoIncidencia
@description Valida que el tipo de incidencia esté dentro de los posibles valores
@return int
@param inci_type:int
@author Batman
@see -
*/
int validarTipoIncidencia (int inci_type)
{
    if ((inci_type>-1) && (inci_type<4)) return RES_OK;
    else return RES_ERR;
}

/**
@function
@name validarPrioridad
@description Valida que la prioridad pasada por parámetro esté dentro de los posibles valores
@return int
@param inci_priority:int
@author Batman
@see -
*/
int validarPrioridad (int inci_priority)
{
    if ((inci_priority>-1) && (inci_priority<5)) return RES_OK;
    else return RES_ERR;
}

/**
@function
@name abrirCrear
@description Se fija si existen los archivos, si no existen los crea.
@return int
@param archInci:char*
@param archUsuarios:char*
@param archProyectos:char*
@author Batman
@see -
*/
int abrirCrear (char *archInci, char *archUsuarios, char *archProyectos)
{
    FILE *fdIncidencias;
    FILE *fdUsuarios;
    FILE *fdProyectos;

    fdIncidencias = fopen(archInci,"r");
    if (!fdIncidencias) fdIncidencias = fopen (archInci, "w");

    fdUsuarios = fopen(archUsuarios,"r");
    if (!fdUsuarios) fdUsuarios = fopen (archUsuarios, "w");

    fdProyectos = fopen(archProyectos,"r");
    if (!fdProyectos) fdProyectos = fopen (archProyectos, "w");

    fclose (fdUsuarios);
    fclose (fdProyectos);
    fclose (fdIncidencias);

    return RES_OK;
}

/**
@function
@name crearConfig
@description Crea el archivo de configuración que guardará las rutas de los archivos de datos
@return int
@param archIncidencias:char*
@param archUsuarios:char*
@param archProyectos:char*
@author Batman
@see -
*/
int crearConfig (char* archIncidencias, char* archUsuarios, char* archProyectos)
{
    FILE *fdConfig;

    fdConfig = fopen ("config.cfg","w");
    fprintf (fdConfig,"%s\n%s\n%s\n",archIncidencias, archUsuarios, archProyectos);
    fclose (fdConfig);
    return RES_OK;
}

/**
@function
@name cargarConfig
@description Lee el archivo de configuración y obtiene las rutas de los archivos de datos
@return int
@param archIncidencias:char*
@param archUsuarios:char*
@param archProyectos:char*
@author Batman
@see -
*/
int cargarConfig (char *archIncidencias, char *archUsuarios, char *archProyectos)
{
    FILE *fdConfig;
    char prueba1[141];
    char prueba2[141];
    char prueba3[141];

    fdConfig = fopen ("config.cfg","r");


    if (fdConfig)
    {
        fscanf (fdConfig,"%[^\t\n]\n%[^\t\n]\n%[^\t\n]\n", prueba1, prueba2, prueba3);
        prueba1[strlen(prueba1)]='\0';
        prueba2[strlen(prueba2)]='\0';
        prueba3[strlen(prueba3)]='\0';
        strcpy(archIncidencias,prueba1);
        strcpy(archUsuarios,prueba2);
        strcpy(archProyectos,prueba3);
        fclose (fdConfig);
        return RES_OK;
    }
    else return RES_ERR;
}

/**
@function
@name AUX_Rutas
@description Indica las rutas de los archivos de datos que se utilizaron por última vez al correr el programa.
@return void
@param void
@author Batman
@see -
*/
void AUX_Rutas()
{
    char archIncidencias[141];
    char archUsuarios[141];
    char archProyectos[141];

    if (cargarConfig (archIncidencias,archUsuarios,archProyectos) == RES_OK) fprintf (stdout,INFO_NOMBRE_ARCHIVOS,archIncidencias,archProyectos,archUsuarios);
    else fprintf (stderr,NERR_ARCH_CFG);
}

/**
@function
@name AUX_ArmarArchivos
@description Función auxiliar que imprime los mensajes de información o de error de TGI_ArmarArchivos
@return int
@param tgi:TGI*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
int AUX_ArmarArchivos(TGI *tgi, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    int resultado;

            resultado = TGI_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias);
            switch (resultado)
            {
                case ERR_ARCHIVO_I  :   fprintf(stderr,NERR_ARCHIVO_I);
                                        return RES_ERR;
                                        break;
                case ERR_ARCHIVO_P  :   fprintf(stderr,NERR_ARCHIVO_P);
                                        return RES_ERR;
                                        break;
                case ERR_ARCHIVO_U  :   fprintf(stderr,NERR_ARCHIVO_U);
                                        return RES_ERR;
                                        break;
                case RES_OK         :   return RES_OK;
                                        break;
                default : break;
            }

        return RES_OK;
}


/**
@function
@name AUX_AgregarComentario
@description Función auxiliar que imprime los mensajes de información o de error de TGI_AgregarComentario
@return int
@param tgi:TGI*
@param inci_id:int
@param comm_user_id:int
@param comm_date:char*
@param comm_desc:char*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
void AUX_AgregarComentario (TGI *tgi, int inci_id, int comm_user_id, char* aux_comm_date, char* aux_comm_desc, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    int resultado;
    char *comm_date;
    char *comm_desc;

    comm_date=(char*)malloc(sizeof(char)*(strlen(aux_comm_date)+1));
    comm_desc=(char*)malloc(sizeof(char)*(strlen(aux_comm_desc)+1));

    strcpy(comm_date,aux_comm_date);
    strcpy(comm_desc,aux_comm_desc);

    if (strlen(comm_date)>140) fprintf(stderr,NERR_FECHA);
    else
    {
        if (strlen(comm_desc)>140) fprintf(stderr,NERR_DESC_LARGA);
        else
        {
            resultado = TGI_AgregarComentario(tgi,inci_id, comm_user_id, comm_date, comm_desc);
            switch (resultado)
            {
                case ERR_FECHA      : fprintf(stderr,NERR_FECHA);
                                      break;
                case ERR_INCIDENCIA : fprintf(stderr,NERR_INCIDENCIA);
                                      break;
                case ERR_USUARIO    : fprintf(stderr,NERR_USUARIO);
                                      break;
                case ERR_MEM        : fprintf(stderr,NERR_MEM);
                                      break;
                default             : if (AUX_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias) == RES_OK) fprintf(stdout,INFO_CAM_COMM_OK);
                                      break;
            }
        }
    }
    free(comm_date);
    comm_date=NULL;
    free(comm_desc);
    comm_desc=NULL;
}


/**
@function
@name AUX_CambiarEstadoIn
@description Función auxiliar que imprime los mensajes de información o de error de TGI_CambiarEstadoIn
@return int
@param tgi:TGI*
@param inci_id:int
@param stat_user_id:int
@param stat_date:char*
@param stat_desc:char*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
void AUX_CambiarEstadoIn(TGI *tgi, int inci_id, int stat_user_id, char* aux_stat_date, char* aux_stat_desc, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    int resultado;
    char *stat_date;
    char *stat_desc;

    stat_date=(char*)malloc(sizeof(char)*(strlen(aux_stat_date)+1));
    stat_desc=(char*)malloc(sizeof(char)*(strlen(aux_stat_desc)+1));
    strcpy(stat_date,aux_stat_date);
    strcpy(stat_desc,aux_stat_desc);

    if (strlen(stat_date)>140) fprintf(stderr,NERR_FECHA);
    else
    {
        if (strlen(stat_desc)>140) fprintf(stderr,NERR_DESC_LARGA);
        else
        {
            resultado = TGI_CambiarEstadoIn(tgi, inci_id, stat_user_id, stat_date, stat_desc);

            switch (resultado)
            {
                case ERR_ESTADO     : fprintf(stderr,NERR_ESTADO);
                                      break;
                case ERR_FECHA      : fprintf(stderr,NERR_FECHA);
                                      break;
                case ERR_INCIDENCIA : fprintf(stderr,NERR_INCIDENCIA);
                                      break;
                case ERR_USUARIO    : fprintf(stderr,NERR_USUARIO);
                                      break;
                case ERR_MEM        : fprintf(stderr,NERR_MEM);
                                      break;
                case ERR_BAD_USER   : fprintf(stderr,NERR_BAD_USER);
                                      break;
                default             : if (AUX_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias) == RES_OK) fprintf(stdout,INFO_CAM_EST_OK);
                                      break;
            }
        }
    }
    free(stat_date);
    stat_date = NULL;
    free(stat_desc);
    stat_desc = NULL;
}


/**
@function
@name nombreTipoInci
@description Dado un enumerado devuelve el nombre correspondiente
@return char*
@param aux_inci_type:tipo_inci_t
@author Batman
@see -
*/
char *nombreTipoInci(tipo_inci_t aux_inci_type)
{
    switch (aux_inci_type)
    {
        case 0  :   return "Error";
                    break;
        case 1  :   return "Mejora";
                    break;
        case 2  :   return "Tarea";
                    break;
        case 3  :   return "Nueva funcionalidad";
                    break;
        default:    break;
    }
    return "OK";
}


/**
@function
@name nombrePrioridad
@description Dado un enumerado devuelve el nombre correspondiente
@return char*
@param aux_inci_priority:prior_inci_t
@author Batman
@see -
*/
char *nombrePrioridad(prior_inci_t aux_inci_priority)
{
    switch (aux_inci_priority)
    {
        case 0  :   return "Bloqueante";
                    break;
        case 1  :   return "Critica";
                    break;
        case 2  :   return "Mayor";
                    break;
        case 3  :   return "Menor";
                    break;
        case 4  :   return "Trivial";
                    break;
        default:    break;
    }
    return "OK";
}


/**
@function
@name nombreEstado
@description Dado un enumerado devuelve el nombre correspondiente
@return char*
@param aux_stat_desc:stat_inci_t
@author Batman
@see -
*/
char *nombreEstado(stat_inci_t aux_stat_desc)
{
    switch (aux_stat_desc)
    {
        case 0  :   return "Abierta";
                    break;
        case 1  :   return "En progreso";
                    break;
        case 2  :   return "Resuelta";
                    break;
        case 3  :   return "Reabierta";
                    break;
        case 4  :   return "Cerrada";
                    break;
        default:    break;
    }
    return "OK";
}


/**
@function
@name AUX_GetIncidencia
@description Función auxiliar que imprime los mensajes de información o de error de TGI_GetIncidencia
@return void
@param tgi:TGI*
@param inci_id:int
@author Batman
@see -
*/
void AUX_GetIncidencia (TGI *tgi, int inci_id)
{
    TIN tin;

/* Variables para guardar los elementos de la incidencia */
    int aux_inci_id;
    tipo_inci_t aux_inci_type;
    prior_inci_t aux_inci_priority;
    int aux_inci_user;
    int aux_inci_assigned_user;
    char *aux_inci_date_created;
    int aux_inci_project_id;
    char *aux_inci_summary;
    char *aux_inci_description;
    resol_inci_t aux_inci_resolved;
    char *aux_inci_date_solved;
    char *nombre_tipo_inci;
    char *nombre_prioridad;


    if (TGI_GetIncidencia (tgi, inci_id, &tin) == RES_ERR) fprintf (stderr,NERR_INCIDENCIA);
    else
    {
        TIN_GetDatos(&tin, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
        nombre_tipo_inci = nombreTipoInci(aux_inci_type);
        nombre_prioridad = nombrePrioridad(aux_inci_priority);

        fprintf (stdout,INFO_DATOS_TIN,aux_inci_id, nombre_tipo_inci, nombre_prioridad, aux_inci_user, aux_inci_assigned_user, aux_inci_date_created, aux_inci_project_id, aux_inci_summary, aux_inci_description);
    }

}

/**
@function
@name AUX_GetHistorialEstadoIn
@description Función auxiliar que imprime los mensajes de información o de error de TGI_GetHistorialEstadosIn incluyendo la cola de estados
@return void
@param tgi:TGI*
@param inci_id:int
@author Batman
@see -
*/
void AUX_GetHistorialEstadoIn (TGI *tgi, int inci_id)
{
    TCola estados;
    inci_status_t auxElemEstado;
    char *nombre_estado;

    C_Crear(&estados,sizeof(inci_status_t));

    if (TGI_GetHistorialEstadoIn (tgi, inci_id, &estados) == ERR_INCIDENCIA) fprintf (stderr,NERR_INCIDENCIA);
    else
    {
        while (!C_Vacia(estados))
        {
            C_Sacar(&estados,&auxElemEstado);
            nombre_estado = nombreEstado (auxElemEstado.stat_desc);
            fprintf(stdout,INFO_DATOS_ESTADO,nombre_estado,auxElemEstado.stat_date,auxElemEstado.stat_user_id);
        }
        C_Vaciar(&estados);
    }
}


/**
@function
@name AUX_GetComentariosIn
@description Función auxiliar que imprime los mensajes de información o de error de TGI_GetComentariosIn, incluyendo la cola de comentarios
@return void
@param tgi:TGI*
@param inci_id:int
@author Batman
@see -
*/
void AUX_GetComentariosIn (TGI *tgi, int inci_id)
{
    TCola comentarios;
    TCola comentariosAux;
    inci_comment_t auxElemComments;

    C_Crear(&comentarios,sizeof(inci_comment_t));
    C_Crear(&comentariosAux,sizeof(inci_comment_t));

    if (TGI_GetComentariosIn (tgi, inci_id,&comentarios) == ERR_INCIDENCIA) fprintf (stderr,NERR_INCIDENCIA);
    else
    {
        if (C_Vacia(comentarios)) fprintf (stdout,INFO_NO_COMMENTS);

        while (!C_Vacia(comentarios))
        {
            C_Sacar(&comentarios,&auxElemComments);
            fprintf(stdout,INFO_DATOS_COMENTARIO,auxElemComments.comm_date,auxElemComments.comm_user_id,auxElemComments.comm_desc);
            C_Agregar(&comentariosAux,&auxElemComments);
        }
        while (!C_Vacia(comentariosAux))
        {
            C_Sacar(&comentariosAux,&auxElemComments);
            C_Agregar(&comentarios,&auxElemComments);
        }
    }
}


/**
@function
@name AUX_GetIncidenciasUsuario
@description Función auxiliar que imprime los mensajes de información o de error de TGI_GetIncidenciasUsuario
@return void
@param tgi:TGI*
@param inci_user:int
@author Batman
@see -
*/
void AUX_GetIncidenciasUsuario (TGI *tgi, int inci_user)
{
    TCola incidencias;
    TIN auxTin;

/* Variables para guardar los elementos de la incidencia */
    int aux_inci_id;
    tipo_inci_t aux_inci_type;
    prior_inci_t aux_inci_priority;
    int aux_inci_user;
    int aux_inci_assigned_user;
    char *aux_inci_date_created;
    int aux_inci_project_id;
    char *aux_inci_summary;
    char *aux_inci_description;
    resol_inci_t aux_inci_resolved;
    char *aux_inci_date_solved;
    char *nombre_tipo_inci;
    char *nombre_prioridad;

    C_Crear(&incidencias,sizeof(TIN));

    if (TGI_GetIncidenciasUsuario (tgi,inci_user,&incidencias)== ERR_USUARIO) fprintf(stderr,NERR_USUARIO);
    else
    {
        if (C_Vacia(incidencias)) fprintf(stdout,INFO_NO_INCI_USER);
        while (!C_Vacia(incidencias))
        {
            C_Sacar(&incidencias,&auxTin);
            TIN_GetDatos(&auxTin, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
            nombre_tipo_inci = nombreTipoInci(aux_inci_type);
            nombre_prioridad = nombrePrioridad(aux_inci_priority);

            fprintf (stdout,INFO_DATOS_TIN,aux_inci_id, nombre_tipo_inci, nombre_prioridad, aux_inci_user, aux_inci_assigned_user, aux_inci_date_created, aux_inci_project_id, aux_inci_summary, aux_inci_description);
        }
    }
    C_Vaciar(&incidencias);
}


/**
@function
@name AUX_GetIncidenciasProyecto
@description Función auxiliar que imprime los mensajes de información o de error de TGI_GetIncidenciasProyecto
@return void
@param tgi:TGI*
@param inci_user:int
@author Batman
@see -
*/
void AUX_GetIncidenciasProyecto (TGI *tgi, int inci_user)
{
    TCola incidencias;
    TIN auxTin;

/* Variables para guardar los elementos de la incidencia */
    int aux_inci_id;
    tipo_inci_t aux_inci_type;
    prior_inci_t aux_inci_priority;
    int aux_inci_user;
    int aux_inci_assigned_user;
    char *aux_inci_date_created;
    int aux_inci_project_id;
    char *aux_inci_summary;
    char *aux_inci_description;
    resol_inci_t aux_inci_resolved;
    char *aux_inci_date_solved;
    char *nombre_tipo_inci;
    char *nombre_prioridad;

    C_Crear(&incidencias,sizeof(TIN));

    if (TGI_GetIncidenciasProyecto (tgi,inci_user,&incidencias)== ERR_PROJECT) fprintf(stderr,NERR_PROJECT);
    else
    {
        if (C_Vacia(incidencias)) fprintf(stdout,INFO_NO_INCI_PROJECT);
        while (!C_Vacia(incidencias))
        {
            C_Sacar(&incidencias,&auxTin);
            TIN_GetDatos(&auxTin, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
            nombre_tipo_inci = nombreTipoInci(aux_inci_type);
            nombre_prioridad = nombrePrioridad(aux_inci_priority);

            fprintf (stdout,INFO_DATOS_TIN,aux_inci_id, nombre_tipo_inci, nombre_prioridad, aux_inci_user, aux_inci_assigned_user, aux_inci_date_created, aux_inci_project_id, aux_inci_summary, aux_inci_description);
        }
    }
    C_Vaciar(&incidencias);
}

/**
@function
@name AUX_AgregarUsuario
@description Función auxiliar que imprime los mensajes de información o de error de TGI_AgregarUsuario
@return void
@param tgi:TGI*
@param user_name:char*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
void AUX_AgregarUsuario(TGI *tgi, char* aux_user_name, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    char *user_name;

    user_name=(char*)malloc(sizeof(char)*(strlen(aux_user_name)+1));
    strcpy(user_name,aux_user_name);

    if (strlen(user_name)>140) fprintf(stderr,NERR_NOMBRE_USUARIO_LARGO);
    else
    {
        if (TGI_AgregarUsuario(tgi,user_name) == RES_OK)
        {
            if (AUX_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias) == RES_OK) fprintf(stdout,INFO_ADD_USER_OK);
        }
        else fprintf (stderr,NERR_MEM);
    }
}

/**
@function
@name AUX_AgregarProyecto
@description Función auxiliar que imprime los mensajes de información o de error de TGI_AgregarProyecto
@return void
@param tgi:TGI*
@param aux_project_name:char*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
void AUX_AgregarProyecto(TGI *tgi, char* aux_project_name, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    char *project_name;

    project_name=(char*)malloc(sizeof(char)*(strlen(aux_project_name)+1));
    strcpy(project_name,aux_project_name);

    if (strlen(project_name)>140) fprintf(stderr,NERR_NOMBRE_PROYECTO_LARGO);
    else
    {
        if (TGI_AgregarProyecto(tgi,project_name) == RES_OK)
        {
            if (AUX_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias) == RES_OK) fprintf(stdout,INFO_ADD_PROJECT_OK);
        }
        else fprintf (stderr,NERR_MEM);
    }
}


/**
@function
@name AUX_AgregarIncidencia
@description Función auxiliar que imprime los mensajes de información o de error de TGI_AgregarIncidencia
@return void
@param tgi:TGI*
@param inci_type:tipo_inci_t
@param inci_priority:prior_inci_t
@param inci_user:int
@param inci_assigned_user:int
@param inci_date_created:char*
@param inci_project_id:int
@param inci_summary:char*
@param inci_description:char*
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
void AUX_AgregarIncidencia (TGI* tgi, tipo_inci_t inci_type, prior_inci_t inci_priority, int inci_user, int inci_assigned_user, char* aux_inci_date_created, int inci_project_id, char* aux_inci_summary, char* aux_inci_description, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
    int resultado;
    char *inci_date_created;
    char *inci_summary;
    char *inci_description;

    inci_date_created=(char*)malloc(sizeof(char)*(strlen(aux_inci_date_created)+1));
    strcpy(inci_date_created,aux_inci_date_created);

    inci_summary=(char*)malloc(sizeof(char)*(strlen(aux_inci_summary)+1));
    strcpy(inci_summary,aux_inci_summary);

    inci_description=(char*)malloc(sizeof(char)*(strlen(aux_inci_description)+1));
    strcpy(inci_description,aux_inci_description);

    if (validarTipoIncidencia (inci_type) == RES_ERR)
    {
        fprintf (stderr,NERR_INVALID_TIPO_INCIDENCIA);
    }
    else
    {
        if (validarPrioridad (inci_priority) == RES_ERR) fprintf (stderr,NERR_INVALID_TIPO_PRIORIDAD);
        else
        {
            if (strlen(inci_summary)>140) fprintf (stderr,NERR_SUMMARY_LARGO);
            else
            {
                if (strlen(inci_description)>140) fprintf (stderr,NERR_DESC_LARGA);
                else
                {
                    resultado = TGI_AgregarIncidencia(tgi,inci_type,inci_priority,inci_user,inci_assigned_user,inci_date_created,inci_project_id, inci_summary, inci_description);
                    switch (resultado)
                    {
                            case ERR_FECHA      :   fprintf(stderr,NERR_FECHA);
                                                    break;
                            case ERR_USUARIO    :   fprintf(stderr,NERR_USUARIO);
                                                    break;
                            case ERR_MEM        :   fprintf(stderr,NERR_MEM);
                                                    break;
                            case ERR_PROJECT    :   fprintf(stderr,NERR_PROJECT);
                                                    break;
                            default             :   if (AUX_ArmarArchivos(tgi,archProyectos,archUsuarios,archIncidencias) == RES_OK) fprintf(stdout,INFO_ADD_INCI_OK);
                                                    break;
                    }
                }
            }
        }
    }
}

void AUX_Batman()
{

    printf("\n\n        _==/          i     i          \\==_\n");
    printf("      /XX/            |\\___/|           \\XX\\ \n");
    printf("    /XXXX\\            |XXXXX|            /XXXX\\ \n");
    printf("   |XXXXXX\\_         _XXXXXXX_         _/XXXXXX| \n");
    printf("  XXXXXXXXXXXxxxxxxxXXXXXXXXXXXxxxxxxxXXXXXXXXXXX \n");
    printf(" |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| \n");
    printf(" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n");
    printf(" |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| \n");
    printf("  XXXXXX/^^^^^\\XXXXXXXXXXXXXXXXXXXXX/^^^^^\\XXXXXX \n");
    printf("   |XXX|       \\XXX/^^\\XXXXX/^^\\XXX/       |XXX| \n");
    printf("     \\XX\\       \\X/    \\XXX/    \\X/       /XX/ \n");
    printf("        i\\       i      \\X/      i       /i \n");

    printf("\n\n                HOLY SMOKES BATMAN! \n");

}
/**
@function
@name opciones
@description A partir de la opción ingresada, llama a la función correspondiente.
@return int
@param argv:char**
@param i:int
@param archProyectos:char*
@param archUsuarios:char*
@param archIncidencias:char*
@author Batman
@see -
*/
int opciones (char* argv[], int argc, int i, char *archProyectos, char *archUsuarios, char *archIncidencias)
{
                TGI tgi;

                int opcion = 12;

                TGI_Crear(&tgi,archProyectos,archUsuarios,archIncidencias);

                if (strcmp(argv[i],"-rutas")==0) opcion = 0;
                if (strcmp(argv[i],"-adds")==0) opcion = 1;
                if (strcmp(argv[i],"-geti")==0) opcion = 2;
                if (strcmp(argv[i],"-getis")==0) opcion = 3;
                if (strcmp(argv[i],"-getic")==0) opcion = 4;
                if (strcmp(argv[i],"-getiu")==0) opcion = 5;
                if (strcmp(argv[i],"-getip")==0) opcion = 6;
                if (strcmp(argv[i],"-addu")==0) opcion = 7;
                if (strcmp(argv[i],"-addp")==0) opcion = 8;
                if (strcmp(argv[i],"-addi")==0) opcion = 9;
                if (strcmp(argv[i],"-addc")==0) opcion = 10;
                if (strcmp(argv[i],"-batman")==0) opcion = 11;

                switch (opcion){
                case 0 : if (argc == i+1) AUX_Rutas ();
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 1 : if (argc == i+5) AUX_CambiarEstadoIn(&tgi, atoi(argv[i+1]), atoi (argv[i+2]), argv[i+3], argv[i+4], archProyectos, archUsuarios, archIncidencias);
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 2 : if (argc == i+2) AUX_GetIncidencia (&tgi, atoi(argv[i+1]));
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 3 : if (argc == i+2) AUX_GetHistorialEstadoIn (&tgi, atoi(argv[i+1]));
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 4 : if (argc == i+2) AUX_GetComentariosIn (&tgi, atoi(argv[i+1]));
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 5 : if (argc == i+2) AUX_GetIncidenciasUsuario (&tgi, atoi(argv[i+1]));
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 6 : if (argc == i+2) AUX_GetIncidenciasProyecto (&tgi, atoi(argv[i+1]));
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 7 : if (argc == i+2) AUX_AgregarUsuario(&tgi, argv[i+1], archProyectos, archUsuarios, archIncidencias);
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 8 : if (argc == i+2) AUX_AgregarProyecto(&tgi, argv[i+1], archProyectos, archUsuarios, archIncidencias);
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 9 : if (argc == i+9) AUX_AgregarIncidencia (&tgi, atoi(argv[i+1]), atoi(argv[i+2]), atoi(argv[i+3]), atoi(argv[i+4]), argv[i+5], atoi(argv[i+6]), argv[i+7], argv[i+8], archProyectos, archUsuarios, archIncidencias);
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 10: if (argc == i+5) AUX_AgregarComentario (&tgi, atoi(argv[i+1]), atoi(argv[i+2]), argv[i+3], argv[i+4], archProyectos, archUsuarios, archIncidencias);
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);
                         break;
                case 11: if (argc == i+1) AUX_Batman();
                                 else fprintf (stderr,NERR_NUMARGUMENTOS);

                         break;
                default: fprintf (stderr,NERR_INVALIDCOMMAND);
                         break;

            }


            TGI_Cerrar (&tgi);

            return RES_OK;

}

#include "TGI_GestorIncidencias.h"

/**
@function
@name posIncidencia
@description Posiciona el corriente en la incidencia buscada
@return int
@param ptroLista:TListaSimple*
@param inci_id:int
@param tinAux:TIN*
@author Batman
@see -
*/
int posIncidencia (TListaSimple* ptroLista, int inci_id,TIN *tinAux)
{
    int pudoMover = 1;
    int encontrado = -1;
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

	if (!ls_Vacia(*ptroLista))
	{
        ls_MoverCorriente(ptroLista, LS_PRIMERO);

		while ((encontrado != 0 ) && (pudoMover))
		{
		    ls_ElemCorriente(*ptroLista, tinAux);
		    TIN_GetDatos(tinAux, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
			if (aux_inci_id == inci_id ) encontrado = 0;
			if (encontrado!=0) pudoMover = ls_MoverCorriente(ptroLista,LS_SIGUIENTE);
		}
	}

    return encontrado;
}

/**
@function
@name obtenerIncidencia
@description Dado un ID de incidencia devuelve un TIN armado. Si no lo pudo encontrar devuelve RES_ERR
@return int
@param tgi:TGI*
@param inci_id:int
@param tinAux:TIN*
@author Batman
@see -
*/
int obtenerIncidencia (const TGI *tgi, int inci_id, TIN* tinAux)
{
   	TListaSimple *ptroLista;
	int encontrado = -1;

    ptroLista = (TListaSimple*)malloc(sizeof(TListaSimple));
	memcpy (ptroLista,&(tgi->incidencias),sizeof(TListaSimple));


    encontrado = posIncidencia(ptroLista, inci_id,tinAux);

    free (ptroLista);
    ptroLista = NULL;
    if (encontrado == 0) return RES_OK;
	else return RES_ERR;
}

/**
@function
@name validarIncidencia
@description Devuelve RES_OK si la incidencia buscada existe, RES_ERR en otro caso
@return int
@param tgi:TGI*
@param inci_id:int
@param tin:TIN*
@author Batman
@see -
*/
int validarIncidencia (TGI *tgi, int inci_id, TIN *tin)
{
    return (obtenerIncidencia (tgi, inci_id, tin));
}

/**
@function
@name validarUsuario
@description Valida la existencia en el TGI del usuario pasado por parámetro
@return int
@param tgi:TGI*
@param stat_user_id:int
@author Batman
@see -
*/
int validarUsuario (TGI *tgi, int stat_user_id)
{
   	TListaSimple *ptroLista;
	int encontrado = -1;
	int pudoMover = 1;
	user_t userAux;

    ptroLista = (TListaSimple*)malloc(sizeof(TListaSimple));
	memcpy (ptroLista,&(tgi->usuarios),sizeof(TListaSimple));

	if (!ls_Vacia(*ptroLista))
	{
        ls_MoverCorriente(ptroLista, LS_PRIMERO);

		while ((encontrado != 0 ) && (pudoMover))
		{
		    ls_ElemCorriente(*ptroLista, &userAux);
			if (userAux.user_id == stat_user_id ) encontrado = 0;
			pudoMover = ls_MoverCorriente(ptroLista,LS_SIGUIENTE);
		}
	}
	free (ptroLista);
	ptroLista = NULL;
    if (encontrado == 0 ) return /*RES_OK*/0;
	else return /*RES_ERR*/-1;
}

/**
@function
@name validarProyecto
@description Valida la existencia en el TGI del proyecto pasado por parámetro
@return int
@param tgi:TGI*
@param project_id:int
@author Batman
@see -
*/
int validarProyecto (TGI *tgi, int project_id)
{
   	TListaSimple *ptroLista;
	int encontrado = -1;
	int pudoMover = 1;
	project_t projectAux;

    ptroLista = (TListaSimple*)malloc(sizeof(TListaSimple));
	memcpy (ptroLista,&(tgi->proyectos),sizeof(TListaSimple));

	if (!ls_Vacia(*ptroLista))
	{
        ls_MoverCorriente(ptroLista, LS_PRIMERO);

		while ((encontrado != 0 ) && (pudoMover))
		{
            ls_ElemCorriente(*ptroLista, &projectAux);
			if (projectAux.project_id == project_id ) encontrado = 0;
			pudoMover = ls_MoverCorriente(ptroLista,LS_SIGUIENTE);
		}
	}
	free (ptroLista);
	ptroLista = NULL;
    if (encontrado == 0 ) return RES_OK;
	else return RES_ERR;
}


/**
@function
@name esBisiesto
@description Dado un año pasado por parámetro devuelve RES_OK si es bisiesto, RES_ERR si no
@return int
@param anio:int
@author Batman
@see -
*/
int esBisiesto(int anio)
{
    if ((anio % 4 == 0) && ((anio % 100 != 0) || (anio % 400 == 0))) return RES_OK;
    else return RES_ERR;
}

/**
@function
@name validarFecha
@description Validar que la fecha pasada por parámetro sea del formato YYYY-MM-DD HH:MM:SS
@return int
@param stat_date:char*
@author Batman
@see -
*/
int validarFecha (char* stat_date)
{
    char sAnio[5], sMes[3], sDia[3], sHoras[3], sMinutos[3], sSegundos[3];
    unsigned int anio, mes, dia, horas, minutos, segundos;

    if (strlen(stat_date)!=19) return RES_ERR;
    else
    {
        if ((*(stat_date+4)=='-') && (*(stat_date+7)=='-') && (*(stat_date+10)==' ') && (*(stat_date+13)==':') && (*(stat_date+16)==':'))
        {
            strncpy(sAnio, stat_date,4);
            strncpy(sMes, stat_date+5,2);
            strncpy(sDia, stat_date+8,2);
            strncpy(sHoras, stat_date+11,2);
            strncpy(sMinutos, stat_date+14,2);
            strncpy(sSegundos, stat_date+17,2);

            anio = atoi (sAnio);
            mes = atoi (sMes);
            dia = atoi (sDia);
            horas = atoi (sHoras);
            minutos = atoi (sMinutos);
            segundos = atoi (sSegundos);


            if ((mes<13) && (dia<32) && (horas<25) && (minutos<61) && (segundos<61))
            {
                if ((mes==4) || (mes==6) || (mes==9) || (mes==11))
                {
                    if (dia==31) return RES_ERR;
                }
                if (mes==2)
                {
                    if (dia>29) return RES_ERR;
                    if ((dia==29) && (esBisiesto(anio)==RES_ERR)) return RES_ERR;
                }
            }
            else return RES_ERR;
        }
        else return RES_ERR;
    }

    return RES_OK;
}

/**
@function
@name validarEstado
@description Recibe un estado y le asigna el valor correspondiente en el enumerado. Si no es ninguno, devuelve RES_ERR
@return int
@param estado:char*
@param tin:TIN*
@author Batman
@see -
*/
int validarEstado (char* estado, TIN *tin)
{
    TPila pilaAux;
    inci_status_t statAux;
    int estadoCorrecto = -1;
    int xxx;

    P_Crear(&pilaAux,sizeof(inci_status_t));

    if (strcmp(estado,"abierta")==0) estadoCorrecto = 0;
    else
        if (strcmp(estado,"enprogreso")==0) estadoCorrecto = 1;
        else
            if ((strcmp(estado,"arreglada")==0) || (strcmp(estado,"noarreglar")==0) || (strcmp(estado,"incompleta")==0)) estadoCorrecto = 2;
            else
                if (strcmp(estado,"reabierta")==0) estadoCorrecto = 3;
                else
                    if (strcmp(estado,"cerrada")==0) estadoCorrecto = 4;

    if (estadoCorrecto == -1) return RES_ERR;
    else
    {

        TIN_GetEstados(tin,&pilaAux);
        xxx = P_Sacar (&pilaAux,&statAux);
        P_Agregar(&pilaAux,&statAux);

        P_Vaciar(&pilaAux);

        switch (estadoCorrecto){
            case TIN_OPEN       : return RES_ERR;
                                  break;
            case TIN_PROGRESS   : if ((statAux.stat_desc != TIN_OPEN) && (statAux.stat_desc != TIN_REOPEN)) return RES_ERR;
                                  else return TIN_PROGRESS;
                                  break;
            case TIN_RESOLVED   : if ((statAux.stat_desc != TIN_OPEN) && (statAux.stat_desc != TIN_REOPEN) && (statAux.stat_desc != TIN_PROGRESS)) return RES_ERR;
                                  else return TIN_RESOLVED;
                                  break;
            case TIN_REOPEN     : if ((statAux.stat_desc != TIN_CLOSED)) return RES_ERR;
                                  else return TIN_REOPEN;
                                  break;
            case TIN_CLOSED     : if ((statAux.stat_desc != TIN_OPEN) && (statAux.stat_desc != TIN_REOPEN) && (statAux.stat_desc != TIN_PROGRESS) && (statAux.stat_desc != TIN_RESOLVED)) return RES_ERR;
                                  else return TIN_CLOSED;
                                  break;
            default             : return RES_OK;
                                  break;
        }

    }
    return RES_OK;
}


/**
@function
@name guardarArchIncidencias
@description Dada una incidencia la copia en el archivo
@return int
@param fdi:FILE*
@param auxTin:TIN*
@author Batman
@see -
*/
int guardarArchIncidencias(FILE *fdi, TIN *auxTin)
{
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
    TCola comentarios;
    TPila estados;
    TPila estadosAux;
    inci_comment_t auxElemComments;
    inci_status_t auxElemEstado;

    P_Crear(&estados,sizeof(inci_status_t));
    P_Crear(&estadosAux,sizeof(inci_status_t));
    C_Crear(&comentarios,sizeof(inci_comment_t));

    TIN_GetDatos(auxTin, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
    TIN_GetComentarios(auxTin,&comentarios);


    TIN_GetEstados(auxTin,&estados);

    /* Damos vuelta la pila para luego cargarla en el orden correcto*/

	fprintf (fdi,"%i\t%i\t%i\t%i\t%i\t%s\t%i\t%s\t%s\t%i\t%s\n",aux_inci_id, aux_inci_type, aux_inci_priority, aux_inci_user, aux_inci_assigned_user, aux_inci_date_created, aux_inci_project_id, aux_inci_summary, aux_inci_description, aux_inci_resolved, aux_inci_date_solved);

    while (!P_Vacia(estados))
    {
        P_Sacar(&estados,&auxElemEstado);
        P_Agregar(&estadosAux,&auxElemEstado);
	}

	while (!P_Vacia(estadosAux))
	{
	    P_Sacar(&estadosAux,&auxElemEstado);
	    fprintf(fdi,"%s\t%i\t%i\n",auxElemEstado.stat_date,auxElemEstado.stat_user_id,auxElemEstado.stat_desc);
	}
    fprintf (fdi,SEP_STAT_FIN);
    while (!C_Vacia(comentarios))
    {
        C_Sacar(&comentarios,&auxElemComments);
	    fprintf(fdi,"%s\t%i\t%s\n",auxElemComments.comm_date,auxElemComments.comm_user_id,auxElemComments.comm_desc);
    }
    fprintf (fdi,SEP_COMM_FIN);
    C_Vaciar(&comentarios);

    return RES_OK;
}


/**
@function
@name armarTin
@description Levanta de un archivo todos los datos de una incidencia y los guarda en un TIN
@return int
@param fd:FILE*
@param tin:TIN*
@author Batman
@see -
*/
int armarTin (FILE* fd,TIN* tin)
{
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
    inci_comment_t auxElemComments;
    inci_status_t auxElemEstado;
    char stg[141];
    char stg2[141];

    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_id = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_type = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_priority = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_user = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_assigned_user = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_date_created = (char*)malloc(sizeof(char)*(strlen(stg)+1));
    strcpy(aux_inci_date_created, stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_project_id = atoi(stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_summary = (char*)malloc(sizeof(char)*(strlen(stg)+1));
    strcpy(aux_inci_summary, stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_description = (char*)malloc(sizeof(char)*(strlen(stg)+1));
    strcpy(aux_inci_description, stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_resolved = atoi (stg);
    fscanf(fd,"%[^\t\n]\n",stg);
    aux_inci_date_solved = (char*)malloc(sizeof(char)*(strlen(stg)+1));
    strcpy(aux_inci_date_solved, stg);
    TIN_Crear(tin, aux_inci_id, aux_inci_type, aux_inci_priority, aux_inci_user, aux_inci_assigned_user, aux_inci_date_created, aux_inci_project_id, aux_inci_summary, aux_inci_description);

    fscanf(fd,"%[^\t\n]\n",stg);
    while (strcmp("SEP_STAT_FIN",stg) != 0)
    {
        auxElemEstado.stat_date = (char*) malloc (sizeof(char)*(strlen(stg)+1));
        strcpy(auxElemEstado.stat_date,stg);
        fscanf(fd,"%[^\t\n]\n",stg);
        auxElemEstado.stat_user_id = atoi (stg);
        fscanf(fd,"%[^\t\n]\n",stg);
        auxElemEstado.stat_desc = atoi(stg);
        TIN_CambiarEstado(tin,auxElemEstado.stat_date,auxElemEstado.stat_user_id,auxElemEstado.stat_desc);
        free (auxElemEstado.stat_date);
        auxElemEstado.stat_date = NULL;

        fscanf(fd,"%[^\t\n]\n",stg);
    }

    fscanf(fd,"%[^\t\n]\n",stg);
    while (strcmp("SEP_COMM_FIN",stg) != 0)
    {
        auxElemComments.comm_date = (char*) malloc (sizeof(char)*(strlen(stg)+1));
        strcpy(auxElemComments.comm_date,stg);
        fscanf(fd,"%[^\t\n]\n",stg);
        auxElemComments.comm_user_id = atoi (stg);
        fscanf(fd,"%[^\t\n]\n",stg2);
        auxElemComments.comm_desc = (char*) malloc (sizeof(char)*(strlen(stg2)+1));
        strcpy(auxElemComments.comm_desc,stg2);

        TIN_Comentar(tin,auxElemComments.comm_date,auxElemComments.comm_user_id,auxElemComments.comm_desc);

        fscanf(fd,"%[^\t\n]\n",stg);
    }

    if (aux_inci_resolved != -1) TIN_Resolver(tin,aux_inci_date_solved,aux_inci_user,aux_inci_resolved,0);

    free (aux_inci_date_solved);
    aux_inci_date_solved = NULL;

    return RES_OK;
}

/**
@function
@name archivoVacio
@description Devuelve el tamaño del archivo pasado por parámetro. Si es 0, está vacío.
@return int
@param fd:FILE*
@author Batman
@see -
*/
int archivoVacio(FILE *fd){
	int size;

	fseek (fd, 0, SEEK_END);
	size = ftell(fd);
	return size;
}

/**
@function
@name TGI_AgregarComentario
@description Agrega un comentario a la incidencia indicada
@return int
@param tgi:TGI*
@param inci_id:const int
@param comm_user_id:const int
@param comm_date:const char*
@param comm_desc:const char*
@author Batman
@see -
*/
int TGI_AgregarComentario(TGI *tgi,const int inci_id, const int comm_user_id, const char* comm_date, const char* comm_desc)
{
    TIN tin;
    TIN tinBasura;
    char *aux_comm_date;
    char *aux_comm_desc;

    TIN_CrearVacio(&tin);

    aux_comm_date = (char*) malloc (sizeof(char)*(strlen(comm_date)+1));
    aux_comm_desc = (char*) malloc (sizeof(char)*(strlen(comm_desc)+1));
    strcpy(aux_comm_date,comm_date);
    strcpy(aux_comm_desc,comm_desc);

    if (validarUsuario (tgi,comm_user_id) == RES_ERR)
    {
        free(aux_comm_date);
        aux_comm_date = NULL;
        free(aux_comm_desc);
        aux_comm_desc= NULL;
        return ERR_USUARIO;
    }

    if (validarIncidencia (tgi,inci_id, &tin) == RES_ERR)
    {
        free(aux_comm_date);
        aux_comm_date = NULL;
        free(aux_comm_desc);
        aux_comm_desc= NULL;
        return ERR_INCIDENCIA;
    }

    if (validarFecha (aux_comm_date)==RES_ERR)
    {
        free(aux_comm_date);
        aux_comm_date = NULL;
        free(aux_comm_desc);
        aux_comm_desc= NULL;
        return ERR_FECHA;
    }

    obtenerIncidencia (tgi, inci_id, &tin);

    if (TIN_Comentar(&tin,aux_comm_date,comm_user_id,aux_comm_desc)==RES_ERR)
    {
        free(aux_comm_date);
        aux_comm_date = NULL;
        free(aux_comm_desc);
        aux_comm_desc= NULL;
        return ERR_MEM;
    }
    posIncidencia(&(tgi->incidencias), inci_id, &tinBasura);

    ls_ModifCorriente(&(tgi->incidencias), &tin);

    return RES_OK;
}


/**
@function
@name TGI_CambiarEstadoIn
@description Modifica el estado actual de una incidencia por el pasado por parámetro. Valida que el estado anterior sea compatible
@return int
@param tgi:TGI*
@param inci_id:const int
@param stat_user_id:const int
@param stat_date:const char*
@param stat_desc:const char*
@author Batman
@see -
*/
int TGI_CambiarEstadoIn (TGI *tgi, const int inci_id, const int stat_user_id, const char* stat_date, const char* stat_desc)
{
    stat_inci_t estado;
    stat_inci_t resolucion=0;
    TIN tin;
    char *aux_stat_date;
    char *aux_stat_desc;
    int estadoCorrecto;
    int resultado;
    TIN tinBasura;

    TIN_CrearVacio(&tin);

    aux_stat_date = (char*) malloc (sizeof(char)*(strlen(stat_date)+1));
    aux_stat_desc = (char*) malloc (sizeof(char)*(strlen(stat_desc)+1));
    strcpy(aux_stat_date,stat_date);
    strcpy(aux_stat_desc,stat_desc);

    if (validarUsuario (tgi,stat_user_id) == RES_ERR)
    {
        free (aux_stat_date);
        aux_stat_date = NULL;
        free (aux_stat_desc);
        aux_stat_desc=NULL;
        return ERR_USUARIO;
    }
    if (validarIncidencia (tgi,inci_id, &tin) == RES_ERR)
    {
        free (aux_stat_date);
        aux_stat_date = NULL;
        free (aux_stat_desc);
        aux_stat_desc=NULL;
        return ERR_INCIDENCIA;
    }

    if (validarFecha (aux_stat_date)==RES_ERR)
    {
        free (aux_stat_date);
        aux_stat_date = NULL;
        free (aux_stat_desc);
        aux_stat_desc=NULL;
        return ERR_FECHA;
    }

    estadoCorrecto = validarEstado (aux_stat_desc, &tin);
    if (estadoCorrecto == RES_ERR)
    {
        free (aux_stat_date);
        aux_stat_date = NULL;
        free (aux_stat_desc);
        aux_stat_desc=NULL;
        return ERR_ESTADO;
    }
    else estado = estadoCorrecto;


    obtenerIncidencia (tgi, inci_id, &tin);

    if (estado == TIN_RESOLVED)
    {
        if (strcmp(aux_stat_desc,"arreglado")==0) resolucion = 0;
        else
            if (strcmp(aux_stat_desc,"noarreglar")==0) resolucion = 1;
            else
                if (strcmp(aux_stat_desc,"incompleto")==0) resolucion = 2;

        resultado = TIN_Resolver (&tin, aux_stat_date, stat_user_id, resolucion,1);
        if (resultado  == ERR_MEM)
        {
            free (aux_stat_date);
            aux_stat_date = NULL;
            free (aux_stat_desc);
            aux_stat_desc=NULL;
            return ERR_MEM;
        }
        else if (resultado==RES_ERR)
        {
            free (aux_stat_date);
            aux_stat_date = NULL;
            free (aux_stat_desc);
            aux_stat_desc=NULL;
            return ERR_BAD_USER;
        }
    }
    else if (TIN_CambiarEstado(&tin, aux_stat_date, stat_user_id, estado) == RES_ERR)
    {
        free (aux_stat_date);
        aux_stat_date = NULL;
        free (aux_stat_desc);
        aux_stat_desc=NULL;
        return ERR_MEM;
    }

    posIncidencia(&(tgi->incidencias), inci_id, &tinBasura);
    ls_ModifCorriente(&(tgi->incidencias), &tin);

    free (aux_stat_date);
    aux_stat_date = NULL;
    free (aux_stat_desc);
    aux_stat_desc=NULL;
    return RES_OK;
}

/**
@function
@name TGI_GetIncidencia
@description Dado un ID de incidencia la devuelve completa en el TIN pasado como parámetro y devuelve RES_OK. Si no lo puede hacer devuelve RES_ERR
@return int
@param tgi:const TGI*
@param inci_id:int
@param tin:TIN*
@author Batman
@see -
*/
int TGI_GetIncidencia (const TGI *tgi, int inci_id, TIN* tin)
{
    return (obtenerIncidencia (tgi, inci_id, tin));
}

/**
@function
@name TGI_GetHistorialEstadoIn
@description Dado un ID de incidencia devuelve una cola con los estados de la misma. Si no existe, devuelve ERR_INCIDENCIA.
@return int
@param tgi:TGI*
@param inci_id:int
@param estados:TCola*
@author Batman
@see -
*/
int TGI_GetHistorialEstadoIn (const TGI *tgi, int inci_id, TCola* estados)
{
    TGI aux_tgi;
    TIN tin;
    TPila auxEstados;
    inci_status_t auxElemEstado;

    TIN_CrearVacio(&tin);

    P_Crear(&auxEstados,sizeof(inci_status_t));

    memcpy(&aux_tgi,tgi,sizeof(TGI));

	if (validarIncidencia(&aux_tgi,inci_id,&tin) == RES_ERR) return ERR_INCIDENCIA;
	else
	{
	    TIN_GetEstados(&tin,&auxEstados);
	    while (!P_Vacia(auxEstados))
	    {
	        P_Sacar(&auxEstados,&auxElemEstado);
	        C_Agregar(estados,&auxElemEstado);
	    }
	    P_Vaciar (&auxEstados);
	    return RES_OK;
	}
}


/**
@function
@name TGI_GetComentariosIn
@description Dado un ID de incidencia devuelve una cola con los comentarios de la misma. Si no existe, devuelve ERR_INCIDENCIA.
@return int
@param tgi:TGI*
@param inci_id:int
@param comentarios:TCola*
@author Batman
@see -
*/
int TGI_GetComentariosIn (const TGI *tgi, int inci_id, TCola* comentarios)
{
    TGI aux_tgi;
    TIN tin;
    memcpy(&aux_tgi,tgi,sizeof(TGI));

    TIN_CrearVacio(&tin);

	if (validarIncidencia(&aux_tgi,inci_id,&tin) == RES_ERR) return ERR_INCIDENCIA;
	else return (TIN_GetComentarios(&tin,comentarios));
}

/**
@function
@name TGI_GetIncidenciasUsuario
@description Dado un ID de usuario devuelve una cola con las incidencias del mismo. Si no existe el usuario, devuelve ERR_USUARIO.
@return int
@param tgi:TGI*
@param inci_user:int
@param incidencias:TCola*
@author Batman
@see -
*/
int TGI_GetIncidenciasUsuario (const TGI *tgi, int inci_user, TCola *incidencias)
{
    TGI aux_tgi;
    TIN tinAux;
    int pudoMover = 1;
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

    TIN_CrearVacio(&tinAux);

    memcpy(&aux_tgi,tgi,sizeof(TGI));

    if (validarUsuario(&aux_tgi, inci_user)==RES_ERR) return ERR_USUARIO;
    else
    {
        if (!ls_Vacia(aux_tgi.incidencias))
        {
            ls_MoverCorriente(&(aux_tgi.incidencias), LS_PRIMERO);

            while (pudoMover)
            {
                ls_ElemCorriente(aux_tgi.incidencias, &tinAux);
                TIN_GetDatos(&tinAux, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
                if (aux_inci_user == inci_user )
                    C_Agregar(incidencias,&tinAux);
                pudoMover = ls_MoverCorriente(&(aux_tgi.incidencias),LS_SIGUIENTE);
            }
        }

    }
    return RES_OK;
}

/**
@function
@name TGI_GetIncidenciasProyecto
@description Dado el ID de un proyecto devuelve una cola con las incidencias del mismo. Si no existe el proyecto, devuelve ERR_PROJECT.
@return int
@param tgi:TGI*
@param project_id:int
@param incidencias:TCola*
@author Batman
@see -
*/
int TGI_GetIncidenciasProyecto (const TGI *tgi, int project_id, TCola *incidencias)
{
    TGI aux_tgi;
    TIN tinAux;
    int pudoMover = 1;
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

    TIN_CrearVacio(&tinAux);

    memcpy(&aux_tgi,tgi,sizeof(TGI));

    if (validarProyecto(&aux_tgi, project_id)==RES_ERR) return ERR_PROJECT;
    else
    {
        if (!ls_Vacia(aux_tgi.incidencias))
        {
            ls_MoverCorriente(&(aux_tgi.incidencias), LS_PRIMERO);

            while (pudoMover)
            {
                ls_ElemCorriente(aux_tgi.incidencias, &tinAux);
                TIN_GetDatos(&tinAux, &aux_inci_id, &aux_inci_type, &aux_inci_priority, &aux_inci_user, &aux_inci_assigned_user, &aux_inci_date_created, &aux_inci_project_id, &aux_inci_summary, &aux_inci_description, &aux_inci_resolved, &aux_inci_date_solved);
                if (aux_inci_project_id == project_id )
                    C_Agregar(incidencias,&tinAux);
                pudoMover = ls_MoverCorriente(&(aux_tgi.incidencias),LS_SIGUIENTE);
            }
        }

    }
    return RES_OK;
}

/**
@function
@name TGI_AgregarUsuario
@description Agrega el nombre de usuario pasado por parámetro, al TGI
@return int
@param tgi:TGI*
@param user_name:char*
@author Batman
@see -
*/
int TGI_AgregarUsuario(TGI *tgi, char* user_name)
{
    user_t user;
    user_t auxUser;

    if (!ls_Vacia (tgi->usuarios))
    {
        while (ls_MoverCorriente(&(tgi->usuarios),LS_SIGUIENTE));
        ls_ElemCorriente ((tgi->usuarios),&auxUser);
        user.user_id = ++auxUser.user_id;
    }
    else user.user_id = 1;

    user.user_name = user_name;

    if (!ls_Insertar(&(tgi->usuarios),LS_SIGUIENTE,&user)) return ERR_MEM;
    else return RES_OK;
}

/**
@function
@name TGI_AgregarProyecto
@description Agrega un proyecto, cuyo nombre se recibe por parámetro, al TGI
@return int
@param tgi:TGI*
@param project_name:char*
@author Batman
@see -
*/
int TGI_AgregarProyecto(TGI *tgi, char* project_name)
{
    project_t project;
    project_t auxProject;

    if (!ls_Vacia (tgi->proyectos))
    {
        while (ls_MoverCorriente(&(tgi->proyectos),LS_SIGUIENTE));
        ls_ElemCorriente ((tgi->proyectos),&auxProject);
        project.project_id = ++auxProject.project_id;
    }
    else project.project_id = 1;

    project.project_name = project_name;

    if (!ls_Insertar(&(tgi->proyectos),LS_SIGUIENTE,&project)) return ERR_MEM;
    return RES_OK;
}

/**
@function
@name TGI_AgregarIncidencia
@description Agrega una incidencia al TGI. Valida que exista el usuario y el proyecto indicado.
@return int
@param tgi:TGI*
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
int TGI_AgregarIncidencia (TGI* tgi, tipo_inci_t inci_type, prior_inci_t inci_priority, int inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id, char* inci_summary, char* inci_description)
{
    TIN tin;
    int inci_id;
    TIN auxTin;

    TIN_CrearVacio(&auxTin);


    if (validarUsuario (tgi,inci_user) == RES_ERR) return ERR_USUARIO;
    if (validarUsuario (tgi,inci_assigned_user) == RES_ERR) return ERR_USUARIO;
    if (validarFecha (inci_date_created) == RES_ERR) return ERR_FECHA;
    if (validarProyecto (tgi,inci_project_id) == RES_ERR) return ERR_PROJECT;

    /* Procedemos a autoasignar el id de incidencias a partir del último ingresado */
    if (!ls_Vacia (tgi->incidencias))
    {
        while (ls_MoverCorriente(&(tgi->incidencias),LS_SIGUIENTE));
        ls_ElemCorriente ((tgi->incidencias),&auxTin);
        inci_id = ++(auxTin.inci_id);
    }
    else inci_id = 1;

    TIN_Crear(&tin, inci_id, inci_type, inci_priority, inci_user, inci_assigned_user, inci_date_created, inci_project_id, inci_summary, inci_description);

    TIN_CambiarEstado(&tin,inci_date_created,inci_assigned_user,TIN_OPEN);

    if (!ls_Insertar(&(tgi->incidencias),LS_SIGUIENTE,&tin)) return ERR_MEM;

    return RES_OK;
}

/**
@function
@name TGI_ArmarArchivos
@description Obtiene todos los elementos del TGI para pasarlos a los archivos de datos.
@return int
@param tgi:TGI*
@param archProyectos:const char*
@param archUsuarios:const char*
@param archIncidencias:const char*
@author Batman
@see -
*/
int TGI_ArmarArchivos (TGI *tgi, const char* archProyectos, const char* archUsuarios, const char* archIncidencias)
{
    FILE *fdp, *fdu, *fdi;
    user_t auxUser;
    project_t auxProject;
    TIN auxTin;
    int nocreadou = 1;
    int nocreadoi = 1;
    int nocreadop = 1;


    /* Creamos tres archivos temporales */
    char tmpProyectos[141] = "proyectos.tmp";
    char tmpUsuarios[141] = "usuarios.tmp";
    char tmpIncidencias[141] = "incidencias.tmp";

    int pudoMover = 1;


    if (!ls_Vacia (tgi->usuarios))
    {
        fdu = fopen(tmpUsuarios,"w");
        if (fdu)
        {
            ls_MoverCorriente(&(tgi->usuarios), LS_PRIMERO);

            while (pudoMover)
            {
                ls_ElemCorriente(tgi->usuarios, &auxUser);
                fprintf (fdu,"%i\t%s\n", auxUser.user_id, auxUser.user_name);
                pudoMover = ls_MoverCorriente(&(tgi->usuarios),LS_SIGUIENTE);
            }
            nocreadou = fclose (fdu);
        }
        else return ERR_ARCHIVO_U;
    }

    pudoMover = 1;

    if (!ls_Vacia (tgi->proyectos))
    {
        fdp = fopen(tmpProyectos,"w");
        if (fdp)
        {
            ls_MoverCorriente(&(tgi->proyectos), LS_PRIMERO);

            while (pudoMover)
            {
                ls_ElemCorriente(tgi->proyectos, &auxProject);
                fprintf (fdp,"%i\t%s\n", auxProject.project_id, auxProject.project_name);
                pudoMover = ls_MoverCorriente(&(tgi->proyectos),LS_SIGUIENTE);
            }
            nocreadop = fclose (fdp);
        }
        else
        {
            remove(tmpUsuarios);
            return ERR_ARCHIVO_P;
        }
    }

    pudoMover = 1;

    if (!ls_Vacia (tgi->incidencias))
    {
        fdi = fopen(tmpIncidencias,"w");
        if (fdi)
        {
            ls_MoverCorriente(&(tgi->incidencias), LS_PRIMERO);

            while (pudoMover)
            {
                ls_ElemCorriente(tgi->incidencias, &auxTin);
                guardarArchIncidencias(fdi,&auxTin);
                ls_ModifCorriente(&(tgi->incidencias),&auxTin);
                pudoMover = ls_MoverCorriente(&(tgi->incidencias),LS_SIGUIENTE);
            }
            nocreadoi = fclose (fdi);
        }
        else
        {
            remove(tmpUsuarios);
            remove(tmpProyectos);
            return ERR_ARCHIVO_I;
        }
    }


    /*Eliminamos los originales y los pisamos con los temporales */
    if (!nocreadoi){
        remove(archIncidencias);
        rename(tmpIncidencias,archIncidencias);
        }
    if (!nocreadop){
        remove(archProyectos);
        rename(tmpProyectos,archProyectos);
        }
    if (!nocreadou){
        remove(archUsuarios);
        rename(tmpUsuarios,archUsuarios);
        }
    return RES_OK;
}

/**
@function
@name TGI_Crear
@description A partir de los datos encontrados en los archivos de datos, rearma el TGI para comenzar a utilizar Gestor.
@return int
@param tgi:TGI*
@param archProyectos:const char*
@param archUsuarios:const char*
@param archIncidencias:const char*
@author Batman
@see -
*/
int TGI_Crear (TGI *tgi, const char* archProyectos, const char* archUsuarios, const char* archIncidencias)
{
    FILE *fdp, *fdu, *fdi;
    TIN auxTin;
    user_t auxUser;
    project_t auxProject;
    char stg[141];
    int conDatos = 0;


    fdp = fopen(archProyectos,"r");
    fdu = fopen(archUsuarios,"r");
    fdi = fopen(archIncidencias,"r");

    if (fdp && fdu && fdi)
    {
        ls_Crear(&(tgi->incidencias),sizeof(TIN));
        ls_Crear(&(tgi->proyectos),sizeof(project_t));
        ls_Crear(&(tgi->usuarios),sizeof(user_t));

        conDatos = archivoVacio(fdp);
        if (conDatos){
            rewind(fdp);
            while (!feof(fdp))
            {
                fscanf(fdp,"%[^\t\n]\n",stg);
                auxProject.project_id = atoi (stg);
                fscanf(fdp,"%[^\t\n]\n",stg);
                auxProject.project_name = (char*) malloc(sizeof(char)*(strlen(stg)+1));
                strcpy(auxProject.project_name,stg);
                ls_Insertar(&(tgi->proyectos),LS_SIGUIENTE,&auxProject);
            }
        }

        conDatos = archivoVacio(fdu);
        if (conDatos){
            rewind(fdu);
            while (!feof(fdu))
            {
                fscanf(fdu,"%[^\t\n]\n",stg);
                auxUser.user_id = atoi (stg);
                fscanf(fdu,"%[^\t\n]\n",stg);
                auxUser.user_name = (char*) malloc(sizeof(char)*(strlen(stg)+1));
                strcpy(auxUser.user_name,stg);
                ls_Insertar(&(tgi->usuarios),LS_SIGUIENTE,&auxUser);
            }
        }

        conDatos = archivoVacio(fdi);
        if (conDatos){
            rewind(fdi);
            while (!feof(fdi))
            {
                armarTin (fdi,&auxTin);
                ls_Insertar(&(tgi->incidencias),LS_SIGUIENTE,&auxTin);
            }
        }

        fclose(fdi);
        fclose(fdu);
        fclose(fdp);
        return RES_OK;
    }
    else
    {
        if (!fdp) return ERR_ARCHIVO_P;
        if (!fdu) return ERR_ARCHIVO_U;
        if (!fdi) return ERR_ARCHIVO_I;
    }

    return RES_OK;
}

/**
@function
@name TGI_Cerrar
@description Elimina todas las estructuras que forman parte del Gestor de Incidencias.
@return int
@param tgi:TGI*
@author Batman
@see -
*/
int TGI_Cerrar (TGI *tgi)
{
    user_t auxUser;
    project_t auxProject;
    TIN tin;
    int pudoMover = 1;

    TIN_CrearVacio(&tin);


    if (!ls_Vacia(tgi->usuarios))
    {
        ls_MoverCorriente (&(tgi->usuarios),LS_PRIMERO);
        while (pudoMover)
        {
            ls_ElemCorriente (tgi->usuarios,&auxUser);
            free (auxUser.user_name);
            auxUser.user_name=NULL;
            pudoMover = ls_MoverCorriente(&(tgi->usuarios),LS_SIGUIENTE);
        }
    }
    pudoMover = 1;

    if (!ls_Vacia(tgi->proyectos))
    {
        ls_MoverCorriente (&(tgi->proyectos),LS_PRIMERO);
        while (pudoMover)
        {
            ls_ElemCorriente (tgi->proyectos,&auxProject);
            free (auxProject.project_name);
            auxProject.project_name=NULL;
            pudoMover = ls_MoverCorriente(&(tgi->proyectos),LS_SIGUIENTE);
        }
    }
    pudoMover = 1;

    if (!ls_Vacia(tgi->incidencias))
    {
       ls_MoverCorriente (&(tgi->incidencias),LS_PRIMERO);
        while (pudoMover)
        {
            ls_ElemCorriente (tgi->incidencias,&tin);
            TIN_Liberar(&tin);
            pudoMover = ls_MoverCorriente(&(tgi->incidencias),LS_SIGUIENTE);
        }
    }


    ls_Vaciar (&(tgi->usuarios));
    ls_Vaciar (&(tgi->proyectos));
    ls_Vaciar (&(tgi->incidencias));

    return RES_OK;
}

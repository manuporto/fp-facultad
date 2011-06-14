/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 *****************************************************************************/

/* TDA Gestor de Inicidencias
 * Archivo: TDA_GestorIncidencias.c
 * version: 1.0
*/

#include "TDA_GestorIncidencias.h"
#include <malloc.h>
#include <memory.h>

/*****************************************************************************/
/* Implementacion de primitivas */
/*------------------------------*/

int TGI_Cerrar( TGI* tgi)
{
	TNodoSimple *ptroNodo , *ptroSiguiente;
	user_t *ptroUser;
	project_t *ptroProject;
	TIN *ptroTin;

	/* se libera la lista de incidencias */
	for (ptroNodo = tgi->incidencias.Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroTin = (TIN*) ptroNodo->Elem;
		TIN_Liberar ( ptroTin ); /* se libera la incidencia */
      free ( ptroNodo );
	}
	tgi->incidencias.Primero = tgi->incidencias.Corriente = NULL;

	/* Se libera la lista de usuarios */
	for (ptroNodo = tgi->usuarios.Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroUser = (user_t*) ptroNodo->Elem;
		free ( ptroUser->user_name ); /* se libera la memoria para el nombre */
		free ( ptroNodo );
	}
	tgi->usuarios.Primero = tgi->usuarios.Corriente = NULL;

	/* Se libera la lista de Proyectos */
	for (ptroNodo = tgi->proyectos.Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroProject = ptroNodo->Elem;
		/* depende de la estructura de t_proyecto */
		free ( ptroProject->project_name );
		free (ptroNodo);
	}
	tgi->proyectos.Primero = tgi->proyectos.Corriente = NULL;

	return 0;
}
/*----------------------------------------------------------------------------*/

int TGI_GetIncidencia (const TGI *tgi, int inci_id)
{
	TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
/*	TIN *ptroTin;*/
	int encontrado = -1;

/*	ptroLista = (TListaSimple*)&(tgi->incidencias);*/
	memcpy (ptroLista,tgi->incidencias,sizeof(TListaSimple));
	
/*	ptroNodo = ptroLista->Primero;*/
	ls_MoverCorriente(ptroLista, PRIMERO);

	while ( ptroNodo && (encontrado != 0 ))
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroTin = (TIN*) ptroNodo->Elem;
		if ( ptroTin->inci_id == inci_id ) encontrado = 0;
			else
				ptroNodo = ptroSiguiente;
	}

	if (encontrado == 0 ) /* se imprime */
	{
		printf ("Datos de la incidencias: \n");
		printf ("ID: %d\n" , ptroTin->inci_id );
		printf ("ID del usuario que la creo: %d\n" , ptroTin->inci_assigned_user );
		printf ("ID del Proyecto: %d\n" , ptroTin->inci_project_id );
		printf ("descripcion: %s\n" , ptroTin->inci_description );

		return 0;
	}
	return -1;
}

/*----------------------------------------------------------------------------*/

int TGI_GetIncidenciasUsuario( const TGI* tgi, int inci_user, TCola* incidencias)
{

	TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
	TIN *ptroTin;
	int resul = -1 , errorCode;

	ptroLista = (TListaSimple*)&tgi->incidencias;

	for (ptroNodo = ptroLista->Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		/* se verifica que la incidencia esta asignada al usuario */
		ptroTin = (TIN*)ptroNodo->Elem;
		if ( ptroTin->inci_assigned_user == inci_user )
		{
			resul = 0;
			/* se agrega a la cola el elemento de tipo tin */
			errorCode = C_Agregar ( incidencias , ptroNodo->Elem );
			if ( errorCode == FALSE ) return -2;
		};
	}

	return resul;
}
/*----------------------------------------------------------------------------*/
/* este imprime las incidencias */
int TGI_GetIncidenciasUsuarioB( const TGI* tgi, int inci_user )
{
	TCola incidencias;
	TNodoCola *pNodoCola, *pNodoColaS;
	TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
	TIN *ptroTin;
	int resul = -1 , errorCode;

	C_Crear (&incidencias , sizeof(TIN) );
	ptroLista = (TListaSimple*)&tgi->incidencias;

	/* se cargan las incidencias */
	for (ptroNodo = ptroLista->Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		/* se verifica que la incidencia esta asignada al usuario */
		ptroTin = ptroNodo->Elem;
		if ( ptroTin->inci_assigned_user == inci_user )
		{
			resul = 0;
			/* se agrega a la cola el elemento de tipo tin */
			errorCode = C_Agregar ( &incidencias , ptroNodo->Elem );
			if ( errorCode == FALSE ) return -2;
		};
	}

	/* se imprimi las incidencias */
	printf ("Listado de incidencias: \n");
	for (pNodoCola = incidencias.Primero ; (pNodoCola) ; pNodoCola = pNodoColaS )
	{
		pNodoColaS = pNodoCola->Siguiente;
		ptroTin = (TIN*)pNodoCola;
		printf ("ID: %d\n", ptroTin->inci_id );
		printf ("ID de usuario que la creo: %d\n" , ptroTin->inci_user );
		printf ("ID del proyecto al que corresponde: %d\n" , ptroTin->inci_project_id);
		printf ("Descripcion: %s\n" , ptroTin->inci_description );
	}
	/* se libera la estructra de tipo cola */
	C_Vaciar ( &incidencias );

	return resul;
}

/*----------------------------------------------------------------------------*/
int TGI_GetIncidenciasProyecto( const TGI* tgi, int proyecto, TListaSimple* incidencias)
{

	TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
	TIN *ptroTin;
	int resul = -1 , errorCode;

	ptroLista = (TListaSimple*)&tgi->incidencias;

	for (ptroNodo = ptroLista->Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroTin = (TIN*)ptroNodo->Elem;
		/* se verifica que la incidencia corresponda al proyecto */
		if ( ptroTin->inci_project_id == proyecto )
		{
			resul = 0;
			/* se agrega a la lista el elemento de tipo tin */
			errorCode = ls_Insertar ( incidencias , LS_SIGUIENTE , ptroNodo->Elem );
			if ( errorCode == FALSE ) return -2;
		};
	}

	return resul;
}
/*----------------------------------------------------------------------------*/
/* PRE: Lo mismo que en las primeras dos.
   POST: Devuelve 0 si lo pudo obtener, -1 en caso contrario.
   DESC: Que obtenga el historial del estado de la incidencia solicitada y que lo imprima (via stdout).
*/

int TGI_GetHistorialEstadoIn (const TGI *tgi, int inci_id)
{
   TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
	TIN *ptroTin;
	inci_status_t *ptroEstado;
	int encontrado = -1;

	ptroLista = (TListaSimple*)&tgi->incidencias;
	ptroNodo = ptroLista->Primero;

	while ( ptroNodo && (encontrado != 0 ))
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroTin = (TIN*) ptroNodo->Elem;
		if ( ptroTin->inci_id == inci_id ) encontrado = 0;
			else
				ptroNodo = ptroSiguiente;
	}

	if (encontrado == 0 ) /* se imprime */
	{
      ptroLista = (TListaSimple*)&ptroTin->inci_stat_hist;
		printf ("Historial de estados: \n");
      for (ptroNodo = ptroLista->Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
      {
         ptroEstado = ( inci_status_t* ) ptroNodo->Elem;
         printf ("Estado de la incidencia: %d\n" , ptroEstado->stat_desc );
         printf ("ID de usuario que cambio el estado: %d\n" , ptroEstado->stat_user_id );
         printf ("Fecha en que se cambio el estado %s\n" , ptroEstado->stat_date );
      }
      return 0;
	}
	return -1;
}
/*----------------------------------------------------------------------------*/
int TGI_GetComentariosIn (const TGI *tgi, int inci_id)
{
   TListaSimple *ptroLista;
	TNodoSimple *ptroNodo , *ptroSiguiente;
	TIN *ptroTin;
	inci_comment_t *ptroComm;
	int encontrado = -1;

	ptroLista = (TListaSimple*)&tgi->incidencias;
	ptroNodo = ptroLista->Primero;

	while ( ptroNodo && (encontrado != 0 ))
	{
		ptroSiguiente = ptroNodo->Siguiente;
		ptroTin = (TIN*) ptroNodo->Elem;
		if ( ptroTin->inci_id == inci_id ) encontrado = 0;
			else
				ptroNodo = ptroSiguiente;
	}

	if (encontrado == 0 ) /* se imprime */
	{
      ptroLista = (TListaSimple*)&ptroTin->inci_comm;
		printf ("Listado de Comentarios : \n\n");
      for (ptroNodo = ptroLista->Primero ; (ptroNodo) ; ptroNodo = ptroSiguiente )
      {
         ptroComm = ( inci_comment_t* ) ptroNodo->Elem;
         printf ("ID del usuario :  %d\n" , ptroComm->comm_user_id );
         printf ("Fecha del comentario : %s\n" , ptroComm->comm_date );
         printf ("Comentario realizado %s\n\n" , ptroComm->comm_desc );
      }
      return 0;
	}
	return -1;
}
/*----------------------------------------------------------------------------*/
/*
   PRE: tgi creado y no vacio.
   POST: Devuelve 0 si pudo agregar al usuario exitosamente,
         -1 si no pudo agregarlo con éxito (creo que no podría pasar nunca).
   DESC: Agrega un usuario a la lista de la estructura.
         Para el campo del ID, autogenérenlo sumándole uno al último ID agregado.
*/

int TGI_AgregarUsuario( TGI *tgi, char* user_name)
{
   TListaSimple *ptroLista;
   user_t user , *ptroUser;
   int tamanio , error;

   /* se aloja memoria para el nombre */
   tamanio = strlen ( user_name ) + 1 ;
   user.user_name = ( char* ) malloc (sizeof (char) * tamanio );
   if ( !user.user_name )
      return -1;
   strcpy (user.user_name , user_name );

   /* se genera el ID */
   ptroLista = ( TListaSimple* )&tgi->usuarios;
   while ( ls_MoverCorriente ( ptroLista , LS_SIGUIENTE ) != 0 );
   ptroUser = ( user_t* ) ptroLista->Corriente->Elem;
   user.user_id = ( ptroUser->user_id ) + 1;
   error = ls_Insertar ( ptroLista , LS_SIGUIENTE , &user );
   if (error == -1 )
   {
      free( user.user_name );
      return -1;
   }
   free (user.user_name);
   return 0;
}
/*----------------------------------------------------------------------------*/
/*
   PRE: TGI creada y no vacia.
   POST: Devuelve 0 si pudo agregar el proyecto exitosamente, -1 si no pudo agregarlo con éxito (creo que no podría pasar nunca).
   DESC: Agrega un proyecto a la lista de la estructura. Para el campo del ID, autogenérenlo sumándole uno al último ID agregado.
*/

int TGI_AgregarProyecto (const TGI *tgi, char* project_name)
{
   TListaSimple *ptroLista;
   project_t project , *ptroProject;
   int tamanio , error;

   /* se aloja memoria para el nombre */
   tamanio = strlen ( project_name ) + 1 ;
   project.project_name = ( char* ) malloc (sizeof (char) * tamanio );
   if ( !project.project_name )
      return -1;
   strcpy (project.project_name , project_name );

   /* se genera el ID */
   ptroLista = ( TListaSimple* )&tgi->proyectos;
   while ( ls_MoverCorriente ( ptroLista , LS_SIGUIENTE ) != 0 );
   ptroProject = ( project_t* ) ptroLista->Corriente->Elem;
   project.project_id = ( ptroProject->project_id ) + 1;
   error = ls_Insertar ( ptroLista , LS_SIGUIENTE , &project );
   if (error == -1 )
   {
      free( project.project_name );
      return -1;
   }
   free (project.project_name);
   return 0;
}
/*----------------------------------------------------------------------------*/
/*
   PRE: hay suficiente memoria para insertar una estructura de tipo TIN.
   POST: Devuelve el ID de la incidencia creada si lo pudo hacer. -1 si no existe el ID del proyecto, -2 si no existe el ID del usuario, -3 en caso de otro error.
   DESC: Agregar una incidencia llamando a la función TIN_Crear, la que te lo devuelve en un TIN que deben agregar a la lista de la estructura. Para el campo del ID, autogenérenlo sumándole uno al último ID agregado. Validen todos los enumerados.
*/
int TGI_AgregarIncidencia (TGI* tgi, tipo_inci_t inci_type, prior_inci_t inci_priority,
      int inci_user, int inci_assigned_user, char* inci_date_created, int inci_project_id,
      char* inci_summary, char* inci_description)
{
   TIN tin;
   TListaSimple *ptroLista;
   TNodoSimple *ptroNodo;
   project_t *ptroProject;
   user_t *ptroUser;
   int encontrado, inci_id , error;


   /* se busca si existe el proyecto */
   ptroLista = ( TListaSimple* ) &tgi->proyectos;
   ptroNodo = ptroLista->Primero;
   encontrado = -1;
   while ( ptroNodo && ( encontrado != 0 ) )
   {
      ptroProject = ( project_t* ) ptroNodo->Elem;
      if (ptroProject->project_id == inci_project_id ) encontrado = 0;
         else
            ptroNodo = ptroNodo->Siguiente;
   }
   if ( encontrado == -1 ) return -1; /* no existe el ID del proyecto */

   /* se busca si existe el usuario */
   ptroLista = ( TListaSimple* ) &tgi->usuarios;
   ptroNodo =ptroLista->Primero;
   encontrado = -1;
   while ( ptroNodo && (encontrado != 0 ) )
   {
      ptroUser = ( user_t* ) ptroNodo->Elem;
      if (ptroUser->user_id == inci_user ) encontrado = 0;
         else
            ptroNodo = ptroNodo->Siguiente;
   }
   if ( encontrado == -1 ) return -2; /* no existe el ID del usuario */

   /* se genera el inci_id */
   ptroLista = (TListaSimple*) &tgi->incidencias;
   while ( ls_MoverCorriente (ptroLista , LS_SIGUIENTE ) != 0 );
   ls_ElemCorriente ( *ptroLista , &tin );
   inci_id = tin.inci_id + 1;
   TIN_Liberar (&tin);

   /* se crea la estructura TIN */
   error = TIN_Crear ( &tin, inci_id , inci_type , inci_priority , inci_user ,
      inci_assigned_user, inci_date_created , inci_project_id,
      inci_summary, inci_description);

   if (error == -1 ) return -3;
      else
         return inci_id;
}
/*----------------------------------------------------------------------------*/


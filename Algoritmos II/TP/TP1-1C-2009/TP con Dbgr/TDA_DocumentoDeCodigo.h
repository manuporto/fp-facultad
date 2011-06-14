/******************************************************************************
 *                   Algoritmos y Programaci�n II - 75.41                     *
 *                        C�tedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingenier�a - Universidad de Buenos Aires            *
 ******************************************************************************/

/* TDA Documento de Codigo
 * Archivo: TDA_DocumentoDeCodigo.h
 * version: 1.0.0
 */

#ifndef TDA_DOCUMENTO_DE_CODIGO_H_
#define TDA_DOCUMENTO_DE_CODIGO_H_

/* Definimos Constantes de Errores */
#define ERR_ERR "Error grave detectado. El programa no puede continuar.\n"

#define ERR_ARG "ERROR: Falta la ruta al archivo de configuracion o al archivo a documentar.\n"
#define ERR_CONFIG "ERROR: No se pudo abrir el archivo de configuracion\n"
#define ERR_FUENTE "ERROR: No se pudo abrir el archivo a documentar.\n"
#define ERR_MEM "ERROR: No hay suficiente memoria.\n"

#define ERR_DESCRIP "WARNING: Linea %i - %s\n"
#define ERR_SINTAXIS "Error de sintaxis."
#define ERR_NOTAG "Tag inexistente."
#define ERR_NOSUBTAG "Subtag inexistente."
#define ERR_MONO "Comentario monolinea. Descartado."
#define ERR_DESCARTADO "Comentario descartado."
#define ERR_LINEAVACIA "Linea vacia"
/* / Definimos Constantes de Errores */

/* Definimos Constantes de tipo de comentario */
#define TAG_APERTURA "/**"
#define TAG_CIERRE "*/"
/* / Definimos Constantes de tipo de comentario */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var_array.h"
#include "getString.h"



/* Tipo de estructura para el TDA */
typedef struct TDC{
         char *archivoOrigen;  /* Nombre del archivo a documentar */
         V_Array listaTags;    /* Puntero a los tipos de TAG. */
} TDC;


/******************************************************************************/
/* Definicion de primitivas */
/*--------------------------*/

/*
  FUNCION: Crea un TDA DocumentoDeCodigo asociado a un archivo de c�digo
           fuente C para su documentaci�n autom�tica.

  PRE: tdc tiene suficiente memoria reservada para una estructura de tipo TDC.
       achPrograma es una ruta de archivo v�lida.
       archConfig es una ruta de archivo v�lida.

  POST: Si devuelve 0, tdc abierto. Si hubo error al abrir el archivo devuelve -1.

  PARAMETROS:
      tdc: -
      archProgram: Ruta al archivo a documentar.
      archConfig: Ruta al archivo de configuraci�n.
*/

int TDC_Crear ( TDC* tdc, char* archPrograma, char* archConfig);

/*----------------------------------------------------------------------------*/
/*
  FUNCI�N: Cierra el tdc.

  PRE: tdc abierto.

  POST: Si devuelve 0, tdc cerrado. En otro caso devuelve -1.

  PAR�METROS:
      tdc: El manipulador del archivo a documentar.
*/
int TDC_Cerrar( TDC* tdc);

/*----------------------------------------------------------------------------*/
/*
  FUNCI�N: Genera un archivo con la documentaci�n.

  PRE: tdc abierto. archDoc es una ruta de archivo v�lida.

  POST: Si devuelve 0, escribi� la documentaci�n autom�tica en archDoc.
        Si devuelve -1 hubo error.

  PAR�METROS:
     tdc: El manipulador del archivo al cual escribir.
     archDoc: Nombre del archivo de documentacion.
*/

int TDC_Documentar ( TDC* tdc, char* archDoc);

/*----------------------------------------------------------------------------*/

#endif /*TDA_DOCUMENTO_DE_CODIGO_H_*/

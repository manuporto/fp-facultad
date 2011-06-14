/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra: Lic. Gustavo Carolo                        *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/

/* TDA Documento de Codigo
 * Archivo: TDA_DocumentoDeCodigo.h
 * version: 1.0.0
 */

#ifndef TDA_DOCUMENTO_DE_CODIGO_H_
#define TDA_DOCUMENTO_DE_CODIGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var_array.h"
#include "getString.h"


/* Tipo de dato */
typedef struct TAG{
        char *nombre; /* apunta al nombre principal de tag */
        char *descrip; /* Descripción del subtag */
        V_Array subTags; /* contiene los subTags */
}TAG;



/* Tipo de estructura para el TDA */
typedef struct TDC{
         char *archivoOrigen;  /* Nombre del archivo a documentar */
         V_Array listaTags;    /* Puntero a los tipos de TAG. */
} TDC;


/******************************************************************************/
/* Definicion de primitivas */
/*--------------------------*/

/*
  FUNCION: Crea un TDA DocumentoDeCodigo asociado a un archivo de código
           fuente C para su docmentacion automatica.

  PRE: Tdc tiene suficiente memoria reservada para una estructura de tipo TDC.
      achPrograma es una ruta de archivo válida.

  POST: Si devuelve 0, tdc abierto.  Si hubo error al abrir el
       archivo devuelve -1.

  PARAMETROS:
      tdc: -
      archProgram: Ruta al archivo a documentar.
*/

int TDC_Crear ( TDC* tdc, char* archPrograma, char* archConfig);

/*----------------------------------------------------------------------------*/
/*
  FUNCIÓN: Cierra el tdc.

  PRE: Tdc abierto.

  POST: Si devuelve 0, tdc cerrado. En otro caso devuelve -1.

  PARÁMETROS:
      Tdc: El manipulador del archivo a documentar.
*/
int TDC_Borrar (TDC* tdc);
int TDC_Cerrar( TDC* tdc);

/*----------------------------------------------------------------------------*/
/*
  FUNCIÓN: Genera un archivo con la documentación..

  PRE: Tdc abierto.  ArchDoc es una ruta de archivo válida.

  POST: Si devuelve 0, escribió la documentación automática en archDoc.
        Si devuelve -1 hubo error.

  PARÁMETROS:
     Tdc: El manipulador del archivo al cual escribirPARÁMETROS.
     archDoc: Nombre del archivo de documentacion.
*/

int TDC_Documentar ( TDC* tdc, char* archDoc);

/*----------------------------------------------------------------------------*/

#endif /*TDA_DOCUMENTO_DE_CODIGO_H_*/

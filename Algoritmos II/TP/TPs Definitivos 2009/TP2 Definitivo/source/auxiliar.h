#ifndef __AUXILIAR_H__
#define __AUXILIAR_H__

#include "TGI_GestorIncidencias.h"
#include "TIN_Incidencia.h"
#include "constantes.h"
/*#include "cmemdbg.h"*/

int validarTipoIncidencia (int inci_type);

int validarPrioridad (int inci_priority);

int opciones (char* argv[], int argc, int i, char *archProyectos, char *archUsuarios, char *archIncidencias);

int cargarConfig (char *archIncidencias, char *archUsuarios, char *archProyectos);

int crearConfig (char* archIncidencias, char* archUsuarios, char* archProyectos);

int abrirCrear (char *archIncidencias, char *archUsuarios, char *archProyectos);


#endif

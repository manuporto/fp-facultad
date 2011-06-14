#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#define SEP_STAT_FIN "SEP_STAT_FIN\n"
#define SEP_COMM_FIN "SEP_COMM_FIN\n"

#define NERR_INVALIDCOMMAND "Comando inexistente.\n"
#define NERR_NUMARGUMENTOS "Error en la cantidad de argumentos.\n"
#define NERR_RUTASARCHIVOS "Error en las rutas de los archivos.\n"
#define NERR_ESTADO "Estado ingresado inexistente.\n"
#define NERR_FECHA "Fecha ingresada invalida.\n"
#define NERR_USUARIO "Usuario inexistente.\n"
#define NERR_PROJECT "Proyecto inexistente.\n"
#define NERR_INCIDENCIA "Incidencia inexistente.\n"
#define NERR_MEM "No hay memoria suficiente para completa la operacion.\n"
#define NERR_ARCHIVO_U "No se puede abrir el archivo de usuarios.\n"
#define NERR_ARCHIVO_I "No se puede abrir el archivo de incidencias.\n"
#define NERR_ARCHIVO_P "No se puede abrir el archivo de proyectos.\n"
#define NERR_NOMBRE_USUARIO_LARGO "El nombre ingresado supera el maximo permitido de 140 caracteres.\n"
#define NERR_NOMBRE_PROYECTO_LARGO "El nombre del proyecto ingresado supera el maximo permitido de 140 caracteres.\n"
#define NERR_INVALID_TIPO_INCIDENCIA "El codigo de incidencia ingresado es invalido.\n"
#define NERR_INVALID_TIPO_PRIORIDAD "El codigo de prioridad ingresado es invalido.\n"
#define NERR_SUMMARY_LARGO "El resumen ingresado supera el maximo permitido de 140 caracteres.\n"
#define NERR_DESC_LARGA "La descripcion ingresada supera el maximo permitido de 140 caracteres.\n"
#define NERR_ARCH_CFG "La ruta de los archivos a utilizar no esta incializada.\n"
#define NERR_BAD_USER "El usuario que intento cambiar el estado no es el usuario encargado de la incidencia.\n"

#define ERR_INVALIDCOMMAND  -2
#define ERR_NUMARGUMENTOS   -3
#define ERR_RUTASARCHIVOS   -4
#define ERR_ESTADO          -5
#define ERR_FECHA           -6
#define ERR_USUARIO         -7
#define ERR_PROJECT         -8
#define ERR_INCIDENCIA      -9
#define ERR_MEM             -10
#define ERR_ARCHIVO_U       -11
#define ERR_ARCHIVO_I       -12
#define ERR_ARCHIVO_P       -13
#define ERR_BAD_USER        -14

#define INFO_CAM_EST_OK "El cambio de estado se realizo exitosamente!\n"
#define INFO_CAM_COMM_OK "El comentarios se ingreso exitosamente!\n"
#define INFO_DATOS_TIN "ID Incidencia: %i\nTipo de Incidencia: %s\nPrioridad: %s\nID del Creador: %i\nID del Usuario Asignado: %i\nFecha de Creacion: %s\nID del Proyecto: %i\nResumen: %s\nDescripcion: %s\n\n"
#define INFO_DATOS_ESTADO "Estado: %s\nFecha: %s\nID de Usuario: %i\n\n"
#define INFO_DATOS_COMENTARIO "Fecha: %s\nUsuario: %i\nComentario: %s\n\n"
#define INFO_NO_COMMENTS "No existen comentarios para la incidencia seleccionada.\n"
#define INFO_NO_INCI_USER "No existen incidencias para el usuario seleccionado.\n"
#define INFO_NO_INCI_PROJECT "No existen incidencias para el proyecto seleccionado.\n"
#define INFO_ADD_USER_OK "Usuario ingresado exitosamente.\n"
#define INFO_ADD_PROJECT_OK "Proyecto ingresado exitosamente!\n"
#define INFO_ADD_INCI_OK "Incidencia ingresada exitosamente!\n"
#define INFO_NOMBRE_ARCHIVOS "Archivo de Incidencias: %s\nArchivo de Proyectos: %s\nArchivo de Usuarios: %s\n"

#define RES_OK              0
#define RES_ERR             -1


#endif

#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "constantes.h"
/*#include "cmemdbg.h"*/


/**
@function
@name main
@description Función main del programa
@return int
@param argc:int
@param argv:char**
@author Batman
@see -
*/
int main(int argc, char* argv[])
{
    char archIncidencias[141];
    char archUsuarios[141];
    char archProyectos[141];

    if (argc==1) /*Si no trae argumentos extras */
    {
        strcpy(archIncidencias,"incidencias.dat");
        strcpy(archUsuarios,"usuarios.dat");
        strcpy(archProyectos,"proyectos.dat");
        abrirCrear (archIncidencias, archUsuarios, archProyectos);
        crearConfig (archIncidencias, archUsuarios, archProyectos);
    }
    else
    {

        if (argc==4 && *argv[1]!='-' && *argv[2]!='-' && *argv[3]!='-') /* Nos están pasando sólo las rutas */
        {
            strcpy(archIncidencias,argv[1]);
            strcpy(archUsuarios,argv[2]);
            strcpy(archProyectos,argv[3]);
            abrirCrear (archIncidencias, archUsuarios, archProyectos);
            crearConfig (archIncidencias, archUsuarios, archProyectos);
/*            PrintMemoryLeakInfo();*/
            return RES_OK;
        }
        else if (argc==4 && *argv[1]!='-') fprintf (stderr,NERR_RUTASARCHIVOS);


        if (argc>4 && *argv[1]!='-' && *argv[2]!='-' && *argv[3]!='-') /* Nos están pasando las rutas y empezando el programa*/
        {
            if (*argv[4]=='-')
            {
                strcpy(archIncidencias,argv[1]);
                strcpy(archUsuarios,argv[2]);
                strcpy(archProyectos,argv[3]);
                abrirCrear (archIncidencias, archUsuarios, archProyectos);
                crearConfig (archIncidencias, archUsuarios, archProyectos);
                cargarConfig (archIncidencias, archUsuarios, archProyectos);
                opciones(argv, argc, 4, archProyectos, archUsuarios, archIncidencias);
            }
            else fprintf (stderr,NERR_INVALIDCOMMAND);
        }

        if (*argv[1]=='-')
        {
            if (cargarConfig (archIncidencias, archUsuarios, archProyectos)==RES_ERR)
            {
                strcpy(archIncidencias,"incidencias.dat");
                strcpy(archUsuarios,"usuarios.dat");
                strcpy(archProyectos,"proyectos.dat");
            }
            abrirCrear (archIncidencias, archUsuarios, archProyectos);
            crearConfig (archIncidencias, archUsuarios, archProyectos);
            opciones(argv, argc, 1, archProyectos, archUsuarios, archIncidencias);
        }
    }

/*    PrintMemoryLeakInfo();*/
    return RES_OK;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_DocumentoDeCodigo.h"

int main(int argc, char* argv[])
{
	TDC tdc;
	char *archPrograma;
	char *archConfig;
	char *archDoc;

    fprintf (stderr,"Prueba de stderr\n\n");

    archPrograma = "prueba.c";
	archConfig = "config.txt";
	archDoc = "prueba.txt";
	printf("Cantidad de argumentos: %d\n\n",argc);

    if (TDC_Crear (&tdc, archPrograma, archConfig) == -1) printf ("Error al crear");
    else
    {
        TDC_Documentar (&tdc,archDoc);
        TDC_Borrar (&tdc);
        TDC_Cerrar(&tdc);

    }

    printf ("Terminó todo bien\n");
	return 0;
}

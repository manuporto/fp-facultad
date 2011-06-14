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

    if (argc<3)
    {
        fprintf (stderr,ERR_ARG);
        return 1;
    }

    archPrograma = argv[2];
	archConfig = argv[1];
	if (argc>3) archDoc = argv[3];
	else
	{
        archDoc = (char*)malloc(strlen(argv[2])+5);
	    strcpy (archDoc,argv[2]);
	    strcat(archDoc,".txt");
	}


    if (TDC_Crear (&tdc, archPrograma, archConfig) == -1) fprintf (stderr,ERR_ERR);
    else
    {
        TDC_Documentar (&tdc,archDoc);
        TDC_Cerrar(&tdc);
    }

    if (argc<=3) free (archDoc);


    PrintMemoryLeakInfo();

    getch();


	return 0;
}

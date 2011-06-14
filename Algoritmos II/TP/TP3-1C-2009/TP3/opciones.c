#include "opciones.h"

void singleAux (char* argv[] )
{
    TExpresion expr;
    TExpresion deriv;
    TExpresion simpl;
    int derivo=0;
    int simplifico=0;
    char *ecuacion;
    char *exp_simpl;

    printf ("Entro\n");

    Expresion_Crear(&expr);
    Expresion_Crear(&simpl);
    Expresion_Crear(&deriv);

    printf ("%s\n",argv[1]);


    if (strcmp(argv[1],"--single")==0)
	{
        ecuacion = (char*)malloc((strlen(argv[2])*sizeof(char))+1);
        strcpy (ecuacion,argv[2]);

        if ((Expresion_Parsear(&expr,ecuacion,VAR)) != 1)
        {
            fprintf(stderr,NERR_EXPRESION);
            Expresion_Destruir(&simpl);
            Expresion_Destruir(&deriv);
            Expresion_Destruir(&expr);
            return;
        }

        derivo = Expresion_Derivar(&expr,&deriv);
        if (derivo == 0)
        {
            fprintf (stderr,NERR_DERIVAR);
        }
        else
        {
            simplifico = Expresion_Simplificar(&deriv,&simpl);

            if (simplifico == 1) Expresion_AString(&simpl,&exp_simpl);
            else Expresion_AString(&deriv,&exp_simpl);
            fprintf (stdout,"%s\n",exp_simpl);
            Expresion_Destruir(&simpl);
            Expresion_Destruir(&deriv);
            Expresion_Destruir(&expr);
            return;
        }
	}
	else fprintf (stderr,NERR_COMANDO);

    Expresion_Destruir(&simpl);
    Expresion_Destruir(&deriv);
    Expresion_Destruir(&expr);
}

void fileAux (char* argv[] )
{
    FILE *fdi;
    FILE *fdo;
    FILE *fdl;
    char *input;
    char *output;
    char *log;
    char ecuacion[80];
    TExpresion expr;
    TExpresion deriv;
    TExpresion simpl;
    int derivo;
    int simplifico;
    char* exp_simpl;
    int linea = 0;
    int success = 0;

    if (strcmp(argv[1],"--file")==0)
    {
        input = (char*)malloc((strlen(argv[2])*sizeof(char))+1);
        output = (char*)malloc((strlen(argv[3])*sizeof(char))+1);
        log = (char*)malloc((strlen(argv[4])*sizeof(char))+1);
        strcpy(input,argv[2]);
        strcpy(output,argv[3]);
        strcpy(log,argv[4]);


        fdi = fopen (input,"r");
        if (!fdi)
        {
            free (input);
            free (output);
            free (log);
            fprintf (stderr,NERR_ARINPUT);
            return;
        }

        fdo = fopen (output,"w");

        if (!fdo)
        {
            fclose (fdi);
            free (input);
            free (output);
            free (log);
            fprintf (stderr,NERR_AROUTPUT);
            return;
        }

        fdl = fopen (log,"w");

        if (!fdl)
        {
            fclose (fdi);
            fclose (fdo);
            free (input);
            free (output);
            free (log);
            fprintf (stderr,NERR_ARLOG);
            return;
        }

        while (!(feof(fdi)))
        {
            linea++;
            Expresion_Crear(&expr);
            Expresion_Crear(&simpl);
            Expresion_Crear(&deriv);
            fscanf(fdi,"%s\n",ecuacion);
            printf ("Ecuacion: %s\n",ecuacion);

            if ((Expresion_Parsear(&expr,ecuacion,VAR)) != 1)
            {
                fprintf(fdl,NERR_EXPRESION_FILE,linea);
            }
            else
            {
                derivo = Expresion_Derivar(&expr,&deriv);
                if (derivo == 0)
                {
                    fprintf (fdl,NERR_DERIVAR_FILE,linea);
                }
                else
                {
                    simplifico = Expresion_Simplificar(&deriv,&simpl);

                    printf ("Hola");
                    if (simplifico == 1) Expresion_AString(&simpl,&exp_simpl);
                    else Expresion_AString(&deriv,&exp_simpl);
                    fprintf (stdout,"Linea %i:  %s\n",linea,exp_simpl);
                    fprintf (fdo,"Linea %i:  %s\n",linea,exp_simpl);
                    success++;
                    free (exp_simpl);
                }
            }
            Expresion_Destruir(&simpl);
            Expresion_Destruir(&deriv);
            Expresion_Destruir(&expr);
        }

        fprintf (fdl,INFO_TOTALES,success,linea-success);
        fclose (fdi);
        fclose (fdo);
        fclose (fdl);
        free (input);
        free (output);
        free (log);
	}
	else fprintf (stderr,NERR_COMANDO);

}

void opciones (int argc, char* argv[])
{
				if (argc == 3)
                    singleAux (argv);
                else
                    if (argc == 5)
                        fileAux(argv);
                    else
                        fprintf (stderr,NERR_ARGUMENTOS);
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fd;
    char stg[509];
    int project_id = 21;
    char *project_name = "Lorem ipsum dolor sit amet.";
    char fin[509];

    /* el problema es con el tamaño máximo de una línea, tendriamos que
    hard codearle que los cometarios, descriptions y summarys tengan un límite
    de chars y así si, cuando el usuario quiere ingresar la descripción, que al
    argv[i] donde está la descripción le haga una validación que no sea mas grande
    que x cantidad de caracteres, si es muy grande que le tire un error por pantalla
    se que es un asco, pero por ahora es la manera de taparlo que se me ocurre */


    /* esto funciona con una cantidad preestabledica de chars, si no salta.
    En el fscanf en el %[^\t] si no le especificas algo como el \t explota
    es raro:P probalo y vas a ver que anda, bueno nos vemos mañana */
    fd = fopen ("test.txt", "a");
    fprintf (fd,"%i\t%s\n", project_id, project_name);
    fclose (fd);

    fd = fopen ("test.txt", "r");

    while (!feof(fd))
    {
        fscanf(fd,"%[^\t\n]\n",fin);
        printf( "El ID es %i \n",atoi(fin));
        fscanf(fd,"%[^\t\n]\n",fin);
        printf( "El Nombre es: %s \n",fin);
        printf ("\n");
    }

    fclose(fd);
    return 0;
}

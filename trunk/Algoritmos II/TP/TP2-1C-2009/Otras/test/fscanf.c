#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
   FILE *fd;
   char *nombre = "prueba.dat";
   int id;
   char name[50], name2[50],name3[50];
   char sep[2]="_";

   fd = fopen (nombre,"r");

    fscanf (fd,"%i",&id);

    fscanf (fd,"%s",&name);


    nombre = strtok(name,sep);
    printf ("%s ",nombre);

    while( (nombre = strtok( NULL, sep )) != NULL )    // Posteriores llamadas
     printf( "%s ", nombre );




/*    printf ("%s (%i)",name,id);*/

   fclose (fd);
   return 0;
}

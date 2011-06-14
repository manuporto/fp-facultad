#include <stdio.h>
#include "archivo.h"

int Archivo_Abrir(FILE *fichero,char* nombre,char* parametros)
{
   fichero=fopen(nombre,parametros);
   if(!fichero) {
       printf("El fichero %s no existe o no puede ser abierto.\n", nombre);
       return 0;
   
   return 1;
}







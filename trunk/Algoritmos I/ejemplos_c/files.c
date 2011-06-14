/****************************************************************************
 * files.c
 *
 * Programa de ejemplo de escritura de registros en un archivo binario.
 * Algoritmos y Programación I
 * Catedra: Pablo Guarna.
 *
 * Para compilar desde linea de comandos (por ejemplo, con MinGW):
 *    gcc files.c -o files
 *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE      30
#define MAX_DIRECCION   30

#define OK			 0
#define ERROR		-1


typedef struct
{
  char nombre[MAX_NOMBRE];
  char direccion[MAX_DIRECCION];
  int edad;
} tPersona;



int main(int argc, char *argv[])
{
  /* Archivo binario con registros de personas */
  FILE *personas;
  tPersona persona;

  personas = fopen("personas.dat", "w+b");   /* read/write/create/truncate */
  if ( personas == NULL )
  {
    printf("Error abriendo/creando el archivo. \n");
    return ERROR;
  }


  /*	Cargo un registro con datos de una persona, para despues
			escribirlo en el archivo. Esto deberia cargarlo el usuario
			por teclado dentro de un while. */
  strcpy(persona.nombre,    "María Rodriguez");
  strcpy(persona.direccion, "Av. Paseo Colon 850");
  persona.edad = 40;


  /*	Escribo el registro en el archivo. La función fwrite() recibe los
			siguientes parametros:
      - Puntero al registro que se va a escribir.
      - Tamaño del registro que se va a escribir.
      - Cantidad de registros que se van a escribir.
      - Puntero al archivo.
			Y retorna la cantidad de registros que efectivamente se escribieron
			al archivo.  */
  if ( fwrite(&persona, sizeof(tPersona), 1, personas) != 1 )
  {
    printf("Error al escribir en el archivo. \n");
    return ERROR;
  }
  printf("El registro se escribió con éxito. \n");

	fclose(personas);

  return OK;
}

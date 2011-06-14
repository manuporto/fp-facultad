/* ----------------------------------------------------------------------
                                Ordenar.c

   Descripci¢n: Programa de demostraci¢n de t‚cnicas de ordenamiento.
                Forma parte de el art¡culo sobre algoritmos de
                ordenamiento en www.conclase.net.
   Autor      : Juli n Hidalgo.
   Contacto   : jhida003@pinhue.ufro.cl, nirvananomuere@yahoo.com
   Notas      : Para compilar en LccWin32 incluir tcconio.lib en el
                linker (en Project/Configuration/Linker/"Additional
                files to be included in the link").

   ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Aprovechamos las funciones de consola si las trae el compilador.
   EL programa no las necesita, pero queda mejor si se puede borrar
   la pantalla y esperar a que se presione una tecla */
#if defined DJGPP || defined __TURBOC__  || \
    defined  __BORLAND__ || defined __LCC__
     #define __CONIO_SOPORTADO__
#endif

#ifdef __CONIO_SOPORTADO__
     #include <conio.h>
     #define PAUSA() \
          printf ("Presione una tecla para volver al men£..."); getch()
     #define LEER_TECLA() getch()
     #define LIMPIAR_PANTALLA() clrscr()
#elif defined __MINGW32__
     #define LEER_TECLA() getchar()
     #define PAUSA() system("PAUSE")
     #define LIMPIAR_PANTALLA() system("CLS")
     #else
          #define LEER_TECLA() getchar()
          #define PAUSA() getchar()
          #define LIMPIAR_PANTALLA()
#endif

/* El tama¤o del arreglo: s¢lo 20 para que quepa en la pantalla */
#define TAM 20
/* La opci¢n para salir */
#define SALIR '7'

/* ----------------------------------------------------------------------
   Definición de funciones.
   ---------------------------------------------------------------------- */
void menu(void);                       /* Presenta el men£                */
int leer_opcion(void);                 /* Lee la opci¢n del usuario       */
int generar_elementos (int arreglo[]); /* Genera n£meros aleatorios para
                                          llenar el arreglo               */
void mostrar (int arreglo[]);          /* Imprime el arreglo              */
void burbuja (int arreglo[]);          /* Ordenamiento burbuja            */
void seleccion (int arreglo[]);        /* Ordenamiento por selecci¢n      */
int menor (int arreglo[], int desde);  /* Utilizada por seleccion(): busca
                                          el elemento menor del arreglo   */
void insercion (int arreglo[]);        /* Ordenamiento por inserci¢n      */
void quicksort (int arreglo[]);        /* Ordenamiento r pido             */
void ord_rap (int arreglo[], int inf, int sup);
                                       /* Parte recursiva de quicksort()  */
void copiar_arr (int *desde, int *hacia); /* Copia desde en hasta         */
/* ---------------------------------------------------------------------- */

int main()
{
     int arreglo[TAM];
     int copia_arreglo[TAM];
     char opcion = 0;

     /* Llenamos el arreglo con n£meros al azar por primera vez */
     generar_elementos(arreglo);
     copiar_arr(arreglo, copia_arreglo);  /* Guardamos una copia */

     while (opcion != SALIR)
          {
          menu();
          opcion = leer_opcion();
          /* Ejecutamos la funci¢n correspondiente a la opci¢n */
          switch (opcion)
               {
               case '1':
                    /* Llenamos el arreglo con n£meros al azar */
                    generar_elementos(arreglo);
                    /* Guardamos una copia */
                    copiar_arr(arreglo, copia_arreglo);
                    LIMPIAR_PANTALLA();
                    printf ("\n\n\tSe generaron los siguientes elementos:\n");
                    mostrar (arreglo);
                    break;
               case '2':
                    LIMPIAR_PANTALLA();
                    printf ("\n\n\tLos elementos del arreglo son:\n");
                    mostrar (arreglo);
                    break;
               case '3':
                    burbuja (arreglo);
                    copiar_arr(copia_arreglo, arreglo);  /* Restauramos */
                    break;
               case '4':
                    seleccion (arreglo);
                    copiar_arr(copia_arreglo, arreglo);  /* Restauramos */
                    break;
               case '5':
                    insercion (arreglo);
                    copiar_arr(copia_arreglo, arreglo);  /* Restauramos */
                    break;
               case '6':
                    quicksort (arreglo);
                    copiar_arr(copia_arreglo, arreglo);  /* Restauramos */
                    break;
               }
          }

     return 0;
}

void menu(void)
{
     LIMPIAR_PANTALLA();
     printf ("\n\n\t   Men£:\n");
     printf ("\n\t1) Generar los elementos en forma aleatoria.");
     printf ("\n\t2) Mostrar los elementos.");
     printf ("\n\t3) Ordenamiento burbuja.");
     printf ("\n\t4) Ordenamiento por selecci¢n.");
     printf ("\n\t5) Ordenamiento por inserci¢n.");
     printf ("\n\t6) Ordenamiento r pido (QUICKSORT).");
     printf ("\n\t7) Salir.");
     printf ("\n\n\t   Ingrese su opci¢n por favor: ");
}

int leer_opcion(void)
{
     char opcion;

     opcion = LEER_TECLA();
     while (opcion < '1' || opcion > SALIR)
          {
          opcion = LEER_TECLA();
          }

     return opcion;
}

int generar_elementos (int arreglo[])
{
     int i;

     /* Introducimos una semilla para los n£meros aleatorios */
     srand ((unsigned) time(NULL));

     for (i=0; i<TAM; i++)
          arreglo[i] = rand()%TAM;    /* S¢lo n£meros peque¤os... */

     return TAM;
}

void mostrar (int arreglo[])
{
     int i;

     for (i=0; i<TAM; i++)
          printf ("\n\tElemento[%2d] = %d", i, arreglo[i]);

     printf ("\n\n\t");
     PAUSA();
}

void burbuja (int arreglo[])
{
     int i, j;
     int temp;

     for (i=1; i<TAM; i++)
          for (j=0; j<TAM - i; j++)
               if (arreglo[j] > arreglo[j+1])
                    {
                    /* Intercambiamos */
                    temp = arreglo[j];
                    arreglo[j] = arreglo[j+1];
                    arreglo[j+1] = temp;
                    }

     LIMPIAR_PANTALLA();
     printf ("\n\n\tOrdenamiento burbuja.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo);
}

void seleccion (int arreglo[])
{
     int i;
     int temp, pos_men;

     for (i=0; i<TAM - 1; i++)
          {
          /* Buscamos el elemento menor */
          pos_men = menor(arreglo, i);
          /* Lo colocamos en el lugar que le corresponde */
          temp = arreglo[i];
          arreglo[i] = arreglo [pos_men];
          arreglo [pos_men] = temp;
          }

     LIMPIAR_PANTALLA();
     printf ("\n\n\tOrdenamiento por selecci¢n.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo);
}

int menor (int arreglo[], int desde)
{
     int i, menor;

     menor = desde++;
     for (i=desde; i<TAM; i++)
          if (arreglo[i] < arreglo[menor])
               menor = i;

     return menor;
}

void insercion (int arreglo[])
{
     int i, j, temp;

     for (i=1; i<TAM; i++)
          {
          temp = arreglo[i];
          j = i - 1;
          /* Desplazamos los elementos mayores que arreglo[i] */
          while ( (arreglo[j] > temp) && (j >= 0) )
               {
               arreglo[j+1] = arreglo[j];
               j--;
               }
          /* Copiamos arreglo[i] en su posici¢n final */
          arreglo[j+1] = temp;
          }

     LIMPIAR_PANTALLA();
     printf ("\n\n\tOrdenamiento por inserci¢n.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo);
}


/* Esta funci¢n es recursiva. La separamos en dos partes: la
   recursiva y la de impresi¢n de resultados. Si no fuera as¡
   cada vez que llamaramos a la funci¢n se imprimir¡a
   'ordenado'(aunque no est‚ ordenado).                       */
void quicksort (int arreglo[])
{
     ord_rap (arreglo, 0, TAM - 1);

     LIMPIAR_PANTALLA();
     printf ("\n\n\tOrdenamiento r pido (QUICKSORT).");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo);
}

void ord_rap (int arreglo[], int inf, int sup)
{
     int elem_div = arreglo[sup];
     int temp ;
     int i = inf - 1, j = sup;
     int cont = 1;

     if (inf >= sup)     /* ¨Se cruzaron los ¡ndices ? */
          return;

     while (cont)
          {
          while (arreglo[++i] < elem_div);
          while (arreglo[--j] > elem_div);
          /* ¨Se cumple la condici¢n ? */
          if (i < j)
               {
               temp = arreglo[i];
               arreglo[i] = arreglo[j];
               arreglo[j] = temp;
               }
          else
              cont = 0;
          }

     /* Dejamos el elemento de divisi¢n en su posici¢n final */
     temp = arreglo[i];
     arreglo[i] = arreglo[sup];
     arreglo[sup] = temp;

     /* Aplicamos recursivamente a los subarreglos generados */
     ord_rap (arreglo, inf, i - 1);
     ord_rap (arreglo, i + 1, sup);
}

void copiar_arr (int *desde, int *hacia)
{
     int i;

     if ( (desde == NULL) || (hacia == NULL) )
          return;

     for (i=0; i<TAM; i++)
         hacia[i] =desde[i];
}

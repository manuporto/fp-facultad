#ifndef _DEMO_H_
    #define _DEMO_H_

/* ----------------------------------------------------------------------
                            Demo.h

    Define constantes y funciones espec�ficas para Demo.c
    Estas est� ocultas de los otros m�dulos
   ---------------------------------------------------------------------- */

/* La cantidad de barras que vamos a ordenar en la demostraci�n gr�fica.
   No recomiendo aumentar mucho esta cantidad */
#define MAX_BAR 50
// El margen horizontal para dibujar las barras
#define MH 25
// El margen vertical para dibujar las barras
#define MV 10
/* La cantidad m�xima de d�gitos para ingresar la pausa.
   �Para qu� m�s de 9999? */
#define MAX_DIG 4

/* La estructura para cada barra. No agregamos ancho porque se calcula
   proporcionalmente al ancho de la ventana */
typedef struct
    {
    int largo;
    COLORREF color;
    }
    Barra;

typedef struct
    {
    DWORD dwTiempo;
    int iComparaciones;
    int iIntercambios;
    }
    Resultados;


/* ----------------------------------------------------------------------
   Definici�n de funciones
   ---------------------------------------------------------------------- */


void DibujarBarra(int i, int pos);
void BorrarBarra(int i);
void IniciarDemo(HWND hwndMain);
void IntercambiarBarras(int i, int j);
void TerminarDemo(HWND hwndMain, int iNumAlgorit);
void ActualizarTiempo(void);
void ActualizarComparaciones(void);
void ActualizarIntercambios(void);
int EncontrarMenor (int desde);
void ord_rap (int inf, int sup);
BOOL ImprimirDatos(HWND hwndDlg);
/* ---------------------------------------------------------------------- */

#endif

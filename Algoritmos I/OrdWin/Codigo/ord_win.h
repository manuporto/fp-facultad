#ifndef __ORD_WIN_H__
    #define __ORD_WIN_H__

/* Todos los archivos de cabecera que necesitamos */
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ord_winres.h"

// La cantidad de partes de la Barra de Estado
#define NUM_PARTS 4
// La cantidad de algoritmos que tenemos
#define CANT_ALG  4
// La cantidad de columnas que vamos a mostrar
#define C_COLUMNS 4

/* ----------------------------------------------------------------------
   Ord_Win.c
   ---------------------------------------------------------------------- */

void ActualizarBarraEstado(LPSTR lpszStringEstado, WORD numeroParte, WORD displayFlags);
void Error(LPCTSTR desc);

/* ----------------------------------------------------------------------
   Demo.c
   ---------------------------------------------------------------------- */

void CrearBarras(void);
void DesordenarBarras(void);
void PintarBarras(HWND hwndMain);
void Burbuja(HWND hwndMain);
void Seleccion (HWND hwndMain);
void Insercion (HWND hwndMain);
void Quicksort (HWND hwndMain);
BOOL CALLBACK Pausa(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Estadisticas(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CrearColumnas(HWND hwndDlg, int iID);
int InsertarItem(HWND hwndDlg, HWND hwndLista, char *pszTexto, int iItem,
                 int iSubItem);
BOOL CALLBACK Acerca_de(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);

/* ----------------------------------------------------------------------
   p_rend.c
   ---------------------------------------------------------------------- */

BOOL CALLBACK PruebaRendimiento(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam);
/* ---------------------------------------------------------------------- */


#endif

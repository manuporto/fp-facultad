#ifndef __P_REND_H__
    #define __P_REND_H__

/* ----------------------------------------------------------------------
                        p_rend.h

   Define constantes y funciones específicas para el módulo de prueba
   de rendimiento.
   ---------------------------------------------------------------------- */


/* ----------------------------------------------------------------------
   Definición de funciones
   ---------------------------------------------------------------------- */

int prBurbuja (int *comparaciones, int *intercambios);
int prSeleccion (int *comparaciones, int *intercambios);
int menor (int desde, int *comparaciones);
int prInsercion (int *comparaciones, int *intercambios);
int prQuicksort (int *comparaciones, int *intercambios);
void prOrd_rap (int inf, int sup, int *comparaciones, int *intercambios);

int InicializarDialogo(HWND hwndDlg);
int CrearLista(HWND hwndDlg, int tam);
void GenerarNumeros (int tam);
void Prueba(HWND hwndDlg);
void CopiarLista (const int *desde, int *hasta);
void Finalizar(void);

/* ---------------------------------------------------------------------- */

#endif

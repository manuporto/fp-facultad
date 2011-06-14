/* ----------------------------------------------------------------------
                        Demo.c

   Este módulo se encarga de la demostración gráfica de cada algoritmo.
   Si quieres agregar un algoritmo hazlo en la parte Algoritmos más abajo
   Los pasos son:
   - Agregar un ítem del menú para llamarlo. Pásale por parámetro
   HWND hwndMain a tu función: AlgoritmoX(HWND hwndMain) por ejemplo.
   - Debes llamar a IniciarDemo(hwndMain) antes de comenzar a ordenar.
   - Ordena el arreglo global Barras.
   - Para intercambiar elementos utiliza IntercambiarBarras(hwndMain, i, j),
   donde i y j son los índices de las barras a intercambiar.
   - Para dibujar o borrar una barra utiliza BorrarBarra() y DibujarBarra()
   Es útil si tu algoritmo no intercambia barras (sólo las desplaza): en
   este caso deberías utilizar sleep(pausa) para que el algoritmo espere
   entre cada paso.
   - Llama a TerminarDemo(hwndMain, iNumAlgorit) al finalizar. iNumAlgorit
   es el número de tu algoritmo. Este número es la posición en el arreglo
   de resultados en que irá la información reunida. Ya hay 4 (CANT_ALG),
   así que insertas otro debería ser 4. Si agregas otro más su número
   sería 5. Recuerda aumentar CANT_ALG cada vez que agregues otro algoritmo.
   Está definida en ord_win.h.
   ¿Qué difícil no?
   ---------------------------------------------------------------------- */

#include "ord_win.h"
#include "demo.h"

/* ----------------------------------------------------------------------
   Variables Globales
   ---------------------------------------------------------------------- */

static Barra Barras[MAX_BAR];   // El arreglo de barras que vamos a ordenar
static Barra Copia[MAX_BAR];    // Una copia de la lista original
static int pausa = 100;         // Intervalo de pausa, para alcanzar a ver
                                //   cómo se ordena todo :-D
static HDC hDC;                 // El DC que utilizaremos para dibujar.
static int LargoVent, AnchoVent;    // Largo y ancho de la ventana
static int LargoBar, AnchoBar;      /* Ancho de la barra. LargoBar es el
                                       factor por el que se multiplica el
                                       largo de una barra para obtener sus
                                       dimensiones en la ventana */

static DWORD dwTiempoInic, dwTiempoFin;     // Para medir el tiempo
static int iComparaciones, iIntercambios;   // Para manejar estadísticas.
Resultados Estadist[CANT_ALG];              // Arreglo con los reultados
BOOL bTodosListos = TRUE;           /* Si se han ejecutado todos los algoritmos
                                       Inicializamos a TRUE para que se borre
                                       el arreglo la primera vez */

/* ----------------------------------------------------------------------
   Funciones básicas
   ---------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Función     : CrearBarras()
   Descripción : Inicializa el arreglo de barras
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void CrearBarras(void)
{
    int factMax, factMed, factMin;  // Factores para crear los colores
    int i;                          // Contador

    /* Este es un pseudoalgoritmo que inventé para asignar colores a las
       barras. Mientras más barras más colores genera */
    factMax = 2550 / MAX_BAR;
    if (factMax <= 0)
        factMax = 1;
    factMin = factMax - 20;
    if (factMin <= 0)
        factMin = 1;
    factMed = (factMax + factMin) / 2;

    for (i=0; i<MAX_BAR; i++)
        {
        // Creamos barras asignando su número como largo
        Barras[i].largo = i + 1;
        // Asignamos un color
        Barras[i].color = RGB(factMax * i, factMin * i, factMed * i);
        }
}

/* ----------------------------------------------------------------------
   Función     : DesordenarBarras()
   Descripción : Desordena las barras inicializadas por CrearBarras()
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void DesordenarBarras(void)
{
    Barra temp;
    int i, Camb;

    // Cambiamos la barra i por una elegida al azar entre todas
    for (i=0; i<MAX_BAR; i++)
        {
        Camb = rand()%MAX_BAR;  // Por qué barra vamos a intercambiar
        temp = Barras[i];
        Barras[i] = Barras[Camb];
        Barras[Camb] = temp;
        }

    // Hacemos una copia del arreglo para poder restaurarlas después
    for (i=0; i<MAX_BAR; i++)
        Copia[i] = Barras[i];
}

/* ----------------------------------------------------------------------
   Función     : DibujarBarra()
   Descripción : Dibuja la barra i en la posición pos en la ventana
   Parámetros  : i   -> índice de la barra en el arreglo
                 pos -> en qué posición se dibuja
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void DibujarBarra(int i, int pos)
{
    HBRUSH hBrush, hBrushAnt;

    // Creamos un pincel del color de la barra
    hBrush = CreateSolidBrush(Barras[i].color);
    if (hBrush == NULL)
        Error("Error al crear hBrush");
    hBrushAnt = SelectObject(hDC, hBrush);  // Guardamos el pincel anterior

    // Dibujamos un rectángulo conservando los márgenes
    Rectangle(hDC, pos * AnchoBar + MH, LargoVent - MV, (pos+1) * AnchoBar + MH,
                  LargoVent - MV - Barras[i].largo * LargoBar);

    SelectObject(hDC, hBrushAnt);   // Restauramos el pincel anterior
    DeleteObject(hBrush);           // Borramos el lápiz que creamos
}

/* ----------------------------------------------------------------------
   Función     : BorrarBarra()
   Descripción : Dibuja una barra blanca en la posición i, lo que tiene
                 el efecto de borrarla
   Parámetros  : Posición en la cual se dibuja la barra
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void BorrarBarra(int i)
{
    HBRUSH hBrushBlanco, hBrushAnt;
    HPEN hPen, hPenAnt;

    // Creamos un lápiz blanco y guardamos el anterior
    hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    if (hPen == NULL)
        Error("No se puede crear el lápiz");
    hPenAnt = SelectObject(hDC, hPen);

    // Creamos un pincel blanco y guardamos el anterior
    hBrushBlanco = CreateSolidBrush(RGB(255, 255, 255));
    if (hBrushBlanco == NULL)
        Error("Error al crear hBrushBlanco");
    hBrushAnt = SelectObject(hDC, hBrushBlanco);    // Guardamos el pincel anterior

    Rectangle(hDC, i * AnchoBar + MH, LargoVent - MV, (i+1) * AnchoBar + MH, MV);

    // Restauramos el pincel anterior
    SelectObject(hDC, hBrushAnt);
    DeleteObject(hBrushBlanco);

    // Restauramos el lápiz anterior
    SelectObject(hDC, hPenAnt);
    DeleteObject(hPen);
}

/* ----------------------------------------------------------------------
   Función     : PintarBarras()
   Descripción : Dibuja todas las barras del arreglo en la ventana
   Parámetros  : hwndMain -> Manejador de la ventana
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void PintarBarras(HWND hwndMain)
{
    PAINTSTRUCT ps;
    int i;

    InvalidateRect(hwndMain, NULL, TRUE);
    hDC = BeginPaint(hwndMain, &ps);

    /* Las siguientes variables las utilizamos para hacer que las barras
       dibujadas tengan dimensiones proporcionales a las dimensiones de
       la ventana */
    AnchoBar = (ps.rcPaint.right - ps.rcPaint.left - 2*MH) / MAX_BAR;
    LargoBar = (ps.rcPaint.bottom - ps.rcPaint.top - 2*MV) / MAX_BAR;
    LargoVent = ps.rcPaint.bottom - ps.rcPaint.top;
    AnchoVent = ps.rcPaint.right - ps.rcPaint.left;

    // Dibujamos cada barra. Dejamos un margen en cada lado de la ventana
    for (i=0; i<MAX_BAR; i++)
        DibujarBarra(i, i);

    EndPaint(hwndMain, &ps);            // Terminamos de pintar
}

/* ----------------------------------------------------------------------
   Función     : IniciarDemo()
   Descripción : Prepara la ventana para dibujar, inicializa los
                 contadores, dibuja las barras con su distribución
                 original y toma el tiempo de inicio
   Parámetros  : hwndMain -> Manejador de la ventana
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void IniciarDemo(HWND hwndMain)
{
    int i;

    // Si es la primera vez que ejecutamos un algoritmo o si ya se han
    // ejecutado todos reinicializamos
    if (bTodosListos)
        {
        memset(&Estadist, 0, sizeof(Estadist));
        bTodosListos = FALSE;
        }

    // Obtenemos un Device Context para poder dibujar en la ventana
    hDC = GetDC(hwndMain);
    iComparaciones = iIntercambios = 0;

    // Nos aseguramos de restaurar las barras desde la copia
    for (i=0; i<MAX_BAR; i++)
        Barras[i] = Copia[i];

    for (i=0; i<MAX_BAR; i++)   // Dibujamos las barras en desorden.
        {                       // Cuando se utiliza un algoritmo, las barras
        BorrarBarra(i);         // estan ordenadas al ejecutar por segunda vez,
        DibujarBarra(i, i);     // Así que las tenemos que dibujar como estaban antes.
        }

    dwTiempoInic = GetTickCount();      // Tomamos el tiempo de inicio
}

/* ----------------------------------------------------------------------
   Función     : IntercambiarBarras()
   Descripción : Intercambia dos barras, dibujándolas en sus nuevas posiciones
   Parámetros  : Los índices de cada barra en el arreglo
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void IntercambiarBarras(int i, int j)
{
    Barra temp;

    BorrarBarra(i);     // Borramos las dos barras
    BorrarBarra(j);
    DibujarBarra(i, j); // de la otra
    DibujarBarra(j, i); // Dibujamos cada una en la posición


    // Intercambiamos las barras en la lista
    temp = Barras[i];
    Barras[i] = Barras[j];
    Barras[j] = temp;

    Sleep(pausa);               // Esperamos un tiempo
}

/* ----------------------------------------------------------------------
   Función     : ActualizarTiempo()
   Descripción : Imprime en la barra de estado el tiempo transcurrido
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void ActualizarTiempo(void)
{
    char strEstado[255];

    dwTiempoFin = GetTickCount();
    sprintf (strEstado, "Tiempo: %ld ms", (DWORD)(dwTiempoFin - dwTiempoInic));
    ActualizarBarraEstado(strEstado, 1, 0);
}

/* ----------------------------------------------------------------------
   Función     : ActualizarComparaciones()
   Descripción : Imprime  en la barra de estado la cantidad de
                 comparaciones realizadas
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void ActualizarComparaciones(void)
{
    char strEstado[255];

    iComparaciones++;
    sprintf (strEstado, "Comparaciones: %d", iComparaciones);
    ActualizarBarraEstado(strEstado, 2, 0);
}

/* ----------------------------------------------------------------------
   Función     : ActualizarIntercambios()
   Descripción : Imprime en la barra de estado la cantidad de
                 intercambios realizados
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void ActualizarIntercambios(void)
{
    char strEstado[255];

    iIntercambios++;
    sprintf (strEstado, "Intercambios: %d", iIntercambios);
    ActualizarBarraEstado(strEstado, 3, 0);
}

/* ----------------------------------------------------------------------
   Función     : TerminarDemo()
   Descripción : Finaliza un demo y guarda las estadísticas
   Parámetros  : hwndMain    -> El manejador de la ventana
                 iNumAlgorit -> El algoritmo relizado. Es necesario para
                 saber en qué elemento del arreglo de estadísticas guardar
                 los resultados
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void TerminarDemo(HWND hwndMain, int iNumAlgorit)
{
    int i;

    // Liberamos el DC
    ReleaseDC(hwndMain, hDC);

    // Mostramos que terminó la ejecución enla Barra de Estado
    ActualizarBarraEstado("Listo", 0, 0);
    // Guardamos las estadísticas en el arreglo
    Estadist[iNumAlgorit].dwTiempo = dwTiempoFin - dwTiempoInic;
    Estadist[iNumAlgorit].iComparaciones = iComparaciones;
    Estadist[iNumAlgorit].iIntercambios = iIntercambios;

    // Si ya hemos ejecutado todos asignamos TRUE a bTodosListos para
    // empezar de nuevo la próxima vez
    bTodosListos = TRUE;
    for (i=0; i<CANT_ALG; i++)
        if (Estadist[i].dwTiempo == 0)
            bTodosListos = FALSE;
}

/* ----------------------------------------------------------------------
   Algoritmos. Los explico en los artículos :-D
   Te darás cuenta que me he plageado el código a mi mismo :-D
   ---------------------------------------------------------------------- */

void Burbuja(HWND hwndMain)
{
    int i, j;
    Barra temp;

    IniciarDemo(hwndMain);

    for (i=1; i<MAX_BAR; i++)
        for (j=0; j<MAX_BAR - i; j++, ActualizarComparaciones())
            if (Barras[j].largo > Barras[j+1].largo)
                {
                IntercambiarBarras(j, j+1);
                ActualizarIntercambios();
                ActualizarTiempo();
                }

    TerminarDemo(hwndMain, 0);
}

int EncontrarMenor (int desde)
{
     int i, menor;

     menor = desde++;
     for (i=desde; i<MAX_BAR; i++, ActualizarComparaciones(), ActualizarTiempo())
          if (Barras[i].largo < Barras[menor].largo)
               menor = i;

     return menor;
}

void Seleccion (HWND hwndMain)
{
     int i, pos_men;
     Barra temp;

     IniciarDemo(hwndMain);

     for (i=0; i<MAX_BAR - 1; i++)
          {
          pos_men = EncontrarMenor(i);
          IntercambiarBarras (i, pos_men);
          ActualizarIntercambios();
          ActualizarTiempo();
          }

    TerminarDemo(hwndMain, 1);
}

void Insercion (HWND hwndMain)
{
     int i, j;
     Barra temp;

     IniciarDemo(hwndMain);

     for (i=1; i<MAX_BAR; i++)
          {
          temp = Barras[i];
          j = i - 1;
          while ( (Barras[j].largo > temp.largo) && (j >= 0) )
               {
               Barras[j+1] = Barras[j];
               BorrarBarra(j+1);
               DibujarBarra(j, j+1);
               j--;

               ActualizarComparaciones();
               ActualizarIntercambios();
               Sleep(pausa);
               ActualizarTiempo();
               }
          Barras[j+1] = temp;
          BorrarBarra(j+1);
          DibujarBarra(j+1, j+1);

          ActualizarIntercambios();
          Sleep(pausa);
          ActualizarTiempo();
          }

     TerminarDemo(hwndMain, 2);
}

void Quicksort (HWND hwndMain)
{
     IniciarDemo(hwndMain);

     ord_rap (0, MAX_BAR - 1);

     TerminarDemo(hwndMain, 3);
}

void ord_rap (int inf, int sup)
{
     Barra elem_div = Barras[sup];
     int i = inf - 1, j = sup;
     int cont = 1;

     if (inf >= sup)
          return;

     while (cont)
          {
          while (Barras[++i].largo < elem_div.largo)
              {
              ActualizarComparaciones();
              ActualizarTiempo();
              }
          while (Barras[--j].largo > elem_div.largo)
              {
              ActualizarComparaciones();
              ActualizarTiempo();
              }

          if (i < j)
               {
               IntercambiarBarras(i, j);
               ActualizarIntercambios();
               ActualizarTiempo();
               }
          else
              cont = 0;
          }

     IntercambiarBarras(i, sup);
     ActualizarIntercambios();
     ActualizarTiempo();

     ord_rap (inf, i - 1);
     ord_rap (i + 1, sup);
}

/* ----------------------------------------------------------------------
   Opciones y ayuda
   ---------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Función     : Pausa()
   Descripción : Maneja los mensajes del cuadro de selección del
                 intervalo de pausa
   Parámetros  : hwndDlg -> Manejador del cuadro de diálogo
                 msg     -> Identificador del mensaje
                 wParam  -> Primer parámetro del mensaje
                 lParam  -> Segundo parámetro del mensaje
   Retorna     : TRUE o FALSE dependiendo del mensaje recibido
   ---------------------------------------------------------------------- */
BOOL CALLBACK Pausa(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static int tpaus;   // Leemos la pausa a esta variable antes de cambiar la global

    switch (msg)
        {
        case WM_INITDIALOG:
            tpaus = pausa;
            /* Limitamos la cantidad de dígitos que se puyede ingresar para
               limitar también la cantidad máxima */
            SendDlgItemMessage (hwndDlg, IDE_PAUSA, EM_SETLIMITTEXT, MAX_DIG, 0);
            // Mostramos el valor actual de pausa
            SetDlgItemInt(hwndDlg, IDE_PAUSA, (UINT)tpaus, FALSE);
            return TRUE;
        case WM_COMMAND:
            switch (LOWORD(wParam))
                {
                case IDE_PAUSA:
                    // Leemos la cantidad ingresada
                    tpaus = GetDlgItemInt(hwndDlg, IDE_PAUSA, NULL, FALSE);
                    return TRUE;
                case IDB_RAPIDO:
                    if (tpaus > 1)          // No queremos pausas negativa
                        {
                        tpaus--;
                        SetDlgItemInt(hwndDlg, IDE_PAUSA, (UINT)tpaus, FALSE);
                        }
                    return TRUE;
                case IDB_LENTO:
                    if (tpaus < 9999)       // Verificamos el valor ingresado
                        {
                        tpaus++;
                        SetDlgItemInt(hwndDlg, IDE_PAUSA, tpaus, FALSE);
                        }
                    return TRUE;
                case IDOK:                  // Aceptar: guardamos los cambios
                    pausa = tpaus;
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                case IDCANCEL:              // Cancelar: no guardamos los cambios
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                }
            break;
        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;
        }

    return FALSE;
}

/* ----------------------------------------------------------------------
   Función     : Estadisticas()
   Descripción : Maneja los mensajes del cuadro de estadísticas
   Parámetros  : hwndDlg -> Manejador del cuadro de diálogo
                 msg     -> Identificador del mensaje
                 wParam  -> Primer parámetro del mensaje
                 lParam  -> Segundo parámetro del mensaje
   Retorna     : TRUE o FALSE dependiendo del mensaje procesado
   ---------------------------------------------------------------------- */
BOOL CALLBACK Estadisticas(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
        {
        case WM_INITDIALOG:
            // Si hay errores retornamos
            if (CrearColumnas(hwndDlg, IDL_ESTAD) == FALSE)
                PostMessage(hwndDlg, WM_CLOSE, 0, 0);
            if (ImprimirDatos(hwndDlg) == FALSE)
                PostMessage(hwndDlg, WM_CLOSE, 0, 0);
            return TRUE;
        case WM_COMMAND:
            switch (LOWORD(wParam))
                {
                case IDOK:                  // Botón cerrar
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                }
            break;
        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;
        }

    return FALSE;
}

/* ----------------------------------------------------------------------
   Función     : ImprimirDatos()
   Descripción : Muestra las estadísticas de todos los algoritmos
                 ejecutados hasta el momento.
   Parámetros  : hwndDlg -> Manejador del diálogo
   Retorna     : TRUE si todo sale bien y FALSE de lo contrario
   ---------------------------------------------------------------------- */
BOOL ImprimirDatos(HWND hwndDlg)
{
    HINSTANCE hInstMain;            // Manejador de la instancia del programa
    HWND hwndLista;                 // Manejador de la lista
    char szNombreAlgoritmo[256];    // Buffer temporal para cargar los nombres de algoritmos
    char szResultados[50];
    int i;

    hInstMain = GetModuleHandle(NULL);  // Necesitamos esto para cargar los strings
    hwndLista = GetDlgItem(hwndDlg, IDL_ESTAD);

    for (i=0; i<CANT_ALG; i++)
        {
        // Insertamos el nombre del algoritmo que vamos a utilizar
        LoadString(hInstMain, (UINT) (IDS_PRIM_ALG + i), szNombreAlgoritmo,
                   sizeof(szNombreAlgoritmo));
        if (InsertarItem(hwndDlg, hwndLista, szNombreAlgoritmo, i, 0) == -1)
            return FALSE;

        // ¿Hay datos para este algoritmo?
        if (Estadist[i].dwTiempo != 0)
            {
            // Necesitamos los resultados en una cadena. Aquí va el tiempo total
            sprintf (szResultados, "%ld ms", Estadist[i].dwTiempo);
            if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 1) == -1)
                return FALSE;

            // Insertamos la cantidad de Comparaciones
            sprintf (szResultados, "%d", Estadist[i].iComparaciones);
            if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 2) == -1)
                return FALSE;

            // Insertamos la cantidad de Intercambios
            sprintf (szResultados, "%d", Estadist[i].iIntercambios);
            if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 3) == -1)
                return FALSE;
            }
        }

    return TRUE;
}

/* ----------------------------------------------------------------------
   Función     : AcercaDe()
   Descripción : Maneja los mensajes del cuadro de diálogo Acerca de...
   Parámetros  : hwndDlg -> Manejador del cuadro de diálogo
                 msg     -> Identificador del mensaje
                 wParam  -> Primer parámetro del mensaje
                 lParam  -> Segundo parámetro del mensaje
   Retorna     : TRUE o FALSE dependiendo del mensaje recibido
   ---------------------------------------------------------------------- */
BOOL CALLBACK Acerca_de(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
        {
        case WM_INITDIALOG:
            return TRUE;
        case WM_COMMAND:
            switch (LOWORD(wParam))
                {
                case IDOK:
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                }
            break;
        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;
        }

    return FALSE;
}

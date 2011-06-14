/* ----------------------------------------------------------------------
                        p_rend.c

   En este módulo se realiza una prueba con una lista de elementos de
   tamaño especificado por el usuario. Se calcula tiempo, comparaciones
   e intercambios para cada algoritmo.
   ---------------------------------------------------------------------- */

#include "ord_win.h"
#include "p_rend.h"

/* ----------------------------------------------------------------------
   Variables Globales
   ---------------------------------------------------------------------- */
static int *lista = NULL;       // Puntero a la lista que vamos a ordenar
static int *copia = NULL;       // Una copia de la lista
static int iCantElem = 5000;    // La cantidad de elementos de la lista


/* ----------------------------------------------------------------------
   Función     : PruebaRendimiento()
   Descripción : Maneja los eventos de este diálogo, se preocupa de crear
                 la lista de elementos, cambiar su tamaño, etc
   Parámetros  : hwndDlg -> Manejador del diálogo
                 msg     -> Identificador del mensaje
                 wParam  -> Primer parámetro del mensaje
                 lParam  -> Segundo parámetro del mensaje
   Retorna     : TRUE o FALSE dependiendo del tipo de mensaje manejado
   ---------------------------------------------------------------------- */
BOOL CALLBACK PruebaRendimiento(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    int iCantTemp;

    switch (msg)
        {
        case WM_INITDIALOG:
            if (InicializarDialogo(hwndDlg) != 0)       // Si hay un error terminamos
                PostMessage(hwndDlg, WM_CLOSE, 0, 0);
            return TRUE;
        case WM_COMMAND:
            switch (LOWORD(wParam))
                {
                case IDB_COMENZAR:      // Mostramos el tamañpo inicial de la lista
                    SetDlgItemInt(hwndDlg, IDE_CANTIDAD, iCantElem, FALSE);
                    Prueba(hwndDlg);    // Realizamos la prueba
                    return TRUE;
                case IDCANCEL:
                    Finalizar();
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                case IDB_CAMBIAR:       // Leemos la cantidad ingresada
                    iCantTemp = GetDlgItemInt(hwndDlg, IDE_CANTIDAD, NULL, FALSE);
                    // Revisamos que sea un número válido
                    if ( (iCantTemp < 1) || (iCantTemp > 32000) )
                        {
                        Error("Por favor sólo un número entre 1 y 32000");
                        SetDlgItemInt(hwndDlg, IDE_CANTIDAD, iCantElem, FALSE);
                        }
                    else
                        {
                        // Liberamos la memoria utilizada si la hay
                        Finalizar();
                        // Creamos la lista con el nuevo tamaño
                        if (CrearLista(hwndDlg, iCantTemp) != -1)   //  Todo bien
                            {
                            iCantElem = iCantTemp;                  // Actualizamos el tamaño
                            }
                        else
                            {
                            iCantElem = 0;  // Ups! Algo salió mal. Ya no hay lista.
                            // Mostramos al usuario que la lista está vacía.
                            SetDlgItemInt(hwndDlg, IDE_CANTIDAD, iCantElem, FALSE);
                            }
                        }
                    return TRUE;
                }
            break;
        case WM_CLOSE:
            Finalizar();
            EndDialog(hwndDlg, 0);
            return TRUE;
        }

    return FALSE;
}

/* ----------------------------------------------------------------------
   Función     : InicializarDialogo()
   Descripción : Crea la lista, las columnas del control e inicializa el
                 control de edición
   Parámetros  : hwndDlg -> Manejador del diálogo
   Retorna     : 0 si todo sale bien y -1 de lo contrario
   ---------------------------------------------------------------------- */
int InicializarDialogo(HWND hwndDlg)
{
    int i;

    if (CrearLista(hwndDlg, iCantElem) == -1)
        return -1;

    if (CrearColumnas (hwndDlg, IDL_RES_PREND) == FALSE)
        return -1;

    // Limitamos la cantidad de caracteres
    SendDlgItemMessage (hwndDlg, IDE_CANTIDAD, EM_SETLIMITTEXT, 6, 0);
    // Mostramos el tamaño actual de la lista
    SetDlgItemInt(hwndDlg, IDE_CANTIDAD, (UINT)iCantElem, FALSE);

    return 0;   // Todo salió bien!
}

/* ----------------------------------------------------------------------
   Función     : CrearLista()
   Descripción : Pide memoria para la lista que ordenaremos y para la
                 copia que mantendremos de ésta
   Parámetros  : hwndDlg -> Manejador del cuadro de diálogo
                 tam     -> El tamaño de la lista a crear
   Retorna     : 0 si todo sale bien y -1 de lo contrario
   ---------------------------------------------------------------------- */
int CrearLista(HWND hwndDlg, int tam)
{
    // Pedimos memoria para las listas
    lista = (int *) malloc ( (size_t) (tam * sizeof(int)) );
    copia = (int *) malloc ( (size_t) (tam * sizeof(int)) );

    if ( (lista == NULL) || (copia == NULL) )   // Comprobamos si obtuvimos memoria
        {
        Error ("Error: No hay memoria suficiente");
        return -1;
        }

    GenerarNumeros(tam);    // Llenamos la lista con números al azar

    return 0;
}

/* ----------------------------------------------------------------------
   Función     : GenerarNumeros()
   Descripción : Rellena la lista con números aleatorios
   Parámetros  : La cantidad de elementos de la lista
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void GenerarNumeros (int tam)
{
    int i;

    // Generamos números aleatorios
    for (i=0; i<tam; i++)
        lista[i] = copia[i] = rand();
}

/* ----------------------------------------------------------------------
   Función     : Prueba()
   Descripción : Ejecuta la prueba de rendimiento para cada algoritmo
   Parámetros  : El manejador del cuadro de diálogo
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void Prueba(HWND hwndDlg)
{
    HINSTANCE hInstMain;    // Manejador de la instancia del programa
    HWND hwndLista;         // Manejador de la instancia de la lista
    // Este es un arreglo de punteros a las funciones que vamos a utilizar
    int (*pr[CANT_ALG])(int *, int *) = {prBurbuja, prSeleccion, prInsercion, prQuicksort};
    // Tiempos de inicio, fin y total empleados para evaluar cada algoritmo
    DWORD tiempoInic, tiempoFinal, tiempoTotal;
    char szNombreAlgoritmo[256];     // Buffer temporal para cargar los nombres de algoritmos
    char szResultados[50];
    int iComparaciones, iIntercambios;
    int i;

    hInstMain = GetModuleHandle(NULL);  // Necesitamos esto para cargar los strings
    hwndLista = GetDlgItem(hwndDlg, IDL_RES_PREND);
    ListView_DeleteAllItems(hwndLista); // Borramos los ítems que puedan haber

    for (i=0; i<CANT_ALG; i++)
        {
        iComparaciones = 0; // Inicializamos los contadores
        iIntercambios = 0;

        // Insertamos el nombre del algoritmo que vamos a utilizar
        LoadString(hInstMain, (UINT) (IDS_PRIM_ALG + i), szNombreAlgoritmo,
                   sizeof(szNombreAlgoritmo));
        if (InsertarItem(hwndDlg, hwndLista, szNombreAlgoritmo, i, 0) == -1)
            return;

        tiempoInic = timeGetTime();                     // Tomamos el tiempo inicial
        (*pr[i])(&iComparaciones, &iIntercambios);      // Ejecutamos la función
        tiempoFinal = timeGetTime();                    // Tomamos el tiempo final
        tiempoTotal = tiempoFinal - tiempoInic;         // Calculamos cuánto tomó todo

        // Necesitamos los resultados en una cadena. Aquí va el tiempo total
        sprintf (szResultados, "%ld ms", tiempoTotal);
        if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 1) == -1)
            return;

        // Insertamos la cantidad de Comparaciones
        sprintf (szResultados, "%d", iComparaciones);
        if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 2) == -1)
            return;

        // Insertamos la cantidad de Intercambios
        sprintf (szResultados, "%d", iIntercambios);
        if (InsertarItem(hwndDlg, hwndLista, szResultados, i, 3) == -1)
            return;

        // Restauramos la lista original, porque la modificamos
        CopiarLista(copia, lista);
        }
}

/* ----------------------------------------------------------------------
   Función     : CopiarLista()
   Descripción : Copia una lista en otra
   Parámetros  : Lista de origen y lista de destino
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void CopiarLista (const int *desde, int *hasta)
{
    int i;

    if ( (desde != NULL) && (hasta != NULL) )   // Validamos los punteros
        for (i=0; i<iCantElem; i++)
            *hasta++ = *desde++;
}

/* ----------------------------------------------------------------------
   Función     : Finalizar()
   Descripción : Libera la memoria utilizada
   Parámetros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void Finalizar(void)
{
    if (lista != NULL)      // No queremos liberar memoria que no hemos pedido, ¿cierto?
        free(lista);
    lista = NULL;

    if (copia != NULL)
        free(copia);
    copia = NULL;
}

/* ----------------------------------------------------------------------
   Algoritmos. No los explico porque ya lo hice en los artículos :-D
   ---------------------------------------------------------------------- */

int prBurbuja (int *iComparaciones, int *iIntercambios)
{
    int i, j;
    int temp;

    for (i=1; i<iCantElem; i++)
        for (j=0; j<iCantElem - i; j++, (*iComparaciones)++)
            if (lista[j] > lista[j+1])
                {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
                (*iIntercambios)++;
                }

    return 0;
}

int prSeleccion (int *iComparaciones, int *iIntercambios)
{
    int i;
    int temp, pos_men;

    for (i=0; i<iCantElem - 1; i++)
        {
        pos_men = menor(i, iComparaciones);
        temp = lista[i];
        lista[i] = lista [pos_men];
        lista [pos_men] = temp;
        (*iIntercambios)++;
        }

    return 0;
}

int menor (int desde, int *iComparaciones)
{
    int i, menor;

    menor = desde++;
    for (i=desde; i<iCantElem; i++, (*iComparaciones)++)
        if (lista[i] < lista[menor])
            menor = i;

    return menor;
}

int prInsercion (int *iComparaciones, int *iIntercambios)
{
    int i, j, temp;

    for (i=1; i<iCantElem; i++)
        {
        temp = lista[i];
        j = i - 1;
        while ( (lista[j] > temp) && (j >= 0) )
            {
            lista[j+1] = lista[j];
            j--;
            (*iComparaciones)++;
            (*iIntercambios)++;
            }
        lista[j+1] = temp;
        (*iIntercambios)++;
        }

    return 0;
}

int prQuicksort (int *iComparaciones, int *iIntercambios)
{
    int i;

    for (i=0; i<iCantElem; i++)
        lista[i] = lista[i];

    prOrd_rap (0, iCantElem - 1, iComparaciones, iIntercambios);

    return 0;
}

void prOrd_rap (int inf, int sup, int *iComparaciones, int *iIntercambios)
{
    int elem_div = lista[sup];
    int temp ;
    int i = inf - 1, j = sup;
    int cont = 1;

    if (inf >= sup)
        return;

    while (cont)
        {
        while (lista[++i] < elem_div)
            (*iComparaciones)++;
        while (lista[--j] > elem_div)
            (*iComparaciones)++;

        if (i < j)
            {
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
            (*iIntercambios)++;
            }
        else
            cont = 0;
        }

    temp = lista[i];
    lista[i] = lista[sup];
    lista[sup] = temp;
    (*iIntercambios)++;

    prOrd_rap (inf, i - 1, iComparaciones, iIntercambios);
    prOrd_rap (i + 1, sup, iComparaciones, iIntercambios);
}

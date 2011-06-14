/* ----------------------------------------------------------------------
                        p_rend.c

   En este m�dulo se realiza una prueba con una lista de elementos de
   tama�o especificado por el usuario. Se calcula tiempo, comparaciones
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
   Funci�n     : PruebaRendimiento()
   Descripci�n : Maneja los eventos de este di�logo, se preocupa de crear
                 la lista de elementos, cambiar su tama�o, etc
   Par�metros  : hwndDlg -> Manejador del di�logo
                 msg     -> Identificador del mensaje
                 wParam  -> Primer par�metro del mensaje
                 lParam  -> Segundo par�metro del mensaje
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
                case IDB_COMENZAR:      // Mostramos el tama�po inicial de la lista
                    SetDlgItemInt(hwndDlg, IDE_CANTIDAD, iCantElem, FALSE);
                    Prueba(hwndDlg);    // Realizamos la prueba
                    return TRUE;
                case IDCANCEL:
                    Finalizar();
                    EndDialog(hwndDlg, 0);
                    return TRUE;
                case IDB_CAMBIAR:       // Leemos la cantidad ingresada
                    iCantTemp = GetDlgItemInt(hwndDlg, IDE_CANTIDAD, NULL, FALSE);
                    // Revisamos que sea un n�mero v�lido
                    if ( (iCantTemp < 1) || (iCantTemp > 32000) )
                        {
                        Error("Por favor s�lo un n�mero entre 1 y 32000");
                        SetDlgItemInt(hwndDlg, IDE_CANTIDAD, iCantElem, FALSE);
                        }
                    else
                        {
                        // Liberamos la memoria utilizada si la hay
                        Finalizar();
                        // Creamos la lista con el nuevo tama�o
                        if (CrearLista(hwndDlg, iCantTemp) != -1)   //  Todo bien
                            {
                            iCantElem = iCantTemp;                  // Actualizamos el tama�o
                            }
                        else
                            {
                            iCantElem = 0;  // Ups! Algo sali� mal. Ya no hay lista.
                            // Mostramos al usuario que la lista est� vac�a.
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
   Funci�n     : InicializarDialogo()
   Descripci�n : Crea la lista, las columnas del control e inicializa el
                 control de edici�n
   Par�metros  : hwndDlg -> Manejador del di�logo
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
    // Mostramos el tama�o actual de la lista
    SetDlgItemInt(hwndDlg, IDE_CANTIDAD, (UINT)iCantElem, FALSE);

    return 0;   // Todo sali� bien!
}

/* ----------------------------------------------------------------------
   Funci�n     : CrearLista()
   Descripci�n : Pide memoria para la lista que ordenaremos y para la
                 copia que mantendremos de �sta
   Par�metros  : hwndDlg -> Manejador del cuadro de di�logo
                 tam     -> El tama�o de la lista a crear
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

    GenerarNumeros(tam);    // Llenamos la lista con n�meros al azar

    return 0;
}

/* ----------------------------------------------------------------------
   Funci�n     : GenerarNumeros()
   Descripci�n : Rellena la lista con n�meros aleatorios
   Par�metros  : La cantidad de elementos de la lista
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void GenerarNumeros (int tam)
{
    int i;

    // Generamos n�meros aleatorios
    for (i=0; i<tam; i++)
        lista[i] = copia[i] = rand();
}

/* ----------------------------------------------------------------------
   Funci�n     : Prueba()
   Descripci�n : Ejecuta la prueba de rendimiento para cada algoritmo
   Par�metros  : El manejador del cuadro de di�logo
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
    ListView_DeleteAllItems(hwndLista); // Borramos los �tems que puedan haber

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
        (*pr[i])(&iComparaciones, &iIntercambios);      // Ejecutamos la funci�n
        tiempoFinal = timeGetTime();                    // Tomamos el tiempo final
        tiempoTotal = tiempoFinal - tiempoInic;         // Calculamos cu�nto tom� todo

        // Necesitamos los resultados en una cadena. Aqu� va el tiempo total
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
   Funci�n     : CopiarLista()
   Descripci�n : Copia una lista en otra
   Par�metros  : Lista de origen y lista de destino
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
   Funci�n     : Finalizar()
   Descripci�n : Libera la memoria utilizada
   Par�metros  : Ninguno
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void Finalizar(void)
{
    if (lista != NULL)      // No queremos liberar memoria que no hemos pedido, �cierto?
        free(lista);
    lista = NULL;

    if (copia != NULL)
        free(copia);
    copia = NULL;
}

/* ----------------------------------------------------------------------
   Algoritmos. No los explico porque ya lo hice en los art�culos :-D
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

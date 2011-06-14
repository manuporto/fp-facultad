/* ----------------------------------------------------------------------
                            Ord_Win.c

    Descripción : Programa de demostración gráfica de varios algoritmos
                  de ordenamiento. Módulo principal.
    Autor       : Julián Hidalgo
    Versión     : 1.0 para LccWin32
    Fecha       : Noviembre de 2001
    Contacto    : jhida003@pinhue.ufro.cl
                  nirvananomuere@yahoo.com
    Página      : http:/www.conclase.net

    Por favor avísame si encuentas algún error o tienes sugerencias sobre
    este programa
   ---------------------------------------------------------------------- */

#include "ord_win.h"        // Las definiciones generales
#include "ord_win_def.h"    // Las definiciones específicas de este modulo

/* ----------------------------------------------------------------------
   Variables Globales
   ---------------------------------------------------------------------- */

HINSTANCE hInst;        // Manejador de la Instancia
HWND hwndMain;          // Manejador de la ventana principal
HWND hwndBarraEstado;   // Para manejar la barra de estado
/* ---------------------------------------------------------------------- */


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
    MSG msg;
    HANDLE hAccelTable;

    hInst = hInstance;
    if (!IniciarAplicacion())
        return 0;

    hAccelTable = LoadAccelerators(hInst,MAKEINTRESOURCE(IDACCEL));
    if ((hwndMain = CrearOrdWinClase()) == (HWND)0)
        return 0;

    ShowWindow(hwndMain,SW_SHOWMAXIMIZED);  // Mostramos la ventana
    UpdateWindow(hwndMain);                 // Actualizamos para pintar las barras
    CrearBarraEstado(hwndMain, "Listo", NUM_PARTS); // Creamos la barra de estado

    // EL famoso ciclo
    while (GetMessage(&msg,NULL,0,0))
        {
        if (!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
            {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            }
        }

    return msg.wParam;
}

/* ----------------------------------------------------------------------
   Función     : IniciarAplicacion()
   Descripción : Registra la clase, inicia los cotroles y crea las barras
   Parámetros  : Ninguno
   Retorna     : 1 si todo sale bien y 0 de lo contrario
   ---------------------------------------------------------------------- */
BOOL IniciarAplicacion(void)
{
    WNDCLASSEX wc;

    memset(&wc,0,sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC;
    wc.lpfnWndProc = (WNDPROC)MainWndProc;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDICONOPRINC));
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = MAKEINTRESOURCE(IDMAINMENU);
    wc.lpszClassName = "OrdWin";

    if (!RegisterClassEx(&wc))      // Registramos la clase
        return 0;

    InitCommonControls();           // Iniciamos los controles

    CrearBarras();                  // Creamos las barras
    DesordenarBarras();             // Las desordenamos

    return 1;
}

/* ----------------------------------------------------------------------
   Función     : CrearOrdWinClase()
   Descripción : Crea la ventana principal
   Parámetros  : Ninguno
   Retorna     : El valor que retorne CreateWindow()
   ---------------------------------------------------------------------- */
HWND CrearOrdWinClase(void)
{
    return CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "OrdWin","OrdWin 1.0",
                        WS_MINIMIZEBOX | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |
                        WS_MAXIMIZEBOX | WS_CAPTION | WS_BORDER | WS_SYSMENU | WS_THICKFRAME |
                        WS_MAXIMIZE,
                        100, 10, 600, 460,
                        NULL, NULL, hInst, NULL);
}

/* ----------------------------------------------------------------------
   Función     : CrearBarraEstado()
   Descripción : Crea la barra de estado de la ventana
   Parámetros  : hwndParent   -> Manejador de la ventan padre
                 textoInicial -> El texto inicial que se mostrará
                 nroDePartes  -> Número de partes de la barra de estado
   Retorna     : TRUE si todo sale bien y FLASE de lo contrario
   ---------------------------------------------------------------------- */
BOOL CrearBarraEstado(HWND hwndParent,char *textoInicial,int nroDePartes)
{
    hwndBarraEstado = CreateStatusWindow(WS_CHILD | WS_VISIBLE | WS_BORDER | SBARS_SIZEGRIP,
                                         textoInicial,
                                         hwndParent,
                                         IDM_STATUSBAR);
    if(hwndBarraEstado)
        {
        InicializarBarraEstado(hwndParent, nroDePartes);
        return TRUE;
        }

    return FALSE;
}

/* ----------------------------------------------------------------------
   Función     : InicializarBarraEstado()
   Descripción : Establece el número de partes y muestra el texto inicial
   Parámetros  : hwndParent  -> Manejador de la ventana padre
                 nroDePartes -> Número de partes de la barra de estado
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void InicializarBarraEstado(HWND hwndParent,int nroDePartes)
{
    int   ptArreglo[NUM_PARTS];   // Arreglo con las coordenada de las partes
    RECT  rect;

    if (!GetClientRect(hwndParent, &rect))  // Obtenemos el área de nuestra ventana
        return;

    // Llenamos el arreglo de partes
    ptArreglo[0] = (int) (rect.right / 2);
    ptArreglo[1] = (int) (4 * rect.right / 6);
    ptArreglo[2] = (int) (5 * rect.right / 6);
    ptArreglo[3] = (int) (rect.right);

    // Establecemos el número de partes de la Barra de Estado
    if (SendMessage(hwndBarraEstado, SB_SETPARTS, nroDePartes, (LPARAM)ptArreglo) == FALSE)
        Error("Error estableciendo el número de partes");

    ActualizarBarraEstado("Listo", 0, 0);
    ActualizarBarraEstado("Tiempo:", 1, 0);
    ActualizarBarraEstado("Comparaciones: ", 2, 0);
    ActualizarBarraEstado("Intercambios: ", 3, 0);
}

/* ----------------------------------------------------------------------
   Función     : ActualizarBarraEstado()
   Descripción : Imprime el texto especificado en la parte indicada
   Parámetros  : lpszStringEstado -> La cadena a imprimir
                 numeroParte      -> En qué parte hacerlo
                 displayFlags     -> Banderas de impresión
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void ActualizarBarraEstado(LPSTR lpszStringEstado, WORD numeroParte, WORD displayFlags)
{
    // Simplemente enviamos el texto a la Barra de Estado
    SendMessage(hwndBarraEstado, SB_SETTEXT, numeroParte | displayFlags,
                (LPARAM)lpszStringEstado);
}

/* ----------------------------------------------------------------------
   Función     : MainWndProc()
   Descripción : Procedimiento de ventana principal
   Parámetros  : hwnd   -> Manejador de la ventana
                 msg    -> Identificador del mensaje
                 wParam -> Primer parámetro del mensaje
                 lParam -> Segundo parámetro del mensaje
   Retorna     : 0 si se procesa el mensaje o el resultado de la llamada
                 a DefWindowProc() de lo contrario
   ---------------------------------------------------------------------- */
LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    switch (msg)
        {
        case WM_SIZE:
            SendMessage(hwndBarraEstado, msg, wParam, lParam);
            InicializarBarraEstado(hwndBarraEstado, NUM_PARTS);
            break;
        case WM_MENUSELECT:
            return MsgSelecMenu(hwnd, msg, wParam, lParam);
        case WM_COMMAND:
            HANDLE_WM_COMMAND(hwnd, wParam, lParam, MainWndProc_OnCommand);
            break;
        case WM_PAINT:
            PintarBarras(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd,msg,wParam,lParam);
        }

    return 0;
}

/* ----------------------------------------------------------------------
   Función     : MsgSelecMenu()
   Descripción : Básicamente esta función envía mensajes a la barra de
                 estado cuando el mouse pasa sobre algún ítem del menú.
                 El mensaje es un string guardado en el fichero de
                 recursos de la aplicación, y debe tener el mismo valor
                 numérico que el ID del comando que se destaca
   Parámetros  : hwnd   -> Manejador de la ventana
                 msg    -> Identificador del mensaje
                 wParam -> Primer parámetro del mensaje
                 lParam -> Segundo parámetro del mensaje
   Retorna     : 0
   ---------------------------------------------------------------------- */
/*  */
LRESULT MsgSelecMenu(HWND hwnd, UINT uMessage, WPARAM wparam, LPARAM lparam)
{
    static char szBuffer[256];
    UINT   nStringID = 0;
    UINT   fuFlags = GET_WM_MENUSELECT_FLAGS(wparam, lparam) & 0xffff;
    UINT   uCmd    = GET_WM_MENUSELECT_CMD(wparam, lparam);
    HMENU  hMenu   = GET_WM_MENUSELECT_HMENU(wparam, lparam);

    szBuffer[0] = 0;                            // Primero anulamos el buffer
    if (fuFlags == 0xffff && hMenu == NULL)     // El Menú ha sido cerrado
        nStringID = 0;

    else
        if (fuFlags & MFT_SEPARATOR)            // Ignoramos los separadores
            nStringID = 0;

        else
            if (fuFlags & MF_POPUP)             // Menú Popup
                {
                if (fuFlags & MF_SYSMENU)       // Menú de Sistema
                nStringID = IDS_SYSMENU;
                else
                // Get string ID for popup menu from idPopup array.
                nStringID = 0;
                }
            else                                // Debe ser un ítem de comando
                nStringID = uCmd;               // ID String == ID Comando

    // Cargamos el string si tenemos un ID
    if (0 != nStringID)
        LoadString(hInst, nStringID, szBuffer, sizeof(szBuffer));
    // Enviamos las cadena a la Barra de Estado.
    ActualizarBarraEstado(szBuffer, 0, 0);
    ActualizarBarraEstado("Tiempo:", 1, 0);
    ActualizarBarraEstado("Comparaciones: ", 2, 0);
    ActualizarBarraEstado("Intercambios: ", 3, 0);

    return 0;
}

/* ----------------------------------------------------------------------
   Función     : MainWndProc_OnCommand()
   Descripción : Maneja la selección de los menús llamando a las funciones
                 correspondientes
   Parámetros  : hwnd       -> Manejador de la ventana
                 id         -> ID del ítem seleccionado
                 hwdnCtl    -> Manejador del control que envía el mensaje
                               si éste fue enviado por un control
                 codeNotify -> Código de notificación si el mesaje es de
                               un control. Es 1 si el mensaje es de un
                               acelerador y 0 si es de un menú
                 Los dos últimos parámetros no son utilzados, pero pueden
                 serlo al agregar más funcionalidad al programa
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void MainWndProc_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
        {
        case IDM_EXIT:
            PostMessage(hwnd,WM_CLOSE,0,0);
            break;
        case IDM_BURBUJ:
            ActualizarBarraEstado("Ejecutando Ordenamiento Burbuja", 0, 0);
            Burbuja(hwnd);
            break;
        case IDM_SELEC:
            ActualizarBarraEstado("Ejecutando Ordenamiento por Selección", 0, 0);
            Seleccion(hwnd);
            break;
        case IDM_INSERC:
            ActualizarBarraEstado("Ejecutando Ordenamiento por Inserción", 0, 0);
            Insercion(hwnd);
            break;
        case IDM_QUICKSORT:
            ActualizarBarraEstado("Ejecutando Ordenamiento Rápido", 0, 0);
            Quicksort(hwnd);
            break;
        case IDM_PREND:
            DialogBox(hInst, MAKEINTRESOURCE(DLG_PREND), hwndMain,
                      (DLGPROC) PruebaRendimiento);
            break;
        case IDM_DESORD:
            DesordenarBarras();                 // Desordenamos las barras
            InvalidateRect(hwnd, NULL, TRUE);   // Invalidamos la ventana para pintarla
            break;
        case IDM_PAUSA:
            DialogBox(hInst, MAKEINTRESOURCE(DLG_PAUSA), hwndMain, (DLGPROC) Pausa);
            break;
        case IDM_ESTAD:
            DialogBox(hInst, MAKEINTRESOURCE(DLG_ESTAD), hwndMain, (DLGPROC) Estadisticas);
            break;
        case IDM_AYUDA:
            ShellExecute(hwnd, "open", "../Ayuda/ayuda.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_ALGORD:
            ShellExecute(hwnd, "open", "../Articulo/alg_ord.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_A_BURB:
            ShellExecute(hwnd, "open", "../Articulo/burbuja.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_A_SELEC:
            ShellExecute(hwnd, "open", "../Articulo/seleccion.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_A_INSER:
            ShellExecute(hwnd, "open", "../Articulo/insercion.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_A_QUICK:
            ShellExecute(hwnd, "open", "../Articulo/quicksort.htm", NULL, NULL, SW_MAXIMIZE);
            break;
        case IDM_ACERCA_DE:
            DialogBox(hInst, MAKEINTRESOURCE(DLG_ACERCA_DE), hwndMain, (DLGPROC) Acerca_de);
            break;
        }
}

/* ----------------------------------------------------------------------
   Las siguientes funciones eran utilizadas por los otros dos módulos,
   así que decidí generalizarlas un poco y ponerlas aquí
   ---------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Función     : CrearColumnas()
   Descripción : Crea las columnas de los controles List View utilizados
                 en el programa. El texto de cada columna es cargado desde
                 el fichero de recursos
   Parámetros  : hwndDlg -> Manejador del diálogo que contiene el control
                 iID     -> Identificador de recurso del control List View
   Retorna     : TRUE si todo sale bien y FALSE de lo contrario
   ---------------------------------------------------------------------- */
BOOL CrearColumnas(HWND hwndDlg, int iID)
{
    HINSTANCE hInstMain;    // Manejador de la instancia del programa
    HWND hwndLista;         // Manejador de la instancia de la lista
    LV_COLUMN lvc;          // La estructura de las columnas que insertamos
    int alineacion[] = {LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_RIGHT};
    char szTexto[256];      // Buffer temporal para cargar los string
    int iCol;

    hInstMain = GetModuleHandle(NULL);      // Obtenemos el manejador de la instancia
    hwndLista = GetDlgItem(hwndDlg, iID);   // Obtenemos el manejador de la lista

    /* Inicializamos la estructura LVCOLUMN. Las máscaras epecifican que los
       miembros formato, ancho texto y subítem de las esctrucutura son válidos */
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvc.cx = 100;           // El ancho de la columna en pixeles

    // Agregamos las columnas
    for (iCol = 0; iCol < C_COLUMNS; iCol++)
        {
        lvc.fmt = alineacion[iCol]; // La alineación de la columna
        lvc.iSubItem = iCol;        // El subítem asociado a esta columna
        // Cargamos el texto correspondiente a cada colunma
        LoadString(hInstMain, (UINT) (IDS_PRIMCOLUMN + iCol), szTexto, sizeof(szTexto));
        lvc.pszText = szTexto;      // El texto del encabezado (que acabamos de cargar)
        if (ListView_InsertColumn(hwndLista, iCol, &lvc) == -1)
            return FALSE;
        }

    return TRUE;
}

/* ----------------------------------------------------------------------
   Función     : InsertarItem()
   Descripción : Inserta un ítem en un control List View.
   Parámetros  : hwndDlg   -> Manejador del diálogo que tiene el control
                 hwndLista -> El manejador del control
                 pszTexto  -> El texto a insertar
                 iItem     -> Índice del ítem
                 iSubItem  -> Índice del subítem
   Retorna     : 0 si todo sale bien y -1 de lo contrario
   ---------------------------------------------------------------------- */
int InsertarItem(HWND hwndDlg, HWND hwndLista, char *pszTexto, int iItem, int iSubItem)
{
    LV_ITEM nuevo;

    // Inicializamos la estructura
    memset ((void *)&nuevo, 0, sizeof(LV_ITEM));
    nuevo.mask = LVIF_TEXT | LVIF_STATE;        // Texto y estado son válidos
    nuevo.iItem = iItem;                        // El ítem, obviamente :-D
    nuevo.iSubItem = iSubItem;                  // Sí, el subítem :-D
    nuevo.pszText = pszTexto;

    // El subítem 0 se inserta con esta función
    if (iSubItem == 0)
        {
        if (ListView_InsertItem(hwndLista, &nuevo) == -1)
            {
            Error ("Error insertando SubItem");
            return -1;
            }
        }

    else    // Para todos los demás se hace con esta
        {
        if (ListView_SetItem(hwndLista, &nuevo) == -1)
            {
            Error ("Error insertando SubItem");
            return -1;
            }
        }
    // Actualizamos el control para que muestre todo
    ListView_Update(hwndLista, iItem);

    return 0;
}

/* ----------------------------------------------------------------------
   Función     : Error()
   Descripción : Muestra un mensaje de error en la pantalla
   Parámetros  : Cadena con el mensaje de error a mostrar
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void Error(LPCTSTR desc)
{
    MessageBox(NULL, desc, "Error", MB_OK | MB_ICONERROR);
}

/* ----------------------------------------------------------------------
                            Ord_Win.c

    Descripci�n : Programa de demostraci�n gr�fica de varios algoritmos
                  de ordenamiento. M�dulo principal.
    Autor       : Juli�n Hidalgo
    Versi�n     : 1.0 para LccWin32
    Fecha       : Noviembre de 2001
    Contacto    : jhida003@pinhue.ufro.cl
                  nirvananomuere@yahoo.com
    P�gina      : http:/www.conclase.net

    Por favor av�same si encuentas alg�n error o tienes sugerencias sobre
    este programa
   ---------------------------------------------------------------------- */

#include "ord_win.h"        // Las definiciones generales
#include "ord_win_def.h"    // Las definiciones espec�ficas de este modulo

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
   Funci�n     : IniciarAplicacion()
   Descripci�n : Registra la clase, inicia los cotroles y crea las barras
   Par�metros  : Ninguno
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
   Funci�n     : CrearOrdWinClase()
   Descripci�n : Crea la ventana principal
   Par�metros  : Ninguno
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
   Funci�n     : CrearBarraEstado()
   Descripci�n : Crea la barra de estado de la ventana
   Par�metros  : hwndParent   -> Manejador de la ventan padre
                 textoInicial -> El texto inicial que se mostrar�
                 nroDePartes  -> N�mero de partes de la barra de estado
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
   Funci�n     : InicializarBarraEstado()
   Descripci�n : Establece el n�mero de partes y muestra el texto inicial
   Par�metros  : hwndParent  -> Manejador de la ventana padre
                 nroDePartes -> N�mero de partes de la barra de estado
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void InicializarBarraEstado(HWND hwndParent,int nroDePartes)
{
    int   ptArreglo[NUM_PARTS];   // Arreglo con las coordenada de las partes
    RECT  rect;

    if (!GetClientRect(hwndParent, &rect))  // Obtenemos el �rea de nuestra ventana
        return;

    // Llenamos el arreglo de partes
    ptArreglo[0] = (int) (rect.right / 2);
    ptArreglo[1] = (int) (4 * rect.right / 6);
    ptArreglo[2] = (int) (5 * rect.right / 6);
    ptArreglo[3] = (int) (rect.right);

    // Establecemos el n�mero de partes de la Barra de Estado
    if (SendMessage(hwndBarraEstado, SB_SETPARTS, nroDePartes, (LPARAM)ptArreglo) == FALSE)
        Error("Error estableciendo el n�mero de partes");

    ActualizarBarraEstado("Listo", 0, 0);
    ActualizarBarraEstado("Tiempo:", 1, 0);
    ActualizarBarraEstado("Comparaciones: ", 2, 0);
    ActualizarBarraEstado("Intercambios: ", 3, 0);
}

/* ----------------------------------------------------------------------
   Funci�n     : ActualizarBarraEstado()
   Descripci�n : Imprime el texto especificado en la parte indicada
   Par�metros  : lpszStringEstado -> La cadena a imprimir
                 numeroParte      -> En qu� parte hacerlo
                 displayFlags     -> Banderas de impresi�n
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void ActualizarBarraEstado(LPSTR lpszStringEstado, WORD numeroParte, WORD displayFlags)
{
    // Simplemente enviamos el texto a la Barra de Estado
    SendMessage(hwndBarraEstado, SB_SETTEXT, numeroParte | displayFlags,
                (LPARAM)lpszStringEstado);
}

/* ----------------------------------------------------------------------
   Funci�n     : MainWndProc()
   Descripci�n : Procedimiento de ventana principal
   Par�metros  : hwnd   -> Manejador de la ventana
                 msg    -> Identificador del mensaje
                 wParam -> Primer par�metro del mensaje
                 lParam -> Segundo par�metro del mensaje
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
   Funci�n     : MsgSelecMenu()
   Descripci�n : B�sicamente esta funci�n env�a mensajes a la barra de
                 estado cuando el mouse pasa sobre alg�n �tem del men�.
                 El mensaje es un string guardado en el fichero de
                 recursos de la aplicaci�n, y debe tener el mismo valor
                 num�rico que el ID del comando que se destaca
   Par�metros  : hwnd   -> Manejador de la ventana
                 msg    -> Identificador del mensaje
                 wParam -> Primer par�metro del mensaje
                 lParam -> Segundo par�metro del mensaje
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
    if (fuFlags == 0xffff && hMenu == NULL)     // El Men� ha sido cerrado
        nStringID = 0;

    else
        if (fuFlags & MFT_SEPARATOR)            // Ignoramos los separadores
            nStringID = 0;

        else
            if (fuFlags & MF_POPUP)             // Men� Popup
                {
                if (fuFlags & MF_SYSMENU)       // Men� de Sistema
                nStringID = IDS_SYSMENU;
                else
                // Get string ID for popup menu from idPopup array.
                nStringID = 0;
                }
            else                                // Debe ser un �tem de comando
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
   Funci�n     : MainWndProc_OnCommand()
   Descripci�n : Maneja la selecci�n de los men�s llamando a las funciones
                 correspondientes
   Par�metros  : hwnd       -> Manejador de la ventana
                 id         -> ID del �tem seleccionado
                 hwdnCtl    -> Manejador del control que env�a el mensaje
                               si �ste fue enviado por un control
                 codeNotify -> C�digo de notificaci�n si el mesaje es de
                               un control. Es 1 si el mensaje es de un
                               acelerador y 0 si es de un men�
                 Los dos �ltimos par�metros no son utilzados, pero pueden
                 serlo al agregar m�s funcionalidad al programa
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
            ActualizarBarraEstado("Ejecutando Ordenamiento por Selecci�n", 0, 0);
            Seleccion(hwnd);
            break;
        case IDM_INSERC:
            ActualizarBarraEstado("Ejecutando Ordenamiento por Inserci�n", 0, 0);
            Insercion(hwnd);
            break;
        case IDM_QUICKSORT:
            ActualizarBarraEstado("Ejecutando Ordenamiento R�pido", 0, 0);
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
   Las siguientes funciones eran utilizadas por los otros dos m�dulos,
   as� que decid� generalizarlas un poco y ponerlas aqu�
   ---------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Funci�n     : CrearColumnas()
   Descripci�n : Crea las columnas de los controles List View utilizados
                 en el programa. El texto de cada columna es cargado desde
                 el fichero de recursos
   Par�metros  : hwndDlg -> Manejador del di�logo que contiene el control
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

    /* Inicializamos la estructura LVCOLUMN. Las m�scaras epecifican que los
       miembros formato, ancho texto y sub�tem de las esctrucutura son v�lidos */
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvc.cx = 100;           // El ancho de la columna en pixeles

    // Agregamos las columnas
    for (iCol = 0; iCol < C_COLUMNS; iCol++)
        {
        lvc.fmt = alineacion[iCol]; // La alineaci�n de la columna
        lvc.iSubItem = iCol;        // El sub�tem asociado a esta columna
        // Cargamos el texto correspondiente a cada colunma
        LoadString(hInstMain, (UINT) (IDS_PRIMCOLUMN + iCol), szTexto, sizeof(szTexto));
        lvc.pszText = szTexto;      // El texto del encabezado (que acabamos de cargar)
        if (ListView_InsertColumn(hwndLista, iCol, &lvc) == -1)
            return FALSE;
        }

    return TRUE;
}

/* ----------------------------------------------------------------------
   Funci�n     : InsertarItem()
   Descripci�n : Inserta un �tem en un control List View.
   Par�metros  : hwndDlg   -> Manejador del di�logo que tiene el control
                 hwndLista -> El manejador del control
                 pszTexto  -> El texto a insertar
                 iItem     -> �ndice del �tem
                 iSubItem  -> �ndice del sub�tem
   Retorna     : 0 si todo sale bien y -1 de lo contrario
   ---------------------------------------------------------------------- */
int InsertarItem(HWND hwndDlg, HWND hwndLista, char *pszTexto, int iItem, int iSubItem)
{
    LV_ITEM nuevo;

    // Inicializamos la estructura
    memset ((void *)&nuevo, 0, sizeof(LV_ITEM));
    nuevo.mask = LVIF_TEXT | LVIF_STATE;        // Texto y estado son v�lidos
    nuevo.iItem = iItem;                        // El �tem, obviamente :-D
    nuevo.iSubItem = iSubItem;                  // S�, el sub�tem :-D
    nuevo.pszText = pszTexto;

    // El sub�tem 0 se inserta con esta funci�n
    if (iSubItem == 0)
        {
        if (ListView_InsertItem(hwndLista, &nuevo) == -1)
            {
            Error ("Error insertando SubItem");
            return -1;
            }
        }

    else    // Para todos los dem�s se hace con esta
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
   Funci�n     : Error()
   Descripci�n : Muestra un mensaje de error en la pantalla
   Par�metros  : Cadena con el mensaje de error a mostrar
   Retorna     : Nada
   ---------------------------------------------------------------------- */
void Error(LPCTSTR desc)
{
    MessageBox(NULL, desc, "Error", MB_OK | MB_ICONERROR);
}

#ifndef _ORD_WIN_DEF_H_
    #define _ORD_WIN_DEF_H_

BOOL IniciarAplicacion(void);
HWND CrearOrdWinClase(void);
BOOL CrearBarraEstado(HWND hwndParent,char *textoInicial,int nrOfParts);
void InicializarBarraEstado(HWND hwndParent,int nrOfParts);
LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
LRESULT MsgSelecMenu(HWND hwnd, UINT uMessage, WPARAM wparam, LPARAM lparam);
void MainWndProc_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

#endif

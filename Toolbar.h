#pragma once
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

HWND hwndToolBar = NULL;
#define IDC_MY_TOOLBAR 1
#define ID_TOOL_POINT 1
#define ID_TOOL_LINE 2
#define ID_TOOL_RECT 3
#define ID_TOOL_ELLIPSE 4

LPARAM IDS[] = { ID_TOOL_POINT, ID_TOOL_LINE, ID_TOOL_RECT, ID_TOOL_ELLIPSE };
const int COUNT_OF_BUTTONS = sizeof(IDS) / sizeof(LPARAM);
TBBUTTON tbb[COUNT_OF_BUTTONS];

class Toolbar
{
private: 
    LPARAM LastID;
public:
	Toolbar();
	~Toolbar();
    BOOL press = FALSE;
	void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND hWnd);
    void OnPress(HWND hWnd, LPARAM id);
    void OnNotify(HWND, WPARAM, LPARAM);
};

Toolbar::Toolbar()
{
}

Toolbar::~Toolbar()
{
}

void Toolbar::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    ZeroMemory(tbb, sizeof(tbb));
    for (size_t i = 0; i < COUNT_OF_BUTTONS; i++)
    {
        tbb[i].iBitmap = i;
        tbb[i].fsState = TBSTATE_ENABLED;
        tbb[i].fsStyle = TBSTYLE_BUTTON;
        tbb[i].idCommand = IDS[i];
    }

    hwndToolBar = CreateToolbarEx(hWnd, //батьківське вікно
        WS_CHILD | WS_VISIBLE | WS_BORDER
        | WS_CLIPSIBLINGS | CCS_TOP |
        TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR, //ID дочірнього вікна Toolbar
        COUNT_OF_BUTTONS, hInst, IDB_BITMAP1,
        tbb,
        COUNT_OF_BUTTONS, //кількість кнопок
        24, 24, 24, 24, //розташування та розміри
        sizeof(TBBUTTON));
}

void Toolbar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar)
    {
        GetClientRect(hWnd, &rc); //нові розміри головного вікна
        GetWindowRect(hwndToolBar, &rw); //нам потрібно знати висоту Toolbar
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
}

void Toolbar::OnPress(HWND hWnd, LPARAM id)
{
    if (LastID == id || !LastID)
    {
        press = !press;
    }

    if (press)
    {
        for (LPARAM ID : IDS)
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID, FALSE);
        LastID = id;
    }
    else
    {
        LastID = 0;
    }

    SendMessage(hwndToolBar, TB_PRESSBUTTON, id, press);
}

void Toolbar::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    LPNMHDR pnmh = (LPNMHDR)lParam;
    if (pnmh->code == TTN_NEEDTEXT)
    {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
        switch (lpttt->hdr.idFrom)
        {
        case ID_TOOL_POINT:
            lstrcpy(lpttt->szText, L"Крапка");
            break;
        case ID_TOOL_LINE:
            lstrcpy(lpttt->szText, L"Лінія");
            break;
        case ID_TOOL_RECT:
            lstrcpy(lpttt->szText, L"Прямокутник");
            break;
        case ID_TOOL_ELLIPSE:
            lstrcpy(lpttt->szText, L"Еліпс");
            break;
        case IDM_ABOUT:
            lstrcpy(lpttt->szText, L"Довідка");
            break;
        default: lstrcpy(lpttt->szText, L"Щось невідоме");
        }
    }
}
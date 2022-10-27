#include "framework.h"
#include "Toolbar.h"

int IDS[] = { ID_TOOL_POINT, ID_TOOL_LINE, ID_TOOL_RECT, ID_TOOL_ELLIPSE };
const int COUNT_OF_BUTTONS = sizeof(IDS) / sizeof(int);
TBBUTTON tbb[COUNT_OF_BUTTONS];

Toolbar::Toolbar(BOOL* press, LPARAM* id)
{
    ppress = press;
    pLastId = id;
}

void Toolbar::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    ZeroMemory(tbb, sizeof(tbb));
    for (int i = 0; i < COUNT_OF_BUTTONS; i++)
    {
        tbb[i].iBitmap = i;
        tbb[i].fsState = TBSTATE_ENABLED;
        tbb[i].fsStyle = TBSTYLE_BUTTON;
        tbb[i].idCommand = IDS[i];
    }

    hwndToolBar = CreateToolbarEx(hWnd,
        WS_CHILD | WS_VISIBLE | WS_BORDER
        | WS_CLIPSIBLINGS | CCS_TOP |
        TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR,
        COUNT_OF_BUTTONS, hInst, IDB_BITMAP1,
        tbb,
        COUNT_OF_BUTTONS,
        24, 24, 24, 24,
        sizeof(TBBUTTON));
}

void Toolbar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar)
    {
        GetClientRect(hWnd, &rc);
        GetWindowRect(hwndToolBar, &rw);
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
}

void Toolbar::OnPress(HWND hWnd, LPARAM id)
{
    if (*pLastId == id || !(*pLastId))
    {
        *ppress = !(*ppress);
    }

    if (*ppress)
    {
        for (LPARAM ID : IDS)
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID, FALSE);
        *pLastId = id;
    }
    else
    {
        *pLastId = 0;
    }

    SendMessage(hwndToolBar, TB_PRESSBUTTON, id, *ppress);
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
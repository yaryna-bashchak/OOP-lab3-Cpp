#pragma once
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

#define IDC_MY_TOOLBAR 1
#define ID_TOOL_POINT 1
#define ID_TOOL_LINE 2
#define ID_TOOL_RECT 3
#define ID_TOOL_ELLIPSE 4

class Toolbar
{
public:
    BOOL press = FALSE;
    LPARAM LastID = 0;
	void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND hWnd);
    void OnPress(HWND hWnd, LPARAM id);
    void OnNotify(HWND, WPARAM, LPARAM);
};
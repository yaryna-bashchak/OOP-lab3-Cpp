#include "framework.h"
#include "ShapeEditor.h"
#include "editors.h"

UINT IDS[] = { IDM_POINT, IDM_LINE, IDM_RECT, IDM_ELLIPSE };

ShapeEditor::ShapeEditor(HWND hwnd) {
	hWnd = hwnd;
	hdc = GetDC(hWnd);
	hPen = CreatePen(PS_SOLID, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
};

void ShapeEditor::UpdateXY()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
}

int ShapeEditor::Check() {
	if (xstart == 0 && ystart == 0 && xend == 0 && yend == 0) return 0;
	else return 1;
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
	UpdateXY();
	xstart = xend;
	ystart = yend;
}

void ShapeEditor::OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < COUNT_OF_OBJECTS; i++)
		pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

void ShapeEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam, LPARAM id, BOOL press) {
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		for (LPARAM ID : IDS)
			CheckMenuItem(hSubMenu, ID, MF_UNCHECKED);
	}
	if (press)
		CheckMenuItem(hSubMenu, IDS[id-1], MF_CHECKED);
};
#include "framework.h"
#include "shape_editor.h"
#include "Editors.h"

ShapeEditor::ShapeEditor(HWND hwnd) {
	hWnd = hwnd;
	hdc = GetDC(hWnd);
	hPen = CreatePen(PS_DOT, 1, 0);
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

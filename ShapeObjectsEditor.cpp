#include "framework.h"
#include "ShapeObjectsEditor.h"
#include "Editor.h"
#include "Shape.h"
#include "editors.h"

const int ARRAY_SIZE = 103;
Shape* pcshape[ARRAY_SIZE];
ShapeEditor* pse = NULL;

BOOL press = FALSE;
BOOL* ppress = &press;
LPARAM LastButtonId = 0;
LPARAM* pLastButtonId = &LastButtonId;

Toolbar ToolBar(ppress, pLastButtonId);

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	pse = new PointEditor(hWnd);
	ToolBar.OnPress(hWnd, ID_TOOL_POINT);
};
void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	pse = new LineEditor(hWnd);
	ToolBar.OnPress(hWnd, ID_TOOL_LINE);
};
void ShapeObjectsEditor::StartRectEditor(HWND hWnd) {
	pse = new RectEditor(hWnd);
	ToolBar.OnPress(hWnd, ID_TOOL_RECT);
};
void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	pse = new EllipseEditor(hWnd);
	ToolBar.OnPress(hWnd, ID_TOOL_ELLIPSE);
};
void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse && press)
		pse->OnLBdown(hWnd);
};
void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse && press)
	{
		pse->OnLBup(hWnd, pcshape, COUNT_OF_OBJECTS);
		COUNT_OF_OBJECTS++;
	}
};
void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse)
		pse->OnMouseMove(hWnd);
};
void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	pse->OnPaint(hWnd, pcshape, COUNT_OF_OBJECTS);
};

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse) 
		pse->OnInitMenuPopup(hWnd, wParam, LastButtonId, press);
}

void ShapeObjectsEditor::OnCreate(HWND hWnd, HINSTANCE hInst) {
	ToolBar.OnCreate(hWnd, hInst);
};

void ShapeObjectsEditor::OnSize(HWND hWnd) {
	ToolBar.OnSize(hWnd);
};

void ShapeObjectsEditor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	ToolBar.OnNotify(hWnd, wParam, lParam);
};
#include "framework.h"
#include "ShapeObjectsEditor.h"
#include "Editor.h"
#include "Shape.h"
#include "editors.h"

const int ARRAY_SIZE = 103;
Shape* pcshape[ARRAY_SIZE];
ShapeEditor* pse = NULL;

int COUNT_OF_OBJECTS = 0;

ShapeObjectsEditor::ShapeObjectsEditor(BOOL* press, LPARAM* id) {
	pCOUNT_OF_OBJECTS = &COUNT_OF_OBJECTS;
	ppress = press;
	pLastId = id;
};

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	pse = new PointEditor(hWnd);
};
void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	pse = new LineEditor(hWnd);
};
void ShapeObjectsEditor::StartRectEditor(HWND hWnd) {
	pse = new RectEditor(hWnd);
};
void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	pse = new EllipseEditor(hWnd);
};
void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse && *ppress)
		pse->OnLBdown(hWnd);
};
void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse && *ppress)
	{
		pse->OnLBup(hWnd, pcshape, *pCOUNT_OF_OBJECTS);
		(*pCOUNT_OF_OBJECTS)++;
	}
};
void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse)
		pse->OnMouseMove(hWnd);
};
void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	pse->OnPaint(hWnd, pcshape, *pCOUNT_OF_OBJECTS);
};

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse) 
		pse->OnInitMenuPopup(hWnd, wParam, *pLastId, *ppress);
}

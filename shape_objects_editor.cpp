#include "framework.h"
#include "shape_objects_editor.h"
#include "editor.h"
#include "shape.h"
#include "Editors.h"

ShapeEditor* pse = NULL;

ShapeObjectsEditor::ShapeObjectsEditor(int size, int* p) {
	ARRAY_SIZE = size;
	pCOUNT_OF_OBJECTS = p;
};

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу крапок");
	pse = new PointEditor(hWnd);
};
void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу ліній");
	pse = new LineEditor(hWnd);
};
void ShapeObjectsEditor::StartRectEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу прямокутників");
	pse = new RectEditor(hWnd);
};
void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу еліпсів");
	pse = new EllipseEditor(hWnd);
};
void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse)
		pse->OnLBdown(hWnd);
};
void ShapeObjectsEditor::OnLBup(HWND hWnd, Shape* p[]) {
	if (pse) {
		pse->OnLBup(hWnd, p, *pCOUNT_OF_OBJECTS);
		(*pCOUNT_OF_OBJECTS)++;
	}
};
void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse && pse -> Check())
		pse->OnMouseMove(hWnd);
};
void ShapeObjectsEditor::OnPaint(HWND hWnd, Shape* p[]) {
	pse->OnPaint(hWnd, p, *pCOUNT_OF_OBJECTS);
};
#include "framework.h"
#include "ShapeObjectsEditor.h"
#include "Editor.h"
#include "Shape.h"
#include "editors.h"

const int ARRAY_SIZE = 103;
Shape* pcshape[ARRAY_SIZE];
ShapeEditor* pse = NULL;

int COUNT_OF_OBJECTS = 0;

ShapeObjectsEditor::ShapeObjectsEditor(void) {
	pCOUNT_OF_OBJECTS = &COUNT_OF_OBJECTS;
};

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	SetWindowText(hWnd, L"����� ����� ������");
	pse = new PointEditor(hWnd);
};
void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	SetWindowText(hWnd, L"����� ����� ����");
	pse = new LineEditor(hWnd);
};
void ShapeObjectsEditor::StartRectEditor(HWND hWnd) {
	SetWindowText(hWnd, L"����� ����� ������������");
	pse = new RectEditor(hWnd);
};
void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	SetWindowText(hWnd, L"����� ����� �����");
	pse = new EllipseEditor(hWnd);
};
void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse)
		pse->OnLBdown(hWnd);
};
void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse) {
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
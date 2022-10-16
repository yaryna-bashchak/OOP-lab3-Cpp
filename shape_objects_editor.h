#pragma once
#include "shape.h"
#include "shape_editor.h"

class ShapeObjectsEditor
{
private:
	int* pCOUNT_OF_OBJECTS;
	int ARRAY_SIZE;
public:
	ShapeObjectsEditor(int size, int* p);
	void StartPointEditor(HWND hWnd);
	void StartLineEditor(HWND hWnd);
	void StartRectEditor(HWND hWnd);
	void StartEllipseEditor(HWND hWnd);
	void OnLBdown(HWND hWnd);
	void OnLBup(HWND hWnd, Shape* p[]);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd, Shape* p[]);
};
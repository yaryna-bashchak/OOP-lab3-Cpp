#pragma once
#include "Shape.h"
#include "ShapeEditor.h"

class ShapeObjectsEditor
{
private:
	int* pCOUNT_OF_OBJECTS;
public:
	ShapeObjectsEditor(void);
	void StartPointEditor(HWND hWnd);
	void StartLineEditor(HWND hWnd);
	void StartRectEditor(HWND hWnd);
	void StartEllipseEditor(HWND hWnd);
	void OnLBdown(HWND hWnd);
	void OnLBup(HWND hWnd);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd);
};
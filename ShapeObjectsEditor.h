#pragma once
#include "Shape.h"
#include "ShapeEditor.h"
#include "Toolbar.h"

class ShapeObjectsEditor
{
private:
	int COUNT_OF_OBJECTS = 0;
public:
	void StartPointEditor(HWND hWnd);
	void StartLineEditor(HWND hWnd);
	void StartRectEditor(HWND hWnd);
	void StartEllipseEditor(HWND hWnd);
	void OnLBdown(HWND hWnd);
	void OnLBup(HWND hWnd);
	void OnMouseMove(HWND hWnd);
	void OnPaint(HWND hWnd);
	void OnInitMenuPopup(HWND, WPARAM);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
};
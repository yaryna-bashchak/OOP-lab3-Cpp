#pragma once
#include "Editor.h"

class ShapeEditor : public Editor
{
protected:
    long xstart = 0, ystart = 0, xend = 0, yend = 0;
	HWND hWnd;
	HDC hdc;
	HPEN hPenSolid, hPenOld;
	void UpdateXY();
	int Check();
public:
	ShapeEditor(HWND hwnd);
	void OnLBdown(HWND hWnd);
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS);
	void OnInitMenuPopup(HWND, WPARAM, LPARAM, BOOL);
};

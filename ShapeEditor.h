#pragma once
#include "Editor.h"

class ShapeEditor : public Editor
{
protected:
    long xstart, ystart, xend, yend;
	HWND hWnd;
	HDC hdc;
	HPEN hPen, hPenOld;
	void UpdateXY();
	int Check();
public:
	ShapeEditor(HWND hwnd);
	void OnLBdown(HWND hWnd);
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};

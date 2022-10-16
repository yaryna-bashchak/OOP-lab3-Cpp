#pragma once
#include "editor.h"

class ShapeEditor : public Editor
{
protected:
    long xstart = 0, ystart = 0, xend = 0, yend = 0;
	HWND hWnd;
	HDC hdc;
	HPEN hPen, hPenOld;
	void UpdateXY();
	
public:
	ShapeEditor(HWND hwnd);
	int Check() {
		if (xstart == 0 && ystart == 0 && xend == 0 && yend == 0) return 0;
		else return 1;
	}
	void OnLBdown(HWND hWnd);
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS);
};

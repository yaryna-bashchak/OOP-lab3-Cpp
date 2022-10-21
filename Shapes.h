#pragma once
#include "Shape.h"

class PointShape : public Shape
{
public:
	void Show(HDC hdc) {
		SelectObject(hdc, hPenForPoint);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, ys2);
	}
};

////////////////////////////////////////////////

class LineShape : public Shape
{
public:
	void Show(HDC hdc) {
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs2, ys2);
	}
};

////////////////////////////////////////////////

class RectShape : public Shape
{
public:
	void Show(HDC hdc) {
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, ys1);
		LineTo(hdc, xs1 , ys1);
		LineTo(hdc, xs1, ys2);
		LineTo(hdc, xs2, ys2);
	}
};

/////////////////////////////////////////////////////

class EllipseShape : public Shape
{
public:
	void Show(HDC hdc)
	{
		SelectObject(hdc, hBrush);
		Ellipse(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, xs2, ys2);
	}
};
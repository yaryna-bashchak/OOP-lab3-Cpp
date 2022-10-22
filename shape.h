#pragma once
#include "framework.h"

class Shape
{
protected:
	long xs1 = 0, ys1 = 0, xs2 = 0, ys2 = 0;
	HPEN hPen = CreatePen(PS_SOLID, 3, 0);
	HPEN hPenForPoint = CreatePen(PS_SOLID, 7, 0);
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
public:
	~Shape();
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
};
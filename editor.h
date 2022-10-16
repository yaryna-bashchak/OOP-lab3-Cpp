#pragma once
#include "framework.h"
#include "Shape.h"

class Editor
{
public:
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
};
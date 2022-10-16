#pragma once
#include "framework.h"
#include "shape.h"

class Editor
{
public:
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
};
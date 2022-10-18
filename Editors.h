#pragma once
#include "shapes.h"
#include "ShapeEditor.h"
#include "resource.h"

/////////////////////////////////////////////////////

class PointEditor : public ShapeEditor
{
public:
	PointEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	void OnLBdown(HWND hWnd) {}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new PointShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd) {};

	void OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
		HMENU hMenu, hSubMenu;
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		if ((HMENU)wParam == hSubMenu)
		{
			CheckMenuItem(hSubMenu, IDM_POINT, MF_CHECKED);
			CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
		}
	};
};

/////////////////////////////////////////////////////

class LineEditor : public ShapeEditor
{
private:
	void DrawLine()
	{
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, yend);
	}
public:
	LineEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new LineShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (Check()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawLine();
			UpdateXY();
			DrawLine();
		}
		
	}

	void OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
		HMENU hMenu, hSubMenu;
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		if ((HMENU)wParam == hSubMenu)
		{
			CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
			CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
		}
	};
};

//////////////////////////////////////////////////////

class RectEditor : public ShapeEditor
{
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, yend);
		LineTo(hdc, xend, yend);
	}
public:
	RectEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new RectShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (Check()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawRect();
			UpdateXY();
			DrawRect();
		}	
	}

	void OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
		HMENU hMenu, hSubMenu;
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		if ((HMENU)wParam == hSubMenu)
		{
			CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_RECT, MF_CHECKED);
			CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
		}
	};
};

///////////////////////////////////////////////////////

class EllipseEditor : public ShapeEditor
{
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, ystart);
		LineTo(hdc, xstart, ystart);
		LineTo(hdc, xstart, yend);
		LineTo(hdc, xend, yend);
	}
	void DrawEllipse()
	{
		Arc(hdc, xstart, ystart, xend, yend, 0, 0, 0, 0);
	}
public:
	EllipseEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	
	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new EllipseShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (Check()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawEllipse();
			DrawRect();
			UpdateXY();
			DrawEllipse();
			DrawRect();
		}
	}

	void OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
		HMENU hMenu, hSubMenu;
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		if ((HMENU)wParam == hSubMenu)
		{
			CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_RECT, MF_UNCHECKED);
			CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_CHECKED);
		}
	};
};
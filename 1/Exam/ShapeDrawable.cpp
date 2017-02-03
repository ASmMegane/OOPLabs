#include "stdafx.h"
#include "ShapeDrawable.h"

CRectangle::CRectangle(int x, int y, int width, int height) 
	: x(x)
	, y(y)
	, width(width)
	, height(height)
{}

void CRectangle::DrawShape(ICanvas & canvas) const
{
	canvas.DrawLine(x, y, x + width - 1, y);
	canvas.DrawLine(x, y, x, y + height - 1);
	canvas.DrawLine(x + width - 1, y, x + width - 1, y + height - 1);
	canvas.DrawLine(x, y + height - 1, x + width - 1, y + height - 1);
}

CTriangle::CTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
	: x1(x1)
	, y1(y1)
	, x2(x2)
	, y2(y2)
	, x3(x3)
	, y3(y3)
{
}

void CTriangle::DrawShape(ICanvas & canvas) const
{
	canvas.DrawLine(x1, y1, x2, y2);
	canvas.DrawLine(x1, y1, x3, y3);
	canvas.DrawLine(x2, y2, x3, y3);
}
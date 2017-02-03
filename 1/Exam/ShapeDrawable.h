#pragma once
#include "Canvas.h"

class ICanvasDrawable
{
public:
	virtual void DrawShape(ICanvas & canvas) const = 0;
};

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(int x, int y, int width, int height);
	void DrawShape(ICanvas & canvas) const override;

private:
	int x;
	int y;
	int width;
	int height;
};


class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
	void DrawShape(ICanvas & canvas) const override;

private:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
};

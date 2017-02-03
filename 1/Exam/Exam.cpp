#include "stdafx.h"
#include "Canvas.h"
#include "ShapeDrawable.h"
#include <vector>
#include <memory>


void DrawPicture(ICanvas & canvas, const std::vector<std::shared_ptr<const ICanvasDrawable>> & picture)
{
	for (auto shape : picture)
	{
		shape->DrawShape(canvas);
	}
	canvas.OutputCanvas();
}

int main()
{
	CCanvas canvas(20);
	std::vector<std::shared_ptr<const ICanvasDrawable>> picture;
	
	picture.push_back(std::shared_ptr<ICanvasDrawable>(new CTriangle(5, 1, 1, 5, 5, 9)));
	picture.push_back(std::shared_ptr<ICanvasDrawable>(new CRectangle(5, 2, 7, 7)));

	DrawPicture(canvas, picture);
    return 0;
}


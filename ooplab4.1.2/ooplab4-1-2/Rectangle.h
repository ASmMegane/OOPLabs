#pragma once
#include "CShape.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint & leftTopPoint, int w, int h);

	void SetPosition(int x, int y);
	void SetPosition(const CPoint & point);

	CPoint GetPosition();

	void SetSize(int width, int height);

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	struct Size
	{
		Size(int w, int h) : width(w), height(h) {}
		int width;
		int height;
	};
	Size m_size;
	CPoint m_position;

public:
	Size GetSize() const;
};


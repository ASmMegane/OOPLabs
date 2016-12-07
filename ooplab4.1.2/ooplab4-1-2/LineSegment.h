#pragma once
#include "CShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint & point1, const CPoint & point2);

	const CPoint GetFirstPointPosition();
	const CPoint GetSecondPointPosition();

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	CPoint m_point1;
	CPoint m_point2;
};


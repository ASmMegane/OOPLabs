#pragma once
#include "IShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint & point1, const CPoint & point2);

	const CPoint GetPointPosition1();
	const CPoint GetPointPosition2();

	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;

	virtual std::string GetShapeType() const override;
	virtual std::string GetStringRepresentation() const override;

private:
	CPoint m_point1;
	CPoint m_point2;
};


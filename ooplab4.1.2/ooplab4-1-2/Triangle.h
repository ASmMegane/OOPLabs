#pragma once
#include "CShape.h"


class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint & point1, const CPoint & point2, const CPoint & point3);

	void SetFirstPositionPoint(int x, int y);
	void SetFirstPositionPoint(const CPoint & point);

	const CPoint GetFirstPositionPoint() const;

	void SetSecondPositionPoint(int x, int y);
	void SetSecondPositionPoint(const CPoint & point);

	const CPoint GetSecondPositionPoint() const;

	void SetThirdPositionPoint(int x, int y);
	void SetThirdPositionPoint(const CPoint & point);

	const CPoint GetThirdPositionPoint() const;

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	CPoint m_point1;
	CPoint m_point2;
	CPoint m_point3;
};

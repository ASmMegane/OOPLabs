#pragma once
#include "CShape.h"


class CTriangle : public CSolideShape
{
public:
	CTriangle(const CPoint & point1, const CPoint & point2, const CPoint & point3);

	void SetPositionPoint1(int x, int y);
	void SetPositionPoint1(CPoint point);
	const CPoint GetPositionPoint1() const;

	void SetPositionPoint2(int x, int y);
	void SetPositionPoint2(CPoint point);
	const CPoint GetPositionPoint2() const;

	void SetPositionPoint3(int x, int y);
	void SetPositionPoint3(CPoint point);
	const CPoint GetPositionPoint3() const;

	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;

	virtual std::string GetShapeType() const override;
	virtual std::string GetStringRepresentation() const override;

private:
	CPoint m_point1;
	CPoint m_point2;
	CPoint m_point3;
};

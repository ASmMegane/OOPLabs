#pragma once
#include "CShape.h"


class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint & point1, const CPoint & point2, const CPoint & point3);

	void SetPositionPoint1(int x, int y);
	void SetPositionPoint1(const CPoint & point);

	const CPoint GetPositionPoint1() const;

	void SetPositionPoint2(int x, int y);
	void SetPositionPoint2(const CPoint & point);

	const CPoint GetPositionPoint2() const;

	void SetPositionPoint3(int x, int y);
	void SetPositionPoint3(const CPoint & point);

	const CPoint GetPositionPoint3() const;

	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	CPoint m_point1;
	CPoint m_point2;
	CPoint m_point3;
};

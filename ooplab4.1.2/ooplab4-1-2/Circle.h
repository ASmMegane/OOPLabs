#pragma once
#include "CShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(const CPoint & centr, float radius);

	void SetPosition(int x, int y);
	void SetPosition(const CPoint & point);

	const CPoint GetPosition() const;

	float GetRadius() const;

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	CPoint m_centerPoint;
	float m_radius;
};

#pragma once
#include "CShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(const CPoint & centr, float rad);

	void SetPosition(int x, int y);
	void SetPosition(const CPoint & point);

	const CPoint GetPosition() const;

	float GetRad() const;

	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	CPoint m_centerPoint;
	float m_radius;
};

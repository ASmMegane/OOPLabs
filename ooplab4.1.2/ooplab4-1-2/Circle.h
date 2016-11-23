#pragma once
#include "IShape.h"

class CCircle : public CSolideShape
{
public:
	CCircle(const CPoint & centr, float rad);

	void SetPosition(int x, int y);
	void SetPosition(CPoint point);
	const CPoint GetPosition() const;

	float GetRad() const;

	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;

	virtual std::string GetShapeType() const override;
	virtual std::string GetStringRepresentation() const override;

private:
	CPoint m_centerPoint;
	float m_radius;
};

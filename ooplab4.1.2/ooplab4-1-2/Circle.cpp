#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(const CPoint & centr, float rad) : m_centerPoint(centr), m_radius(std::max(rad, 0.0f)) {}

void CCircle::SetPosition(int x, int y)
{
	m_centerPoint.SetPosition(x, y);
}

void CCircle::SetPosition(const CPoint & point)
{
	m_centerPoint.SetPosition(point.GetPosition());
}

const CPoint CCircle::GetPosition() const
{
	return m_centerPoint;
}



float CCircle::GetRad() const
{
	return m_radius;
}



float CCircle::GetArea() const
{
	return (float)(M_PI * pow(m_radius, 2));
}

float CCircle::GetPerimetr() const
{
	return (float)(2 * M_PI * m_radius);
}



std::string CCircle::GetShapeType() const
{
	return "Circle";
}

std::string CCircle::AppendCustomProperties() const
{
	std::string stringPositionCentr = " <" + std::to_string(m_centerPoint.GetPosition().x) + ", " + std::to_string(m_centerPoint.GetPosition().y) + ">,";
	return std::string(stringPositionCentr + " R=" + std::to_string(m_radius));
}
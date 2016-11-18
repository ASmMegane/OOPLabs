#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const CPoint & point1, const CPoint & point2) : m_point1(point1), m_point2(point2) {};

const CPoint CLineSegment::GetPointPosition1()
{
	return m_point1;
};

const CPoint CLineSegment::GetPointPosition2()
{
	return m_point2;
};

float CLineSegment::GetArea() const
{
	return 0.0f;
}

float CLineSegment::GetPerimetr() const
{
	return (float)sqrt(pow(m_point1.GetPosition().x - m_point2.GetPosition().x, 2) + pow(m_point1.GetPosition().y - m_point2.GetPosition().y, 2));
}

std::string CLineSegment::GetShapeType() const
{
	return "Line";
}

std::string CLineSegment::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	return std::string(GetShapeType() + stringPositionPoint1 + stringPositionPoint2 + stringAreaAndPerimetr);
}
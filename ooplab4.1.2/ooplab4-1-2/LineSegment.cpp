#include "stdafx.h"
#include "LineSegment.h"

CLineSegment::CLineSegment(const CPoint & point1, const CPoint & point2)
	: m_point1(point1)
	, m_point2(point2)
{};

const CPoint CLineSegment::GetFirstPointPosition()
{
	return m_point1;
};

const CPoint CLineSegment::GetSecondPointPosition()
{
	return m_point2;
};



float CLineSegment::GetArea() const
{
	return 0.0f;
}

float CLineSegment::GetPerimeter() const
{
	return (float)sqrt(pow(m_point1.GetPosition().x - m_point2.GetPosition().x, 2) + pow(m_point1.GetPosition().y - m_point2.GetPosition().y, 2));
}



std::string CLineSegment::GetShapeType() const
{
	return "Line";
}

std::string CLineSegment::AppendCustomProperties() const
{
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	return std::string(stringPositionPoint1 + stringPositionPoint2);
}
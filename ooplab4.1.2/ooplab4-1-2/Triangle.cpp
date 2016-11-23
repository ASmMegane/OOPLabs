#include "stdafx.h"
#include "Triangle.h"
#include "LineSegment.h"

CTriangle::CTriangle(const CPoint & point1, const CPoint & point2, const CPoint & point3) : m_point1(point1), m_point2(point2), m_point3(point3) {}

void CTriangle::SetPositionPoint1(int x, int y)
{
	m_point1.SetPosition(x, y);
}

void CTriangle::SetPositionPoint1(CPoint point)
{
	m_point1.SetPosition(point.GetPosition());
}

void CTriangle::SetPositionPoint2(int x, int y)
{
	m_point2.SetPosition(x, y);
}

void CTriangle::SetPositionPoint2(CPoint point)
{
	m_point2.SetPosition(point.GetPosition());
}

void CTriangle::SetPositionPoint3(int x, int y)
{
	m_point3.SetPosition(x, y);
}

void CTriangle::SetPositionPoint3(CPoint point)
{
	m_point3.SetPosition(point.GetPosition());
}

const CPoint CTriangle::GetPositionPoint1() const
{
	return m_point1;
}

const CPoint CTriangle::GetPositionPoint2() const
{
	return m_point2;
}

const CPoint CTriangle::GetPositionPoint3() const
{
	return m_point3;
}

float CTriangle::GetArea() const
{
	float a = CLineSegment(m_point1, m_point2).GetPerimetr();
	float b = CLineSegment(m_point1, m_point3).GetPerimetr();
	float c = CLineSegment(m_point3, m_point2).GetPerimetr();
	float halfPerimetr = (a + b + c) / 2;
	return sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
};

float CTriangle::GetPerimetr() const
{
	return CLineSegment(m_point1, m_point2).GetPerimetr() + CLineSegment(m_point1, m_point3).GetPerimetr() + CLineSegment(m_point3, m_point2).GetPerimetr();
};

std::string CTriangle::GetShapeType() const
{
	return "Triangle";
}

std::string CTriangle::GetStringRepresentation() const
{
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	std::string stringPositionPoint3 = " <" + std::to_string(m_point3.GetPosition().x) + ", " + std::to_string(m_point3.GetPosition().y) + ">,";
	return std::string(GetShapeType() + stringPositionPoint1 + stringPositionPoint2 + stringPositionPoint3 + CShape::GetStringRepresentation());
}
#include "stdafx.h"
#include "Triangle.h"
#include "LineSegment.h"

CTriangle::CTriangle(const CPoint & point1, const CPoint & point2, const CPoint & point3)
	: m_point1(point1)
	, m_point2(point2)
	, m_point3(point3)
{}

void CTriangle::SetFirstPositionPoint(int x, int y)
{
	m_point1.SetPosition(x, y);
}

void CTriangle::SetFirstPositionPoint(const CPoint & point)
{
	m_point1.SetPosition(point.GetPosition());
}

void CTriangle::SetSecondPositionPoint(int x, int y)
{
	m_point2.SetPosition(x, y);
}

void CTriangle::SetSecondPositionPoint(const CPoint & point)
{
	m_point2.SetPosition(point.GetPosition());
}

void CTriangle::SetThirdPositionPoint(int x, int y)
{
	m_point3.SetPosition(x, y);
}

void CTriangle::SetThirdPositionPoint(const CPoint & point)
{
	m_point3.SetPosition(point.GetPosition());
}

CPoint CTriangle::GetFirstPositionPoint()
{
	return m_point1;
}

CPoint CTriangle::GetSecondPositionPoint()
{
	return m_point2;
}

CPoint CTriangle::GetThirdPositionPoint()
{
	return m_point3;
}

float CTriangle::GetArea() const
{
	float a = CLineSegment(m_point1, m_point2).GetPerimeter();
	float b = CLineSegment(m_point1, m_point3).GetPerimeter();
	float c = CLineSegment(m_point3, m_point2).GetPerimeter();
	float halfPerimeter = (a + b + c) / 2;
	return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
};

float CTriangle::GetPerimeter() const
{
	return CLineSegment(m_point1, m_point2).GetPerimeter() + CLineSegment(m_point1, m_point3).GetPerimeter() + CLineSegment(m_point3, m_point2).GetPerimeter();
};

std::string CTriangle::GetShapeType() const
{
	return "Triangle";
}

std::string CTriangle::AppendCustomProperties() const
{
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	std::string stringPositionPoint3 = " <" + std::to_string(m_point3.GetPosition().x) + ", " + std::to_string(m_point3.GetPosition().y) + ">,";
	return std::string(stringPositionPoint1 + stringPositionPoint2 + stringPositionPoint3);
}
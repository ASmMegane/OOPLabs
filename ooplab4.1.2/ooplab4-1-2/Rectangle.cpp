#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle(const CPoint & leftTopPoint, int w, int h)
	: m_position(leftTopPoint)
	, m_size(std::max(w, 0), std::max(h, 0))
{}

void CRectangle::SetPosition(int x, int y)
{
	m_position.SetPosition(x, y);
}

void CRectangle::SetPosition(const CPoint & point)
{
	m_position.SetPosition(point.GetPosition());
}

void CRectangle::SetSize(int width, int height)
{
	m_size.width = width;
	m_size.height = height;
}

CPoint CRectangle::GetPosition()
{
	return m_position;
}

CRectangle::Size CRectangle::GetSize() const
{
	return m_size;
}

float CRectangle::GetArea() const
{
	return (float)(m_size.width * m_size.height);
}

float CRectangle::GetPerimeter() const
{
	return (float)((m_size.width + m_size.width) * 2);
}

std::string CRectangle::GetShapeType() const
{
	return "Rectangle";
}

std::string CRectangle::AppendCustomProperties() const
{
	std::string stringSize = ", " + std::to_string(m_size.width) + ", " + std::to_string(m_size.height);
	std::string stringPositionPointLTAndSize = " <" + std::to_string(m_position.GetPosition().x) + ", " + std::to_string(m_position.GetPosition().y) + stringSize + ">,";
	return std::string(stringPositionPointLTAndSize);
}

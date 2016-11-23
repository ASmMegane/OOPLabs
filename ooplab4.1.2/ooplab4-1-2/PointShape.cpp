#include "stdafx.h"
#include "PointShape.h"

CPointShape::CPointShape(int x, int y) : m_position(x, y) {}

void CPointShape::SetPosition(int x, int y)
{
	m_position.x = x; m_position.y = y;
}

CPointShape::Position CPointShape::GetPosition() const
{
	return m_position;
}

float CPointShape::GetArea() const
{
	return 0.0f;
}

float CPointShape::GetPerimetr() const
{
	return 0.0f;
}



std::string CPointShape::GetShapeType() const
{
	return "Point";
}

std::string CPointShape::GetStringRepresentation() const
{
	return std::string(GetShapeType() + " <" + std::to_string(GetPosition().x) + ", " + std::to_string(GetPosition().y) + ">, " + CShape::GetStringRepresentation());
}
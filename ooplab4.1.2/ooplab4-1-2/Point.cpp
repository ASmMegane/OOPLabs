#include "stdafx.h"
#include "Point.h"

void CPoint::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void CPoint::SetPosition(const Position & position)
{
	m_position.x = position.x;
	m_position.y = position.y;
}

const CPoint::Position CPoint::GetPosition() const
{
	return m_position;
}
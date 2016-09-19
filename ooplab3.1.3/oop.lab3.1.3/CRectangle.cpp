#include "stdafx.h"
#include "CRectangel.h"
#include <algorithm>

CRectangle::CRectangle(int x, int y, int width, int height)
{
	SetPosition(x, y);
	SetSize(width, height);
}

size_t CRectangle::GetArea() const
{
	return GetSize().height * GetSize().width;
}

size_t CRectangle::GetPerimeter() const
{
	return (GetSize().height + GetSize().width) * 2;
}

const CRectangle::Size & CRectangle::GetSize() const
{
	return m_size;
	
}

void CRectangle::SetSize(const int widthIn, const int heightIn)
{
	m_size.width = std::max(widthIn, 0);
	m_size.height = std::max(heightIn, 0);
}

const CRectangle::Position & CRectangle::GetPosition() const
{
	return m_position;
}

void CRectangle::SetPosition(const int xIn, const int yIn)
{
	m_position.x = xIn;
	m_position.y = yIn;
}

const CRectangle::Position CRectangle::GetPositionRightBottom() const
{
	CRectangle::Position positionRightBot = m_position;
	positionRightBot.x += m_size.width;
	positionRightBot.y += m_size.height;
	return positionRightBot;
}

void CRectangle::SetPositionRightBottom(const int xRIn, const int yBIn)
{
	m_position.x = xRIn - m_size.width;
	m_position.y = yBIn - m_size.height;
}

void CRectangle::Move(const int dx, const int dy)
{
	m_position.x += dx;
	m_position.y += dy;
}

void CRectangle::Scale(const int sx, const int sy)
{
	if (sx >= 0)
	{
		m_size.width *= sx;
	}
	if (sy >= 0)
	{
		m_size.height *= sy;
	}
}

bool CRectangle::Intersect(const CRectangle & other)
{
	if (GetPositionRightBottom().x > other.GetPosition().x && GetPosition().x < other.GetPositionRightBottom().x
		 && GetPositionRightBottom().y > other.GetPosition().y && GetPosition().y < other.GetPositionRightBottom().y)
	{
		CRectangle::Position positionLT;
		positionLT.x = std::max(GetPosition().x, other.GetPosition().x);
		positionLT.y = std::max(GetPosition().y, other.GetPosition().y);

		CRectangle::Position positionRB;
		positionRB.x = std::min(GetPositionRightBottom().x, other.GetPositionRightBottom().x);
		positionRB.y = std::min(GetPositionRightBottom().y, other.GetPositionRightBottom().y);

		SetPosition(positionLT.x, positionLT.y);
		SetSize(positionRB.x - positionLT.x, positionRB.y - positionLT.y);
		return true;		
	}
	SetSize(0, 0);
	return false;
}
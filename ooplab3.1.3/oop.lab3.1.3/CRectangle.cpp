#include "stdafx.h"
#include "CRectangel.h"

unsigned int CRectangle::GetArea() const
{
	return GetSize().height * GetSize().width;
}

unsigned int CRectangle::GetPerimeter() const
{
	return (GetSize().height + GetSize().width) * 2;
}

const CRectangle::Size CRectangle::GetSize() const
{
	return m_size;
	
}

void CRectangle::SetSize(const int width, const int height)
{
	m_size.width = std::max(width, 0);
	m_size.height = std::max(height, 0);
}

const CRectangle::Position CRectangle::GetPositionLeftTop() const
{
	return m_position;
}

void CRectangle::SetPositionLeftTop(const int x, const int y)
{
	m_position.x = x;
	m_position.y = y;
}

const CRectangle::Position CRectangle::GetPositionRightBottom() const
{
	CRectangle::Position positionRightBot = m_position;
	positionRightBot.x += m_size.width;
	positionRightBot.y += m_size.height;
	return positionRightBot;
}

void CRectangle::SetPositionRightBottom(const int x, const int y)
{
	m_size.width = x - GetPositionLeftTop().x;
	m_size.height = y - GetPositionLeftTop().y;
	m_size.width = std::max(m_size.width, 0);
	m_size.height = std::max(m_size.height, 0);
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
	if (GetPositionRightBottom().x > other.GetPositionLeftTop().x && GetPositionLeftTop().x < other.GetPositionRightBottom().x
		 && GetPositionRightBottom().y > other.GetPositionLeftTop().y && GetPositionLeftTop().y < other.GetPositionRightBottom().y)
	{
		CRectangle::Position positionLT;
		positionLT.x = std::max(GetPositionLeftTop().x, other.GetPositionLeftTop().x);
		positionLT.y = std::max(GetPositionLeftTop().y, other.GetPositionLeftTop().y);

		CRectangle::Position positionRB;
		positionRB.x = std::min(GetPositionRightBottom().x, other.GetPositionRightBottom().x);
		positionRB.y = std::min(GetPositionRightBottom().y, other.GetPositionRightBottom().y);

		SetPositionLeftTop(positionLT.x, positionLT.y);
		SetSize(positionRB.x - positionLT.x, positionRB.y - positionLT.y);
		return true;		
	}
	SetSize(0, 0);
	return false;
}

bool CRectangle::ExpectRectangle(CRectangle const& other, int x, int y, int width, int height)
{
	if (other.GetPositionLeftTop().x != x)
		return false;
	if (other.GetPositionLeftTop().y != y)
		return false;
	if (other.GetSize().width != width)
		return false;
	if (other.GetSize().height != height)
		return false;
	return true;
}


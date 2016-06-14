#include "stdafx.h"
#include "CRectangel.h"
#include <algorithm>

CRectangle::CRectangle(const int x, const int y, const size_t width, const size_t height)
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
	return size;
	
}

void CRectangle::SetSize(const int widthIn, const int heightIn)
{
	size.width = std::max(widthIn, 0);
	size.height = std::max(heightIn, 0);
}

const CRectangle::Position & CRectangle::GetPosition() const
{
	return position;
}

void CRectangle::SetPosition(const int xIn, const int yIn)
{
	position.x = xIn;
	position.y = yIn;
}

const CRectangle::Position CRectangle::GetPositionRightBot() const
{
	CRectangle::Position positionRightBot = position;
	positionRightBot.x += size.width;
	positionRightBot.y += size.height;
	return positionRightBot;
}

void CRectangle::SetPositionRightBot(const int xRIn, const int yBIn)
{
	position.x = xRIn - size.width;
	position.y = yBIn - size.height;
}

void CRectangle::Move(const int dx, const int dy)
{
	position.x += dx;
	position.y += dy;
}

void CRectangle::Scale(const int sx, const int sy)
{
	if (sx >= 0)
	{
		size.width *= sx;
	}
	if (sy >= 0)
	{
		size.height *= sy;
	}
}

bool CRectangle::Intersect(const CRectangle & other)
{
	if (GetPositionRightBot().x > other.GetPosition().x && GetPosition().x < other.GetPositionRightBot().x
		 && GetPositionRightBot().y > other.GetPosition().y && GetPosition().y < other.GetPositionRightBot().y)
	{
		CRectangle::Position positionLT;
		positionLT.x = std::max(GetPosition().x, other.GetPosition().x);
		positionLT.y = std::max(GetPosition().y, other.GetPosition().y);

		CRectangle::Position positionRB;
		positionRB.x = std::min(GetPositionRightBot().x, other.GetPositionRightBot().x);
		positionRB.y = std::min(GetPositionRightBot().y, other.GetPositionRightBot().y);

		SetPosition(positionLT.x, positionLT.y);
		SetSize(positionRB.x - positionLT.x, positionRB.y - positionLT.y);
		return true;		
	}

	return false;
}
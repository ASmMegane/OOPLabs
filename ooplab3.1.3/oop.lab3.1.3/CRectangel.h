#pragma once
#include <algorithm>

class CRectangle
{
public:
	struct Position
	{
		Position() {}
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
	struct Size
	{
		Size() {}
		Size(int width, int height) : width(std::max(0, width)), height(std::max(0, height)) {}
		int width;
		int height;
	};
	CRectangle() : m_position(0, 0), m_size(0, 0) {}
	CRectangle(int x, int y, int width, int height) : m_position(x, y), m_size(width, height) {}
	unsigned int GetArea() const;
	unsigned int GetPerimeter() const;

	const Size GetSize() const;
	void SetSize(int width, int height);

	const Position GetPositionLeftTop() const;
	void SetPositionLeftTop(int x, int y);

	const Position GetPositionRightBottom() const;
	void SetPositionRightBottom(int x, int y);

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);

	bool ExpectRectangle(CRectangle const& other, int x, int y, int width, int height);
private:
	Size m_size;
	Position m_position;
};

#pragma once

class CRectangle
{
public:
	struct Position
	{
		int x;
		int y;
	};
	struct Size
	{
		int width;
		int height;
	};
	CRectangle() 
	{
		m_position.x = 0;
		m_position.y = 0;
		m_size.width = 0;
		m_size.height = 0;
	}
	CRectangle(int x, int y, int width, int height);
	unsigned int GetArea() const;
	unsigned int GetPerimeter() const;

	const Size & GetSize() const;
	void SetSize(const int widthIn, const int heightIn);

	const Position & GetPosition() const;
	void SetPosition(const int xIn, const int yIn);

	const Position GetPositionRightBottom() const;
	void SetPositionRightBottom(const int xRIn, const int yBIn);

	void Move(const int dx, const int dy);
	void Scale(const int sx, const int sy);
	bool Intersect(CRectangle const& other);
private:
	Size m_size;
	Position m_position;
};

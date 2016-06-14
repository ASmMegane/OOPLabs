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
		size_t width;
		size_t height;
	};
	CRectangle()
	{
		position.x = 0;
		position.y = 0;
		size.width = 0;
		size.height = 0;
	}
	CRectangle(const int x, const int y, const size_t width, const size_t height);
	size_t GetArea() const;
	size_t GetPerimeter() const;

	const Size & GetSize() const;
	void SetSize(const int widthIn, const int heightIn);

	const Position & GetPosition() const;
	void SetPosition(const int xIn, const int yIn);

	const Position GetPositionRightBot() const;
	void SetPositionRightBot(const int xRIn, const int yBIn);

	void Move(const int dx, const int dy);
	void Scale(const int sx, const int sy);
	bool Intersect(CRectangle const& other);
private:
	Size size;
	Position position;
};

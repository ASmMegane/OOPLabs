#pragma once

class CPoint
{
public:
	struct Position
	{
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};

	CPoint(int x, int y) : m_position(x, y) {}

	void SetPosition(int x, int y);
	void SetPosition(Position position);
	const Position GetPosition() const;

private:
	Position m_position;
};

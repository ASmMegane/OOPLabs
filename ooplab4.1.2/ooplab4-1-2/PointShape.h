#pragma once
#include "CShape.h"

class CPointShape : public CShape
{
public:
	CPointShape(int x, int y);

	void SetPosition(int x, int y);

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;

	virtual std::string GetShapeType() const override;

protected:
	virtual std::string AppendCustomProperties() const override;

private:
	struct Position
	{
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
	Position m_position;

public:
	Position GetPosition() const;
};

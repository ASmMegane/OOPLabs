#pragma once
#include "IShape.h"

class CPointShape : public IShape
{
public:
	CPointShape(int x, int y);
	void SetPosition(int x, int y);
	virtual float GetArea() const override;
	virtual float GetPerimetr() const override;
	virtual std::string GetShapeType() const override;
	virtual std::string GetStringRepresentation() const override;

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

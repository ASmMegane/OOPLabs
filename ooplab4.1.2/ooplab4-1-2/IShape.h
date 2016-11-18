#pragma once
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include "Point.h"

class IShape
{
public:
	virtual ~IShape() {};
	virtual float GetArea() const abstract;
	virtual float GetPerimetr() const abstract;
	virtual std::string GetShapeType() const abstract;
	virtual std::string GetStringRepresentation() const abstract;
	void SetLineColor(std::string const & colorInput);
protected:
	std::string m_shapeLineColor;
};

class ISolidShape : public IShape
{
public:
	void SetShapeColor(std::string const & colorInput);
protected:
	std::string m_shapeColor;
};

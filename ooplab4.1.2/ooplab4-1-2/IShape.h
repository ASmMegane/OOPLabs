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

	virtual float GetArea() const = 0;
	virtual float GetPerimetr() const = 0;

	virtual std::string GetShapeType() const = 0;
	virtual std::string GetStringRepresentation() const = 0;
};



class CShape : public IShape
{
public:
	virtual std::string GetStringRepresentation() const;

	void SetLineColor(std::string const & colorInput);
protected:
	std::string m_shapeLineColor;
};



class CSolideShape : public CShape
{
public:
	void SetShapeColor(std::string const & colorInput);
protected:
	std::string m_shapeColor;
};



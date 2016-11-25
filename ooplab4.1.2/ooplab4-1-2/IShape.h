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



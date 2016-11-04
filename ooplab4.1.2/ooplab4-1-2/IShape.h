#pragma once
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

class IShape
{
protected:
	std::string colorShapeLine;
public:
	virtual float GetArea() const abstract;
	virtual float GetPerimetr() const abstract;
	virtual std::string GetTypeShape() const abstract;
	virtual std::string GetStringRepresentation() const abstract;
	void SetColorLine(std::string const & colorInput);
};

class ISolidShape : public IShape
{
protected:
	std::string colorShape;
public:
	void SetColorShape(std::string const & colorInput);
};

class CPoint : public IShape
{
private:
	struct Position
	{
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
	Position position;
public:
	CPoint(int x, int y) : position(x, y) {}
	void SetPosition(int x, int y);
	Position GetPosition() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetTypeShape() const;
	virtual std::string GetStringRepresentation() const;
};

class CLineSegment : public IShape
{
private:
	CPoint point1;
	CPoint point2;
public:
	CLineSegment(CPoint point1, CPoint point2) : point1(point1), point2(point2) {};
	CPoint GetPointPosition(int numberPoint);
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetTypeShape() const;
	virtual std::string GetStringRepresentation() const;
};

class CRectangle : public ISolidShape
{
private:
	CPoint position;
	struct Size
	{
		Size(int w, int h) : width(w), height(h) {}
		int width;
		int height;
	};
	Size size;
public:
	CRectangle(CPoint LTPoint, int w, int h) : position(LTPoint), size(std::max(w, 0), std::max(h, 0)) {}
	void SetPosition(int x, int y);
	CPoint GetPosition() const;
	void SetSize(int width, int height);
	Size GetSize() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetTypeShape() const;
	virtual std::string GetStringRepresentation() const;
};

class CCircle : public ISolidShape
{
private:
	CPoint centerPoint;
	float radius;
public:
	CCircle(CPoint centr, float rad) : centerPoint(centr), radius(std::max(rad, 0.0f)) {}
	void SetPosition(int x, int y);
	CPoint GetPosition() const;
	float GetRad() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetTypeShape() const;
	virtual std::string GetStringRepresentation() const;
};

class CTriangle : public ISolidShape
{
private:
	CPoint point1;
	CPoint point2;
	CPoint point3;
public:
	CTriangle(CPoint point1, CPoint point2, CPoint point3) : point1(point1), point2(point2), point3(point3) {}
	void SetPositionPoint1(int x, int y);
	CPoint GetPositionPoint1() const;
	void SetPositionPoint2(int x, int y);
	CPoint GetPositionPoint2() const;
	void SetPositionPoint3(int x, int y);
	CPoint GetPositionPoint3() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetTypeShape() const;
	virtual std::string GetStringRepresentation() const;
};
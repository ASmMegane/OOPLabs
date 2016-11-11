#pragma once
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include "Point.h"

class IShape
{
protected:
	std::string m_shapeLineColor;
public:
	virtual ~IShape() = default;
	virtual float GetArea() const abstract;
	virtual float GetPerimetr() const abstract;
	virtual std::string GetShapeType() const abstract;
	virtual std::string GetStringRepresentation() const abstract;
	void SetLineColor(std::string const & colorInput);
};

class ISolidShape : public IShape
{
protected:
	std::string m_shapeColor;
public:
	void SetShapeColor(std::string const & colorInput);
};

class CPointShape : public IShape
{
private:
	struct Position
	{
		Position(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};
	Position m_position;
public:
	CPointShape(int x, int y) : m_position(x, y) {}
	void SetPosition(int x, int y);
	Position GetPosition() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetShapeType() const;
	virtual std::string GetStringRepresentation() const;
};

class CLineSegment : public IShape
{
private:
	CPoint m_point1;
	CPoint m_point2;
public:
	CLineSegment(CPoint point1, CPoint point2) : m_point1(point1), m_point2(point2) {};
	const CPoint GetPointPosition1();
	const CPoint GetPointPosition2();
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetShapeType() const;
	virtual std::string GetStringRepresentation() const;
};

class CRectangle : public ISolidShape
{
private:
	CPoint m_position;
	struct Size
	{
		Size(int w, int h) : width(w), height(h) {}
		int width;
		int height;
	};
	Size m_size;
public:
	CRectangle(CPoint LTPoint, int w, int h) : m_position(LTPoint), m_size(std::max(w, 0), std::max(h, 0)) {}
	void SetPosition(int x, int y);
	void SetPosition(CPoint point);
	const CPoint GetPosition() const;
	void SetSize(int width, int height);
	Size GetSize() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetShapeType() const;
	virtual std::string GetStringRepresentation() const;
};

class CCircle : public ISolidShape
{
private:
	CPoint m_centerPoint;
	float m_radius;
public:
	CCircle(CPoint centr, float rad) : m_centerPoint(centr), m_radius(std::max(rad, 0.0f)) {}
	void SetPosition(int x, int y);
	void SetPosition(CPoint point);
	const CPoint GetPosition() const;
	float GetRad() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetShapeType() const;
	virtual std::string GetStringRepresentation() const;
};

class CTriangle : public ISolidShape
{
private:
	CPoint m_point1;
	CPoint m_point2;
	CPoint m_point3;
public:
	CTriangle(CPoint point1, CPoint point2, CPoint point3) : m_point1(point1), m_point2(point2), m_point3(point3) {}
	void SetPositionPoint1(int x, int y);
	void SetPositionPoint1(CPoint point);
	const CPoint GetPositionPoint1() const;
	void SetPositionPoint2(int x, int y);
	void SetPositionPoint2(CPoint point);
	const CPoint GetPositionPoint2() const;
	void SetPositionPoint3(int x, int y);
	void SetPositionPoint3(CPoint point);
	const CPoint GetPositionPoint3() const;
	virtual float GetArea() const;
	virtual float GetPerimetr() const;
	virtual std::string GetShapeType() const;
	virtual std::string GetStringRepresentation() const;
};
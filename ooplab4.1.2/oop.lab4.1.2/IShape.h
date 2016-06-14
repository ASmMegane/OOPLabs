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
	void SetColorLine(std::string const & colorInput) { colorShapeLine = colorInput; }
};

class ISolidShape : public IShape
{
protected:
	std::string colorShape;
public:
	void SetColorShape(std::string const & colorInput) { colorShape = colorInput; }
};

class CPoint : public IShape
{
private:
	struct Position
	{
		Position(int xIn, int yIn) : x(xIn), y(yIn) {}
		int x;
		int y;
	};
	Position position;
public:
	CPoint(int xIn, int yIn) : position(xIn, yIn) {}
	void SetPosition(int xIn, int yIn) { position.x = xIn; position.x = yIn; }
	Position GetPosition() const { return position; }
	virtual float GetArea() const { return 0.0f; };
	virtual float GetPerimetr() const { return 0.0f; };
	virtual std::string GetTypeShape() const { return "Point"; }
	virtual std::string GetStringRepresentation() const
	{
		std::string stringAreaAndPerimetr = "S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
		return std::string(GetTypeShape() + " <" + std::to_string(GetPosition().x) + ", " + std::to_string(GetPosition().y) + ">, " + stringAreaAndPerimetr);
	}
};

class CLineSegment : public IShape
{
private:
	CPoint point1;
	CPoint point2;
public:
	CLineSegment(CPoint point1, CPoint point2) : point1(point1), point2(point2) {};
	virtual float GetArea() const { return 0.0f; };
	virtual float GetPerimetr() const { return sqrt(pow(point1.GetPosition().x - point2.GetPosition().x, 2) + pow(point1.GetPosition().y - point2.GetPosition().y, 2)); };
	virtual std::string GetTypeShape() const { return "Line"; }
	virtual std::string GetStringRepresentation() const
	{
		std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
		std::string stringPositionPoint1 = " <" + std::to_string(point1.GetPosition().x) + ", " + std::to_string(point1.GetPosition().y) + ">,";
		std::string stringPositionPoint2 = " <" + std::to_string(point2.GetPosition().x) + ", " + std::to_string(point2.GetPosition().y) + ">,";
		return std::string(GetTypeShape() + stringPositionPoint1 + stringPositionPoint2 + stringAreaAndPerimetr);
	}
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
	void SetPosition(int xIn, int yIn) { position.SetPosition(xIn, yIn); }
	CPoint GetPosition() const { return position; }
	void SetSize(int width, int height) { size.width = width; size.height = height; }
	Size GetSize() const { return size; }
	virtual float GetArea() const { return size.width * size.height; };
	virtual float GetPerimetr() const { return (size.width + size.width) * 2; };
	virtual std::string GetTypeShape() const { return "Rectangle"; }
	virtual std::string GetStringRepresentation() const
	{
		std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
		std::string stringSize = ", " + std::to_string(size.width) + ", " + std::to_string(size.height);
		std::string stringPositionPointLTAndSize = " <" + std::to_string(position.GetPosition().x) + ", " + std::to_string(position.GetPosition().y) + stringSize + ">,";
		return std::string(GetTypeShape() + stringPositionPointLTAndSize + stringAreaAndPerimetr);
	}
};

class CCircle : public ISolidShape
{
private:
	CPoint centerPoint;
	float radius;
public:
	CCircle(CPoint centr, float rad) : centerPoint(centr), radius(std::max(rad, 0.0f)) {}
	void SetPosition(int xIn, int yIn) { centerPoint.SetPosition(xIn, yIn); }
	CPoint GetPosition() const { return centerPoint; }
	virtual float GetArea() const { return M_PI * pow(radius, 2); };
	virtual float GetPerimetr() const { return 2 * M_PI * radius; };
	virtual std::string GetTypeShape() const { return "Circle"; }
	virtual std::string GetStringRepresentation() const
	{
		std::string stringAreaAndPerimetr = ", S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
		std::string stringPositionCentr = " <" + std::to_string(centerPoint.GetPosition().x) + ", " + std::to_string(centerPoint.GetPosition().y) + ">,";
		return std::string(GetTypeShape() + stringPositionCentr + " R=" + std::to_string(radius) + stringAreaAndPerimetr);
	}
};

class CTriangle : public ISolidShape
{
private:
	CPoint point1;
	CPoint point2;
	CPoint point3;
public:
	CTriangle(CPoint point1, CPoint point2, CPoint point3) : point1(point1), point2(point2), point3(point3){}
	void SetPositionPoint1(int xIn, int yIn) { point1.SetPosition(xIn, yIn); }
	CPoint GetPositionPoint1() const { return point1; }
	void SetPositionPoint2(int xIn, int yIn) { point2.SetPosition(xIn, yIn); }
	CPoint GetPositionPoint2() const { return point2; }
	void SetPositionPoint3(int xIn, int yIn) { point3.SetPosition(xIn, yIn); }
	CPoint GetPositionPoint3() const { return point3; }
	virtual float GetArea() const
	{
		float a = CLineSegment(point1, point2).GetPerimetr();
		float b = CLineSegment(point1, point3).GetPerimetr();
		float c = CLineSegment(point3, point2).GetPerimetr();
		float halfPerimetr = (a + b + c) / 2;
		return sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
	};
	virtual float GetPerimetr() const 
	{
		return CLineSegment(point1, point2).GetPerimetr() + CLineSegment(point1, point3).GetPerimetr() + CLineSegment(point3, point2).GetPerimetr();		 
	};
	virtual std::string GetTypeShape() const { return "Triangle"; }
	virtual std::string GetStringRepresentation() const
	{
		std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
		std::string stringPositionPoint1 = " <" + std::to_string(point1.GetPosition().x) + ", " + std::to_string(point1.GetPosition().y) + ">,";
		std::string stringPositionPoint2 = " <" + std::to_string(point2.GetPosition().x) + ", " + std::to_string(point2.GetPosition().y) + ">,";
		std::string stringPositionPoint3 = " <" + std::to_string(point3.GetPosition().x) + ", " + std::to_string(point3.GetPosition().y) + ">,";
		return std::string(GetTypeShape() + stringPositionPoint1 + stringPositionPoint2 + stringPositionPoint3 + stringAreaAndPerimetr);
	}
};
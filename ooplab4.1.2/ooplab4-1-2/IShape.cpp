#include "stdafx.h"
#include "IShape.h"

//------------IShape--------------
void IShape::SetColorLine(std::string const & colorInput)
{
	colorShapeLine = colorInput; 
}
//--------------------------------


//---------------ISolidShape-------------
void ISolidShape::SetColorShape(std::string const & colorInput)
{
	colorShape = colorInput; 
}
//---------------------------------------


//--------------CPoint-----------------
void CPoint::SetPosition(int x, int y)
{
	position.x = x; position.y = y; 
}

CPoint::Position CPoint::GetPosition() const 
{
	return position; 
}

float CPoint::GetArea() const
{
	return 0.0f; 
}

float CPoint::GetPerimetr() const 
{
	return 0.0f;
}

std::string CPoint::GetTypeShape() const 
{
	return "Point"; 
}

std::string CPoint::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = "S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	return std::string(GetTypeShape() + " <" + std::to_string(GetPosition().x) + ", " + std::to_string(GetPosition().y) + ">, " + stringAreaAndPerimetr);
}
//-----------------------------------------


//--------------CLineSegment----------------
CPoint CLineSegment::GetPointPosition(int numberPoint)
{
	if (numberPoint == 2)
		return point2;
	else
		
		return point1;
};

float CLineSegment::GetArea() const 
{
	return 0.0f;
}

float CLineSegment::GetPerimetr() const 
{
	return (float)sqrt(pow(point1.GetPosition().x - point2.GetPosition().x, 2) + pow(point1.GetPosition().y - point2.GetPosition().y, 2)); 
}

std::string CLineSegment::GetTypeShape() const
{
	return "Line"; 
}

std::string CLineSegment::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionPoint1 = " <" + std::to_string(point1.GetPosition().x) + ", " + std::to_string(point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(point2.GetPosition().x) + ", " + std::to_string(point2.GetPosition().y) + ">,";
	return std::string(GetTypeShape() + stringPositionPoint1 + stringPositionPoint2 + stringAreaAndPerimetr);
}
//---------------------------------------------


//-----------------CRectangle------------------
void CRectangle::SetPosition(int x, int y) 
{
	position.SetPosition(x, y); 
}

void CRectangle::SetSize(int width, int height) 
{
	size.width = width; size.height = height; 
}

CPoint CRectangle::GetPosition() const 
{
	return position;
}

CRectangle::Size CRectangle::GetSize() const 
{
	return size;
}

float CRectangle::GetArea() const
{
	return (float)(size.width * size.height); 
}

float CRectangle::GetPerimetr() const
{
	return (float)((size.width + size.width) * 2); 
}

std::string CRectangle::GetTypeShape() const 
{
	return "Rectangle"; 
}

std::string CRectangle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringSize = ", " + std::to_string(size.width) + ", " + std::to_string(size.height);
	std::string stringPositionPointLTAndSize = " <" + std::to_string(position.GetPosition().x) + ", " + std::to_string(position.GetPosition().y) + stringSize + ">,";
	return std::string(GetTypeShape() + stringPositionPointLTAndSize + stringAreaAndPerimetr);
}
//---------------------------------------------


//----------------CCircle---------------------
void CCircle::SetPosition(int x, int y)
{
	centerPoint.SetPosition(x, y); 
}

CPoint CCircle::GetPosition() const
{
	return centerPoint; 
}

float CCircle::GetRad() const
{
	return radius; 
}

float CCircle::GetArea() const 
{
	return (float)(M_PI * pow(radius, 2)); 
}

float CCircle::GetPerimetr() const 
{
	return (float)(2 * M_PI * radius); 
}

std::string CCircle::GetTypeShape() const 
{
	return "Circle"; 
}

std::string CCircle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = ", S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionCentr = " <" + std::to_string(centerPoint.GetPosition().x) + ", " + std::to_string(centerPoint.GetPosition().y) + ">,";
	return std::string(GetTypeShape() + stringPositionCentr + " R=" + std::to_string(radius) + stringAreaAndPerimetr);
}
//---------------------------------------------


//-------------------Triangle------------------
void CTriangle::SetPositionPoint1(int x, int y)
{
	point1.SetPosition(x, y); 
}

void CTriangle::SetPositionPoint2(int x, int y) 
{
	point2.SetPosition(x, y); 
}

void CTriangle::SetPositionPoint3(int x, int y) 
{
	point3.SetPosition(x, y); 
}

CPoint CTriangle::GetPositionPoint1() const 
{
	return point1;
}

CPoint CTriangle::GetPositionPoint2() const 
{
	return point2; 
}

CPoint CTriangle::GetPositionPoint3() const 
{
	return point3;
}

float CTriangle::GetArea() const
{
	float a = CLineSegment(point1, point2).GetPerimetr();
	float b = CLineSegment(point1, point3).GetPerimetr();
	float c = CLineSegment(point3, point2).GetPerimetr();
	float halfPerimetr = (a + b + c) / 2;
	return sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
};

float CTriangle::GetPerimetr() const
{
	return CLineSegment(point1, point2).GetPerimetr() + CLineSegment(point1, point3).GetPerimetr() + CLineSegment(point3, point2).GetPerimetr();
};

std::string CTriangle::GetTypeShape() const 
{
	return "Triangle"; 
}

std::string CTriangle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionPoint1 = " <" + std::to_string(point1.GetPosition().x) + ", " + std::to_string(point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(point2.GetPosition().x) + ", " + std::to_string(point2.GetPosition().y) + ">,";
	std::string stringPositionPoint3 = " <" + std::to_string(point3.GetPosition().x) + ", " + std::to_string(point3.GetPosition().y) + ">,";
	return std::string(GetTypeShape() + stringPositionPoint1 + stringPositionPoint2 + stringPositionPoint3 + stringAreaAndPerimetr);
}
//----------------------------------------------


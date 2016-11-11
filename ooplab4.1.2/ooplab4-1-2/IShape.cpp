#include "stdafx.h"
#include "IShape.h"

//------------IShape--------------
void IShape::SetLineColor(std::string const & colorInput)
{
	m_shapeLineColor = colorInput; 
}
//--------------------------------


//---------------ISolidShape-------------
void ISolidShape::SetShapeColor(std::string const & colorInput)
{
	m_shapeColor = colorInput; 
}
//---------------------------------------


//--------------CPoint-----------------
void CPointShape::SetPosition(int x, int y)
{
	m_position.x = x; m_position.y = y; 
}

CPointShape::Position CPointShape::GetPosition() const 
{
	return m_position; 
}

float CPointShape::GetArea() const
{
	return 0.0f; 
}

float CPointShape::GetPerimetr() const 
{
	return 0.0f;
}

std::string CPointShape::GetShapeType() const 
{
	return "Point"; 
}

std::string CPointShape::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = "S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	return std::string(GetShapeType() + " <" + std::to_string(GetPosition().x) + ", " + std::to_string(GetPosition().y) + ">, " + stringAreaAndPerimetr);
}
//-----------------------------------------


//--------------CLineSegment----------------
const CPoint CLineSegment::GetPointPosition1()
{
	return m_point1;
};

const CPoint CLineSegment::GetPointPosition2()
{
	return m_point2;
};

float CLineSegment::GetArea() const 
{
	return 0.0f;
}

float CLineSegment::GetPerimetr() const 
{
	return (float)sqrt(pow(m_point1.GetPosition().x - m_point2.GetPosition().x, 2) + pow(m_point1.GetPosition().y - m_point2.GetPosition().y, 2)); 
}

std::string CLineSegment::GetShapeType() const
{
	return "Line"; 
}

std::string CLineSegment::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	return std::string(GetShapeType() + stringPositionPoint1 + stringPositionPoint2 + stringAreaAndPerimetr);
}
//---------------------------------------------


//-----------------CRectangle------------------
void CRectangle::SetPosition(int x, int y) 
{
	m_position.SetPosition(x, y); 
}

void CRectangle::SetPosition(CPoint point)
{
	m_position.SetPosition(point.GetPosition());
}

void CRectangle::SetSize(int width, int height) 
{
	m_size.width = width; m_size.height = height; 
}

const CPoint CRectangle::GetPosition() const
{
	return m_position;
}

CRectangle::Size CRectangle::GetSize() const 
{
	return m_size;
}

float CRectangle::GetArea() const
{
	return (float)(m_size.width * m_size.height); 
}

float CRectangle::GetPerimetr() const
{
	return (float)((m_size.width + m_size.width) * 2); 
}

std::string CRectangle::GetShapeType() const 
{
	return "Rectangle"; 
}

std::string CRectangle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringSize = ", " + std::to_string(m_size.width) + ", " + std::to_string(m_size.height);
	std::string stringPositionPointLTAndSize = " <" + std::to_string(m_position.GetPosition().x) + ", " + std::to_string(m_position.GetPosition().y) + stringSize + ">,";
	return std::string(GetShapeType() + stringPositionPointLTAndSize + stringAreaAndPerimetr);
}
//---------------------------------------------


//----------------CCircle---------------------
void CCircle::SetPosition(int x, int y)
{
	m_centerPoint.SetPosition(x, y); 
}

void CCircle::SetPosition(CPoint point)
{
	m_centerPoint.SetPosition(point.GetPosition());
}

const CPoint CCircle::GetPosition() const
{
	return m_centerPoint; 
}

float CCircle::GetRad() const
{
	return m_radius; 
}

float CCircle::GetArea() const 
{
	return (float)(M_PI * pow(m_radius, 2)); 
}

float CCircle::GetPerimetr() const 
{
	return (float)(2 * M_PI * m_radius); 
}

std::string CCircle::GetShapeType() const 
{
	return "Circle"; 
}

std::string CCircle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = ", S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionCentr = " <" + std::to_string(m_centerPoint.GetPosition().x) + ", " + std::to_string(m_centerPoint.GetPosition().y) + ">,";
	return std::string(GetShapeType() + stringPositionCentr + " R=" + std::to_string(m_radius) + stringAreaAndPerimetr);
}
//---------------------------------------------


//-------------------Triangle------------------
void CTriangle::SetPositionPoint1(int x, int y)
{
	m_point1.SetPosition(x, y); 
}

void CTriangle::SetPositionPoint1(CPoint point)
{
	m_point1.SetPosition(point.GetPosition());
}

void CTriangle::SetPositionPoint2(int x, int y) 
{
	m_point2.SetPosition(x, y); 
}

void CTriangle::SetPositionPoint2(CPoint point)
{
	m_point2.SetPosition(point.GetPosition());
}

void CTriangle::SetPositionPoint3(int x, int y) 
{
	m_point3.SetPosition(x, y); 
}

void CTriangle::SetPositionPoint3(CPoint point)
{
	m_point3.SetPosition(point.GetPosition());
}

const CPoint CTriangle::GetPositionPoint1() const
{
	return m_point1;
}

const CPoint CTriangle::GetPositionPoint2() const
{
	return m_point2; 
}

const CPoint CTriangle::GetPositionPoint3() const
{
	return m_point3;
}

float CTriangle::GetArea() const
{
	float a = CLineSegment(m_point1, m_point2).GetPerimetr();
	float b = CLineSegment(m_point1, m_point3).GetPerimetr();
	float c = CLineSegment(m_point3, m_point2).GetPerimetr();
	float halfPerimetr = (a + b + c) / 2;
	return sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
};

float CTriangle::GetPerimetr() const
{
	return CLineSegment(m_point1, m_point2).GetPerimetr() + CLineSegment(m_point1, m_point3).GetPerimetr() + CLineSegment(m_point3, m_point2).GetPerimetr();
};

std::string CTriangle::GetShapeType() const 
{
	return "Triangle"; 
}

std::string CTriangle::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	std::string stringPositionPoint1 = " <" + std::to_string(m_point1.GetPosition().x) + ", " + std::to_string(m_point1.GetPosition().y) + ">,";
	std::string stringPositionPoint2 = " <" + std::to_string(m_point2.GetPosition().x) + ", " + std::to_string(m_point2.GetPosition().y) + ">,";
	std::string stringPositionPoint3 = " <" + std::to_string(m_point3.GetPosition().x) + ", " + std::to_string(m_point3.GetPosition().y) + ">,";
	return std::string(GetShapeType() + stringPositionPoint1 + stringPositionPoint2 + stringPositionPoint3 + stringAreaAndPerimetr);
}
//----------------------------------------------


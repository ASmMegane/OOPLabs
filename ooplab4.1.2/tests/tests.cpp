#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../ooplab4-1-2/IShape.h"


BOOST_AUTO_TEST_SUITE(myTests)

BOOST_AUTO_TEST_CASE(testing_CPoint_constructor)
{
	CPoint shape(1, 4);
	BOOST_CHECK(shape.GetPosition().x == 1 && shape.GetPosition().y == 4);
}

BOOST_AUTO_TEST_CASE(testing_CPoint_setPosition_metod)
{
	CPoint shape(1, 4);
	shape.SetPosition(4, 2);
	BOOST_CHECK(shape.GetPosition().x == 4 && shape.GetPosition().y == 2);
}

BOOST_AUTO_TEST_CASE(testing_CPoint_Area_and_Perimetr_metod)
{
	CPoint shape(1, 4);
	BOOST_CHECK(shape.GetArea() == 0);
	BOOST_CHECK(shape.GetPerimetr() == 0);
}

BOOST_AUTO_TEST_CASE(testing_CPoint_type_metod)
{
	CPoint shape(1, 4);
	BOOST_CHECK(shape.GetTypeShape() == "Point");
}

BOOST_AUTO_TEST_CASE(testing_CLine_constructor)
{
	CLineSegment line(CPoint(1, 4), CPoint(2, 6));
	BOOST_CHECK(line.GetPointPosition(1).GetPosition().x == 1);
	BOOST_CHECK(line.GetPointPosition(1).GetPosition().y == 4);
	BOOST_CHECK(line.GetPointPosition(2).GetPosition().x == 2);
	BOOST_CHECK(line.GetPointPosition(2).GetPosition().y == 6);
}

BOOST_AUTO_TEST_CASE(testing_CLine_area_metod)
{
	CLineSegment line(CPoint(1, 4), CPoint(2, 6));
	BOOST_CHECK(line.GetArea() == 0);
}

BOOST_AUTO_TEST_CASE(testing_CLine_Perimetr_metod)
{
	CLineSegment line(CPoint(1, 4), CPoint(1, 6));
	BOOST_CHECK(line.GetPerimetr() == 2);
}

BOOST_AUTO_TEST_CASE(testing_CLine_type_metod)
{
	CLineSegment line(CPoint(1, 4), CPoint(1, 6));
	BOOST_CHECK(line.GetTypeShape() == "Line");
}

BOOST_AUTO_TEST_CASE(testing_CRectangle_type_metod)
{
	CRectangle rect(CPoint(0, 2), 4, 6);
	BOOST_CHECK(rect.GetPosition().GetPosition().x == 0);
	BOOST_CHECK(rect.GetPosition().GetPosition().y == 2);
	BOOST_CHECK(rect.GetSize().width == 4);
	BOOST_CHECK(rect.GetSize().height == 6);
}

BOOST_AUTO_TEST_CASE(testing_CRectangle_perimetr_metod)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	BOOST_CHECK(rect.GetPerimetr() == 16);
}

BOOST_AUTO_TEST_CASE(testing_CRectangle_area_metod)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	BOOST_CHECK(rect.GetArea() == 16);
}

BOOST_AUTO_TEST_CASE(testing_CRect_type_metod)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	BOOST_CHECK(rect.GetTypeShape() == "Rectangle");
}

BOOST_AUTO_TEST_CASE(testing_CRect_set_position_metod)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	rect.SetPosition(2, 3);	
	BOOST_CHECK(rect.GetPosition().GetPosition().x == 2);
	BOOST_CHECK(rect.GetPosition().GetPosition().y == 3);
}

BOOST_AUTO_TEST_CASE(testing_CRect_set_size_metod)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	rect.SetSize(10, 12);
	BOOST_CHECK(rect.GetSize().width == 10);
	BOOST_CHECK(rect.GetSize().height == 12);
}

BOOST_AUTO_TEST_CASE(testing_Circle_constructor)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK(circle.GetRad() == 4);
	BOOST_CHECK(circle.GetPosition().GetPosition().x == 0);
	BOOST_CHECK(circle.GetPosition().GetPosition().y == 1);
}

BOOST_AUTO_TEST_CASE(testing_Circle_type_metod)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK(circle.GetTypeShape() == "Circle");
}

BOOST_AUTO_TEST_CASE(testing_Circle_area_metod)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK((int)circle.GetArea() == 50);
}

BOOST_AUTO_TEST_CASE(testing_Circle_perimetr_metod)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK((int)circle.GetPerimetr() == 25);
}

BOOST_AUTO_TEST_CASE(testing_Circle_set_position_metod)
{
	CCircle circle(CPoint(0, 1), 4);
	circle.SetPosition(3, 5);
	BOOST_CHECK(circle.GetPosition().GetPosition().x == 3);
	BOOST_CHECK(circle.GetPosition().GetPosition().y == 5);
}

BOOST_AUTO_TEST_CASE(testing_CTriangle_constructor)
{
	CTriangle triangle(CPoint(0, 1), CPoint(1, 0), CPoint(1, 1));
	BOOST_CHECK(triangle.GetPositionPoint1().GetPosition().x == 0);
	BOOST_CHECK(triangle.GetPositionPoint1().GetPosition().y == 1);

	BOOST_CHECK(triangle.GetPositionPoint2().GetPosition().x == 1);
	BOOST_CHECK(triangle.GetPositionPoint2().GetPosition().y == 0);

	BOOST_CHECK(triangle.GetPositionPoint3().GetPosition().x == 1);
	BOOST_CHECK(triangle.GetPositionPoint3().GetPosition().y == 1);
}

BOOST_AUTO_TEST_CASE(testing_CTriangle_set_position_metod)
{
	CTriangle triangle(CPoint(0, 1), CPoint(1, 0), CPoint(1, 1));
	triangle.SetPositionPoint1(10, 5);
	BOOST_CHECK(triangle.GetPositionPoint1().GetPosition().x == 10);
	BOOST_CHECK(triangle.GetPositionPoint1().GetPosition().y == 5);
}

BOOST_AUTO_TEST_CASE(testing_CTriangle_area_metod)
{
	CTriangle triangle(CPoint(0, 0), CPoint(4, 0), CPoint(0, 4));
	BOOST_CHECK((int)triangle.GetArea() == 8);
}

BOOST_AUTO_TEST_CASE(testing_CTriangle_perimetr_metod)
{
	CTriangle triangle(CPoint(0, 0), CPoint(6, 0), CPoint(0, 8));
	BOOST_CHECK((int)triangle.GetPerimetr() == 24);
}


BOOST_AUTO_TEST_SUITE_END()

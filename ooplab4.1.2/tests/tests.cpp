#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../ooplab4-1-2/IShape.h"
#include "../ooplab4-1-2/AllShapesHeader.h"


BOOST_AUTO_TEST_SUITE(myTests)

BOOST_AUTO_TEST_SUITE(testing_CPoint)

BOOST_AUTO_TEST_CASE(constructor)
{
	CPointShape shape(1, 4);
	BOOST_CHECK_EQUAL(shape.GetPosition().x, 1);
	BOOST_CHECK_EQUAL(shape.GetPosition().y, 4);
}

BOOST_AUTO_TEST_CASE(setPosition_method_takes_new_position_and_set_shape_in_it)
{
	CPointShape shape(1, 4);
	shape.SetPosition(4, 2);
	BOOST_CHECK_EQUAL(shape.GetPosition().x, 4);
	BOOST_CHECK_EQUAL(shape.GetPosition().y, 2);
}

BOOST_AUTO_TEST_CASE(Area_and_Perimeter_method_return_area_and_perimeter_shape)
{
	CPointShape shape(1, 4);
	BOOST_CHECK_CLOSE(shape.GetArea(), 0.000, 0.001);
	BOOST_CHECK_EQUAL(shape.GetArea(), 0);
	BOOST_CHECK_EQUAL(shape.GetPerimeter(), 0);
}

BOOST_AUTO_TEST_CASE(type_method_return_type_shape)
{
	CPointShape shape(1, 4);
	BOOST_CHECK_EQUAL(shape.GetShapeType(), "Point");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testing_CLine)

BOOST_AUTO_TEST_CASE(constructor)
{
	CLineSegment line(CPoint(1, 4), CPoint(2, 6));
	BOOST_CHECK_EQUAL(line.GetFirstPointPosition().GetPosition().x, 1);
	BOOST_CHECK_EQUAL(line.GetFirstPointPosition().GetPosition().y, 4);
	BOOST_CHECK_EQUAL(line.GetSecondPointPosition().GetPosition().x, 2);
	BOOST_CHECK_EQUAL(line.GetSecondPointPosition().GetPosition().y, 6);
}

BOOST_AUTO_TEST_CASE(Area_method_return_area_shape)
{
	CLineSegment line(CPoint(1, 4), CPoint(2, 6));
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
}

BOOST_AUTO_TEST_CASE(Perimeter_method_return_perimeter_shape)
{
	CLineSegment line(CPoint(1, 4), CPoint(1, 6));
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 2);
}

BOOST_AUTO_TEST_CASE(Type_method_return_type_shape)
{
	CLineSegment line(CPoint(1, 4), CPoint(1, 6));
	BOOST_CHECK_EQUAL(line.GetShapeType(), "Line");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testing_CRectangle)

BOOST_AUTO_TEST_CASE(Constructor)
{
	CRectangle rect(CPoint(0, 2), 4, 6);
	BOOST_CHECK_EQUAL(rect.GetPosition().GetPosition().x, 0);
	BOOST_CHECK_EQUAL(rect.GetPosition().GetPosition().y, 2);
	BOOST_CHECK_EQUAL(rect.GetSize().width, 4);
	BOOST_CHECK_EQUAL(rect.GetSize().height, 6);
}

BOOST_AUTO_TEST_CASE(Perimeter_method_return_perimeter_shape)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	const float correctPerimeter = 4.0 * 4.0;
	BOOST_CHECK_CLOSE(rect.GetPerimeter(), correctPerimeter, 0.0001);
}

BOOST_AUTO_TEST_CASE(Area_method_return_area_shape)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	const float correctArea = 4.0 * 4.0;
	BOOST_CHECK_CLOSE(rect.GetArea(), correctArea, 0.0001);
}

BOOST_AUTO_TEST_CASE(Type_method_return_type_shape)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	BOOST_CHECK_EQUAL(rect.GetShapeType(), "Rectangle");
}

BOOST_AUTO_TEST_CASE(Set_position_method_takes_new_position_and_set_shape_in_it)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	rect.SetPosition(2, 3);
	BOOST_CHECK_EQUAL(rect.GetPosition().GetPosition().x, 2);
	BOOST_CHECK_EQUAL(rect.GetPosition().GetPosition().y, 3);
}

BOOST_AUTO_TEST_CASE(Set_size_method_takes_new_size_for_rect_and_set_it)
{
	CRectangle rect(CPoint(0, 0), 4, 4);
	rect.SetSize(10, 12);
	BOOST_CHECK_EQUAL(rect.GetSize().width, 10);
	BOOST_CHECK_EQUAL(rect.GetSize().height, 12);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testing_Circle)

BOOST_AUTO_TEST_CASE(Constructor)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK_EQUAL(circle.GetRadius(), 4);
	BOOST_CHECK_EQUAL(circle.GetPosition().GetPosition().x, 0);
	BOOST_CHECK_EQUAL(circle.GetPosition().GetPosition().y, 1);
}

BOOST_AUTO_TEST_CASE(Type_method_return_type_shape)
{
	CCircle circle(CPoint(0, 1), 4);
	BOOST_CHECK_EQUAL(circle.GetShapeType(), "Circle");
}

BOOST_AUTO_TEST_CASE(Area_method_return_area_shape)
{
	CCircle circle(CPoint(0, 1), 4);
	const double correctArea = M_PI * pow(4, 2);
	BOOST_CHECK_CLOSE(circle.GetArea(), correctArea, 0.001);
}

BOOST_AUTO_TEST_CASE(Perimeter_method_return_perimeter_shape)
{
	CCircle circle(CPoint(0, 1), 4);
	const double correctPerimeter = 2 * M_PI * 4;
	BOOST_CHECK_CLOSE(circle.GetPerimeter(), correctPerimeter, 0.001);
}

BOOST_AUTO_TEST_CASE(Set_position_method_takes_new_position_and_set_shape_in_it)
{
	CCircle circle(CPoint(0, 1), 4);
	circle.SetPosition(3, 5);
	BOOST_CHECK_EQUAL(circle.GetPosition().GetPosition().x, 3);
	BOOST_CHECK_EQUAL(circle.GetPosition().GetPosition().y, 5);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testing_CTriangle)

BOOST_AUTO_TEST_CASE(Constructor)
{
	CTriangle triangle(CPoint(0, 1), CPoint(1, 0), CPoint(1, 1));
	BOOST_CHECK_EQUAL(triangle.GetFirstPositionPoint().GetPosition().x, 0);
	BOOST_CHECK_EQUAL(triangle.GetFirstPositionPoint().GetPosition().y, 1);
}

BOOST_AUTO_TEST_CASE(Set_position_method_takes_new_position_and_set_shape_in_it)
{
	CTriangle triangle(CPoint(0, 1), CPoint(1, 0), CPoint(1, 1));
	triangle.SetFirstPositionPoint(10, 5);
	BOOST_CHECK_EQUAL(triangle.GetFirstPositionPoint().GetPosition().x, 10);
	BOOST_CHECK_EQUAL(triangle.GetFirstPositionPoint().GetPosition().y, 5);
}

BOOST_AUTO_TEST_CASE(Area_method_return_area_shape)
{
	CTriangle triangle(CPoint(0, 0), CPoint(1, 0), CPoint(0, 1));
	const double correctArea = sqrt(1.707 * pow(0.707, 2) * (1.707 - 1.414));
	BOOST_CHECK_CLOSE(triangle.GetArea(), correctArea, 0.001);
}

BOOST_AUTO_TEST_CASE(Perimeter_method_return_perimeter_shape)
{
	CTriangle triangle(CPoint(0, 0), CPoint(1, 0), CPoint(0, 1));
	const double correctPerimeter = 2 + sqrt(2);
	BOOST_CHECK_CLOSE(triangle.GetPerimeter(), correctPerimeter, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
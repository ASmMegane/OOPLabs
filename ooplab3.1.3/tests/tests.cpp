#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../oop.lab3.1.3/CRectangel.h"


BOOST_AUTO_TEST_SUITE(myTests)

BOOST_AUTO_TEST_CASE(testing_empty_constructor)
{
	CRectangle rectangle;
	BOOST_CHECK(rectangle.GetSize().width == 0 && rectangle.GetSize().height == 0);
	BOOST_CHECK(rectangle.GetPosition().x == 0 && rectangle.GetPosition().y == 0);
}

BOOST_AUTO_TEST_CASE(testing_constructor)
{
	CRectangle rectangle(1, 2, 25, 30);
	BOOST_CHECK(rectangle.GetSize().width == 25 && rectangle.GetSize().height == 30);
	BOOST_CHECK(rectangle.GetPosition().x == 1 && rectangle.GetPosition().y == 2);
}

BOOST_AUTO_TEST_CASE(testing_constructor_with_negative_data)
{
	CRectangle rectangle(-1, -2, -25, -30);
	BOOST_CHECK(rectangle.GetSize().width == 0 && rectangle.GetSize().height == 0);
	BOOST_CHECK(rectangle.GetPosition().x == -1 && rectangle.GetPosition().y == -2);
}

BOOST_AUTO_TEST_CASE(testing_metod_Set_Position)
{
	CRectangle rectangle(1, 2, 25, 30);
	rectangle.SetPosition(20, -20);
	BOOST_CHECK(rectangle.GetPosition().x == 20 && rectangle.GetPosition().y == -20);
}

BOOST_AUTO_TEST_CASE(testing_metod_Set_Size)
{
	CRectangle rectangle(1, 2, 25, 30);
	rectangle.SetSize(20, 20);
	BOOST_CHECK(rectangle.GetSize().width == 20 && rectangle.GetSize().height == 20);
}

BOOST_AUTO_TEST_CASE(testing_metod_Set_Size_with_negativ_data)
{
	CRectangle rectangle(1, 2, 25, 30);
	rectangle.SetSize(-20, 20);
	BOOST_CHECK(rectangle.GetSize().width == 0 && rectangle.GetSize().height == 20);
}

BOOST_AUTO_TEST_CASE(testing_metod_Set_Position_Right_Bottom)
{
	CRectangle rectangle(20, 20, 25, 30);
	rectangle.SetPositionRightBottom(-20, -20);
	BOOST_CHECK(rectangle.GetPosition().x == -45 && rectangle.GetPosition().y == -50);
}

BOOST_AUTO_TEST_CASE(testing_metod_Move)
{
	CRectangle rectangle(20, 20, 25, 30);
	rectangle.Move(-20, -20);
	BOOST_CHECK(rectangle.GetPosition().x == 0 && rectangle.GetPosition().y == 0);
	BOOST_CHECK(rectangle.GetSize().width == 25 && rectangle.GetSize().height == 30);
}

BOOST_AUTO_TEST_CASE(testing_metod_Scale)
{
	CRectangle rectangle(20, 20, 50, 100);
	rectangle.Scale(2, 1);
	BOOST_CHECK(rectangle.GetPosition().x == 20 && rectangle.GetPosition().y == 20);
	BOOST_CHECK(rectangle.GetSize().width == 100 && rectangle.GetSize().height == 100);
}

BOOST_AUTO_TEST_CASE(testing_metod_Scale_with_nagativ_data)
{
	CRectangle rectangle(20, 20, 50, 100);
	rectangle.Scale(-2, -1);
	BOOST_CHECK(rectangle.GetPosition().x == 20 && rectangle.GetPosition().y == 20);
	BOOST_CHECK(rectangle.GetSize().width == 50 && rectangle.GetSize().height == 100);
}

BOOST_AUTO_TEST_CASE(testing_metod_Intersect_when_ractangle_intersected)
{
	CRectangle rectangle(20, 20, 50, 100);
	CRectangle rectangleOther(21, 21, 26, 51);
	BOOST_CHECK(rectangle.Intersect(rectangleOther));
	BOOST_CHECK(rectangle.GetPosition().x == 21 && rectangle.GetPosition().y == 21);
	BOOST_CHECK(rectangle.GetSize().width == 26 && rectangle.GetSize().height == 51);
}

BOOST_AUTO_TEST_CASE(testing_metod_Intersect_when_ractangle_not_intersected)
{
	CRectangle rectangle(20, 20, 50, 100);
	CRectangle rectangleOther(2, 1, 5, 4);
	BOOST_CHECK(!rectangle.Intersect(rectangleOther));
	BOOST_CHECK(rectangle.GetPosition().x == 20 && rectangle.GetPosition().y == 20);
	BOOST_CHECK(rectangle.GetSize().width == 0 && rectangle.GetSize().height == 0);
}

BOOST_AUTO_TEST_SUITE_END()


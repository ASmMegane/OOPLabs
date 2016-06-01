#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>
#include "../oop.lab7.1.3/Function.h"

BOOST_AUTO_TEST_SUITE(myTests)

BOOST_AUTO_TEST_CASE(Sportsman_max_weight)
{
	struct Sportsman
	{
		std::string FIO;
		int	growth;
		int	weight;
	};
	std::vector<Sportsman> atlets = { { "popov", 180, 90 },{ "petrov", 178, 95 },{ "ivanov", 176, 74 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.weight < secondMan.weight; });
	BOOST_CHECK_EQUAL(maxValue.weight, 95);
}

BOOST_AUTO_TEST_CASE(Sportsman_max_growth)
{
	struct Sportsman
	{
		std::string FIO;
		int	growth;
		int	weight;
	};
	std::vector<Sportsman> atlets = { { "popov", 180, 90 },{ "petrov", 178, 95 },{ "ivanov", 176, 74 } };
	Sportsman maxValue;
	FindMaxEx(atlets, maxValue, [](const Sportsman & firstMan, const Sportsman & secondMan) { return firstMan.growth < secondMan.growth; });
	BOOST_CHECK_EQUAL(maxValue.growth, 180);
}

typedef boost::mpl::list<int, float> testTypes;

BOOST_AUTO_TEST_CASE_TEMPLATE(Test1, T, testTypes)
{
	std::vector<T> arr = { T(1), T(5), T(7), T(8), T(9), T(3) };
	T maxValue;
	FindMaxEx(arr, maxValue, [](const T & a, const T & b) { return a < b; });
	BOOST_CHECK_EQUAL(maxValue, T(9));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(Test2, T, testTypes)
{
	std::vector<T> arr;
	T maxValue = T(-1);
	FindMaxEx(arr, maxValue, [](const T & a, const T & b) { return a < b; });
	BOOST_CHECK_EQUAL(maxValue, T(-1));
}

BOOST_AUTO_TEST_SUITE_END()


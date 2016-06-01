#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../oop.lab2.2.3/Functions.h"


BOOST_AUTO_TEST_SUITE(myTests)

	BOOST_AUTO_TEST_CASE(testing_recursion_in_str) 
	{
		std::string str = "mama";
		std::string newStr;
		newStr = ReplaceStr(str, "ma", "mama");
		BOOST_CHECK(newStr == "mamamama");		
	}
	
	BOOST_AUTO_TEST_CASE(testing_empty_str) 
	{
		std::string str = "";
		std::string newStr;
		newStr = ReplaceStr(str, "ma", "mama");
		BOOST_CHECK(newStr == "");
	}

	BOOST_AUTO_TEST_CASE(testing_str)
	{
		std::string str = "privet";
		std::string newStr;
		newStr = ReplaceStr(str, "t", "tevirp");
		BOOST_CHECK(newStr == "privetevirp");
	}

BOOST_AUTO_TEST_SUITE_END()



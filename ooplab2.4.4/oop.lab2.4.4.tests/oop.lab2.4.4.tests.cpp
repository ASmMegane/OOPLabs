#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../oop.lab2.4.4/Functions.h"


BOOST_AUTO_TEST_SUITE(myTests)

	BOOST_AUTO_TEST_CASE(Test1) 
	{
		std::vector<bool> vec = {false, false, true, true, false, true};
		BOOST_CHECK(vec == MarkAllPrimeNumbers(5));
	}

	BOOST_AUTO_TEST_CASE(Test2) 
	{
		BOOST_CHECK_THROW(MarkAllPrimeNumbers(-1), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(Test3) 
	{
		std::set<size_t> primeNumberSet = {2, 3, 5, 7, 11};
		BOOST_CHECK(GeneratePrimeNumbersSet(12) == primeNumberSet);
	}

	BOOST_AUTO_TEST_CASE(Test4) 
	{
		BOOST_CHECK_THROW(MarkAllPrimeNumbers(1000000000), std::out_of_range);
	}

BOOST_AUTO_TEST_SUITE_END()

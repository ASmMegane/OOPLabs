#include "stdafx.h"

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(EverythingIsOk) {
	BOOST_CHECK_EQUAL(2 * 2, 3);
}


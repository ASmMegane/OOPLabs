#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../oop.lab.6.1.7/CHttpUrl.h"



BOOST_AUTO_TEST_SUITE(myTests);

BOOST_AUTO_TEST_CASE(correct_url_constructor)
{
	CHttpUrl parser("http://google.com:343/a.txt");
	BOOST_CHECK_EQUAL(parser.GetURL(), "http://google.com:343/a.txt");
	BOOST_CHECK_EQUAL(parser.GetDocument(), "/a.txt");
	BOOST_CHECK_EQUAL(parser.GetDomain(), "google.com");
	BOOST_CHECK_EQUAL(parser.GetPort(), 343);
	BOOST_CHECK_EQUAL(parser.GetProtocol(), HTTP);
}

BOOST_AUTO_TEST_CASE(empty_document)
{
	CHttpUrl parser("http://google.com:343");
	BOOST_CHECK_EQUAL(parser.GetURL(), "http://google.com:343/");
	BOOST_CHECK_EQUAL(parser.GetDocument(), "/");
	BOOST_CHECK_EQUAL(parser.GetDomain(), "google.com");
	BOOST_CHECK_EQUAL(parser.GetPort(), 343);
	BOOST_CHECK_EQUAL(parser.GetProtocol(), HTTP);
}

BOOST_AUTO_TEST_CASE(incorrect_protocol)
{
	BOOST_REQUIRE_THROW(CHttpUrl("httpt://google.com/a.txt"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(incorrect_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:343t/a.txt"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(incorrect_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("http://goo gle.com:343t/a.txt"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(correct_url)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl("http://google.com:343/a.txt"));
}

BOOST_AUTO_TEST_CASE(correct_url_second_constructor)
{
	CHttpUrl parser("google.com", "/a.txt", HTTP, 343);
	BOOST_CHECK_EQUAL(parser.GetURL(), "http://google.com:343/a.txt");
	BOOST_CHECK_EQUAL(parser.GetDocument(), "/a.txt");
	BOOST_CHECK_EQUAL(parser.GetDomain(), "google.com");
	BOOST_CHECK_EQUAL(parser.GetPort(), 343);
	BOOST_CHECK_EQUAL(parser.GetProtocol(), HTTP);
}

BOOST_AUTO_TEST_CASE(incorrect_url_second_constructor)
{
	BOOST_REQUIRE_THROW(CHttpUrl("goo gle.com", "/a.txt", HTTP, 343), CUrlParsingError);
}
BOOST_AUTO_TEST_SUITE_END();
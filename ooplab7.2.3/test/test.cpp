#include "stdafx.h"
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#include "../oop.lab7.2.3/MyList.h"

BOOST_AUTO_TEST_SUITE(myTests)

BOOST_AUTO_TEST_CASE(testing_empty_list)
{	
	CMyList<int> myList;
	BOOST_CHECK(myList.GetSize() == 0);
}

BOOST_AUTO_TEST_CASE(testing_pushEnd_and_pushFront)
{
	CMyList<int> myList;
	myList.PushFront(4);
	myList.PushBack(2);
	BOOST_CHECK(myList.GetSize() == 2);
}

BOOST_AUTO_TEST_CASE(testing_push_value)
{
	CMyList<int> myList;
	myList.PushFront(4);
	BOOST_CHECK(myList.begin()->value == 4);
}

BOOST_AUTO_TEST_CASE(testing_move_for_iterator)
{
	CMyList<int> myList;
	myList.PushFront(4);
	myList.PushFront(4);
	myList.PushFront(4);
	myList.PushFront(4);
	int k = 0;
	for (auto node : myList)
	{
		k++;
	}
	BOOST_CHECK(k == 4);
}

BOOST_AUTO_TEST_CASE(testing_move_for_iterator_with_value)
{
	CMyList<int> myList;
	myList.PushFront(4);
	myList.PushFront(4);
	myList.PushFront(4);
	myList.PushFront(4);
	int k = 0;
	for (auto node : myList)
	{
		k += node;
	}
	BOOST_CHECK(k == 16);
}

BOOST_AUTO_TEST_CASE(testing_insert)
{
	CMyList<int> myList;
	myList.PushFront(4);
	CMyList<int>::iterator itrMyList = myList.begin();
	myList.insert(itrMyList, 2);
	BOOST_CHECK(myList.GetSize() == 2);
}

BOOST_AUTO_TEST_CASE(testing_insert_value)
{
	CMyList<int> myList;
	myList.PushFront(4);
	CMyList<int>::iterator itrMyList = myList.begin();
	myList.insert(itrMyList, 2);
	BOOST_CHECK(myList.begin()->value == 2);
}

BOOST_AUTO_TEST_CASE(testing_erase)
{
	CMyList<int> myList;
	myList.PushFront(4);
	CMyList<int>::iterator itrMyList = myList.begin();
	myList.erase(itrMyList);
	BOOST_CHECK(myList.GetSize() == 0);
}

BOOST_AUTO_TEST_CASE(testing_assign)
{
	CMyList<int> myList;
	myList.PushFront(4);
	CMyList<int> myList2 = myList;
	BOOST_CHECK(myList2.GetSize() == 1);
}

BOOST_AUTO_TEST_CASE(testing_copy)
{
	CMyList<int> myList;
	myList.PushFront(4);
	CMyList<int> myList2(myList);
	BOOST_CHECK(myList2.GetSize() == 1 && myList.GetSize() == 1);
}

BOOST_AUTO_TEST_CASE(testing_operator_plusplus_iterator)
{
	CMyList<int> myList;
	myList.PushFront(4);
	myList.PushFront(2);
	CMyList<int>::iterator itrMyList = myList.begin();
	++itrMyList;
	BOOST_CHECK(itrMyList->value == 4);
}

BOOST_AUTO_TEST_CASE(testing_revers_operator_plusplus_iterator)
{
	CMyList<int> myList;
	myList.PushFront(4);
	myList.PushFront(2);
	CMyList<int>::iterator itrMyList = myList.rbegin();
	++itrMyList;
	BOOST_CHECK(itrMyList->value == 2);
}


BOOST_AUTO_TEST_SUITE_END()



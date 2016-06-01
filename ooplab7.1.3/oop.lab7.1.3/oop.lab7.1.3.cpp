#include "stdafx.h"
#include "Function.h"

int main()
{
	std::vector<int> intArr = { 1, 2, 4, 6, 3, 7, 3, 9, -1 };
	int maxValue;
	FindMax(intArr, maxValue);
	std::cout << maxValue << std::endl;
	return 0;
}


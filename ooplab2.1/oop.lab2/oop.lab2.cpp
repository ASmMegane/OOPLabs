#include "stdafx.h"
#include "functions.h"

int main()
{
	std::vector<double> arrayNums(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	std::cout << "New array:" << std::endl;
	OutputArray(arrayNums, SumThreeMinNumbers(arrayNums));
	std::cout << std::endl;
    return 0;
}


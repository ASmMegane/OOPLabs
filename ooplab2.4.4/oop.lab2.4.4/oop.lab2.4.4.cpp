#include "stdafx.h"
#include "Functions.h"


int main(int argc, char * argv[])
{
	if (argc != 2)
		return 0;
	size_t number = std::atoi(argv[1]);
	std::set<size_t> setOfPrimeNumber;
	setOfPrimeNumber = GeneratePrimeNumbersSet(number);
	std::cout << setOfPrimeNumber.size() << std::endl;
	/*for (auto num : setOfPrimeNumber)
	{
		std::cout << num.size() << " " << std::endl;
	}*/
    return 0;
}

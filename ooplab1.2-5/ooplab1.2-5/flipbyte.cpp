#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <locale>

void Invers(unsigned num) 
{
	unsigned numEnd = 0;
	for (int i = 0; i < 8; i++) 
	{
		numEnd = numEnd | (num & 1);
		num = num >> 1;
		if (i != 7)
			numEnd = numEnd << 1;
	}
	std::cout << numEnd << std::endl;
}


int main(int argc, char * argv[])
{
	bool isNum = false;
	if (argc != 2)
	{
		std::cout << "Error." << std::endl;
		std::cout << "Usage: flipbyte.exe <input byte>" << std::endl;
		return 1;
	}
	if (std::strcmp(argv[1], "0"))
		isNum = true;
	int number = std::atoi(argv[1]);
	if (isNum && number == 0)
	{
		std::cout << "Error. It isn't number." << std::endl;
		return 1;
	}
	else if (!(number < 256 && number >= 0)) 
	{
		std::cout << "Error. Your number isn't in range [0:255]" << std::endl;
		return 1;
	}
	else 
	{
		Invers(unsigned(number));
	}
	return 0;
}


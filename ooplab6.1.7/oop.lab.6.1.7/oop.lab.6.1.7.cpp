#include "stdafx.h"


#include "stdafx.h"
#include "CHttpUrl.h"

int main()
{
	std::string str;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "Enter url: ";
		std::getline(std::cin, str);
		if (!std::cin.fail())
		{
			CHttpUrl parser(str);
		}
	}
	return 0;
}


#include "stdafx.h"
#include "functions.h"

double SumThreeMinNumbers(const std::vector<double> & arrNums)
{
	double sumThreeMinNum = 0;
	std::vector<double> threeMinNumber;
	for (int i = 0; i < arrNums.size(); i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (threeMinNumber.size() == k)
			{
				threeMinNumber.insert(threeMinNumber.begin() + k, arrNums[i]);
				break;
			}
			else if (arrNums[i] < threeMinNumber[k])
			{
				threeMinNumber.insert(threeMinNumber.begin() + k, arrNums[i]);
				if (threeMinNumber.size() > 3)
				{
					threeMinNumber.resize(3);
				}
				break;
			}
		}
	}
	for (auto element : threeMinNumber)
	{
		sumThreeMinNum += element;
	}
	return sumThreeMinNum;
}


void OutputArray(std::vector<double> & arrNums, double sumThreeMinNum)
{
	double elementArray;
	for (auto element : arrNums)
	{
		elementArray = element + sumThreeMinNum;
		std::cout << elementArray << ' ';
	}
}

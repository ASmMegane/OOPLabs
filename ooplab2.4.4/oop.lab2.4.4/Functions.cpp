#include "stdafx.h"
#include "Functions.h"
#include <stdint.h>

std::vector<bool> MarkAllPrimeNumbers(size_t upNumber) {
	int minNum = 2;
	int maxNum = 100000000;
	if (!(upNumber >= minNum && upNumber <= maxNum))
		throw std::out_of_range("Number must be in range(2, 10^8)");
	std::vector<bool> numbersRow(upNumber + 1, true);
	numbersRow[0] = numbersRow[1] = false;
	for (size_t i = 2; i <= upNumber; i++) {
		if (numbersRow[i]) {
			if (uint64_t(i) * i <= upNumber) {
				for (size_t j = i * i; j <= upNumber; j += i) {
					numbersRow[j] = false;
				}
			}
		}
	}
	return numbersRow;
}


std::set<size_t> GeneratePrimeNumbersSet(size_t upNumber) {
	std::vector<bool> primeNumbersVector = MarkAllPrimeNumbers(upNumber);
	std::set<size_t> primeNumberSet;
	for (size_t k = 0; k <= upNumber; k++) {
		if (primeNumbersVector[k]) {
			primeNumberSet.insert(k);
		}
	}
	return primeNumberSet;
}
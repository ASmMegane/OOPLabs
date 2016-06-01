#include "stdafx.h"
#include "Functions.h"


std::string ReplaceStr(const std::string & str, const std::string & oldWord, const std::string & newWord) {
	std::string newString;
	newString = str;
	size_t idx = newString.find(oldWord);
	while (idx != std::string::npos) {
		newString.replace(idx, oldWord.length(), newWord);
		idx = newString.find(oldWord, idx + newWord.length());
	}
	return newString;
}

void InputString(const std::string & searchStr, const std::string & replaceStr) {
	std::string subjectStr;
	std::cin >> subjectStr;
	while (subjectStr != "End.") {
		std::cout << ReplaceStr(subjectStr, searchStr, replaceStr) << std::endl;
		std::cin >> subjectStr;
	}
}

#include "stdafx.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <io.h>
#include <algorithm>
#include <sys/stat.h>

void ReplaceStr(std::string & str, const std::string & oldWord, const std::string & newWord) {
	int idx = str.find(oldWord);
	while (idx != std::string::npos) {
		str.replace(idx, oldWord.length(), newWord);
		idx = str.find(oldWord, idx + newWord.length());
	}
}

void ReadFilesAndReplace(const std::string & inputFileName, const std::string & outputFileName, const std::string & oldStr, const std::string & newStr) {
	std::string str;
	std::ifstream inFile(inputFileName);
	std::ofstream outFile(outputFileName);
	while (std::getline(inFile, str)) {
		ReplaceStr(str, oldStr, newStr);
		outFile << str << std::endl;
	}
	inFile.close();
	outFile.close();
};

bool CheckFileExpansion(const std::string & input, const std::string & output) {
	if (input.substr(input.find_last_of(".") + 1) == "txt" && output.substr(output.find_last_of(".") + 1) == "txt")
		return true;
	else
		return false;
}

int main(int argc, char * argv[])
{
	if (argc > 5) {
		std::cout << "Error. Toomany arguments" << std::endl;
		std::cout << "Example: replace.exe <InputFile> <OutputFile> <ToFind> <ToReplace>" << std::endl;
		return 0;
	}
	else if (argc < 4) {
		std::cout << "Error! Not enough arguments." << std::endl;
		std::cout << "Example: replace.exe <InputFile> <OutputFile> <ToFind> <ToReplace>" << std::endl;
		return 0;
	}
	else if (_access(argv[1], 0)) {
		std::cout << "Error. File not found." << std::endl;
		return 0;
	}
	else if (!CheckFileExpansion(argv[1], argv[2]))
		return 0;
	else { 
		ReadFilesAndReplace(argv[1], argv[2], argv[3], argv[4]);
	}
	return 0;
}


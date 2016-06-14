#include "stdafx.h"
#include "CRectangel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void ReadRectangle(const std::string & inFileRectangle, CRectangle & rectangle)
{
	std::ifstream inputFile(inFileRectangle);
	std::string command;
	inputFile >> command;
	while (!inputFile.eof())
	{
		if (command == "Rectangle")
		{
			int x, y;
			size_t width, height;
			inputFile >> x >> y >> width >> height;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			rectangle.SetPosition(x, y);
			rectangle.SetSize(width, height);
		}
		else if (command == "Move")
		{
			int x, y;
			inputFile >> x >> y;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			rectangle.Move(x, y);
		}
		else if (command == "Scale")
		{
			int x, y;
			inputFile >> x >> y;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			rectangle.Scale(x, y);
		}
		inputFile >> command;
	}
}

void OutputRectangle(const CRectangle & rectangle, std::string rectangleName)
{
	std::cout << rectangleName << std::endl;
	std::cout << "  Left top: (" << rectangle.GetPosition().x << "," << rectangle.GetPosition().y << ")" << std::endl;
	std::cout << "  Size: (" << rectangle.GetSize().width << "," << rectangle.GetSize().height << ")" << std::endl;
	std::cout << "  Right bottom: (" << rectangle.GetPositionRightBot().x << "," << rectangle.GetPositionRightBot().y << ")" << std::endl;
	std::cout << "  Area: (" << rectangle.GetArea() << ")" << std::endl;
	std::cout << "  Perimeter: (" << rectangle.GetPerimeter() << ")" << std::endl;
}

void Rectangles(const std::string & inFileRectangle1, const std::string & inFileRectangle2)
{
	CRectangle rectangle1;
	CRectangle rectangle2;
	try
	{
		ReadRectangle(inFileRectangle1, rectangle1);
		ReadRectangle(inFileRectangle2, rectangle2);
	}
	catch (...)
	{
		std::cout << "Incorrect files." << std::endl;
		return;
	}
	OutputRectangle(rectangle1, "Rectangle1:");
	OutputRectangle(rectangle2, "Rectangle2:");
	rectangle1.Intersect(rectangle2);
	OutputRectangle(rectangle1, "Intersect rectangle:");
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	Rectangles(argv[1], argv[2]);
    return 0;
}


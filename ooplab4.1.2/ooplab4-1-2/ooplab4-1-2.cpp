#include "stdafx.h"
#include "IShape.h"
#include "PointShape.h"
#include "AllShapesHeader.h"
#include <vector>
#include <fstream>
#include <memory>


void ReadShapes(const std::string & inFile, std::vector<std::shared_ptr<IShape>> & shapesVector)
{
	std::ifstream inputFile(inFile);
	std::string type;
	inputFile >> type;
	while (!inputFile.eof())
	{
		if (type == "Point")
		{
			int x, y;
			std::string color;
			inputFile >> x >> y >> color;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			std::shared_ptr<CPointShape> pointPtr(new CPointShape(x, y));
			pointPtr->SetLineColor(color);
			shapesVector.push_back(pointPtr);
		}
		else if (type == "Line")
		{
			int x1, y1, x2, y2;
			std::string color;
			inputFile >> x1 >> y1 >> x2 >> y2 >> color;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			std::shared_ptr<CLineSegment> linePtr(new CLineSegment(CPoint(x1, y1), CPoint(x2, y2)));
			linePtr->SetLineColor(color);
			shapesVector.push_back(linePtr);
		}
		else if (type == "Circle")
		{
			int x, y;
			float radius;
			std::string color;
			std::string colorShape;
			inputFile >> x >> y >> radius >> color >> colorShape;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			std::shared_ptr<CCircle> circlePtr(new CCircle(CPoint(x, y), radius));
			circlePtr->SetLineColor(color);
			circlePtr->SetShapeColor(colorShape);
			shapesVector.push_back(circlePtr);
		}
		else if (type == "Rectangle")
		{
			int x, y, width, height;
			std::string color;
			std::string colorShape;
			inputFile >> x >> y >> width >> height >> color >> colorShape;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			std::shared_ptr<CRectangle> circlePtr(new CRectangle(CPoint(x, y), width, height));
			circlePtr->SetLineColor(color);
			circlePtr->SetShapeColor(colorShape);
			shapesVector.push_back(circlePtr);
		}
		else if (type == "Triangle")
		{
			int x1, y1, x2, y2, x3, y3;
			std::string color;
			std::string colorShape;
			inputFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> color >> colorShape;
			if (inputFile.fail())
			{
				throw std::invalid_argument("");
			}
			std::shared_ptr<CTriangle> circlePtr(new CTriangle(CPoint(x1, y1), CPoint(x2, y2), CPoint(x3, y3)));
			circlePtr->SetLineColor(color);
			circlePtr->SetShapeColor(colorShape);
			shapesVector.push_back(circlePtr);
		}
		inputFile >> type;
	}
}

void OutputShapesData(std::vector<std::shared_ptr<IShape>> & shapesVector)
{
	for (auto shapePtr : shapesVector)
	{
		std::cout << shapePtr->GetStringRepresentation() << std::endl;
	}
}

void SortShapesData(std::vector<std::shared_ptr<IShape>> & shapesVector)
{
	std::sort(shapesVector.begin(), shapesVector.end(),
		[](std::shared_ptr<IShape> shape1Ptr, std::shared_ptr<IShape> shape2Ptr)
	{
		return shape1Ptr->GetArea() < shape2Ptr->GetArea();
	});
	std::cout << std::endl << "Area:" << std::endl << std::endl;
	OutputShapesData(shapesVector);

	std::sort(shapesVector.begin(), shapesVector.end(),
		[](std::shared_ptr<IShape> shape1Ptr, std::shared_ptr<IShape> shape2Ptr)
	{
		return shape1Ptr->GetPerimetr() > shape2Ptr->GetPerimetr();
	});
	std::cout << std::endl << "Perimetr:" << std::endl << std::endl;
	OutputShapesData(shapesVector);
}

void ShapesReader(const std::string & inFile)
{
	std::vector<std::shared_ptr<IShape>> shapesVector;
	try
	{
		ReadShapes(inFile, shapesVector);
	}
	catch (...)
	{
		std::cout << "Incorrect files." << std::endl;
		return;
	}
	SortShapesData(shapesVector);

}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	ShapesReader(argv[1]);
	return 0;
}


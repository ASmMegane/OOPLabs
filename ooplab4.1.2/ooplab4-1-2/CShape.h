#pragma once
#include "IShape.h"


class CShape : public IShape
{
public:
	virtual std::string GetStringRepresentation() const;

	void SetLineColor(std::string const & colorInput);
protected:
	std::string m_shapeLineColor;
};



class CSolideShape : public CShape
{
public:
	void SetShapeColor(std::string const & colorInput);
protected:
	std::string m_shapeColor;
};

#pragma once
#include "IShape.h"


class CShape : public IShape
{
public:
	virtual std::string GetStringRepresentation() const override;

	void SetLineColor(std::string const & colorInput);
protected:
	virtual std::string AppendCustomProperties() const = 0;

	std::string m_shapeLineColor;
};



class CSolidShape : public CShape
{
public:
	void SetShapeColor(std::string const & colorInput);
protected:
	std::string m_shapeColor;
};

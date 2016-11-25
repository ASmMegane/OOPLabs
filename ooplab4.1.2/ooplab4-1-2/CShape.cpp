#include "stdafx.h"
#include "CShape.h"


//-------------CShape--------------------------
void CShape::SetLineColor(std::string const & colorInput)
{
	m_shapeLineColor = colorInput;
}


std::string CShape::GetStringRepresentation() const
{
	std::string stringAreaAndPerimetr = " S = " + std::to_string(GetArea()) + ", P = " + std::to_string(GetPerimetr());
	return stringAreaAndPerimetr;
}
//--------------------------------


//---------------ISolidShape-------------
void CSolideShape::SetShapeColor(std::string const & colorInput)
{
	m_shapeColor = colorInput;
}
//---------------------------------------

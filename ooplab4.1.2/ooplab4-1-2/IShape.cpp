#include "stdafx.h"
#include "IShape.h"
#include "LineSegment.h"

//------------IShape--------------
void IShape::SetLineColor(std::string const & colorInput)
{
	m_shapeLineColor = colorInput; 
}
//--------------------------------


//---------------ISolidShape-------------
void ISolidShape::SetShapeColor(std::string const & colorInput)
{
	m_shapeColor = colorInput; 
}
//---------------------------------------


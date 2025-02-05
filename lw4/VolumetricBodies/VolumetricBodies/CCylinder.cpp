#include "CCylinder.h"

CCylinder::CCylinder(double baseRadius, double height, double density)
	: CSolidBody(density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * m_height;
}

std::string CCylinder::GetType() const
{
	return TYPE_CYLINDER;
}


void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << APPEND_CYLINDER_RADIUS << GetBaseRadius() << std::endl
		 << APPEND_CYLINDER_HEIGHT << GetHeight() << std::endl;
}
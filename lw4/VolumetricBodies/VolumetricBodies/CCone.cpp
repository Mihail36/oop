#include "CCone.h"

CCone::CCone(double baseRadius, double height, double density)
	: CSolidBody(density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return M_PI * pow(m_baseRadius, 2) * (m_height / 3);
}

std::string CCone::GetType() const
{
	return TYPE_CONE;
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << APPEND_CONE_RADIUS << GetBaseRadius() << std::endl
		 << APPEND_CONE_HEIGHT << GetHeight() << std::endl;
}
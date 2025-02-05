#include "CSphere.h"

CSphere::CSphere(double radius, double density)
	: CSolidBody(density)
	, m_radius(radius)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4 / 3) * (M_PI * pow(m_radius, 3));
}

std::string CSphere::GetType() const
{
	return TYPE_SPHERE;
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	strm << APPEND_SPHERE_RADIUS << GetRadius() << std::endl;
}
#include "CBody.h"

CBody::CBody()
{
}

CBody::~CBody()
{
}

std::string CBody::ToString() const
{
	std::ostringstream strm;
	strm << GetType() << std::endl << std::setprecision(PRECISION)
		 << BODY_DENSITY << GetDensity() << std::endl
		 << BODY_VOLUME << GetVolume() << std::endl
		 << BODY_MASS << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}
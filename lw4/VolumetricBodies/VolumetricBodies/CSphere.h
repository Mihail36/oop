#pragma once
#include "CSolidBody.h"

class CSphere final : public CSolidBody
{
public:
	CSphere(double radius, double density);

	double GetRadius() const;
	double GetVolume() const override;
	std::string GetType() const override;
private:
	void AppendProperties(std::ostream & strm) const override;
	double m_radius;
};


#pragma once
#include "CSolidBody.h"

class CCone final : public CSolidBody
{
public:
	CCone(double baseRadius, double height, double density);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetType() const override;
private:
	void AppendProperties(std::ostream & strm) const override;
	double m_baseRadius;
	double m_height;
};


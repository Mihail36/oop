#pragma once
#include "CSolidBody.h"

class CParallelepiped final : public CSolidBody
{
public:
	CParallelepiped(double width, double depth, double height, double density);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;
	std::string GetType() const override;
private:
	void AppendProperties(std::ostream & strm) const override;
	double m_width;
	double m_height;
	double m_depth;
};


#pragma once
//Паттерн composite(компоновщик)
#include "CBody.h"

class CCompound : public CBody
{
public:
	CCompound();

	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	std::string GetType() const override;

	void AddChild(std::shared_ptr<CBody> body);

private:
	void AppendProperties(std::ostream& strm) const override;

	std::vector<std::shared_ptr<CBody>> m_children;
};

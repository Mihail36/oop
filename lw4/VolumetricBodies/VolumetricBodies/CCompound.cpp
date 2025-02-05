#include "CCompound.h"

CCompound::CCompound()
{
}

double CCompound::GetDensity() const
{
	if (m_children.empty())
	{
		throw std::logic_error(ERROR_EMPTY_COMPOUND);
	}

	double totalMass = 0;
	double totalVolume = 0;

	for (const auto& child : m_children)
	{
		totalMass += child->GetMass();
		totalVolume += child->GetVolume();
	}

	return totalMass / totalVolume;
}

double CCompound::GetVolume() const
{
	double totalVolume = 0;

	for (const auto& child : m_children)
	{
		totalVolume += child->GetVolume();
	}

	return totalVolume;
}

double CCompound::GetMass() const
{
	double totalMass = 0;

	for (const auto& child : m_children)
	{
		totalMass += child->GetMass();
	}

	return totalMass;
}

std::string CCompound::GetType() const
{
	return TYPE_COMPOUND;
}

void CCompound::AddChild(std::shared_ptr<CBody> body)
{
	auto it = std::find(m_children.begin(), m_children.end(), body);

	if (it != m_children.end())
	{
		throw std::logic_error(ERROR_ALREADY_PART_OF_COMPOUND);
	}

	m_children.push_back(body);
}

void CCompound::AppendProperties(std::ostream& strm) const
{
	strm << DIVIDER_STRING;
	strm << std::endl << NUMBER_OF_CHILD << m_children.size() << std::endl << std::endl;

	for (const auto& child : m_children)
	{
		strm << child->ToString() << std::endl;
	}
}
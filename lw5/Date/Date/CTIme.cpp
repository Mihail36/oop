#include "CTime.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours >= HOURS_IN_DAY || minutes >= MINUTES_IN_HOUR || seconds >= SECONDS_IN_MINUTE)
	{
		throw std::invalid_argument(ERROR_TIME_NOT_CORRECT);
	}
	else
	{
		m_timeStamp = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
	}
}

CTime::CTime(unsigned timeStamp)
	: m_timeStamp(timeStamp)
{
	if (timeStamp > MAX_SECONDS_IN_DAY)
	{
		throw std::invalid_argument(ERROR_TIME_NOT_CORRECT);
	}
}

unsigned CTime::GetHours() const
{
	return m_timeStamp / SECONDS_IN_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return (m_timeStamp / SECONDS_IN_MINUTE) % MINUTES_IN_HOUR;
}

unsigned CTime::GetSeconds() const
{
	return m_timeStamp % SECONDS_IN_MINUTE;
}

CTime CTime::operator++()
{
	++m_timeStamp;
	if (m_timeStamp > MAX_SECONDS_IN_DAY)
	{
		m_timeStamp = 0;
	}
	return *this;
}

CTime CTime::operator++(int)
{
	CTime thisTime = *this;
	++(*this);
	return thisTime;
}

CTime CTime::operator--()
{
	if (m_timeStamp == 0)
	{
		m_timeStamp = MAX_SECONDS_IN_DAY;
	}
	else
	{
		--m_timeStamp;
	}
	return *this;
}

CTime CTime::operator--(int)
{
	CTime thisTime = *this;
	--(*this);
	return thisTime;
}

CTime CTime::operator+(const CTime& newTime) const
{
	unsigned sumTime = m_timeStamp + newTime.m_timeStamp;
	return CTime(sumTime % SECONDS_IN_DAY);
}

CTime CTime::operator-(const CTime& newTime) const
{
	int divTime = m_timeStamp - newTime.m_timeStamp;
	if (divTime < 0)
	{
		divTime += SECONDS_IN_DAY;
	}
	return CTime(divTime);
}

CTime& CTime::operator+=(const CTime& newTime)
{
	m_timeStamp += newTime.m_timeStamp;
	if (m_timeStamp > MAX_SECONDS_IN_DAY)
	{
		m_timeStamp %= SECONDS_IN_DAY;
	}
	return *this;
}

CTime& CTime::operator-=(const CTime& newTime)
{
	if (m_timeStamp >= newTime.m_timeStamp)
	{
		m_timeStamp -= newTime.m_timeStamp;
	}
	else
	{
		m_timeStamp = SECONDS_IN_DAY - (newTime.m_timeStamp - m_timeStamp);
	}
	return *this;
}

CTime CTime::operator*(int multiplier) const
{
	unsigned mulTime = m_timeStamp * multiplier;
	return CTime(mulTime % SECONDS_IN_DAY);
}

CTime operator*(int multiplier, const CTime& time)
{
	return time * multiplier;
}

int CTime::operator/(const CTime& newTime) const
{
	if (newTime.m_timeStamp == 0)
	{
		throw std::invalid_argument(ERROR_TIME_ZERO);
	}
	return m_timeStamp / newTime.m_timeStamp;
}

CTime& CTime::operator*=(int multiplier)
{
	m_timeStamp *= multiplier;
	if (m_timeStamp > MAX_SECONDS_IN_DAY)
	{
		m_timeStamp %= SECONDS_IN_DAY;
	}
	return *this;
}

CTime& CTime::operator/=(int multiplier)
{
	if (multiplier == 0)
	{
		throw std::invalid_argument(ERROR_TIME_ZERO);
	}
	m_timeStamp /= multiplier;
	return *this;
}

std::ostream& operator<<(std::ostream& output, const CTime& time)
{
	output << std::setfill('0') << std::setw(2) << time.GetHours() << SEPARATOR
		<< std::setw(2) << time.GetMinutes() << SEPARATOR
		<< std::setw(2) << time.GetSeconds();
	return output;
}

std::istream& operator>>(std::istream& input, CTime& time)
{
	unsigned hours, minutes, seconds;
	char separator;
	input >> hours >> separator >> minutes >> separator >> seconds;
	time = CTime(hours, minutes, seconds);
	return input;
}

bool CTime::operator==(const CTime& newTime) const
{
	return m_timeStamp == newTime.m_timeStamp;
}

bool CTime::operator!=(const CTime& newTime) const
{
	return m_timeStamp != newTime.m_timeStamp;
}

bool CTime::operator<(const CTime& newTime) const
{
	return m_timeStamp < newTime.m_timeStamp;
}

bool CTime::operator>(const CTime& newTime) const
{
	return m_timeStamp > newTime.m_timeStamp;
}

bool CTime::operator<=(const CTime& newTime) const
{
	return m_timeStamp <= newTime.m_timeStamp;
}

bool CTime::operator>=(const CTime& newTime) const
{
	return m_timeStamp >= newTime.m_timeStamp;
}
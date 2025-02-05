#pragma once
#include <iostream>
#include <iomanip>

class CTime
{
public:
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	CTime(unsigned timeStamp = 0);
	unsigned GetHours()const;
	unsigned GetMinutes()const;
	unsigned GetSeconds()const;

	CTime operator++();
	CTime operator++(int);
	CTime operator--();
	CTime operator--(int);
	CTime operator+(const CTime& newTime)const;
	CTime operator-(const CTime& newTime)const;
	CTime& operator+=(const CTime& newTime);
	CTime& operator-=(const CTime& newTime);
	CTime operator*(int multiplier)const;
	friend CTime operator*(int multiplier, const CTime& time);
	int operator/(const CTime& newTime)const;
	CTime& operator*=(int multiplier);
	CTime& operator/=(int multiplier);

	friend std::ostream& operator<<(std::ostream& output, const CTime& time);
	friend std::istream& operator>>(std::istream& input, CTime& time);

	bool operator==(const CTime& newTime)const;
	bool operator!=(const CTime& newTime)const;
	bool operator<(const CTime& newTime)const;
	bool operator>(const CTime& newTime)const;
	bool operator<=(const CTime& newTime)const;
	bool operator>=(const CTime& newTime)const;
private:
	unsigned m_timeStamp = 0;
};


const int HOURS_IN_DAY = 24;
const int MINUTES_IN_HOUR = 60;
const int SECONDS_IN_MINUTE = 60;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_DAY = 86400;
const int MAX_SECONDS_IN_DAY = 86399;

const char SEPARATOR = ':';

const std::string ERROR_TIME_NOT_CORRECT = "the time is not correct";
const std::string ERROR_TIME_ZERO = "time cannot be 0";
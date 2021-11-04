/*********************************************************
 * Name: Jay Ashishbhai Patel
 * Student ID: 154925192
 * Seneca email: japatel31@myseneca.ca
 * Section: OOP 244 NGG
 * Project : Milestone 1
 *
 * I have done all the coding by myself and only copied the code
 *  that my professor provided to complete my workshops and assignments.
 **********************************************************/

#include "Time.h"
#include "utils.h"
#include <iostream>

using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = sdds::getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	ostream& Time::write(ostream& ostr) const
	{
		int minutes = 0, hours = 0;
		hours = m_min / 60;
		minutes = m_min % 60;

		if (hours < 10) 
		{
			ostr.fill('0');
			ostr.width(2);
			ostr << hours << ":";
		}
		else 
		{
			ostr << hours << ":";
		}
		
		ostr.fill('0');
		ostr.width(2);
		ostr << minutes;
		return ostr;
	}

	istream& Time::read(istream& istr)
	{
		int hours = 0;
		int minuts = 0;
		char coloun = '\0';

		istr >> hours;
		if (hours > 0)
		{
			m_min = hours * 60;
		}
		else
		{
			istr.setstate(ios::failbit);
		}
		
		istr.get(coloun);
		if (coloun != ':')
		{
			istr.setstate(ios::failbit);
		}

		istr >> minuts;
		if (minuts > 0)
		{
			m_min += minuts;
		}
		else
		{
			istr.setstate(ios::failbit);
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		while (m_min < D.m_min) 
		{
			m_min += 1440;
		}
		m_min -= D.m_min;
		
		return *this;
	}

	Time Time::operator-(const Time& D)const 
	{
		Time time;
		unsigned int newMin = m_min;

		while (newMin < D.m_min) 
		{
			newMin += 1440;
		}
		time.m_min = newMin - D.m_min;
		
		return time;
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D)const 
	{
		return Time(m_min + D.m_min);
	}

	Time& Time::operator=(unsigned int val) 
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const 
	{
		return Time(m_min * val);
	}

	Time Time::operator /(unsigned int val)const
	{
		return Time(m_min / val);
	}

	Time::operator unsigned int()const 
	{
		return m_min;
	}

	Time::operator int()const
	{
		return (int)m_min;
	}

	ostream& operator<<(ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}

	istream& operator>>(istream& istr, Time& D) 
	{
		return D.read(istr);
	}
}
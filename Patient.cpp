#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include "IOAble.h"
#include "Ticket.h"
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	
	Patient::Patient(int ticket_number, bool flag) : m_ticket(ticket_number)
	{
		m_flag = flag;
		m_insNumber = 0;
		m_patientName = nullptr;
	}

	Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}
	
	bool Patient::fileIO() const
	{
		return m_flag;
	}
	
	void Patient::fileIO(bool flag)
	{
		m_flag = flag;
	}
	
	bool Patient::operator==(const char patientType) const 
	{
		bool valid = false;
		if (type() == patientType)
		{
			valid = true;
		}
		return valid;
	}
	
	bool Patient::operator==(const Patient& p) const 
	{
		bool valid = false;
		if (type() == p.type())
		{
			valid = true;
		}

		return valid;
	}
	
	void Patient::setArrivalTime() 
	{
		m_ticket.resetTime();
	}
	
	Patient::operator Time() const 
	{
		return Time(m_ticket);
	}
	
	int Patient::number() const 
	{
		return m_ticket.number();
	}
	
	ostream& Patient::csvWrite(std::ostream& os) const
	{
		os << type() << ",";
		os << m_patientName << ",";
		os << m_insNumber << ",";
		m_ticket.csvWrite(os);
		return os;
	}
	
	istream& Patient::csvRead(istream& istring)
	{
		char temp[100];
		delete[] m_patientName;
		m_patientName = nullptr;
		istring.getline(temp, 501, ',');
		
		if (strlen(temp))
		{
			m_patientName = new char[strlen(temp) + 1];
			strcpy(m_patientName, temp);
			istring >> m_insNumber;
			istring.ignore(1000, ',');
			m_ticket.csvRead(istring);
		}
		return istring;
	}
	
	ostream& Patient::write(ostream& os) const 
	{
		os << m_ticket << std::endl;
		for (int j = 0; j < 25 && m_patientName[j]; j++)
		{
			os << m_patientName[j];
		}
		
		os << ", OHIP: " << m_insNumber;
		return os;
	}
	
	istream& Patient::read(istream& is) 
	{
		m_patientName = getcstr("Name: ", is, '\n');
		m_insNumber = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return is;
	}
}

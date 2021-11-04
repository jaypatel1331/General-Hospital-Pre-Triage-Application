/*********************************************************
 * Name: Jay Ashishbhai Patel
 * Student ID: 154925192
 * Seneca email: japatel31@myseneca.ca
 * Section: OOP 244 NGG
 * Project : Milestone 2
 *
 * I have done all the coding by myself and only copied the code
 *  that my professor provided to complete my workshops and assignments.
 **********************************************************/

#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;

namespace sdds {
	ostream& operator<<(ostream& ostr, const IOAble& able)
	{
		return able.write(ostr);
	}
	
	istream& operator>>(istream& istr, IOAble& able) 
	{
		return able.read(istr);
	}
}
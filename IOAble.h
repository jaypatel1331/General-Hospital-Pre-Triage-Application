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

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& os) const = 0;
		virtual istream& csvRead(istream& is) = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble() {};
	};
	ostream& operator<<(ostream& ostr, const IOAble& able);
	istream& operator>>(istream& istr, IOAble& able);
}

#endif
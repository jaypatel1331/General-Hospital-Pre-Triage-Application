/*********************************************************
 * Name: Jay Ashishbhai Patel
 * Student ID: 154925192
 * Seneca email: japatel31@myseneca.ca
 * Section: OOP 244 NGG
 * Project : Milestone 4
 *
 * I have done all the coding by myself and only copied the code
 *  that my professor provided to complete my workshops and assignments.
 **********************************************************/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
#include "Ticket.h"
using namespace std;

namespace sdds {
	class CovidPatient : public Patient {
	public:
		CovidPatient();
		char type() const;
		istream& csvRead(istream& is);
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};

}
#endif // !SDDS_COVIDPATIENT_H_




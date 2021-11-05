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




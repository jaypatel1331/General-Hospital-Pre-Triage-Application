#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"

using namespace std;
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symChar;
	public:
		TriagePatient();
		~TriagePatient();
		char type() const;
		ostream& csvWrite(ostream& os) const;
		istream& csvRead(istream& is);
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};
}
#endif // !SDDS_TRIAGEPATIENT_H



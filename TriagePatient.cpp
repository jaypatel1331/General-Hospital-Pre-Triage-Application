#include <iostream>
#include "TriagePatient.h"
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
	   m_symChar = nullptr;
	   nextTriageTicket++;
   }

   char TriagePatient::type() const
   {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& os) const
   {
	   Patient::csvWrite(os);
	   return os << "," << m_symChar;
   }

   istream& TriagePatient::csvRead(istream& is)
   {
	   delete[] m_symChar;
	   Patient::csvRead(is);
	   is.ignore(1000, ',');
	   m_symChar = getcstr(nullptr, is);
	   nextTriageTicket = Patient::number() + 1;
	   return is;
   }

   ostream& TriagePatient::write(ostream& os) const 
   {
	   if (Patient::fileIO())
	   {
		   csvWrite(os);
	   }
	   else
	   {
		   os << "TRIAGE" << endl;
		   // os << "TRIAGE\n"; 
		   Patient::write(os);
		   os << endl;
		   os << "Symptoms: " << m_symChar << endl;
	   }
	   return os;
   }

   istream& TriagePatient::read(istream& is)
   {
	   if (Patient::fileIO())
	   {
		   csvRead(is);
	   }
	   else 
	   {
		   delete[] m_symChar;
		   Patient::read(is);
		   m_symChar = getcstr("Symptoms: ", is);
	   }
	   return is;
   }

   TriagePatient::~TriagePatient() 
   {
	   delete[] m_symChar;
	   m_symChar = nullptr;
   }
}

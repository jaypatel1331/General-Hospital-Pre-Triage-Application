#include <iostream>
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const
   {
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& is) 
   {
	   Patient::csvRead(is);
	   nextCovidTicket = Patient::number() + 1;
	   is.ignore(2000, '\n');
	   return is;
   }

   ostream& CovidPatient::write(ostream& os) const 
   {
	   if (Patient::fileIO())
	   {
		   Patient::csvWrite(os);
	   }
	   else {
		   os << "COVID TEST" << std::endl;
		   Patient::write(os);
		   os << std::endl;
	   }
	   return os;
   }

   istream& CovidPatient::read(istream& is) 
   {
	   if (Patient::fileIO())
	   {
		   csvRead(is);
	   }
	   else
	   {
		   Patient::read(is);
	   }
	   return is;
   }
}

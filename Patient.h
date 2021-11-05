#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"
using namespace std;
namespace sdds {
	class Patient : public IOAble {
		char* m_patientName;
		int m_insNumber;
		Ticket m_ticket;
		bool m_flag;
	public:
		Patient(int ticket_number = 0, bool flag = false);
		Patient(const Patient& p) = delete;
		Patient& operator=(const Patient& p) = delete;
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool flag);
		bool operator==(const char) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		ostream& csvWrite(ostream& os) const;
		istream& csvRead(istream& is);
		ostream& write(ostream& os) const;
		istream& read(istream& is);
	};
}

#endif // !SDDS_PATIENT_H

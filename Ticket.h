/*********************************************************
 * Name: Jay Ashishbhai Patel
 * Student ID: 154925192
 * Seneca email: japatel31@myseneca.ca
 * Section: OOP 244 NGG
 * Project : Milestone 3
 *
 * I have done all the coding by myself and only copied the code
 *  that my professor provided to complete my workshops and assignments.
 **********************************************************/

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
using namespace std;
namespace sdds {
    class Ticket :public IOAble {
        Time m_time;
        int m_number;
    public:
        Ticket(int number);
        operator Time()const;
        int number()const;
        void resetTime();
        ostream& csvWrite(ostream& ostr)const;
        istream& csvRead(istream& istr);
        ostream& write(ostream& ostr)const;
        istream& read(istream& istr);
    };
}
#endif // !SDDS_TICKET_H_


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

#include "Ticket.h"
using namespace std;

namespace sdds {
    Ticket::Ticket(int number) 
    {
        m_number = number;
    }
    
    Ticket::operator Time() const 
    {
        return m_time;
    }
    
    int Ticket::number() const 
    {
        return m_number;
    }
    
    void Ticket::resetTime() 
    {
        m_time.setToNow();
    }
    
    ostream& Ticket::csvWrite(ostream& ostr) const 
    {
        return ostr << m_number << "," << m_time;
    }
    
    istream& Ticket::csvRead(istream& istr) 
    {
        istr >> m_number;
        istr.ignore();
        return istr >> m_time;
    }
    
    ostream& Ticket::write(ostream& ostr) const 
    {
        return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
    }
    
    istream& Ticket::read(istream& istr)
    {
        return csvRead(istr);
    }
}

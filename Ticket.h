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


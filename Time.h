#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
using namespace std;

namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& setToNow();
        Time(unsigned int min = 0);
        ostream& write(ostream& ostr) const;
        istream& read(istream& istr);

        Time& operator-=(const Time& D);
        Time operator-(const Time& D)const;
        Time& operator+=(const Time& D);
        Time operator+(const Time& D)const;

        Time& operator=(unsigned int val);
        Time& operator *= (unsigned int val);
        Time& operator /= (unsigned int val);
        Time operator *(unsigned int val)const;
        Time operator /(unsigned int val)const;

        operator unsigned int()const;
        operator int()const;
    };
    ostream& operator<<(ostream& ostr, const Time& D);
    istream& operator>>(istream& istr, Time& D);
}

#endif // !SDDS_TIME_H


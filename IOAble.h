#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& os) const = 0;
		virtual istream& csvRead(istream& is) = 0;
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual ~IOAble() {};
	};
	ostream& operator<<(ostream& ostr, const IOAble& able);
	istream& operator>>(istream& istr, IOAble& able);
}

#endif

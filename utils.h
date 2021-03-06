#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
using namespace std;
namespace sdds {
    extern bool debug;

    int getTime();

    int getInt(const char* prompt = nullptr);
    
    int getInt( int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
    
    char* getcstr(const char* prompt = nullptr, istream& istr = cin, char delimiter = '\n');
}
#endif // !SDDS_UTILS_H_


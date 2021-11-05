#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {

    bool debug = false;
    
    int getTime() 
    {
        int mins = -1;
        
        if (debug) 
        {
            Time t(0);
            cout << "Enter current time: ";
            
            do
            {
                cin.clear();
                cin >> t;  
                
                if (!cin) 
                {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else 
                {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            
            } while (mins < 0);
        }
        else
        {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        
        return mins;
    }

    int getInt(const char* prompt) 
    {
        int value;
        bool check = false;

        if (prompt)
        {
            cout << prompt;
        }
        
        while (!check)
        {
            cin >> value;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Bad integer value, try again: ";
            }
            else if (cin.get() != '\n')
            {
                cout << "Enter only an integer, try again: ";
                cin.ignore(1000, '\n');
            }
            else 
            {
                check = true;

            }
        }

        return value;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) 
    {
        int value;
        bool check = false;

        value = getInt(prompt);

        while (check == false) 
        {
            if (value > max || value < min)
            {
                if (errorMessage)
                {
                    cout << errorMessage;
                }

                if (showRangeAtError)
                {
                    cout << "[" << min << " <= value <= " << max << "]: ";
                }
                
                value = getInt();
            }
            
            else 
            {
                check = true;
            }
        
        }
        return value;
    }

    char* getcstr(const char* prompt, istream& istr, char delimiter) 
    {
        if (prompt)
        {
            cout << prompt;
        }
        
        char character[1000];
        char* value;

        istr.getline(character, 1000, delimiter);

        value = new char[strlen(character) + 1];
        
        strcpy(value, character);

        return value;
    }


}

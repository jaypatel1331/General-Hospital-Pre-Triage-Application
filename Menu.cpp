#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>

#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds {
    void Menu::display()const 
    {
        cout << m_text;
        cout << endl;
        cout << "0- Exit";
        cout << endl;
    }

    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        m_text = nullptr;
        m_noOfSel = 0;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
        m_noOfSel = NoOfSelections;
    }

    Menu::~Menu() 
    {
        delete[] m_text;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
        return Selection;
    }

   
    Menu::Menu(const Menu& menu) 
    {
        m_text = nullptr;
        m_noOfSel = 0;
        m_text = new char[strlen(menu.m_text) + 1];
        strcpy(m_text, menu.m_text);
        m_noOfSel = menu.m_noOfSel;
    }
}

//
//  Date.cpp
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#include "Date.h"


Date::Date()
{
    Date::month = 0;
    Date::year = 0;
}

Date::Date(int month, int year)
{
    Date::month = month;
    Date::year = year;
}
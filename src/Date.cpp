//
// Created by arsga on 9/10/2017.
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
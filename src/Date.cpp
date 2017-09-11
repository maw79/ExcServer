//
// Created by arsga on 9/10/2017.
//

#include "Date.h"


Date::Date()
{
    Date::day = 0;
    Date::month = 0;
    Date::year = 0;
}

Date::Date(int day, int month, int year)
{
    Date::day = day;
    Date::month = month;
    Date::year = year;
}
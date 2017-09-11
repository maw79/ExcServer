//
// Created by arsga on 9/10/2017.
//

#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

class Date{
public:
    int day;
    int month;
    int year;

    Date::Date();
    Date::Date(int day, int month, int year);
    Date::getDay(){return day;}
    Date::getMonth(){return month;}
    Date::getYear(){return year;}
};

#endif //UNTITLED_DATE_H

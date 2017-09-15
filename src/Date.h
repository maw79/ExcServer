//
//  Date.h
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H

class Date{
public:
    int month;
    int year;

    Date();
    Date(int month, int year);
    int getMonth(){return month;}
    int getYear(){return year;}
};

#endif //UNTITLED_DATE_H

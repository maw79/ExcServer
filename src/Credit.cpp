//
// Created by arsga on 9/11/2017.
//

#include "Credit.h"


Credit::Credit()
{
    Credit::zip = 0;
    Credit::svc = 0;
    Credit::expDate = Date(rand() % 30, rand() % 12, rand() % 10 + 2010);
    Credit::CCnum0 = 0;
    Credit::CCnum1 = 0;
    Credit::CCnum2 = 0;
    Credit::CCnum3 = 0;
}

Credit::Credit(int CCnum0,int CCnum1,int CCnum2,int CCnum3, Date expDate, int svc, int zip)
{
    Credit::CCnum0 = CCnum0;
    Credit::CCnum1 = CCnum1;
    Credit::CCnum2 = CCnum2;
    Credit::CCnum3 = CCnum3;
    Credit::expDate = expDate;
    Credit::svc = svc;
    Credit::zip = zip;
}

void Credit::setZip(int num)
{
    Credit::zip = num;
}

void Credit::setSvc(int svc)
{
    Credit::svc = svc;
}

void Credit::setExpDate(Date expDate)
{
    Credit::expDate = expDate;
}

void Credit::setCCnum(int CCnum0,int CCnum1,int CCnum2,int CCnum3)
{
    Credit::CCnum0 = CCnum0;
    Credit::CCnum1 = CCnum1;
    Credit::CCnum2 = CCnum2;
    Credit::CCnum3 = CCnum3;
}
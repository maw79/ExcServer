//
// Created by arsga on 9/11/2017.
//

#include "Credit.h"


Credit::Credit()
{
    Credit::zip = rand() % 89999 + 10000;
    Credit::svc = rand() % 899 + 100;
    Credit::expDate = Date(rand() % 30, rand() % 12, rand() % 10 + 2010);
    Credit::CCnum0 = rand() % 8999 + 1000;
    Credit::CCnum1 = rand() % 8999 + 1000;
    Credit::CCnum2 = rand() % 8999 + 1000;
    Credit::CCnum3 = rand() % 8999 + 1000;
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
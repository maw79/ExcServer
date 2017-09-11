//
// Created by arsga on 9/11/2017.
//

#ifndef UNTITLED_CREDIT_H
#define UNTITLED_CREDIT_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Credit{
private:
    int CCnum0, CCnum1, CCnum2, CCnum3;
    Date expDate;
    int svc;
    int zip;

public:
    Credit();
    Credit(int CCnum0,int CCnum1,int CCnum2,int CCnum3, Date expDate, int svc, int zip);

    string getCCnum(){return (to_string(CCnum0) + " " + to_string(CCnum1) + " " + to_string(CCnum2) + " " + to_string(CCnum3));}
    Date getExpDate(){return expDate;}
    int getSvc(){return svc;}
    int getZip(){return zip;}
};

#endif //UNTITLED_CREDIT_H

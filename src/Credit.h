//
// Created by arsga on 9/11/2017.
//

#ifndef UNTITLED_CREDIT_H
#define UNTITLED_CREDIT_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class{
private:
    int CCnum0, CCnum1, CCnum2, CCnum3;
    Date expDate;
    int svc;
    int zip;

public:
    Credit();
    Credit(int CCnum0,int CCnum1,int CCnum2,int CCnum3);

    string getCCnum(){return (CCnum0 + " " + CCnum1 + " " + CCnum2 + " " + CCnum3);}
};

#endif //UNTITLED_CREDIT_H

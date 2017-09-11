//
// Created by arsga on 9/10/2017.
//

#ifndef EXCSERVER_CUSTOMER_H
#define EXCSERVER_CUSTOMER_H

#include <string>
#include <iostream>
#include "Date.h"
#include <math.h>

using namespace std;

class Customer{

private:
    string name;
    string address;
    Date expDate;
    int accountID;
    int CCnum;
    int svc;
    int zip;

public:
    Customer::Customer();
    Customer::Customer(string name, string address, Date expDate, int accountID, int CCnum, int svc, int zip);

    string Customer::getName(){return name;}
    string Customer::getAddress(){return address;}
    Date Customer::getExpDate(){return expDate;}
    int Customer::getAccountID(){return accountID;}
    int Customer::getCCnum(){return CCnum;}
    int Customer::getSvc(){return svc;}
    int Customer::getZip(){return zip;}
};

#endif //EXCSERVER_CUSTOMER_H

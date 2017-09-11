//
// Created by arsga on 9/10/2017.
//

#ifndef EXCSERVER_CUSTOMER_H
#define EXCSERVER_CUSTOMER_H

#include <string>
#include <iostream>
#include "Date.h"
#include <math.h>

class Customer{
public:
    std::string name;
    std::string address;
    Date expDate;
    int accountID;
    int CCnum;
    int svc;
    int zip;

    Customer::Customer();
    Customer::Customer(std::string name, std::string address, Date expDate, int accountID, int CCnum, int svc, int zip);

    std::string Customer::getName(){return name;}
    std::string Customer::getAddress(){return address;}
    Date Customer::getExpDate(){return expDate;}
    int Customer::getAccountID(){return accountID;}
    int Customer::getCCnum(){return CCnum;}
    int Customer::getSvc(){return svc;}
    int Customer::getZip(){return zip;}
};

#endif //EXCSERVER_CUSTOMER_H

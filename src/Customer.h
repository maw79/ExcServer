//
// Created by arsga on 9/10/2017.
//

#ifndef EXCSERVER_CUSTOMER_H
#define EXCSERVER_CUSTOMER_H

#include <string>
#include <iostream>

class Customer{
public:
    std::string name;
    int accountID;
    int CCnum;
    int expDate;
    int svc;
    std::string zip;
    std::string address;

    Customer::Customer();
};

#endif //EXCSERVER_CUSTOMER_H

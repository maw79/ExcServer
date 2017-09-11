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
    Customer();
    Customer(string name, string address, Date expDate, int accountID, int CCnum, int svc, int zip);

    string getName(){return name;}
    string getAddress(){return address;}
    Date getExpDate(){return expDate;}
    int getAccountID(){return accountID;}
    int CgetCCnum(){return CCnum;}
    int getSvc(){return svc;}
    int getZip(){return zip;}
};

#endif //EXCSERVER_CUSTOMER_H

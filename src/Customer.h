//
//  Customer.h
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#ifndef EXCSERVER_CUSTOMER_H
#define EXCSERVER_CUSTOMER_H

#include <string>
#include <iostream>
#include "Date.h"
#include <math.h>
#include "Credit.h"

using namespace std;

class Customer{

private:
    string name;
    string address;
    Credit creditC;
    long long int accountID;
    int accBalance;
public:
    Customer();
    Customer(string name);
    Customer(string name, string address, long long int accountID, Credit creditC, int accBalance);

    string getName(){return name;}
    string getAddress(){return address;}
    long long int getAccountID(){return accountID;}
    Credit getCC(){return creditC;}
    int getBalance(){return accBalance;}

    void setBalance(int num){accBalance = num;}
    void setCC(Credit CCfile){creditC = CCfile;}
};

#endif //EXCSERVER_CUSTOMER_H

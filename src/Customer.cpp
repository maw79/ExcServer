//
//  Customer.cpp
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#include "Customer.h"

using namespace std;
int zipArray[] = {90263, 93461, 20891, 34230,10023};
int accountBalanceArray[] = {1800, 200, 20000001, 900000, 130000};
int svcArray[] = {123,456,789,435,234};

Customer::Customer()
{
    Customer::name = "";
    Customer::address = "";
    Customer::accountID = 0;
    Credit CC;
    Customer::creditC = CC;
    Customer::accBalance = 0;
}

Customer::Customer(string name)
{
    int nums = rand() % 5;
    Customer::name = name;
    Customer::accountID = rand() % 10000;
    Credit CC;
    CC.setZip(zipArray[nums]);
    CC.setSvc(svcArray[nums]);
    Customer::creditC = CC;
    Customer::accBalance = accountBalanceArray[nums];
}

Customer::Customer(string names, string address, long long int accountID, Credit creditC, int accBalance)
{
    Customer::name = names;
    Customer::address = address;
    Customer::accountID = accountID;
    Customer::creditC = creditC;
    Customer::accBalance = accBalance;
}

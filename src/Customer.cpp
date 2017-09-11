//
// Created by arsga on 9/10/2017.
//

#include "Customer.h"

using namespace std;
string nameArray[] = {"Bob Dillon", "James Dean", "Jimmy Hendrix", "Brian Johnson", "Steven Tyler"};

Customer::Customer()
{
    int ranNum = rand() % (sizeof(nameArray)/sizeof(*nameArray));
    Customer::name = nameArray[ranNum];
    Customer::accountID = rand() & 8999999999 + 1000000000;
    Customer::address = "P. Sherman, 42 Wallaby Way, Sydney, DEATH PLACE";
    Credit CC;
    Customer::creditC = CC;
}

Customer::Customer(string name, string address, long long int accountID, Credit creditC)
{
    Customer::name = name;
    Customer::address = address;
    Customer::accountID = accountID;
    Customer::creditC = creditC;
}

//
// Created by arsga on 9/10/2017.
//

#include "Customer.h"

std::string nameArray[] = {"Bob Dillon", "James Dean", "Jimmy Hendrix", "Brian Johnson", "Steven Tyler"};

Customer::Customer()
{
    int ranNum = rand() % (sizeof(nameArray)/sizeof(*nameArray));
    Customer::name = nameArray[ranNum];
}

Customer::Customer(std::string name, std::string address, Date expDate, int accountID, int CCnum, int svc, int zip)
{
    Customer::name = name;
    Customer::address = address;
    Customer::expDate = expDate;
    Customer::accountID = accountID;
    Customer::CCnum = CCnum;
    Customer::svc = svc;
    Customer::zip = zip;
}

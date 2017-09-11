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
    Customer::zip = rand() % 89999 + 10000;
    Customer::svc = rand() % 899 + 100;
    Customer::CCnum = rand() % 8999999999999999 + 1000000000000000;
    Customer::accountID = rand() & 8999999999 + 1000000000;
    Customer::expDate = Date(rand() % 30, rand() % 12, rand() % 10 + 2010);
    Customer::address = "P. Sherman, 42 Wallaby Way, Sydney, DEATH PLACE";

}

Customer::Customer(string name, string address, Date expDate, long long int accountID, long long int CCnum, int svc, int zip)
{
    Customer::name = name;
    Customer::address = address;
    Customer::expDate = expDate;
    Customer::accountID = accountID;
    Customer::CCnum = CCnum;
    Customer::svc = svc;
    Customer::zip = zip;
}

//
// Created by arsga on 9/10/2017.
//

#include "Customer.h"
#include <ctime>

using namespace std;
string nameArray[] = {"Bob Dylan", "James Dean", "Jimi Hendrix", "Brian Johnson", "Steven Tyler"};
string addressArray[] = {"Malibu, California", "Cholame, California", "Kensington, London", "Sarasota, Florida", "Manhattan, New York"};
int zipArray[] = {};


Customer::Customer()
{
    srand(time(NULL));
    int ranNum = rand() % (sizeof(nameArray)/sizeof(*nameArray));
    Customer::name = nameArray[ranNum];
    Customer::accountID = rand() % 8999999999 + 1000000000;
    Customer::address = addressArray[ranNum];
    Credit CC;
    Customer::creditC = CC;
    Customer::accBalance = rand() % 10000;
}

Customer::Customer(string name, string address, long long int accountID, Credit creditC, int accBalance)
{
    Customer::name = name;
    Customer::address = address;
    Customer::accountID = accountID;
    Customer::creditC = creditC;
    Customer::accBalance = accBalance;
}

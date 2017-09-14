//
// Created by arsga on 9/10/2017.
//

#include "Customer.h"
#include <ctime>

using namespace std;
string nameArray[] = {"Bob Dylan", "James Dean", "Jimi Hendrix", "Brian Johnson", "Steven Tyler"};
string addressArray[] = {"Malibu, California", "Cholame, California", "Kensington, London", "Sarasota, Florida", "Manhattan, New York"};
int zipArray[] = {90263, 93461, 20891, 34230,10023};
int accountBallanceArray[] = {180000000, 20000000, 80000000, 90000000, 130000000};

int nums = 1;

Customer::Customer()
{
    Customer::name = nameArray[nums];
    Customer::accountID = rand() % 8999999999 + 1000000000;
    Customer::address = addressArray[nums];
    Credit CC;
    CC.setZip(zipArray[nums]);
    Customer::creditC = CC;
    Customer::accBalance = accountBallanceArray[nums];
    nums++;
}

Customer::Customer(string name, string address, long long int accountID, Credit creditC, int accBalance)
{
    Customer::name = name;
    Customer::address = address;
    Customer::accountID = accountID;
    Customer::creditC = creditC;
    Customer::accBalance = accBalance;
}

//
//  Customer.cpp
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#include "Customer.h"

using namespace std;
//string nameArray[] = {"Bob Dylan", "James Dean", "Jimi Hendrix", "Brian Johnson", "Steven Tyler"};
//string addressArray[] = {"Malibu, California", "Cholame, California", "Kensington, London", "Sarasota, Florida", "Manhattan, New York"};
int zipArray[] = {90263, 93461, 20891, 34230,10023};
int accountBalanceArray[] = {1800, 200, 20000001, 900000, 130000};
int svcArray[] = {123,456,789,435,234};
//int CC1Array[] = {1234,3423,5555,7830,1357};
//int CC2Array[] = {1334,3456,5123,7840,2377};
//int CC3Array[] = {1567,3246,5658,7850,3347};
//int CC4Array[] = {3244,3996,5348,7860,4387};
//long long int accountArray[]={1234567890,6789012345,9087654321,7850276589,4543673492};

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

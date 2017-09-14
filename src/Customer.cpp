//
// Created by arsga on 9/10/2017.
//

#include "Customer.h"

using namespace std;
string nameArray[] = {"Bob Dylan", "James Dean", "Jimi Hendrix", "Brian Johnson", "Steven Tyler"};
string addressArray[] = {"Malibu, California", "Cholame, California", "Kensington, London", "Sarasota, Florida", "Manhattan, New York"};
int zipArray[] = {90263, 93461, 20891, 34230,10023};
int accountBallanceArray[] = {180000000, 20000000, 80000000, 90000000, 130000000};
int svcArray[] = {123,456,789,435,234};
int CC1Array[] = {1234,3423,5555,7830,1357};
int CC2Array[] = {1334,3456,5123,7840,2377};
int CC3Array[] = {1567,3246,5658,7850,3347};
int CC4Array[] = {3244,3996,5348,7860,4387};
long long int accountArray[]={};

Customer::Customer(int nums)
{
    Customer::name = nameArray[nums];
    Customer::accountID = rand() % 8999999999 + 1000000000;
    Customer::address = addressArray[nums];
    Credit CC;
    CC.setZip(zipArray[nums]);
    CC.setSvc(svcArray[nums]);
    CC.setCCnum(CC1Array[nums], CC2Array[nums], CC3Array[nums], CC4Array[nums]);
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

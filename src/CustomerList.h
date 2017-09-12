//
// Created by arsga on 9/12/2017.
//

#ifndef UNTITLED_CUSTOMERLIST_H
#define UNTITLED_CUSTOMERLIST_H

#import "Customer.h"

using namespace std;

struct custList{
    Customer cust;
    custList *next;
};

class CustomerList{
private:
    custList *root;
    custList *conductor;
public:
    CustomerList();
    CustomerList(int numofCustomers);

    void makeCustomer();
    bool deleteCustomer();


    Customer nextCustomer();
    Customer previousCustomer();
    Customer custatLoc(int Loc);
    Customer getCustomer(Customer);

};

#endif //UNTITLED_CUSTOMERLIST_H

//
// Created by arsga on 9/12/2017.
//

#ifndef UNTITLED_CUSTOMERLIST_H
#define UNTITLED_CUSTOMERLIST_H

#include "Customer.h"

using namespace std;

struct custList{
    Customer cust;
    custList *next;
    custList *previous;
}*start;

class CustomerList{
private:
    custList *root;
    custList *conductor;
public:
    CustomerList(Customer bob);

    void Insert(Customer bob);
    bool makeCustomer();
    Customer popCustomer();
    bool moveUP();
    bool moveDown();
    int count();

    Customer getCustomer();
};

#endif //UNTITLED_CUSTOMERLIST_H

//
// Created by arsga on 9/12/2017.
//

#ifndef UNTITLED_CUSTOMERLIST_H
#define UNTITLED_CUSTOMERLIST_H

#include "Customer.h"

struct custList{
    Customer cust;
    custList *next;
    custList *previous;
};

class CustomerList{
private:
    custList *start;
public:
    void CreateList(Customer bob);
    CustomerList(){start = NULL;}

    void Insert(Customer bob);
    void delete_element(long long int accountID);
    int count();

    Customer getCustomer(long long int value);

};

#endif //UNTITLED_CUSTOMERLIST_H

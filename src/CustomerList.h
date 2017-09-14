//
// Created by arsga on 9/12/2017.
//

#ifndef UNTITLED_CUSTOMERLIST_H
#define UNTITLED_CUSTOMERLIST_H

#include "Customer.h"

struct custList{
    Customer cust = Customer(0,0,0,Credit(0,0,0,0, Date(0, 0, 0), 0, 0),0);
    custList *next;
    custList *previous;
    custList(){Customer(0,0,0,Credit(0,0,0,0, Date(0, 0, 0), 0, 0),0);}
};

class CustomerList{
private:
    custList *start;
public:

    void CreateList(Customer bob);
    CustomerList();

    void Insert(Customer bob);
    void delete_element(long long int accountID);
    int count();

    Customer getCustomer(long long int value);

};

#endif //UNTITLED_CUSTOMERLIST_H

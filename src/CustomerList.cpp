//
// Created by arsga on 9/12/2017.
//

#include "CustomerList.h"


CustomerList::CustomerList()
{
    root = new custList;
    root->next = 0;
    Customer first;
    root->cust = first;
    conductor = root;
}

void CustomerList::makeCustomer()
{
    Customer add;
    conductor->next = new custList;
    conductor = conductor->next;
    conductor->cust = add;
}
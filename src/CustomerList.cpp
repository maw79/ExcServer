//
// Created by arsga on 9/12/2017.
//

#include "CustomerList.h"


CustomerList::CustomerList()
{
    root = new custList;
    root->next = 0;
    root->previous = 0;
    Customer first;
    root->cust = first;
    conductor = root;
}

void CustomerList::makeCustomer()
{
    Customer n;
    conductor->previous = conductor;
    conductor->next = new custList;
    conductor = conductor->next;
    conductor->cust = n;
    conductor->next = 0;
}

Customer CustomerList::popCustomer()
{
    custList *n = ;
    delete conductor->cust;
    conductor = conductor->previous;
}

/*
int popValue(){
    Node *n = head;
    int ret = n->x;

    head = head->next;
    delete n;
    return ret;
}*/
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

/*
 * If you get false back then the conductor is not at the end of the list.
 */

bool CustomerList::makeCustomer()
{
    if(conductor->next == 0)
    {
        Customer n;
        conductor->previous = conductor;
        conductor->next = new custList;
        conductor = conductor->next;
        conductor->cust = n;
        conductor->next = 0;
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * If you get a null back then you are not at the end of the list.
 */

Customer CustomerList::popCustomer()
{
    if(conductor->next == 0)
    {
        Customer ret = conductor->cust;
        delete conductor->cust;
        conductor = conductor->previous;
        delete conductor->next;
        return ret;
    }
    else
    {
        return NULL;
    }
}

bool CustomerList::moveDown()
{
    if(conductor->next != 0)
    {
        conductor->next = conductor->next->next;

        return true;
    }
    else
    {
        return false;
    }
}
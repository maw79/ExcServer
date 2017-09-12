//
// Created by arsga on 9/12/2017.
//

#include "CustomerList.h"


CustomerList::CustomerList(Customer bob)
{
    struct custList *s, *temp;
    temp = new(struct custList);
    temp->cust = bob;
    temp->next = NULL;
    if(start == NULL)
    {
        temp->previous = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while(s->next != NULL)
            s=s->next;
        s->next = temp;
        temp->previous = s;
    }
}

void CustomerList::Insert(Customer bob)
{
    if(start == NULL)
    {
        cout << "NO List" << endl;
        return;
    }
    struct custList *temp;
    temp = new(struct custList);
    temp->previous = NULL;
    temp->cust = bob;
    temp->next = start;
    start->previous = temp;
    start = temp;
}

int CustomerList::count()
{
    struct custList *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    return cnt;
}

void CustomerList::delete_element(Customer value)
{
    struct custList *tmp, *q;
    /*first element deletion*/
    if (start->cust.getAccountID() == value.getAccountID())
    {
        tmp = start;
        start = start->next;
        start->previous = NULL;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->cust.getAccountID() == value.getAccountID())
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    /*last element deleted*/
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
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
    Customer ret = conductor->cust;
    //delete conductor->cust;
    conductor->next = conductor;
    conductor = conductor->previous;
    conductor->next = 0;
    return ret;
}

bool CustomerList::moveDown()
{
    if(conductor->next != 0)
    {
        conductor->next = conductor->next->next;
        conductor->previous = conductor;
        conductor = conductor->next;
        return true;
    }
    else
    {
        return false;
    }
}

bool CustomerList::moveUP()
{
    if(conductor->previous != 0)
    {
        conductor->previous = conductor->previous->previous;
        conductor->next = conductor;
        conductor = conductor->previous;
        return true;
    }
    else
    {
        return false;
    }
}

Customer CustomerList::getCustomer()
{
    return conductor->cust;
}
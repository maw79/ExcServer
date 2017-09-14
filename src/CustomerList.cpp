//
// Created by arsga on 9/12/2017.
//

#include "CustomerList.h"


CustomerList::CustomerList()
{
    start = NULL;
}

void CustomerList::CreateList(Customer bob)
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

void CustomerList::delete_element(long long int accountID)
{
    struct custList *tmp, *q;
    /*first element deletion*/
    if (start->cust.getAccountID() == accountID)
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
        if (q->next->cust.getAccountID() == accountID)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->previous = q;
            free(tmp);
            return;
        }
        q = q->next;
    }
    /*last element deleted*/
    if (q->next->cust.getAccountID() == accountID)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        return;
    }
}

Customer CustomerList::getCustomer(long long int accountID)
{
    struct custList *q;
    q = start;
    while(q != NULL)
    {
        if(q->cust.getAccountID() == accountID)
        {
            return q->cust;
        }
        q = q->next;
    }

}
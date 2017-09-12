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
    custList *previous;
};

class CustomerList{
private:
    custList *root;
    custList *conductor;
public:
    CustomerList();

    void makeCustomer();
    Customer popCustomer();
    void moveUP();
    void moveDown();


    Customer nextCustomer();
    Customer previousCustomer();
    Customer custatLoc(int Loc);
    Customer getCustomer(Customer);

};

#endif //UNTITLED_CUSTOMERLIST_H

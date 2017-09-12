//
//  main.cpp
//  Online Shopping System
//
//  Created by Aaron Turner, Aaron Riggs and Scott Reilman on 9/10/17.
//  Copyright © 2017 AARONS. All rights reserved.
//

#include <iostream>
#include <string>
#include "Customer.h"
#include "Date.h"
#include "Credit.h"
#include "Product.h"
#include <ctime>
using namespace std;

//testing seeded random functionality
int seededNum()
{
    srand(time(NULL));
    int num = rand() % 100;
    return num;
}


//MAIN SEQUENCE

/*
 * Function : orderReq()
 * Arguments : None
 * Return : Void
 * Functionality : From the main menu the customer provides order request and customer account ID to pay for purchase
 *                 as well as selecting the item to purchase.
 */
void orderReq()
{
    Customer customer1;
    Product product1;
    cout << "CUSTOMER DETAILS:" << endl;
    cout << "Name: " << customer1.getName() << endl;
    cout << "Address: " << customer1.getAddress() << endl;
    cout << "Account ID: " << customer1.getAccountID() << endl;
    cout << "Credit Card Number: " << customer1.getCC().getCCnum() << endl;
    cout << "Initial Account Balance: $" << customer1.getBalance() << endl;
    cout << "Item to buy: " << product1.getName() << endl;
    cout << "Price of item: $" << product1.getPrice() << endl;
    cout << "Remaining Account Balance: $" << customer1.getBalance() - product1.getPrice() << endl;

    cout << endl;

    /*
    Customer customer2;
    Product product2;
    cout << "CUSTOMER DETAILS:" << endl;
    cout << "Name: " << customer2.getName() << endl;
    cout << "Address: " << customer2.getAddress() << endl;
    cout << "Account ID: " << customer2.getAccountID() << endl;
    cout << "Credit Card Number: " << customer2.getCC().getCCnum() << endl;
    cout << "Item to buy: " << product2.getName() << endl;
    cout << "Price of item: $" << product2.getPrice() << endl;
     */


}

/*
 * Function : pullData()
 * Arguments : None
 * Return : Void
 * Functionality : The System will retrieve customer account information, including the customer’s credit card details.
 */
/*
void pullData()
{
    
}

/*
 * Function : bankCheck()
 * Arguments : None
 * Return : Void
 * Functionality : The System requests to a bank checking the customer’s credit card for the purchase amount and,
 *                 if approved, creates a credit card purchase authorization number.
 */
/*
void bankCheck()
{

}

/*
 * Function : createOrder()
 * Arguments : None
 * Return : Void
 * Functionality : The system creates a delivery order containing order details, customer Id,
 *                 and credit card authorization number
 */

/*
void createOrder()
{
    
}

/*
 * Function : displayConfirmation()
 * Arguments : None
 * Return : Void
 * Functionality : System confirms approval of purchase and displays order information to customer.
 */
/*
void displayConfirmation()
{

}

//ALTERNATIVE SEQUENCES

/*
 * Function : invalidAccount()
 * Arguments : None
 * Return : Void
 * Functionality : If customer does not have an account, the system prompts the
                   customer to provide information in order to create a new account. The
                   customer can either enter the account information or cancel the order.
 */
/*
void invalidAccount()
{

}

/*
* Function : accessDenied()
* Arguments : None
* Return : Void
* Functionality : If authorization of the customer’s credit card is denied (e.g., invalid
                  credit card or insufficient funds in the customer’s credit card account), the
                  system prompts the customer to enter a different credit card number. The
                  customer can either enter a different credit card number or cancel the order.
*/
/*void accessDenied()
{

}*/

int main()
{
    //MainMenu();
    //cout << seededNum() << endl;
    //cout << seededNum() << endl;
    //cout << seededNum() << endl;
    //cout << seededNum() << endl;
    orderReq();
}

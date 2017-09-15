//
//  main.cpp
//  Online Shopping System
//
//  Created by Aaron Turner, Aaron Riggs and Scott Reilman on 9/10/17.
//  Copyright © 2017 AARONS. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Customer.h"
#include "Product.h"
using namespace std;

vector<Customer> customerList(100);

int customerID;
//Customer currentCustomer;

void printCustInfo(Customer customer1)
{
    cout << "CUSTOMER DETAILS:" << endl;
    cout << "Name: " << customer1.getName() << endl;
    cout << "Address: " << customer1.getAddress() << endl;
    cout << "Account ID: " << customer1.getAccountID() << endl;
    cout << "Credit Card Number: " << customer1.getCC().getCCnum() << endl;
    cout << "Initial Account Balance: $" << customer1.getBalance() << endl;
    cout << endl;
}

void Sleep(int long long time)
{
    int i = 0;
    while(i < time*10000)
    {
        i++;
    }
}

void MainLoop()
{
    int i = 0;
    while (true)
    {
        cout << "Input 109 for new account" << endl;
        cout << "enter Customer ID: ";
        cin >> customerID;
        if(customerID == 109)
        {
            string name;
            cout << "Input 1 to Cancel" << endl;
            cout << "Input full name: ";
            cin >> name;
            cout << endl;
            if (name != "1")
            {
                Customer C1(name);
                customerList[i] = C1;

                cout << "your Account ID is : " << C1.getAccountID() << endl;
                cout << "Make sure to write this down" << endl;
            }
        }
        else if(cin.fail())
        {
            cout << endl;
            cout << "We didn't understand that, please re-enter your selection" << endl;
        }
        else
        {
            cout << endl;
            break;
        }
        i++;
    }

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
//    Product product1;
//    cout << "Item to buy: " << product1.getName() << endl;
//    cout << "Price of item: $" << product1.getPrice() << endl;
//    cout << "Remaining Account Balance: $" << customer1.getBalance() - product1.getPrice() << endl;
//
//    cout << endl;
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

void displayConfirmation(Customer C1)
{
    cout << "Thank you for your order " << C1.getName() << endl;
    cout << "Your confirmation number is: " << rand() % 1000 << endl;
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
void accessDenied()
{
    string CCnum;
    cout << "ACCESS DENIED" << endl;
    cout << "Enter new Credit Card number (XXXX XXXX XXXX XXXX)" << endl;
    cout << ":";
    cin >> CCnum;
    cout << endl;
    string delimit = " ";
    if(CCnum.find(delimit) == string::npos)
    {
        cout << "You entered your cedit card number wrong" << endl;
    }
}

int main()
{
    customerList.reserve(100);
    MainLoop();
    //orderReq();
}

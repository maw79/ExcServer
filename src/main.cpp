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
#include <limits>
#include "Customer.h"
using namespace std;

vector<Customer> customerList(100);

int customerID;
//Customer currentCustomer;

void displayConfirmation(Customer C1); //Display conformation prototype
void orderReq(Customer C1); //Order request prototype
void accessDenied();

Customer findCustInVector(int accountID)
{
    Customer Cust;
    for(int i = 0; i < 100; i++)
    {
        int accID = customerList[i].getAccountID();
        if(accID == accountID)
        {
            return customerList[i];
        }
    }
    return Cust;
}

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
            if (!cin)
            {
                cin.clear();
                std::string ignoreLine; //read the invalid input into it
                std::getline(cin, ignoreLine); //read the line till next space
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            }
        }
        else
        {
            Customer c1 = findCustInVector(customerID);
            if(c1.getAccountID() == 0)
            {
                cout << "We did not find that one " << endl;
            }
            else
            {
                cout << "We found you: " << c1.getName() << endl;
                orderReq(c1);
            }
            cout << endl;
            break;
        }
        i++;
    }

}

void initializeCustomer()
{
    Customer C1("Bob Dylan","Malibu, California", 1,Credit(1234,1234,1234,1234,Date(01,2018),123,90263),1800);
    customerList[1] = C1;
    Customer C2("James Dean","Cholame, California", 2,Credit(9876,9876,9876,9876,Date(05,2019),987,93461),200);
    customerList[2] = C2;
    Customer C3("Jimi Hendrix","Kensington, London", 3,Credit(4567,4567,4567,4567,Date(02,2018),456,20891),20000001);
    customerList[3] = C3;
    Customer C4("Brian Johnson","Sarasota, Florida", 4,Credit(6543,6543,6543,6543,Date(12,2017),654,34230),900000);
    customerList[4] = C4;
    Customer C5("Steven Tyler","Manhattan, New York", 5,Credit(5432,5432,5432,5432,Date(06,2019),543,10023),130000);
    customerList[5] = C5;
}

//MAIN SEQUENCE

/*
 * Function : orderReq()
 * Arguments : None
 * Return : Void
 * Functionality : From the main menu the customer provides order request and customer account ID to pay for purchase
 *                 as well as selecting the item to purchase.
 */
void orderReq(Customer C1)
{
    string CCnum;
    cout << "You want to buy a M1A1 Abrams Tank for 20000000" << endl;
    while(true)
    {
        cout << "(XXXX XXXX XXXX XXXX)" << endl;
        cout << "Please enter credit card number now: ";
        cin >> CCnum;

        if (cin)
        {
            cin.clear();
            std::string ignoreLine; //read the invalid input into it
            std::getline(cin, ignoreLine); //read the line till next space
        }

        cout << endl;
        char delimit = ' ';
        if(CCnum.find(delimit) == ' ')
        {
            cout << "You entered your cedit card number wrong" << endl;
        }
        else
        {
            string bankA;
            cout << "BANK: is this a valid card? : ";
            cin >> bankA;
            cout << endl;
            if(bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y")
            {
                int CCnums[4];
                size_t pos;
                string delimiter = " ";
                int i = 0;
                while ((pos = CCnum.find(delimiter)) != std::string::npos) {
                    CCnums[i] = std::stoi(CCnum.substr(0, pos));
                    CCnum.erase(0, pos + delimiter.length());
                    i++;
                }
                C1.getCC().setCCnum(CCnums[0],CCnums[1],CCnums[2],CCnums[3]);
                if (cin)
                {
                    cin.clear();
                    std::string ignoreLine; //read the invalid input into it
                    std::getline(cin, ignoreLine); //read the line till next space
                }
                cout << "The customer has $" << C1.getBalance() << " in their account, is this transaction approved?";
                cin >> bankA;
                cout << endl;
                if(bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y")
                {
                    displayConfirmation(C1);
                }else
                {
                    accessDenied();
                }
                break;
            }else{
                accessDenied();
            }
        }
    }
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
    cout << "Your order will be sent to: " << C1.getAddress() << " Zip: " << C1.getCC().getZip() << endl;
    cout << "The order will be charged to: " << C1.getCC().getCCnum() << endl;
    cout << "your new balance is: $" << C1.getBalance() - 20000000 << endl;
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
    while(true)
    {
        string CCnum;
//    size_t pos = 0;
//    int CCnums[4];
        cout << "ACCESS DENIED" << endl;
        cout << "Enter new Credit Card number (XXXX XXXX XXXX XXXX) or \"NO\" to cancel Transaction" << endl;
        cout << ": ";
        cin >> CCnum;
        cout << endl;
        char delimit = ' ';
        if(CCnum.find(delimit) == ' ')
        {
            cout << "You entered your cedit card number wrong" << endl;
        }
        else if (CCnum == "NO" || CCnum == "no")
        {
            break;
        }
        else
        {
            string bankA;
            cout << "BANK: is this a valid card?";
            cin >> bankA;
            cout << endl;
            if(bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y")
            {
                break;
            }
        }
    }
}

int main()
{
    customerList.reserve(100);
    initializeCustomer();
    MainLoop();
}

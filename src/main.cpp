//
//  main.cpp
//  Online Shopping System
//
//  Collaborated effort of Aaron Riggs and David Turner
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <limits>
#include <cstring>
#include "Customer.h"
using namespace std;

vector<Customer> customerList(100);

int customerID;

void displayConfirmation(Customer C1); //Display confirmation prototype
void orderReq(Customer C1); //Order request prototype
void approvalDenied(); //Bank approval denied prototype

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

void MainLoop()
{
    int i = 0;
    while (true)
    {
        cout << "Input Customer ID (0 for new account): ";
        cin >>  customerID;
        if(customerID == 0)
        {
            cout << "Input full name (1 to cancel): ";

            if (cin) {
                cin.clear();
                std::string ignoreLine; //read the invalid input into it
                std::getline(cin, ignoreLine); //read the line till next space
            }

            char name[200];
            cin.getline(name,sizeof(name));
            cout << endl;
            if (name[0] != '1')
            {
                Customer C1(name);
                customerList[i+5] = C1;

                cout << "Your Account ID is: " << C1.getAccountID() << endl;
                cout << "Make sure to write this down" << endl;

                orderReq(C1);
                break;
            }
        }
        else if(cin.fail())
        {
            cout << endl;
            cout << "Invalid input, please re-enter your selection" << endl;
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
                cout << "Invalid Customer ID...exiting" << endl;
                cout << "Goodbye!" << endl;
            }
            else
            {
                cout << "Customer name for this Account ID: " << c1.getName() << endl;
                orderReq(c1);
            }
            break;
        }
        i++;
    }
}

/*
 * Function : initializeCustomer()
 * Arguments : None
 * Return : Void
 * Functionality : Initializing 5 pre-defined customers with address, CC info, and account balance
 */
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
 * Arguments : Customer C1, input of object of Customer class type
 * Return : Void
 * Functionality : From the main menu the customer provides order request and customer account ID to pay for purchase
 *                 as well as selecting the item to purchase.
 */
void orderReq(Customer C1)
{
    string CCnum;
    int option;
    cout << "Your shopping cart consists of:" << endl << "- 1 x M1A1 Abrams Tank.........$20,000,000" << endl;
    while(true)
    {
        option = 0;
        if(C1.getCC().getCCnum() == "0 0 0 0")
        {
            Credit newCC;
            char input[20];
            cout << "Input a new credit card number (in the form XXXX XXXX XXXX XXXX): " ;
            cin.getline(input,sizeof(input));
            string newCCnum;

            for(int i = 0; i < sizeof(input); i++)
            {
                newCCnum+=input[i];
            }

            char *pch;
            char delim[] = " ";

            pch = strtok(input,delim);

            int CCnums[4] = {};
            int i = 0;
            while(pch)
            {
                CCnums[i] = stoi(pch);
                pch = strtok(NULL,delim);
                i++;
            }


            newCC.setCCnum(CCnums[0], CCnums[1], CCnums[2], CCnums[3]);
            newCC.setSvc(rand()%899-100);
            newCC.setZip(rand()%89999-10000);
            newCC.setExpDate(Date(05,2020));
            C1.setCC(newCC);
        }
        cout << "Input 1 to use card on file or 2 for new CC: ";
        cin >> option;
        if(option==1)
        {
            string bankA;

            if (cin) {
                cin.clear();
                std::string ignoreLine; //read the invalid input into it
                std::getline(cin, ignoreLine); //read the line till next space
            }
            cout << "The number for the credit card you have on file is: " << C1.getCC().getCCnum() << endl;
            cout << "The customer has $" << C1.getBalance()
                 << " in their account, is this transaction approved? (y or n): ";
            cin >> bankA;
            cout << endl;
            if (bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y")
            {
                displayConfirmation(C1);
            } else {
                approvalDenied();
            }
            break;
        }
        else if(option==2)
        {
            cout << "Please enter credit card number now (in the form XXXX XXXX XXXX XXXX): ";
            cin >>  CCnum;

            if (cin) {
                cin.clear();
                std::string ignoreLine; //read the invalid input into it
                std::getline(cin, ignoreLine); //read the line till next space
            }

            cout << endl;
            char delimit = ' ';
            if (CCnum.find(delimit) == ' ') {
                cout << "Invalid credit card number" << endl;
            } else {
                string bankA;
                cout << "BANK: Approve this card? (y or no): ";
                cin >>  bankA;
                cout << endl;
                if (bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y") {
                    int CCnums[4];
                    size_t pos;
                    string delimiter = " ";
                    int i = 0;
                    while ((pos = CCnum.find(delimiter)) != std::string::npos) {
                        CCnums[i] = std::stoi(CCnum.substr(0, pos));
                        CCnum.erase(0, pos + delimiter.length());
                        i++;
                    }
                    C1.getCC().setCCnum(CCnums[0], CCnums[1], CCnums[2], CCnums[3]);
                    if (cin) {
                        cin.clear();
                        std::string ignoreLine; //read the invalid input into it
                        std::getline(cin, ignoreLine); //read the line till next space
                    }
                    cout << "The customer has $" << C1.getBalance()
                         << " in their account, is this transaction approved (y or n)?: ";
                    cin >> bankA;
                    cout << endl;
                    if (bankA == "yes" || bankA == "Yes" || bankA == "y" || bankA == "Y") {
                        displayConfirmation(C1);
                    } else {
                        approvalDenied();
                    }
                    break;
                } else {
                    approvalDenied();
                }
            }
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
}

/*
 * Function : displayConfirmation()
 * Arguments : Customer C1, input of object of Customer class type
 * Return : Void
 * Functionality : System confirms approval of purchase and displays order information to customer.
 */
void displayConfirmation(Customer C1) {
    cout << "ORDER CONFIRMATION DETAILS:" << endl;
    cout << "Thank you for your order " << C1.getName() << "!" << endl;
    cout << "Order confirmation number: " << rand() % 1000 << endl;
    if (C1.getAddress() == "")
    {
        cout << "Order will be sent to: Austin, Texas; Zip: " << C1.getCC().getZip() << endl;
    }
    else
    {
        cout << "Order will be sent to: " << C1.getAddress() << "; Zip: " << C1.getCC().getZip() << endl;
    }
    cout << "Order will be charged to credit card with number: " << C1.getCC().getCCnum() << endl;
    C1.setBalance(C1.getBalance() - 20000000);
    cout << "New account balance is: $" << C1.getBalance() << endl;
    if(C1.getBalance() < 0)
    {
        cout << "Bummer! You are seriously in debt for the rest of your sorry life!" << endl;
    }
}

/*
* Function : approvalDenied()
* Arguments : None
* Return : Void
* Functionality : If authorization of the customer’s credit card is denied (e.g., invalid
                  credit card or insufficient funds in the customer’s credit card account), the
                  system prompts the customer to enter a different credit card number. The
                  customer can either enter a different credit card number or cancel the order.
*/
void approvalDenied()
{
    while(true)
    {
        string CCnum;
        cout << "Invalid credit necessary: APPROVAL DENIED" << endl;
        cout << "Enter new Credit Card number (XXXX XXXX XXXX XXXX) (n to cancel): ";
        cin >> CCnum;
        cout << endl;
        char delimit = ' ';
        if(CCnum.find(delimit) == ' ')
        {
            cout << "Invalid credit card number" << endl;
        }
        else if (CCnum == "NO" || CCnum == "no" || CCnum == "n" || CCnum == "N")
        {
            break;
        }
        else
        {
            string bankA;
            cout << "BANK: Approve this card? (y or n): ";
            cin >>  bankA;
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
    cout << endl;
    cout << "Thank you for using the OSS! Goodbye!";
}

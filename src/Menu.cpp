//
// Created by arsga on 9/10/2017.
//

#include "Menu.h"
#include "Customer.h"

bool Select = false;
int productID = 0;


using namespace std;

/*
 * Function : MainLoop()
 * Arguments : None
 * Return : Void
 * Functionality : to provide the main loop for the main menu
 */

void MainLoop()
{
    while(Select != true)
    {
        cout << "Item 1: Fag Shoes" << endl;
        cout << "Item 2: Fag Shirt" << endl;
        cout << "Item 3: Fag Socks" << endl;
        cout << "Item 4: Fag Pants" << endl;
        cout << "Item 5: Fag Underwear" << endl;
        cout << "Item 6: Fag Hat" << endl;
        cout << "Item 7: Rusty Dagger (LEVEL 7)" << endl;
        char selectArray[] = "1234567";
        char Selection;
        bool done = true;
        while (done){
            cin >> Selection;
            cout << endl;
            bool errChk = true;
            for(int i; i < (sizeof(selectArray)/sizeof(selectArray)); i++)
            {
                if(Selection == selectArray[i])
                {
                    errChk = false;
                    break;
                }
            }
            if(cin.fail() || errChk )
            {
                cout << "We didn't understand that, please re-enter your selection" << endl;
            }
            else
            {
                done = false;
            }
        }
        switch(Selection)
        {
            case '1' :
                cout << "You want to buy Fag Shoes" << endl;
                Select = true;
                break;
            case '2' :
                cout << "You want to buy a Fag Shirt" << endl;
                Select = true;
                break;
            case '3' :
                cout << "You want to buy Fag Socks" << endl;
                Select = true;
                break;
            case '4' :
                cout << "You want to buy Fag Pants" << endl;
                Select = true;
                break;
            case '5' :
                cout << "You want to buy Fag Underwear" << endl;
                Select = true;
                break;
            case '6' :
                cout << "You want to buy a Fag Hat" << endl;
                Select = true;
                break;
            case '7' :
                cout << "You want to buy a rusty dagger (LEVEL 7) " << endl;
                Select = true;
                break;
            default:
                cout << "Error" << endl;
                //go to error handling
                break;
        }
    }
}

/*
 * Function : MainMenu()
 * Arguments : None
 * Return : Void
 * Functionality : to provide the main menu to the user through the Terminal application so
 *                 that they can interact with the program.
 */

void MainMenu()
{
    cout << "Welcome to the menu" << endl;
    MainLoop();
}
//
// Created by arsga on 9/10/2017.
//

#include "Product.h"

using namespace std;
string nameArray[] = {"Kershaw Knife", "Beretta 9mm", "M1A1 Abrams Tank", "100 Gallon Gas Tank (GAS INCLUDED)", "200x9mm Rounds", "Tesla Model 7"};
int priceArray[] = {30, 500, 20000000, 500, 46, 80000};

Product::Product()
{
    int ranNum = rand() % (sizeof(nameArray)/sizeof(*nameArray));
    Product::name = nameArray[ranNum];
    Product::code = rand() % 89999 + 10000;
    Product::price = priceArray[ranNum];
}

Product::Product(string name, int code, int price)
{
    Product::name = name;
    Product::code = code;
    Product::price = price;
}

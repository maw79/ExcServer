//
// Created by arsga on 9/10/2017.
//

#ifndef EXCSERVER_PRODUCT_H
#define EXCSERVER_PRODUCT_H

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Product{

private:
    string name;
    int code;
    int price;

public:
    Product();
    Product(string name, int code, int price);

    string getName(){return name;}
    int getCode(){return code;}
    int getPrice(){return price;}
};

#endif //EXCSERVER_PRODUCT_H

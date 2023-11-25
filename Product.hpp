#pragma once
#include "IProduct.h"

class Product: public IProduct{
    int id;
    std::string description;
    double ratings;
    public:

    Product(int id, std::string description);
    std::string getDescription();

};
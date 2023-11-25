#include "Product.hpp"

Product::Product(int id, std::string description){
    this->id = id;
    this->description = description;
}

std::string Product::getDescription(){
    return description;
}


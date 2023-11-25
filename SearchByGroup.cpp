#include "SearchByGroup.hpp"

std::vector<Product*> SearchByGroup::searchProduct(std::string groupName){
    std::vector<Product*> productList;
    Inventory::getInstance()->findProducts(groupName, productList);
    return productList;
}

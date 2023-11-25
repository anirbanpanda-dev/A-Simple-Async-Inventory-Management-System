#pragma once

#include "Common.h"
#include "ProductGroup.hpp"

class Inventory{
    std::map<std::string, ProductGroup*> ProductGategoryList;
    static Inventory* m_Inventory;
    Inventory();
    public:
    static Inventory* getInstance();
    void addProduct(std::string product, std::string group, int count);
    bool isProductAvailable(Product* product, ProductGroup* group);
    bool isGroupPresent(std::string groupName);
    void findProducts(std::string groupName, std::vector<Product*>& productList);
    void reduceProduct(std::string groupName, std::string prodcutName);
};
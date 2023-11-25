#pragma once
#include "Common.h"
#include "Product.hpp"

class ProductGroup{
    std::map<std::string, std::pair<Product*, int>> productList;
    std::string GroupName;
    public: 
    ProductGroup(std::string name);
    bool isProductAvailable(Product* product);
    void addProduct(std::string product, int count);
    void findProducts(std::vector<Product*>& result);
    void reduceProduct(std::string productName);

};
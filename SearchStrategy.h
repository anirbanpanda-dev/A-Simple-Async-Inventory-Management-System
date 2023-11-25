#pragma once

#include "ProductGroup.hpp"
#include "InventoryService.hpp"

class SearchStrategy{
    public: 

    virtual std::vector<Product*> searchProduct(std::string name) = 0;
};
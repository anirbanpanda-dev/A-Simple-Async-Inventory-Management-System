#pragma once

#include "Common.h"
#include "Product.hpp"
#include "SearchStrategy.h"
#include "SearchByGroup.hpp"

class SearchService{
    SearchStrategy* searchStrategy;
    public:
    SearchService();
    std::vector<Product*> searchProduct(std::string name);
};
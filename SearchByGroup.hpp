#pragma once

#include "SearchStrategy.h"
#include "InventoryService.hpp"

class SearchByGroup : public SearchStrategy {
    public:
    std::vector<Product*> searchProduct(std::string name) override;
};

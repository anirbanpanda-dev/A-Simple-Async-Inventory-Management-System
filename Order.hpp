#pragma once

#include "Common.h"
#include "InventoryService.hpp"

class Order{
    int OrderID;
    int startingTime;
    OrderStatus status;
    Product* product;
    ProductGroup* group;
    public:
    Order(std::string productName, std::string GroupName);
    void setStatus(OrderStatus status);
    OrderStatus getStatus();
};
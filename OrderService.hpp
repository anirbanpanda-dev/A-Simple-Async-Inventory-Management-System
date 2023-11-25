#pragma once

#include "Common.h"
// #include "OrderHandler.hpp"
#include "OrderQueue.hpp"

class OrderService{
    static std::mutex orderServiceMtx;
    static OrderService* m_OrderService;
    std::vector<std::thread> handlerList;
    std::mutex inventoryMtx;
    OrderService();
    public: 
    static OrderService* getInstance();
    void CreateOrder(std::string GroupName, std::string ProductName);
};
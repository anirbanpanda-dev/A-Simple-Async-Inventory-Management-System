#pragma once

#include "Common.h"
#include "Order.hpp"
// #include "OrderHandler.hpp"

class OrderQueue{
    std::queue<Order*> orderQueue;
    std::vector<std::thread> executor;
    static OrderQueue* m_queue;
    static std::mutex q_Mtx;
    std::mutex orderMutex;
    std::condition_variable cond_var;
    OrderQueue();
    void run();
    public:
    static OrderQueue* getInstance();
    void PushToQueue(Order* order);

};
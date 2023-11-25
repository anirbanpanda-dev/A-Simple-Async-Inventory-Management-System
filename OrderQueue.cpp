#include "OrderQueue.hpp"

OrderQueue* OrderQueue::m_queue = NULL;
std::mutex OrderQueue::q_Mtx;

OrderQueue::OrderQueue(){
    for(int i = 0; i<MAX_THREADS_ORDER; i++){
        executor.emplace_back([this](){
            while(true){
                std::unique_lock<std::mutex> lck(orderMutex);
                cond_var.wait(lck, [&](){
                    return orderQueue.size()!=0;
                });
                Order* order = orderQueue.front();
                orderQueue.pop();
                std::cout << " Order ID = " << std::endl;
                order->setStatus(OrderStatus::COMPLETED);

            }
        });
    }
}

void OrderQueue::run(){
    while(true){
        std::unique_lock<std::mutex> lck(orderMutex);
        cond_var.wait(lck, [&](){
            return orderQueue.size()!=0;
        });
        Order* order = orderQueue.front();
        orderQueue.pop();
        std::cout << " Order ID = " << std::endl;
        order->setStatus(OrderStatus::COMPLETED);

    }
}

OrderQueue* OrderQueue::getInstance(){
    if(!m_queue){
        q_Mtx.lock();
        if(!m_queue){
            m_queue = new OrderQueue();
        }
        q_Mtx.unlock();
    }
    return m_queue;
}

void OrderQueue::PushToQueue(Order* order){
    orderQueue.push(order);
    cond_var.notify_all();
}
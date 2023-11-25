#include "OrderService.hpp"

OrderService* OrderService::m_OrderService = NULL;
std::mutex OrderService::orderServiceMtx;

OrderService::OrderService(){

}

OrderService* OrderService::getInstance(){
    if(!m_OrderService){
        orderServiceMtx.lock();
        if(!m_OrderService){
            m_OrderService = new OrderService();
        }
        orderServiceMtx.unlock();
    }
    return m_OrderService;

}


void OrderService::CreateOrder(std::string GroupName, std::string ProductName){
    Order* order = new Order(GroupName, ProductName);
    OrderQueue::getInstance()->PushToQueue(order);
    inventoryMtx.lock();
    Inventory::getInstance()->reduceProduct(GroupName, ProductName);
    //PaymentManager::processPayment()
    inventoryMtx.unlock();
    order->setStatus(OrderStatus::QUEUED);
}
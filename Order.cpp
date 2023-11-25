#include "Order.hpp"

Order::Order(std::string productName, std::string GroupName){
    // product = Inventory::getInstance()->
    this->status = OrderStatus::CREATED;
}

void Order::setStatus(OrderStatus status){
    this->status = status;
}

OrderStatus Order::getStatus(){
    return status;
}
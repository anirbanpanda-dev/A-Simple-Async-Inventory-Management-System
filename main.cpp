#include "Common.h"
#include "InventoryService.hpp"
#include "SearchService.hpp"
#include "OrderService.hpp"



int main(){
    Inventory::getInstance()->addProduct("Shoes", "Wearables", 1);
    Inventory::getInstance()->addProduct("TShirts", "Wearables", 2);
    Inventory::getInstance()->addProduct("BoatEarPhone", "Gadgets", 1);
    
    SearchService* m_searchService = new SearchService();
    std::vector<Product*> searchList = m_searchService->searchProduct("Wearables");
    for(auto it : searchList){
        std::cout << it->getDescription() << std::endl;
    }
    OrderService::getInstance()->CreateOrder("Wearables", "Shoes");
}
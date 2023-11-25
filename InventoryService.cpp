#include "InventoryService.hpp"

Inventory* Inventory::m_Inventory = NULL;

Inventory::Inventory(){}
    
Inventory* Inventory::getInstance(){
    if(!m_Inventory){
        m_Inventory = new Inventory();
    }
    return m_Inventory;
}
void Inventory::addProduct(std::string product, std::string group, int count){
    if(ProductGategoryList.find(group)==ProductGategoryList.end()){
        ProductGategoryList[group] = new ProductGroup(group);
    }
    ProductGategoryList[group]->addProduct(product, count);
}

bool Inventory::isProductAvailable(Product* product, ProductGroup* group){
    return false;
}

bool Inventory::isGroupPresent(std::string groupName){
    std::cout << " group size = " << ProductGategoryList.size() << std::endl;
    return (ProductGategoryList.find(groupName)!= ProductGategoryList.end());
}

void Inventory::findProducts(std::string groupName, std::vector<Product*>& productList){
    if(ProductGategoryList.find(groupName)== ProductGategoryList.end()){
        std::cout << "Group Not Present\n";
        return;
    }
    
    ProductGategoryList[groupName]->findProducts(productList);
}

void Inventory::reduceProduct(std::string groupName, std::string productName){
    if(!isGroupPresent(groupName)){
        throw "Error";
    }
    ProductGategoryList[groupName]->reduceProduct(productName);
}

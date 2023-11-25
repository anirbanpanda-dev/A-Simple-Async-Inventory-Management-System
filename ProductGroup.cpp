#include "ProductGroup.hpp"

ProductGroup::ProductGroup(std::string name){

}
bool ProductGroup::isProductAvailable(Product* product){

}
void ProductGroup::addProduct(std::string product, int count){
    if(productList.find(product)== productList.end()){
        productList[product] = {new Product(1, product), 0};
    }
    productList[product].second += count;
}

void ProductGroup::findProducts(std::vector<Product*>& result){
    for(auto product : productList){
        result.push_back(product.second.first);
    }
}

void ProductGroup::reduceProduct(std::string productName){
    if(productList.find(productName)==productList.end()){
        throw "Error";
    }
    productList[productName].second -= 1;
}
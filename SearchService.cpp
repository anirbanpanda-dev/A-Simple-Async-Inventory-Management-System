#include "SearchService.hpp"

SearchService::SearchService(){
    searchStrategy = new SearchByGroup();
}
std::vector<Product*> SearchService::searchProduct(std::string name){
    return searchStrategy->searchProduct(name);
}
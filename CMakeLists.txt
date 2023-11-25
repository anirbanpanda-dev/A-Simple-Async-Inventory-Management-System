
cmake_minimum_required(VERSION 3.12)
project(InventoryMgmt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InventoryMgmt 
                main.cpp 
                InventoryService.cpp 
                Order.cpp 
                OrderQueue.cpp 
                OrderService.cpp
                Product.cpp 
                ProductGroup.cpp
                SearchByGroup.cpp
                SearchService.cpp 
                )
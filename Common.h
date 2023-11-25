#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <thread>
#include<queue>


#define WAIT_PERIOD 60
#define MAX_THREADS_ORDER 2

enum class OrderStatus{
    ERROR,
    CREATED, 
    QUEUED,
    COMPLETED,
    CANCELLED
};
//
// Created by bazylip on 18.04.18.
//

#include "ArrayFill.h"
#include "iostream"
#include "memory"

int main(void){
    std::vector<int> vs;
    auto generator = std::make_unique<std:: default_random_engine>();
    auto distribution = std::make_unique<std::uniform_int_distribution<int>>(1,6);
    FillArray(1024, RandomFill {move(generator), move(distribution)}, &vs);
    for(auto el : vs){
        std::cout<<el<<" ";
    }
    return 0;
}

//
// Created by bazylip on 23.05.18.
//

#include "FactoryMethod.h"
#include "iostream"
#include "memory"

using std::cout;
using std::endl;
using std::vector;
using ::factoryMethod::Value;
using ::factoryMethod::Add;
using ::factoryMethod::Mean;

int main(void){

    vector<int> v{1,2,3,4,5,6};

    int test = 1;

    std::unique_ptr<int> ptr = std::make_unique<int>(test);

    vector<int>::iterator it = v.begin()+2;
//
//    int number = Value(it);
//    std::string sum = Add<std::string, std::string>("ab", "cd");

    cout<<Value(ptr)<<endl<<Add<std::string, std::string>("ab", "cd")<<endl<<Mean(v);

    return 0;
}


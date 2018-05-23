//
// Created by bazylip on 23.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include "vector"
#include "string"
#include "numeric"

namespace factoryMethod{
    template<class T>
    T Create(){
        return T();
    }

    class MyType{
    public:
        MyType() = default;
        inline std::string SayHello() {return "hello";}
    };

    template<class First, class Second>
    auto Add(First first, Second second) {
        return first+second;
    }

    template<class Pointer>
    auto Value(const Pointer ptr) {
        return *ptr;
    }

    template<class T>
    auto Mean(const std::vector<T> &v){
        return std::accumulate( v.begin(), v.end(), 0.0)/v.size();
    }
};




#endif //JIMP_EXERCISES_FACTORYMETHOD_H

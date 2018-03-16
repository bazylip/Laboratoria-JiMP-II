//
// Created by bazylip on 14.03.18.
//

#include "iostream"
#include "vector"
#include "GreatestProduct.h"

using namespace std;

int main(void){

    vector<int> v = {17, 5, 9, 1000, 15689, 57, 89, 10, 89, 283, 197, 0, 0, 132, 45, 78, 18, 15, 89,
                     19203, 98, 14, 78, 45, 35, 23, 24, 25, 46, 45, 756, 7567, 123, 890, 99, 98, 51,
                     991, 9123, 8912, 89534, 8923, 1823, 7385, 91, 1748, 1, 1, 893, 2813,
                     1381, 23, 563, 645, 24, 24, 51, 839, 38, 34, 35, 123, 324, 9283, 22, 19};

    cout<<GreatestProduct(v, 2);

    return 0;
}
//
// Created by bazylip on 14.03.18.
//

#include "iostream"
#include "vector"
#include "GreatestProduct.h"

using namespace std;

int main(void){

    vector<int> v = {3,4,5,6,0,8,9};

    cout<<GreatestProduct(v, 4);

    return 0;
}
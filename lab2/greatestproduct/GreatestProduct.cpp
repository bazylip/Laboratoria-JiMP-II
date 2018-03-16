//
// Created by bazylip on 14.03.18.
//

#include "GreatestProduct.h"
#include "vector"
#include "algorithm"

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k){

    vector<int> tmp;

    for(int i : numbers){

        if(tmp.size() < k){

            if(tmp.size() == 0){
                tmp.push_back(i);
            }else{
                int pos = 0;
                while(tmp[pos] > i){
                    pos++;
                }
                vector<int>::iterator it;
                it = tmp.begin();
                tmp.insert(it + pos, i);
            }

        }else{
            int pos = 0;
            while(tmp[pos] > i){
                pos++;
            }
            vector<int>::iterator it;
            it = tmp.begin();
            tmp.insert(it + pos, i);
            tmp.pop_back();
        }

    }

    int result = 1;

    for(int i : tmp){
        result *= i;
    }

    return result;
}
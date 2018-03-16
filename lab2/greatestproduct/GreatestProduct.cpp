//
// Created by bazylip on 14.03.18.
//

#include "GreatestProduct.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k){

    vector<int> newNumbers(numbers);
    int result = 1;
    sort(newNumbers.begin(), newNumbers.end());

    if(k % 2 == 1 && newNumbers.end()[-1] <= 0){
        for(int i = newNumbers.size(); i > newNumbers.size() - k; --i){
            result *= newNumbers[i-1];
        }
    }else {

        while (k > 1) {

            bool which = newNumbers.end()[-1] * newNumbers.end()[-2] > newNumbers[0] * newNumbers[1];

            if (which) {
                result *= newNumbers.end()[-1] * newNumbers.end()[-2];
                newNumbers.erase(newNumbers.end(), newNumbers.end()-2);
            } else {
                result *= newNumbers[0] * newNumbers[1];
                newNumbers.erase(newNumbers.begin(), newNumbers.begin() + 2);
            }

            k -= 2;
        }

        if (k == 1)
            result *= max(newNumbers.end()[-1], newNumbers[0]);
    }
    return result;

}
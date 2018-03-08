//
// Created by bazylip on 08.03.18.
//

#include "string"
#include "DoubleBasePalindromes.h"
#include "iostream"
#include "cstdint"

using namespace std;

string convert(int number){
    string output = "";
    while(number > 0){
        if(number % 2 == 1) {
            string c = "1";
            output.insert(0, c);
        }
        else{
            string c = "0";
            output.insert(0, c);
        }
        number /= 2;
    }
    return output;
}

bool checkPalindrome(string str){
    while(str.size() > 1){
        char first = str.at(0), last = str.at(str.size() - 1);
        if(first != last)
            return false;
        else{
            str.erase(0,1);
            str.erase(str.size()-1, 1);
        }
    }

    return true;
}

uint64_t DoubleBasePalindromes(int max_value_exculsive){
    uint64_t sum = 0;

    for(int i = 1; i <= max_value_exculsive; ++i){
        string s = to_string(i);
        if(checkPalindrome(s) && checkPalindrome(convert(i)))
            sum += i;
    }

    return sum;
}
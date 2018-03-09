//
// Created by bazylip on 08.03.18.
//

#include "string"
#include "DoubleBasePalindromes.h"
#include "Palindrome.h"
#include "iostream"
#include "cstdint"

using namespace std;

string Convert(int number){
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

uint64_t DoubleBasePalindromes(int max_value_exculsive){
    uint64_t sum = 0;

    for(int i = 1; i <= max_value_exculsive; ++i){
        string s = to_string(i);
        if(IsPalindrome(s) && IsPalindrome(Convert(i)))
            sum += i;
    }

    return sum;
}
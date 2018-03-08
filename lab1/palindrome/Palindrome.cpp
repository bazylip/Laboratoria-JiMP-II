//
// Created by bazylip on 08.03.18.
//

#include "Palindrome.h"
#include "string"

using namespace std;

bool is_palindrome(string str){
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
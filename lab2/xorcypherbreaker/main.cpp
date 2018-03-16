//
// Created by bazylip on 16.03.18.
//

#include "XorCypherBreaker.h"

int main(void){
    std::string zaszyfrowany = "3b1e0f1a11070d110c0d12181008091f";
    std::vector<char> znaki;
    std::vector<std::string> klucz = {"123","tekst","klucz", "test"};

    for(auto ch : zaszyfrowany){
        znaki.push_back(ch);
    }

    XorCypherBreaker(znaki, 5, klucz);

    return 0;
}

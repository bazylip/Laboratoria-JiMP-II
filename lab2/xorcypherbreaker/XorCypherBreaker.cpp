//
// Created by bazylip on 16.03.18.
//

#include "string"
#include "vector"
#include "iostream"

#include "XorCypherBreaker.h"

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                      int key_length,
                      const std::vector<std::string> &dictionary){

    for(auto word : dictionary){

        std::string output = "";
        int i = 0;
        for(auto ch : cryptogram){

            int ChDecrypted = (int)ch ^ (int)word[i];
            i++;
            if(i > key_length)
                i = 0;

            char ChChar = ChDecrypted;
            output += ChChar;

        }

        std::cout<<"i: "<<i<<" output: "<<output<<std::endl;

    }

    return "";

}

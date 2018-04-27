//
// Created by bazylip on 25.04.18.
//

#include "Pesel.h"

using std::string;
using std::regex;

academia::Pesel::Pesel(const string &str){
    ValidatePesel(str);
    Pesel_ = str;
}

void academia::Pesel::ValidatePesel(const string &str) {
    regex pattern{R"(^\d{11}$)"};
    std::smatch s;
    if(str.length() != 11){
        throw InvalidPeselLength(str, str.length());
    }else if(!std::regex_match(str, s, pattern)){
        throw InvalidPeselCharacter(str);
    }else{
        int i = CheckSum(str);
        if(i%10 != 0) {
            throw InvalidPeselChecksum(str, i);
        }
    }
}

int academia::Pesel::CheckSum(const std::string &str) {
    int sum = (str[0]-48) + (str[1]-48)*3 + (str[2]-48)*7 + (str[3]-48)*9 + (str[4]-48) + (str[5]-48)*3 + (str[6]-48)*7 + (str[7]-48)*9 + (str[8]-48) + (str[9]-48)*3 + (str[10]-48);
    return sum;
}

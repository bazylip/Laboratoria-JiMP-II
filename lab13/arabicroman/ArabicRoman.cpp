//
// Created by bazylip on 06.06.18.
//

#include "ArabicRoman.h"

using std::vector;

#include "iostream"

std::string ArabicToRoman(int i){
    if(i < 1){
        throw std::invalid_argument("Number too small!");
    }else if(i > 3999){
        throw std::invalid_argument("Number too big!");
    }

    vector<std::pair<int, std::string>> numbers = {{1000, "M"}, {900, "CM"},
                                        {500, "D"}, {400, "CD"},
                                        {100, "C"}, { 90, "XC"},
                                        { 50, "L"}, { 40, "XL"},
                                        { 10, "X"}, { 9, "IX"},
                                        { 5, "V"}, { 4, "IV"},
                                        { 1, "I"}, {0, "0"}};

    std::string result;
    int j = 0;
    for (std::pair<int, std::string> current = numbers[j]; current.first > 0; current = numbers[j++])
    {
        while (i >= current.first)
        {
            result += current.second;
            i -= current.first;
        }
    }

    return result;
}

int RomanToArabic(std::string roman){
    return 1;
}
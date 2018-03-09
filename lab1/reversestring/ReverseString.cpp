//
// Created by polebazy on 02.03.18.
//

#include "ReverseString.h"
#include "string"

using namespace std;

string Reverse(string str){
    if(str.size() == 1)
        return str;
    else if(str.size() == 0)
        return "";
    else {
        char buf = str[0];
        str.erase(0, 1);
        str = Reverse(str);
        str.push_back(buf);
        return str;
    }
}

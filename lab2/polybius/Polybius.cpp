//
// Created by bazylip on 13.03.18.
//

#include "Polybius.h"
#include "string"
#include "iostream"

using namespace std;

string PolybiusCrypt(string message){

    string output = "";

    for(int i = 0; i < message.length(); ++i) {
        if(message[i] != ' '){
            if(message[i] > 90) {
                message[i] -= 32;
            }
            int tmp = message[i] - 'A';
            if (message[i] > 'I')
                tmp--;
            int first = tmp / 5 + 1;
            int second = tmp % 5 + 1;
            output.append(to_string(first));
            output.append(to_string(second));
        }

    }

    return output;

}

string PolybiusDecrypt(string message){

    string output = "";

    for(int i = 0; i < message.length(); i += 2){
        if(message[i] == ' '){
            output += ' ';
            i--;
            continue;
        }
        int first = message[i] - 48;
        int second = message[i+1] - 48;
        int cords = first*10 + second;
        first = cords % 10 - 1;
        second = cords / 10 - 1;
        cords = second * 5 + first + 'A';
        if( cords > 'I' ){
            cords++;
        }
        char NewChar = char(cords) + 32;
        output += NewChar;
    }

    return output;
}

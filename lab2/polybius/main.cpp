//
// Created by bazylip on 13.03.18.
//

#include "string"
#include "iostream"
#include "Polybius.h"
#include "fstream"

using namespace std;

int main(int argc, char const *argv[]){

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    char line[256];

    if(!infile){
        cout<<"Blad otwarcia!"<<endl;
    }

    infile.getline(line, 256);

    string str(line);

    if(argv[3] == "1"){
        PolybiusCrypt(str);
    }else{
        PolybiusDecrypt(str);
    }

    cout<<PolybiusCrypt("abcdef")<<endl;
    cout<<PolybiusDecrypt("111213141521 1245 32")<<endl;

}
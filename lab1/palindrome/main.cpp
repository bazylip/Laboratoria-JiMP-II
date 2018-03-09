//
// Created by bazylip on 08.03.18.
//

#include "iostream"
#include "Palindrome.h"

using namespace std;

int main(void){
    while(1){
        cout<<"Wybierz:"<<endl<<"1 - sprawdz palindrom"<<endl<<"2 - wyjdz"<<endl<<endl;
        int choice;
        cin>>choice;
        if(choice == 2)
            return 0;
        else{
            cout<<"Podaj napis: ";
            string s;
            cin>>s;
            if(is_palindrome(s))
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
    }
}


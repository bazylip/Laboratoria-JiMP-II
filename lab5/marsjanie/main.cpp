//
// Created by bazylip on 06.04.18.
//

#include "Marsjanie.h"

using std::list;
using std::move;

int main(void){
    list<Marsjanin> lista;

    for(int i = 0; i < 30; ++i){
        lista.emplace_back("Imie");
        std::cout<<lista.size()<<std::endl;
        if(lista.front().Atakuj()){
            while(lista.size() > 2){
                lista.pop_back();
            }
        }
    }

    return 0;
}


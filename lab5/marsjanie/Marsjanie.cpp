//
// Created by bazylip on 06.04.18.
//

#include "Marsjanie.h"

int Marsjanin::liczbaMarsjan = 0;

Marsjanin::Marsjanin(std::string imie) {
    Marsjanin::liczbaMarsjan ++;
    imie_ = imie;
}

Marsjanin::~Marsjanin() {
    Marsjanin::liczbaMarsjan --;
}

bool Marsjanin::Atakuj() {
    return(liczbaMarsjan > 5);
}

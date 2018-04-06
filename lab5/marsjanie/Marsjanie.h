//
// Created by bazylip on 06.04.18.
//

#ifndef JIMP_EXERCISES_MARSJANIE_H
#define JIMP_EXERCISES_MARSJANIE_H

#include "iostream"
#include "list"
#include "string"

class Marsjanin {
public:
    Marsjanin(std::string imie);
    ~Marsjanin();
    bool Atakuj();
    static int liczbaMarsjan;
private:
    std::string imie_;
};


#endif //JIMP_EXERCISES_MARSJANIE_H

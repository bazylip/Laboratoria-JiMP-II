//
// Created by bazylip on 06.04.18.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H

#include <string>
#include <cstring>
#include <algorithm>
using ::std::swap;
using ::std::string;

class XXX {
public:
    //w zeszłym odcinku:
    //domyślny konstruktor
    XXX();
    //konstruktory parametryczne
    XXX(int param);
    XXX(const std::string name);

    //Rule of five://
    //1. konstruktor kopiujący
    XXX(const XXX &xxx);
    //2. konstruktor przenoszący
    XXX(XXX &&xxx);
    //3. operator przypisania kopiujący
    XXX &operator=(const XXX &xxx);
    //4. operator przypisania przenoszący
    XXX &operator=(XXX &&xxx);
    //5. Destruktor
    ~XXX();

private:
    char *name_;
};

class Child{

public:
    Child();
    Child(string name, string surname, int age, string school);
    ~Child() = default;
    friend class Parent;

private:
    string name_;
    string surname_;
    int age_;
    string school_;
};

class Parent{
public:
    Parent();
    Parent(string name, string surname, int age, Child child);
    ~Parent() = default;
    void PrzepiszDoInnejSzkoly(string NewSchool_);

private:
    string name_;
    string surname_;
    int age_;
    Child child_;
};


#endif //JIMP_EXERCISES_XXX_H

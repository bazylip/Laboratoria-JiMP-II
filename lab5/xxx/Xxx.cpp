//
// Created by bazylip on 06.04.18.
//

#include "Xxx.h"

XXX::XXX() : name_{new char[1024]} {

}

XXX::~XXX() {
    delete [] name_;
}

XXX::XXX(const XXX& xxx) {
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}


XXX & XXX::operator=(const XXX& xxx) {
    if (this == &xxx) {
        return *this;
    }
    delete[] name_;
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}

XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_,xxx.name_);
}

XXX & XXX::operator=(XXX &&xxx) {
    if (this == &xxx) {
        return xxx;
    }
    delete[] name_;
    name_ = nullptr;
    swap(name_,xxx.name_);
}

Child::Child() {
    name_ = "";
    surname_ = "";
    age_ = 0;
    school_ = "";
}

Child::Child(string name, string surname, int age, string school) {
    name_ = name;
    surname_ = surname;
    age_ = age;
    school_ = school;
}

Parent::Parent() {
    name_ = "";
    surname_ = "";
    age_ = 0;
    child_ = Child();
}

Parent::Parent(string name, string surname, int age, Child child) {
    name_ = name;
    surname_ = surname;
    age_ = age;
    child_ = child;
}

void Parent::PrzepiszDoInnejSzkoly(string NewSchool_) {
    child_.school_ = NewSchool_;
}
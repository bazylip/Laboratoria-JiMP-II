//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <ostream>
#include "Point.h"
#include "iostream"

using ::std::ostream;
using ::std::cout;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y){
//    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    cout << endl;
}

double Point::GetX() const {
    return this->x_;
}

double Point::GetY() const {
    return this->y_;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(this->GetX()-other.GetX(),2)+pow(this->GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

Square::Square(Point p1, Point p2, Point p3, Point p4){
    p1_ = p1;
    p2_ = p2;
    p3_ = p3;
    p4_ = p4;
}

double Square::Circumference() {

    double Distance1 = this->p1_.Distance(p2_);
    double Distance2 = this->p2_.Distance(p3_);
    double Distance3 = this->p3_.Distance(p4_);
    double Distance4 = this->p4_.Distance(p1_);

    return Distance1+Distance2+Distance3+Distance4;
}

double Square::Area() {

    double Distance1 = this->p1_.Distance(p2_);
    double Distance2 = this->p2_.Distance(p3_);

    return Distance1*Distance2;
}
//
// Created by bazylip on 01.04.18.
//

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include "Point.h"

using namespace std;

int main(void){
    Point p1(0,0);
    Point p2(2,0);
    Point p3(2,2);
    Point p4(0,2);

    Square s1(p1,p2,p3,p4);

    cout<<endl<<s1.Circumference()<<endl<<s1.Area()<<endl;

}
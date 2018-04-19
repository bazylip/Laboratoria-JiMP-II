//
// Created by bazylip on 13.04.18.
//

#include "Student.h"
#include "iostream"
int main(){
    StudyYear sy(2001);
    sy++;
    std::cout<<sy.GetYear()<<std::endl;


    return 0;
}
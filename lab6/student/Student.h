//
// Created by bazylip on 13.04.18.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "string"

class StudyYear{
public:
    StudyYear(int year);
    StudyYear &operator++(int i);
    StudyYear &operator--(int i);
    int GetYear();
private:
    int year_;
};

class Student {


private:
    std::string id_;
    std::string FirstName_;
    std::string LastName_;
    std::string Program_;
    StudyYear Year_;
};




#endif //JIMP_EXERCISES_STUDENT_H

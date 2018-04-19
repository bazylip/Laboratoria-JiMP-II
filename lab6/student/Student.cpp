//
// Created by bazylip on 13.04.18.
//

#include "Student.h"

StudyYear::StudyYear(int year) {
    year_ = year;
}

StudyYear& StudyYear::operator++(int i) {
    year_++;
    return *this;
}

StudyYear& StudyYear::operator--(int i) {
    year_--;
    return *this;
}

int StudyYear::GetYear() {
    return year_;
}
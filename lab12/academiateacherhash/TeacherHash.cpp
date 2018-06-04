//
// Created by bazylip on 04.06.18.
//

#include "TeacherHash.h"


std::size_t academia::TeacherHash::operator()(const Teacher &teacher) const {
    return std::hash<int>()(teacher.Id()) ^ std::hash<std::string>()(teacher.Name()) ^ std::hash<std::string>()(teacher.Department());
}

bool academia::Teacher::operator!=(const Teacher &rhs) const {return (this->Id_ != rhs.Id_ or this->Name_ != rhs.Name_ or this->Department_ != rhs.Department_);}

bool academia::Teacher::operator==(const Teacher &rhs) const {return (this->Id_ == rhs.Id_ && this->Name_ == rhs.Name_ && this->Department_ == rhs.Department_);}
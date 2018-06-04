//
// Created by bazylip on 04.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include "string"
#include "functional"

namespace academia {
    class Teacher {
    public:
        Teacher(int id, std::string name, std::string dep): Id_{id}, Name_{name}, Department_{dep}{}
        inline int Id() const {return Id_;}
        inline std::string Name() const {return Name_;}
        inline std::string Department() const { return Department_;}
        bool operator==(const Teacher &rhs) const;
        bool operator!=(const Teacher &rhs) const;

    private:
        int Id_;
        std::string Name_;
        std::string Department_;
    };

    class TeacherId{
    public:
        TeacherId(int value): Id_{value}{}

        operator int() const{
            return Id_;
        }

    private:
        int Id_;
    };

    class TeacherHash{
    public:
        std::size_t operator()(const Teacher &teacher) const;
    };


}


#endif //JIMP_EXERCISES_TEACHERHASH_H

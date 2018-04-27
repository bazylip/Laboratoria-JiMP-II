//
// Created by bazylip on 25.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include "string"
#include "regex"
#include "stdexcept"

namespace academia {
    class Pesel {
    public:
        Pesel(const std::string &str);
        void ValidatePesel(const std::string &str);

    private:
        std::string Pesel_;
        int CheckSum(const std::string &str);
    };

    class InvalidPeselChecksum : public std::invalid_argument {
    public:
        InvalidPeselChecksum(const std::string &str, int checksum) : invalid_argument{"Invalid PESEL("+str+") checksum: "+std::to_string(checksum)}, Pesel_{str}{}

    private:
        std::string Pesel_;
        int checksum_;
    };

    class InvalidPeselLength : public std::invalid_argument {
    public:
        InvalidPeselLength(const std::string &str, int length) : invalid_argument{"Invalid PESEL("+str+") length: "+std::to_string(length)}, Pesel_{str}{}

    private:
        std::string Pesel_;
        int length_;
    };



    class AcademiaDataValidationError : public std::invalid_argument {
    public:
        AcademiaDataValidationError(const std::string &str) : invalid_argument{"Invalid PESEL("+str+") character set"}{}

    };

    class InvalidPeselCharacter : public academia::AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(const std::string &str) : AcademiaDataValidationError{"Invalid PESEL("+str+") character set"}, Pesel_{str}{}

    private:
        std::string Pesel_;
};
}


#endif //JIMP_EXERCISES_PESEL_H

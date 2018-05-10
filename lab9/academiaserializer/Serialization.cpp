//
// Created by bazylip on 09.05.18.
//

#include "Serialization.h"

namespace academia{

    std::string Room::EnumToString(Type EnumType) const {
        switch(EnumType){
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }
}

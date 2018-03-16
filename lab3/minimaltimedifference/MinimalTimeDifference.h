//
// Created by bazylip on 16.03.18.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "iostream"
#include "algorithm"

namespace minimaltimedifference{
    using ::std::string;
    using ::std::vector;
    unsigned int ToMinutes(const string &time_HH_MM);
    unsigned int MinimalTimeDifference(vector<string> times);
}

#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

//
// Created by bazylip on 03.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include "chrono"
#include "utility"


namespace profiling{
    template<class T>
    auto TimeRecorder(T function){
        auto start = std::chrono::system_clock::now();
        auto result = function();
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end-start).count();
        return std::make_pair(result, time);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H

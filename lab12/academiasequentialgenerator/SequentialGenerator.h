//
// Created by bazylip on 04.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class T, class U>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(): IdCounter_{0}{}
    SequentialIdGenerator(U id): IdCounter_{id}{}

    T NextValue();

private:
    T IdCounter_;

};

template <class T, class U>
T SequentialIdGenerator<T,U>::NextValue() {
    T ReturnId = IdCounter_;
    int ReturnValue = IdCounter_;
    IdCounter_ = T{ReturnValue+1};
    return ReturnId;
}
#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H

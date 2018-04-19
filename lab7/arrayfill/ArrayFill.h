//
// Created by bazylip on 18.04.18.
//
#include "vector"
#include "cstddef"
#include "random"
#include "memory"


#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

class ArrayFill {
public:
    virtual int Value(int index) const =0;
};



class UniformFill : public ArrayFill {
public:
    UniformFill(int value = 0) : value_{value} {}
    virtual int Value(int index) const override;
private:
    int value_;
};

class IncrementalFill : public ArrayFill {
public:
    IncrementalFill(int start, int step = 1) : start_{start}, step_{step} {}
    virtual int Value(int index) const override;

private:
    int start_;
    int step_;
};

class RandomFill : public ArrayFill {
public:
    RandomFill(std::unique_ptr<std::default_random_engine> generator,
               std::unique_ptr<std::uniform_int_distribution<int>> distribution) : generator_ {move(generator)}, distribution_ {move(distribution)} {}
    virtual int Value(int index) const override;

private:
    std::unique_ptr<std::default_random_engine> generator_;
    std::unique_ptr<std::uniform_int_distribution<int>> distribution_;

};

class SquaredFill : public ArrayFill {
public:
    SquaredFill(int a = 1, int b = 0) : a_ {a}, b_ {b} {}
    virtual int Value(int index) const override;

private:
    int a_;
    int b_;

};
void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);




#endif //JIMP_EXERCISES_ARRAYFILL_H

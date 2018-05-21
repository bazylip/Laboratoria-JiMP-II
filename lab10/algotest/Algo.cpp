//
// Created by bazylip on 16.05.18.
//

#include "Algo.h"

void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    std::copy(v.begin(), v.begin()+n_elements, std::back_inserter(*out));
}

bool algo::Contains(const std::vector<int> &v, int element) {
    if(std::find(v.begin(), v.end(), element) == v.end())
        return false;
    else
        return true;
}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    std::fill(v->begin(), v->end(), initial_value);
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    std::vector<int> output(length, 0);
    std::fill_n(output.begin(), length, initial_value);
    return output;
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    std::vector<std::string> output;
    std::transform(v.begin(), v.end(), std::back_inserter(output), [](double value) -> std::string{return std::to_string(value);});
    return output;
}

void algo::SortInPlace(std::vector<int> *v) {
    std::sort(v->begin(), v->end());
}

std::vector<int> algo::Sort(const std::vector<int> &v) {
    std::vector<int> output;
    std::copy(v.begin(), v.end(), std::back_inserter(output));
    std::sort(output.begin(), output.end());
}

void algo::SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
    auto comparator = [](const std::pair<int,int> &first, const std::pair<int,int> &second){return first.first<second.first;};
    std::sort(v->begin(), v->end(), comparator);
}

void algo::SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
    auto comparator = [](const std::pair<int,int> &first, const std::pair<int,int> &second){return first.second<second.second;};
    std::sort(v->begin(), v->end(), comparator);
}

void algo::SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
    auto comparator = [](const std::tuple<int,int,int> &first, const std::tuple<int,int,int> &second){return std::get<2>(first)<std::get<2>(second);};
    std::sort(v->begin(), v->end(), comparator);
}

int algo::Sum(const std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0);
}

int algo::Product(const std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
}

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    std::set<std::string> output;
    std::transform(m.begin(), m.end(), std::inserter(output, output.begin()), [](std::pair<std::string, int> para){return para.first; });
    return output;
}

std::vector<int> algo::Values(const std::map<std::string, int> &m) {
    std::vector<int> output;
    std::transform(m.begin(), m.end(), std::inserter(output, output.begin()), [](std::pair<std::string, int> para){return para.second; });
    return output;
}

bool algo::ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
    std::set<std::string> keys = Keys(v);
    if(std::find(keys.begin(), keys.end(), key) != keys.end())
        return true;
    else
        return false;
}

bool algo::ContainsValue(const std::map<std::string, int> &v, int value) {
    std::vector<int> values = Values(v);
    if(std::find(values.begin(), values.end(), value) != values.end())
        return true;
    else
        return false;
}

void algo::RemoveDuplicatesInPlace(std::vector<std::string> *v) {
    std::unique(v->begin(), v->end());
}

std::vector<int> algo::DivisableBy(const std::vector<int> &m, int divisor) {
    std::vector<int> v;
    CopyInto(m,m.size(),&v);
    v.erase(std::remove_if(v.begin(), v.end(), [&](const int &value){return value%divisor!=0;}), v.end());
    return v;
}

int algo::HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
    return std::count_if(v.begin(), v.end(), [&](const std::string test){if(test.length()<=inclusive_short_length){ return true;}else{return false;}});
}

std::vector<std::string> algo::RemoveDuplicates(const std::vector<std::string> &v) {
    std::vector<std::string> NewVector;
    std::copy(v.begin(), v.end(), NewVector);
    std::unique(NewVector.begin(), NewVector.end());

    return NewVector;
}
//
// Created by bazylip on 16.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include "vector"
#include "algorithm"
#include "tuple"
#include "set"
#include "map"

namespace algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);
    bool Contains(const std::vector<int> &v, int element);
    void InitializeWith(int initial_value, std::vector<int> *v);
    std::vector<int> InitializedVectorOfLength(int length, int initial_value);
    std::vector<std::string> MapToString(const std::vector<double> &v);
    void SortInPlace(std::vector<int> *v);
    std::vector<int> Sort(const std::vector<int> &v);
    void SortByFirstInPlace(std::vector<std::pair<int,int>> *v);
    void SortBySecondInPlace(std::vector<std::pair<int,int>> *v);
    void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v);
    std::set<std::string> Keys(const std::map<std::string, int> &m);
    std::vector<int> Values(const std::map<std::string, int> &m);
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);
    bool ContainsValue(const std::map<std::string, int> &v, int value);
    int Sum(const std::vector<int> &v);
    int Product(const std::vector<int> &v);
    void RemoveDuplicatesInPlace(std::vector<std::string> *v);
    std::vector<int> DivisableBy(const std::vector<int> &m,int divisor);
    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);
    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v);
}


#endif //JIMP_EXERCISES_ALGO_H

//
// Created by bazylip on 16.05.18.
//

#include "Algo.h"
#include "iostream"

using std::cout;
using std::endl;


int main(){

    std::vector<std::pair<int,int> > vector;
    std::vector<std::tuple<int,int,int> > tuples;

    vector.emplace_back(std::make_pair(2,3));
    vector.emplace_back(std::make_pair(5,3));
    vector.emplace_back(std::make_pair(-1,6));
    vector.emplace_back(std::make_pair(4,4));
    algo::SortBySecondInPlace(&vector);

    tuples.emplace_back(std::make_tuple(1,2,3));
    tuples.emplace_back(std::make_tuple(1,4,5));
    tuples.emplace_back(std::make_tuple(4,2,-2));
    tuples.emplace_back(std::make_tuple(1,2,7));

    algo::SortByThirdInPlace(&tuples);

    std::vector<std::string> str;
    std::vector<std::string> new_str;
    str.emplace_back("abc");
    str.emplace_back("abd");
    str.emplace_back("dzisiajjestsroda");
    str.emplace_back("cosdluzszego");

    int num = algo::HowManyShortStrings(str, 5);
    new_str = algo::RemoveDuplicates(str);

    for(auto i:new_str){
        cout<<i;
    }

    return 0;
}

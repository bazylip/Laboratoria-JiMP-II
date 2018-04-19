//
// Created by bazylip on 19.04.18.
//

#include "WordCounter.h"
#include "iostream"

namespace datastructures {
    Counts &Counts::operator++(int i) {
        count_++;
        return *this;
    }

//    bool Counts::operator==(const Counts &another) {
//        return (count_ == another.GetCount());
//    }

    bool operator==(const Counts &another, const int number){
        return(another.GetCount() == number);
    }

    bool Counts::operator<(const Counts &another) {
        return (count_ < another.GetCount());
    }

    bool Counts::operator>(const Counts &another) {
        return (count_ > another.GetCount());
    }

    const bool operator<(const Word &first, const Word &other) {
        return (first.GetWord() < other.GetWord());
    }
    const bool operator==(const Word &first, const Word &other) {
        return (first.GetWord() == other.GetWord());
    }

//    WordCounter::WordCounter(const std::initializer_list<std::string> &StringList) {
//        for (auto word : StringList) {
//            bool change = false;
//            for (auto elem : dict_) {
//                if (word == elem.first.GetWord()) {
//                    elem.second++;
//                    change = true;
//                }
//            }
//            if (!change) {
//                dict_.emplace_back(std::make_pair(Word(word), 0));
//            }
//        }
//    }

    int WordCounter::operator[](const std::string &str) {
        for (auto elem : dict_) {
            if (str == elem.first.GetWord()) {
                int amount = elem.second.GetCount();
                return amount;
            }
        }

        return 0;
    }

    int WordCounter::DistinctWords() {
        std::cout<<"wielkosc: "<<dict_.size()<<" "<<std::endl;
        return dict_.size();
    }

    int WordCounter::TotalWords() {
        int result = 0;
        for (auto el : dict_) {
            result += el.second.GetCount();
        }

        return result;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> result;
        for (auto el : dict_) {
            result.emplace(el.first.GetWord());
        }

        return result;
    }
}
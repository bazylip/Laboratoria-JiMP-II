//
// Created by bazylip on 19.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "string"
#include "vector"
#include "initializer_list"
#include "set"

namespace datastructures {
    class Counts {
    public:
        Counts() : count_{1} {}

        Counts(int i) : count_{i} {}

        inline void Increment(){
            count_++;
        }

        friend bool operator==(const Counts &another, const int number);

        bool operator<(const Counts &another);

        bool operator>(const Counts &another);

        Counts &operator++(int i);

        inline int GetCount() const { return count_; }

    private:
        int count_;
    };



    class Word {
    public:
        Word() : word_{""} {}

        Word(const std::string &str) : word_{str} {}

        friend const bool operator<(const Word &first, const Word &other);
        friend const bool operator==(const Word &first, const Word &other);
        inline std::string GetWord() const { return word_; }

    private:
        std::string word_;
    };

    const bool operator<(const Word &first, const Word &other);
    const bool operator==(const Word &first, const Word &other);

    class WordCounter {
    public:
        WordCounter() {}

        WordCounter(const std::initializer_list<Word> &List) : vector_{List}{
            for (auto word : vector_) {
                bool change = false;
                for (auto &elem : dict_) {
                    if (word.GetWord() == elem.first.GetWord()) {
                        elem.second.Increment();
                        change = true;
                    }
                }
                if (!change) {
                    dict_.emplace_back(std::make_pair(Word(word), 1));
                }
            }
        }

        int operator[](const std::string &str);
//    WordCounter operator<<(const std::string &file);


        int DistinctWords();

        int TotalWords();

        std::set<Word> Words();

    private:
        std::vector<std::pair<Word, Counts> > dict_;
        std::vector<Word> vector_;
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H

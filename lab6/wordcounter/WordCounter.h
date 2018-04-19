//
// Created by bazylip on 19.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "string"
#include "set"
#include "initializer_list"

class Counts{
public:
    Counts();
    Counts(int i);
    Counts &operator<(Counts &another);
    Counts &operator>(Counts &another);
    Counts &operator==(Counts &another);
    Counts &operator++(int i);


private:
    int count_;
};

class Word{
public:
    Word();
    Word(const std::string &str);

private:
    std::string word_;
};

class WordCounter{
public:
    WordCounter();
    WordCounter(const std::initializer_list<std::string> &StringList);
    WordCounter &operator[](const std::string &str);
    WordCounter &operator<<(const std::string &file);

    int DistinctWords();
    int TotalWords();
    std::set<Word> Words();


private:
    std::set<std::pair<Word, Counts> > dict_;
};


#endif //JIMP_EXERCISES_WORDCOUNTER_H

//
// Created by bazylip on 12.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include "initializer_list"
#include "string"
#include "experimental/string_view"
#include "set"
#include "algorithm"
#include "iostream"

namespace pool {
    class TextPool {
    public:
        TextPool();

        TextPool(const std::initializer_list<std::string> &StringList);

//        TextPool(const TextPool &t);

        TextPool(TextPool &&t);

        TextPool &operator=(TextPool &&t);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

        ~TextPool();

    private:
        std::set<std::string> StringSet_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H

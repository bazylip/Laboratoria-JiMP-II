//
// Created by bazylip on 12.04.18.
//

#include "TextPool.h"

namespace pool {
    using std::cout;
    using std::endl;
    using std::set;
    using std::experimental::string_view;

    TextPool::TextPool() {}
    TextPool::~TextPool() {}

//    TextPool::TextPool(const TextPool &t)  {
//        StringSet_.clear();
//        for(const std::string &str : t.StringSet_){
//            Intern(str);
//        }
//
//    }

    TextPool::TextPool(const std::initializer_list<std::string> &StringList) : StringSet_{StringList} {}

    TextPool::TextPool(TextPool &&t){
        std::swap(StringSet_, t.StringSet_);
    }

    TextPool &TextPool::operator=(TextPool &&t) {
        if (this == &t) {
            return t;
        }


        swap(StringSet_, t.StringSet_);
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        for (const std::string &s : StringSet_) {
            if (str.compare(s) == 0) {
                return s;

            }

        }
        StringSet_.insert(str);
        return string_view(str);

    }

    size_t TextPool::StoredStringCount() const {
        return StringSet_.size();
    }
}
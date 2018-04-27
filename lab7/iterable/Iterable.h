//
// Created by bazylip on 27.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include "string"
#include "memory"

namespace utility{

    class IterableIterator{
    public:
        virtual ~IterableIterator() = default;
        virtual std::pair<int, std::string> Dereference() const =0;
        virtual IterableIterator &Next() =0;
        virtual bool NotEquals(const std::unique_ptr<utility::IterableIterator>&) const =0;
    };

    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);


    };



}

#endif //JIMP_EXERCISES_ITERABLE_H

//
// Created by bazylip on 27.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include "string"
#include "memory"
#include "vector"

namespace utility{

    class IterableIterator{
    public:
        virtual ~IterableIterator() = default;
        virtual std::pair<int, std::string> Dereference() const =0;
        virtual IterableIterator &Next() =0;
        virtual bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const =0;
    };

    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end): LeftIterator_{left_begin}, RightIterator_{right_begin}, LeftEnd_{left_end}, RightEnd_{right_end}{}
        ZipperIterator() = default;
        ~ZipperIterator() override = default;
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const override;

        std::vector<int>::const_iterator LeftIterator_;
        std::vector<std::string>::const_iterator RightIterator_;
        std::vector<int>::const_iterator LeftEnd_;
        std::vector<std::string>::const_iterator RightEnd_;
    };

    class IterableIteratorWrapper{
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator): Iterator_{move(iterator)}{}
        bool operator!=(const IterableIteratorWrapper &other) const;
        std::pair<int, std::string> operator*() const;
        IterableIteratorWrapper &operator++();

        std::unique_ptr<utility::IterableIterator> Iterator_;
    };

    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin()  const =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

    };

    class Zipper : public Iterable{
    public:
        Zipper(std::vector<int> First, std::vector<std::string> Second);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        ZipperIterator Begin_;
        ZipperIterator End_;

        std::pair<std::vector<int>, std::vector<std::string>> Vectors_;
    };

    class Product : public Iterable{
    public:
        Product(std::vector<int> First, std::vector<std::string> Second);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        ZipperIterator Begin_;
        ZipperIterator End_;

        std::pair<std::vector<int>, std::vector<std::string>> Vectors_;
    };

    class Enumerate : public Iterable{
    public:
        Enumerate(std::vector<std::string> Second);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        ZipperIterator Begin_;
        ZipperIterator End_;

        std::pair<std::vector<int>, std::vector<std::string>> Vectors_;
    };


}

#endif //JIMP_EXERCISES_ITERABLE_H

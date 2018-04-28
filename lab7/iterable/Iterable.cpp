//
// Created by bazylip on 27.04.18.
//

#include "Iterable.h"

namespace utility{
    std::pair<int, std::string> ZipperIterator::Dereference() const {
        return std::pair <int, std::string> (*LeftIterator_, *RightIterator_);
    }

    IterableIterator& ZipperIterator::Next() {
        if(LeftIterator_ != LeftEnd_)
            ++LeftIterator_;
        if(RightIterator_ != RightEnd_)
            ++RightIterator_;

        return *this;
    }

    std::vector<int>::const_iterator& ZipperIterator::GetLeft() {
        return LeftIterator_;
    }

    std::vector<std::string>::const_iterator& ZipperIterator::GetRight() {
        return RightIterator_;
    }
//
//    bool ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
//        return(this == other)
//    }
//
//    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) const {
//        return NotEquals(std::unique_ptr<IterableIteratorWrapper> );
//    }git status
//
//    std::pair<int, std::string> IterableIteratorWrapper::Dereference() const {
//        return Iterator_->Dereference();
//    }
//
//    IterableIterator& IterableIteratorWrapper::Next() {
//        return Iterator_->Next();
//    }
}
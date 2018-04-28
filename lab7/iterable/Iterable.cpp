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

    bool ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
        ZipperIterator* ZipperOther = dynamic_cast<ZipperIterator*>(other.get());
        return((ZipperOther->LeftIterator_ != this->LeftIterator_) and (ZipperOther->RightIterator_ != this->RightIterator_));
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) const {
        return Iterator_->NotEquals(other.Iterator_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() const {
        return Iterator_->Dereference();
    }

    IterableIteratorWrapper& IterableIteratorWrapper::operator++() {
        Iterator_->Next();
        return *this;
    }
}
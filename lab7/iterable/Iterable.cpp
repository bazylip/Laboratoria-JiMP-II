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

    IterableIteratorWrapper Iterable::cbegin() const {
        return IterableIteratorWrapper(this->ConstBegin());
    }

    IterableIteratorWrapper Iterable::cend() const {
        return IterableIteratorWrapper(this->ConstEnd());
    }

    IterableIteratorWrapper Iterable::begin() const {
        return this->cbegin();
    }

    IterableIteratorWrapper Iterable::end() const {
        return this->cend();
    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        return std::make_unique<ZipperIterator>(Begin_);
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        return std::make_unique<ZipperIterator>(End_);
    }

    Zipper::Zipper(std::vector<int> First, std::vector<std::string> Second):Begin_(), End_() {

        if(First.size() > Second.size()){
            int diff = First.size()-Second.size();
            for(int i = 0; i < diff; ++i){
                Second.emplace_back(Second.back());
            }
        }else if (First.size() < Second.size()){
            int diff = Second.size()-First.size();
            for(int i = 0; i < diff; ++i){
                First.emplace_back(First.back());
            }
        }
        

        Vectors_ = std::make_pair(First, Second);
        Begin_ = ZipperIterator(Vectors_.first.begin(), Vectors_.second.begin(), Vectors_.first.end(), Vectors_.second.end());
        End_ = ZipperIterator(Vectors_.first.end(), Vectors_.second.end(), Vectors_.first.end(), Vectors_.second.end());

    }

    std::unique_ptr<IterableIterator> Product::ConstBegin() const {
        return std::make_unique<ZipperIterator>(Begin_);
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const {
        return std::make_unique<ZipperIterator>(End_);
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        return std::make_unique<ZipperIterator>(Begin_);
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        return std::make_unique<ZipperIterator>(End_);
    }

    Enumerate::Enumerate(std::vector<std::string> Second):Begin_(), End_() {
        std::vector<int> Index;

        for(int i = 1; i <= Second.size(); ++i){
            Index.emplace_back(i);
        }

        Vectors_ = std::make_pair(Index, Second);
        Begin_ = ZipperIterator(Vectors_.first.begin(), Vectors_.second.begin(), Vectors_.first.end(), Vectors_.second.end());
        End_ = ZipperIterator(Vectors_.first.end(), Vectors_.second.end(), Vectors_.first.end(), Vectors_.second.end());

    }

    Product::Product(std::vector<int> First, std::vector<std::string> Second):Begin_(), End_() {
        std::vector<int> Left;
        std::vector<std::string> Right;

        for(auto &LeftIt : First){
            for(auto &RightIt : Second){
                
                Right.emplace_back(RightIt);
                Left.emplace_back(LeftIt);
                
            }
        }
        
        Vectors_ = std::make_pair(Left, Right);
        Begin_ = ZipperIterator(Vectors_.first.begin(), Vectors_.second.begin(), Vectors_.first.end(), Vectors_.second.end());
        End_ = ZipperIterator(Vectors_.first.end(), Vectors_.second.end(), Vectors_.first.end(), Vectors_.second.end());

    }
}
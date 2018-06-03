//
// Created by bazylip on 30.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include "memory"

namespace tree {
    template<class Type>
    class Tree{
    public:
        Tree():left_{nullptr}, right_{nullptr}, element_{Type()}, Size_{1}{}
        Tree(Type element): element_{element}, left_{nullptr}, right_{nullptr}, Size_{1}{}
        size_t Size() const;
        size_t Depth() const;
        auto Value() const;
        void Insert(Type element);

    private:
        Type element_;
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        size_t Size_;
    };

    template<class Type>
    auto Tree<Type>::Value() const {
        return element_;
    }

    template<class Type>
    size_t Tree<Type>::Size() const {
        return Size_;
    }

    template<class Type>
    void Tree<Type>::Insert(Type element) {
        Tree<Type> *iterator = this;
        this->Size_ += 1;

        while(iterator->right_ != nullptr or iterator->left_ != nullptr){
            if(element < iterator->Value()){
                iterator = iterator->left_.get();
            } else{
                iterator = iterator->right_.get();
            }
        }

        if(element < iterator->Value()){
            iterator->left_ = std::make_unique<Tree>(element);
        } else{
            iterator->right_ = std::make_unique<Tree>(element);
        }


    }

    template<class Type>
    size_t Tree<Type>::Depth() const {
        size_t LeftDepth = this->left_->Depth();
        size_t RigthDepth = this->right_->Depth();
        if(LeftDepth > RigthDepth){
            return LeftDepth+1;
        } else{
            return RigthDepth+1;
        }

    }



}



#endif //JIMP_EXERCISES_TREE_H

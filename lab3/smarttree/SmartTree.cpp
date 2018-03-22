//
// Created by bazylip on 21.03.18.
//

#include "SmartTree.h"

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        auto leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){

        tree->left = std::move(left_subtree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){

        tree->right = std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr != nullptr){
            PrintTreeInOrder(unique_ptr->left, out);
            *out<<unique_ptr->value<<", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        using ::std::string;
        std::string output;
        if(tree != nullptr) {
            if(output.length() != 0)
                output += " [" + std::to_string(tree->value);
            else
                output += "[" + std::to_string(tree->value);
            output += " "+DumpTree(tree->left);
            output += " "+DumpTree(tree->right);
            output += "]";
        }else{
            output += "[none]";
        }

        return output;
    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        using ::std::string;



        string StringValue, LeftChildren, RightChildren;
        int i = 1, IntValue, counter = 0, test = 0;
        while(!isspace(tree[i]) && tree[i] != ']'){
            StringValue += tree[i++];
        }
        if(StringValue == "none")
            return nullptr;

        i++;
        while(counter != 0 || test == 0){
            test = 1;
            if(tree[i] == '[')
                ++counter;
            if(tree[i] == ']')
                --counter;
            LeftChildren += tree[i];
            ++i;
        }
        ++i;
        for(i; i < tree.length()-1; ++i){
            RightChildren += tree[i];
        }

        IntValue = std::stoi(StringValue);
        std::unique_ptr<SmartTree> leaf = CreateLeaf(IntValue);

        if(LeftChildren.compare("[none]") == 0) {
            leaf = InsertLeftChild(std::move(leaf), nullptr);
        }else {
            leaf = InsertLeftChild(std::move(leaf), std::move(RestoreTree(LeftChildren)));
        }
        if(RightChildren.compare("[none]") == 0){
            leaf = InsertRightChild(std::move(leaf), nullptr);
        }else {
            leaf = InsertRightChild(std::move(leaf), std::move(RestoreTree(RightChildren)));
        }

        return leaf;
    }
}

//
// Created by bazylip on 12.03.18.
//

#include "SimpleForwardList.h"
#include "iostream"

using namespace std;

void Init(ForwardList **head){
    *head = nullptr;
}

void DestroyList(ForwardList *list){
    if(list != nullptr) {
        ForwardList *Tmp = list;
        ForwardList *Next;
        while (Tmp->next != nullptr) {
            Next = Tmp;
            Tmp = Tmp->next;
            delete (Next);
        }
        delete (Tmp);
    }
}

ForwardList *CreateNode(int value){
    ForwardList *NewNode = (ForwardList*) new ForwardList;


    NewNode->next = nullptr;
    NewNode->value = value;

    return NewNode;
}

ForwardList *PushFront(ForwardList *list, int value){
    if(list == nullptr){
        return nullptr;
    }else {
        ForwardList *NewNode = CreateNode(value);

        NewNode->next = list;
        NewNode->value = value;

        list = NewNode;
        return list;
    }
}



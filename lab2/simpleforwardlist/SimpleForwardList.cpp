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
    ForwardList *Tmp = list;
    ForwardList *Next;
    while( Tmp->next != nullptr ){
        Next = Tmp;
        Tmp = Tmp->next;
        delete(Next);
    }
}

ForwardList* CreateNode(ForwardList *list, int value){
    ForwardList *NewNode = (ForwardList*) new ForwardList;

    NewNode->next = nullptr;
    NewNode->data = value;

    return NewNode;
}

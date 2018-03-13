//
// Created by bazylip on 12.03.18.
//

#include "iostream"
#include "SimpleForwardList.h"

using namespace std;

int main(void){
    ForwardList *list;

    Init(&list);

    list = PushFront(list, 5);

    cout<<list->value<<endl;

    list = PushFront(list, 6);

    cout<<list->value<<endl;

    return 0;
}


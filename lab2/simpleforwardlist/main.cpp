//
// Created by bazylip on 12.03.18.
//

#include "iostream"
#include "SimpleForwardList.h"

using namespace std;

int main(void){
    ForwardList *head;

    Init(&head);

    head = CreateNode(head, 5);

    cout<<head->data<<endl;

    return 0;
}


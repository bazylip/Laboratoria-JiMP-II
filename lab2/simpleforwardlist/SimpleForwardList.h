//
// Created by bazylip on 12.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

using namespace std;

struct ForwardList{
    int data;
    ForwardList *next;
};

void Init(ForwardList **head);
void DestroyList(ForwardList *list);
ForwardList *CreateNode(ForwardList *list, int value);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H

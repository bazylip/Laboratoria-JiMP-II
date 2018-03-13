//
// Created by bazylip on 12.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

using namespace std;

struct ForwardList{
    int value;
    ForwardList *next;
};

void Init(ForwardList **head);
void DestroyList(ForwardList *list);
ForwardList *CreateNode(int value);
ForwardList *PushFront(ForwardList *list, int value);



#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H

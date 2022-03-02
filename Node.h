//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_NODE_H
#define FIRSTDRAFT_NODE_H

template<class T>
struct  Node
{
    T data;
    Node* prev;
    Node* next;
};

#endif //FIRSTDRAFT_NODE_H
